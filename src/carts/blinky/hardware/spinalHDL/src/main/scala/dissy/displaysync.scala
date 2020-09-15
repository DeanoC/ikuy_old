package dissy

import spinal.core._
import bus_and_chips._
import spinal.lib.blackbox.xilinx.s7._

class DissyCustomChip(
  val axiFrequency : ClockDomain.ClockFrequency,
  override val chipID : ChipID,
  override val motherboard : Motherboard
) 
extends CustomChip( size = TINY, 
                    chipID = chipID,
                    motherboard = motherboard,
                    chipName = "Dissy" )
{
  override val io = new Bundle {
    val axiClk = in Bool
    val axiReset = in Bool
  } 

  // for 640 x 480 @ 60 hz we want a 25.175 MHz pixel clock
  // 1062.5 MHz (FCLK0 x 10.625) / 42.25 gives 25.1479 MHz
  // for 640 x 480 @ 85 hz we want a 36 Mhz pixel clock
  // 1515.625 Mhz (125MHz x 12.125) / 42.125 = 35.979 MHz
  val mmcm0 = new MMCME2_BASE(clkOut_Mult_Frac = 10.625,
                              clkOut0_Divide_Frac = 42.25)
  mmcm0.CLKFBIN := mmcm0.CLKFBOUT // internal loop back
  mmcm0.CLKIN1 := io.axiClk // input clock 100 MHz
  mmcm0.RST := io.axiReset
  mmcm0.PWRDWN := False

  val axiClockDomain = ClockDomain.internal(
    name = "axiClock",
    frequency = axiFrequency,
    config = ClockDomainConfig (
      clockEdge = RISING,
      resetKind = SYNC,
      resetActiveLevel = HIGH
    )
  )
  axiClockDomain.clock := io.axiClk
  axiClockDomain.reset := io.axiReset

  val pixelClockDomain = ClockDomain.internal(
    name = "pixelClock",
    frequency = FixedFrequency(25.1479 MHz),
    config = ClockDomainConfig (
      clockEdge = RISING,
      resetKind = SYNC,
      resetActiveLevel = HIGH
    )  
  )
  pixelClockDomain.clock := mmcm0.CLKOUT0
  pixelClockDomain.reset := io.axiReset

  val lineBuffer = ASYNC_FIFO(  BRAMSize = 18, 
                                dataWidth = 36,
                                outputRegister = true)
  lineBuffer.io.regCE := False
  lineBuffer.io.reset := io.axiReset
  lineBuffer.io.resetReg := io.axiReset

  val axiClockArea = new ClockingArea(axiClockDomain)
  {
    val colourBars = new DissyColourBars()
    val colour = Reg(Bits(36 bits)) init 0 
    lineBuffer.io.writeClk := io.axiClk
    lineBuffer.io.writeEnable := colourBars.io.writeEnable 
    lineBuffer.io.writeData := colour 

    colourBars.io.stall := lineBuffer.io.full
    when(!colourBars.io.stall)
    {
      colour := Cat(B"12'xFFF", colourBars.io.writeData)
    }

    colourBars.io.newLine := True
  }

  val pixelClockArea = new ClockingArea(pixelClockDomain)
  {
    val colour = Reg(lineBuffer.io.readData) init 0
    lineBuffer.io.readClk := ClockDomain.current.clock
    when(!lineBuffer.io.empty) 
    {
      lineBuffer.io.readEnable := True
    }.otherwise
    {
      lineBuffer.io.readEnable := False
    }
  }

  override def addRegisters() : Unit = 
  {
    addRegister( RegisterReadWrite(
        ReadWriteRegisterDef( 
                name = "DisplaySource",
                description = "Where is the display data coming from?",
                default = B"32'x0000_0000") ) )
  }
}