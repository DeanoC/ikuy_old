package dissy

import spinal.core._
import spinal.lib._
import bus_and_chips._
import spinal.lib.blackbox.xilinx.s7._
import spinal.lib.graphic.hdmi.TmdsEncoder

sealed trait OutputPixelFormat
{
  def fetchRaw36bits() : Bits
}

case class PixelFormat_3x12()
extends OutputPixelFormat
{
  val r = Bits(12 bits)
  val g = Bits(12 bits)
  val b = Bits(12 bits)

  def fetchRaw36bits() : Bits  = r ## g ## b
}

case class PixelFormat_1x12_3x8()
extends OutputPixelFormat
{
  val a = Bits(12 bits)
  val r = Bits(8 bits)
  val g = Bits(8 bits)
  val b = Bits(8 bits)

  def fetchRaw36bits() : Bits = a ## r ## g ## b 
}

case class HDMIConnector( val hasDCC : Boolean = false,
                          val hasCEC : Boolean = false,
                          val hasHotPlugDetect : Boolean = false )
extends Bundle with IMasterSlave
{
  val data_clk = TmdsEncoder()
  val data0 = TmdsEncoder()
  val data1 = TmdsEncoder()
  val data2 = TmdsEncoder()

  val hotPlugDetect = if(hasHotPlugDetect) Bool else null
  val ddc_scl : Bool = if(hasDCC) Bool else null
  val ddc_sda : Bool = if(hasDCC) Bool else null
  val cec : Bool = if(hasCEC) Bool else null

  override def asMaster() : Unit = 
  {
    // data_clk, data0, data1, data2
    if(hasHotPlugDetect) in(hotPlugDetect)
    if(hasDCC) in(ddc_scl, ddc_sda)
    if(hasCEC) in(cec)
  }
}

case class VGAConnector()
extends Bundle
{
  val r = out Bits(8 bits)
  val g = out Bits(8 bits)
  val b = out Bits(8 bits)
  val hsync = out Bool
  val vsync = out Bool
}



class DissyChip(
  override val chipID : ChipID,
  override val motherboard : Motherboard
) 
extends CustomChip( size = TINY, 
                    chipID = chipID,
                    motherboard = motherboard)
{
  class DissyIO extends CustomChipBaseIO 
  {
      val vga = VGAConnector()
      val sys125MHzClk = in Bool
      val sys125MHzReset_n = in Bool
 //   val hdmi = master(HDMIConnector(hasDCC = false, hasCEC = false, hasHotPlugDetect = false))
  }
  
  override val io = new DissyIO

  override val description: String = 
    """Dissy is a display chip for HDMI output.
      |Uses multiple clocks :
      |1 pixel clock of the display resolution.
      |2.Axi clock for the interface 
    """.stripMargin

  val dispCtrlReg = addRegister( RegisterDef( 
                name = "DISP_CTRL0",
                description = "Parameter for the display output",
                rtype = READ_WRITE ) 
              )

  val backGroundColourReg = addRegister( RegisterDef( 
                name = "BACKGROUND_COLOUR",
                description = "24 bit colour for background/solid colour",
                rtype = READ_WRITE ) 
              )
              
  val lineBuffer = ASYNC_FIFO(  BRAMSize = 36, 
                                dataWidth = 36,
                                outputRegister = true)  
  lineBuffer.io.writeClk := io.busClk
 
  // recreate the vsync counter this side of the clock boundrary
  val colourBars = new DissyColourBars(height = 640, width = 480)
  colourBars.io.stall := lineBuffer.io.full
  lineBuffer.io.writeEnable := False 
  lineBuffer.io.readEnable := False
  // select which data based on control mode
  switch(dispCtrlReg.storage) {
    is(0x0) {
      lineBuffer.io.writeEnable := colourBars.io.enable 
      lineBuffer.io.writeData := colourBars.io.data.resize(36)
    }
    is(0x1) {
      lineBuffer.io.writeData := backGroundColourReg.storage.resize(36)
    }
    default {
      lineBuffer.io.writeData := (B(0xD0, 8 bits) ## B(0xC0, 8 bits) ##B(0x0, 8 bits)).resize(36)
    }
  }
  // cross clock bits marking line end and screen end
  // need pulse sychronisation as these are set in the slow domain 
  var lineEnd = Reg(Bool)
  var screenEnd = Reg(Bool)
  val lineEndCC = new BufferCC(Bool, null, 2)
  lineEnd := lineEndCC.io.dataOut 
  val screenEndCC = new BufferCC(Bool, null, 2)
  screenEnd := screenEndCC.io.dataOut 

  val timingPipelineReg = Reg(Bool)
  timingPipelineReg := io.sys125MHzClk

  // for 640 x 480 @ 60 hz we want a 25.175 MHz pixel clock
  // 1000 MHz (syClk x 8) / 39.75 gives 25.16 MHz
  // for 640 x 480 @ 85 hz we want a 36 Mhz pixel clock
  // 1515.625 Mhz (125MHz x 12.125) / 42.125 = 35.979 MHz
  val mmcm0 = new MMCME2_BASE(clkOut_Mult_Frac = 8.0,
                              clkOut0_Divide_Frac = 39.75,
                              clkIn1_Period = 8.0)
  mmcm0.CLKIN1 := timingPipelineReg; // 125 MHz clk
  mmcm0.CLKFBIN := mmcm0.CLKFBOUT // internal loop back
  mmcm0.RST := io.sys125MHzReset_n
  mmcm0.PWRDWN := False

  val pixelClockDomain = ClockDomain.internal(
    name = "pixelClock",
    frequency = FixedFrequency(25.16 MHz),
    config = ClockDomainConfig (
      clockEdge = RISING,
      resetKind = SYNC,
      resetActiveLevel = LOW
    )  
  )

  pixelClockDomain.clock := mmcm0.CLKOUT0
  pixelClockDomain.reset := io.sys125MHzReset_n

  val pixelClockArea = new ClockingArea(pixelClockDomain)
  {
    val resetLength = 8 // in cycles
    val resetPipe = Reg(Bits(resetLength bits)) init 1
    when(mmcm0.LOCKED && resetPipe(resetLength-1) === False)
    {
      resetPipe := resetPipe(0 until (resetLength-1)) ## B(0, 1 bit)
    }
    lineBuffer.io.reset := resetPipe(resetLength-1)
 
    val colour = Reg(lineBuffer.io.readData) init 0

    lineBuffer.io.readClk := ClockDomain.current.clock

    val timing = new DisplayTiming()
    // cross clock transfer the two bits for lineEnd and screenEnd
    lineEndCC.io.dataIn := timing.io.lineEnd
    screenEndCC.io.dataIn := timing.io.screenEnd

    // if in the visible section of the display pull data from FIFO 
    when(timing.io.visible)
    {
      // if the fifo doesn't have any data use the last colour
      when(!lineBuffer.io.empty) 
      {
        colour := lineBuffer.io.readData
        lineBuffer.io.readEnable := True
      }
      io.vga.r := colour(0 until 8)
      io.vga.g := colour(8 until 16)
      io.vga.b := colour(16 until 24)
    }
    .otherwise
    {
      io.vga.r := B(0)
      io.vga.g := B(0)
      io.vga.b := B(0)
    }
    io.vga.hsync := timing.io.hsync
    io.vga.vsync := timing.io.vsync    
  }

  colourBars.io.lineEnd := lineEnd
  colourBars.io.screenEnd := screenEnd

  connect()
}