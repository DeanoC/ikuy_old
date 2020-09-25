package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._
import spinal.lib.blackbox.xilinx.s7._
import scala.collection.mutable.{ArrayBuffer, HashMap}
import bus_and_chips._
import zynq_hard_soc._
import dissy._

case class MasterAxi4SharedEndPlug(config : Axi4Config)
extends Component
{
  val io = new Bundle{
    val output = master(Axi4Shared(config))
  }

  io.output.arw.valid := False
  io.output.arw.payload.addr := 0
  io.output.arw.payload.write := False
  if(config.useId) io.output.arw.payload.id := 0
  if(config.useLen) io.output.arw.payload.len := 0
  if(config.useSize) io.output.arw.payload.size := 0
  if(config.useBurst) io.output.arw.payload.burst := 0
  if(config.useLock) io.output.arw.payload.lock := 0
  if(config.useCache) io.output.arw.payload.cache := 0
  if(config.useQos) io.output.arw.payload.qos := 0
  if(config.useProt) io.output.arw.payload.prot := 0
  if(config.useRegion) io.output.arw.payload.region := 0
  
  io.output.w.valid := False
  io.output.w.payload.data := 0
  if(config.useStrb) io.output.w.payload.strb := 0
  if(config.useLast) io.output.w.payload.last := False

  io.output.b.ready := False

  io.output.r.ready := False
}

class PWM(width : Int) extends Component {
  var io = new Bundle {
    // duty_cycle is the threshold value where the bit is on
    // UInt(width-1) = 100%
    // UInt(0) = 0%   
    val duty_cycle = in UInt(width bits)
    val pwm_out = out Bool
  }
  val counter = Reg(UInt(width bits))
  counter := (counter + 1).resize(width)
  when(io.duty_cycle > counter) {
    io.pwm_out := True
  }.otherwise
  {
    io.pwm_out := False
  }
}

class Blinky 
extends Motherboard {
  override val io = new Bundle {
    val leds = out Bits(4 bits)
    val rgb_led0 = out Bits(3 bits)
    val rgb_led1 = out Bits(3 bits)
    val btns = in Bits(4 bits)

    val sys_clk = in Bool

    val DDR = master( zynqDDR() )
    val MIO = master( zynqMIO() )
    val PS_CLOCK_AND_RESET = master( zynqPSClockAndReset() )
    val a = out Bits(6 bits)
    val ar = out Bits(14 bits)
//    val HDMI0 = master( HDMIConnector() )
  } 
  // Remove io_ prefix from verilog names
  noIoPrefix()

  val externalClockDomain = ClockDomain(
    clock = io.sys_clk,
    frequency = FixedFrequency(125 MHz),
    config = ClockDomainConfig (
      clockEdge = RISING,
      resetKind = BOOT
    )
  )

  val externalArea = new ClockingArea(externalClockDomain)
  {
    val sysPLL = new PLLE2_BASE(clkOut_Mult = 12,  // PLL @ 1500 MHz
                              clkOut0_Divide = 6,  // 250 MHz
                              clkOut1_Divide = 10, // 150 MHz
                              clkOut2_Divide = 12, // 125 MHz
                              clkOut3_Divide = 15, // 100 MHz
                              clkOut4_Divide = 60,  // 25 MHz
                              clkIn1_Period = 8.0 // 8ns == 125MHz
                              )
    sysPLL.CLKFBIN := sysPLL.CLKFBOUT // internal loop back
    sysPLL.CLKIN1 := io.sys_clk // input clock 125 MHz
    sysPLL.RST := False
    sysPLL.PWRDWN := False

    val sysClockDomain = ClockDomain.internal( name = "sysClk",
      frequency = FixedFrequency(125 MHz),
      config = ClockDomainConfig (
        clockEdge = RISING,
        resetKind = SYNC,
        resetActiveLevel = LOW
      )
    )

    sysClockDomain.clock := sysPLL.CLKOUT2
    var sysResetCC : BufferCC[Bool] = null

    val busClockDomain = ClockDomain.internal( 
      name = "busClk",
      frequency = FixedFrequency(100 MHz),
      config = ClockDomainConfig (
        clockEdge = RISING,
        resetKind = SYNC,
        resetActiveLevel = LOW
      )
    )
    busClockDomain.clock := sysPLL.CLKOUT3
    var busResetCC : BufferCC[Bool] = null

    val resetClockDomain = ClockDomain.internal( name = "resetClockDomain",
      config = ClockDomainConfig (
        clockEdge = RISING,
        resetKind = BOOT
      )
    )
    resetClockDomain.clock := sysPLL.CLKOUT4

    // layout motherboard
    val mcpID = addHardChip(
      "zynq_ps",
      (chipID : ChipID, mb : Motherboard) => 
      { 
        new zynqHardSoC(chipID = chipID, 
                        motherboard = mb,
                        config = zynqSoCConfig(
                          usePSMasterGP0Axi = true
                        ))
      })

    val buggyBoyID = addCustomChip(
      "BuggyBoy",
      (chipID : ChipID, mb : Motherboard) => 
      { 
        new DebugCustomChip(chipID = chipID, motherboard = mb) 
      })

    val dissyID = addCustomChip(
      "Dissy",
      (chipID : ChipID, mb : Motherboard) => 
      { 
        new DissyChip(chipID = chipID, motherboard = mb) 
      })

    val slaveGp0ID = addBus(
      "slaveGp0", 
      (busID : BusID, mb : Motherboard) => 
      { 
        new Axi3Slave(
          config = zynqAxis.PSMasterGPAxiConfig,
          addressSpaceHighBit = 30, // 0x40000000 address range
          busID = busID,
          motherboard = mb)
      })
    connectChipToBus( buggyBoyID, FULL_DUPLUX_CONN, slaveGp0ID)
    connectChipToBus( dissyID, FULL_DUPLUX_CONN, slaveGp0ID)

    val busClockArea = new ClockingArea(busClockDomain)
    {
      busResetCC = new BufferCC(Bool, null, 2)

      // stage 1 build creates just the hard hips
      build_stage1()

      // all bus and register area created and clocked
      // in the bus domain
      build_stage2(busClockDomain)
    }
    busClockDomain.reset := busResetCC.io.dataOut
    val sysClockArea = new ClockingArea(sysClockDomain)
    {
      sysResetCC = new BufferCC(Bool, null, 2)      
    }

    sysClockDomain.reset := sysResetCC.io.dataOut
    val dissy = getChipByID(dissyID).asInstanceOf[DissyChip]
    dissy.io.sys125MHzClk := sysClockDomain.clock
    dissy.io.sys125MHzReset_n := sysClockDomain.reset

    // basic MCP hook ups
    val mcp = getChipByID(mcpID).asInstanceOf[zynqHardSoC]
    mcp.io.PS_CLOCK_AND_RESET <> io.PS_CLOCK_AND_RESET
    mcp.io.DDR <> io.DDR 
    mcp.io.MIO <> io.MIO 

    // connect mcp and PS master GP0
    mcp.io.M_AXI_GP0_clk := busClockDomain.clock
    getBusByID(slaveGp0ID).io.s_axi << mcp.io.M_AXI_GP0

    // connect dissy to the outside world
    io.a(0) := ~dissy.io.vga.vsync
    io.a(1) := ~dissy.io.vga.hsync
    io.a(2 until 6) := dissy.io.vga.r(4 until 8)
    io.ar(0 until 4) := dissy.io.vga.g(4 until 8)
    io.ar(4 until 6) := dissy.io.vga.b(6 until 8) // blue not working dueto wiring OOPsie
    io.ar(6 until 14) := 0

    val resetArea = new ClockingArea(resetClockDomain)
    {
      val resetLength = 32 // in cycles
      // reset occurs in the slowest domain so everybody get *at least*
      // resetLength cycles of reset
      val resetPipe = Reg(Bits(resetLength bits)) init 1
      when(sysPLL.LOCKED && resetPipe(resetLength-1) === False)
      {
        resetPipe := resetPipe(0 until (resetLength-1)) ## B(0, 1 bit)
      }
      val reset_n : Bool = resetPipe(resetLength-1)
      busResetCC.io.dataIn := reset_n
      sysResetCC.io.dataIn := reset_n
      io.rgb_led0 := reset_n ## reset_n ## B"1'b0"
    }

    io.leds := B"4'b0000"
//    io.rgb_led0 := B"3'b000"
    io.rgb_led1 := B"3'b000"
  }
}