package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._
import spinal.lib.blackbox.xilinx.s7._
import scala.collection.mutable.{ArrayBuffer, HashMap}
import bus_and_chips._
import zynq_hard_soc._
//import dissy._

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
/*    val leds = out Bits(4 bits)
    val rgb_led0 = out Bits(3 bits)
    val rgb_led1 = out Bits(3 bits)*/
    val btns = in Bits(4 bits)
    val sys_clk = in Bool

    val DDR = master( zynqDDR() )
    val MIO = master( zynqMIO() )
    val PS_CLOCK_AND_RESET = master( zynqPSClockAndReset() )
  } 
  // Remove io_ prefix from verilog names
  noIoPrefix()
  
  val systemClockDomain = ClockDomain(
    clock = io.sys_clk,
    frequency = FixedFrequency(125 MHz)
  )
 
  val mcpID = addChip(
            "zynq_ps",
            (chipID : ChipID, mb : Motherboard) => 
            { 
              new zynqHardSoC(chipID = chipID, 
                              motherboard = mb,
                              config = zynqSoCConfig(
                                useFPGAClock0 = true,
                                usePSMasterGP0Axi = true
                              ))
            })
  val fclk0ClockDomain = ClockDomain.internal( 
    name = "fclk0",
    frequency = FixedFrequency(108 MHz),
    withClockEnable = true,
    config = ClockDomainConfig (
      clockEdge = RISING,
      resetKind = BOOT,
      resetActiveLevel = HIGH,
      clockEnableActiveLevel = HIGH
    )
  )

  val buggyBoyID = addChip(
              "BuggyBoy",
              (chipID : ChipID, mb : Motherboard) => 
              { 
                new DebugCustomChip(chipID = chipID, motherboard = mb) 
              })

  val slaveGp0ID = addBus(
                  "slaveGp0", 
                  (busID : BusID, mb : Motherboard) => { 
                    new Axi3Slave(
                      config = zynqAxis.PSMasterGPAxiConfig,
                      addressSpaceHighBit = 30, // 0x40000000 address range
                      busID = busID,
                      motherboard = mb)
                  })
  connectChipToBus( buggyBoyID, FULL_DUPLUX_CONN, slaveGp0ID)

  val fclk0ClockArea = new ClockingArea(fclk0ClockDomain)
  {
    build()
  }

  val mcp = getChipByID(mcpID).asInstanceOf[zynqHardSoC]
  mcp.io.PS_CLOCK_AND_RESET <> io.PS_CLOCK_AND_RESET
  mcp.io.DDR <> io.DDR 
  mcp.io.MIO <> io.MIO 
  mcp.io.FPGAClockEnable0 := True
  fclk0ClockDomain.clock := mcp.io.FPGAClock0
  fclk0ClockDomain.clockEnable := mcp.io.FPGAClockEnable0

  getBusByID(slaveGp0ID).io.s_axi << mcp.io.M_AXI_GP0
  mcp.io.M_AXI_GP0_clk <> mcp.io.FPGAClock0


/*
  val fclk0ClockArea = new ClockingArea(fclk0ClockDomain)*/
  {
  }
/*          val mrRessetiID = addChip(
                "MrResseti",
                (chipID : ChipID, mb : Motherboard) => 
                { 
                  new MrRessetiChip(chipID = chipID, motherboard = mb) 
                })


    build()

    val fpgaReset_n = !(getChipByID(mrRessetiID).io.get("reset_n").getOrElse(True) as(Bool))

    hardSoc.io.M_AXI_GP0_clk := hardSoc.io.FPGAClock0    
    getBusByID(slaveGp0ID).io.s_axi << hardSoc.ps7.io.ps_axi3_master_gp0
    
//    val dissy = new DissyCustomChip(fclk0ClockDomain.frequency)
//    dissy.io.axiClk <> fclk0ClockDomain.clock

//    dissy.io.axiReset <> fclk0ClockDomain.reset
//    hardSoc.io.M_AXI_GP0_clk := hardSoc.io.FCLK0_CLK
//    slaveGp0.io.s_axi << hardSoc.io.M_AXI_GP0
//    slaveGp0.io.axiClk <> fclk0ClockDomain.clock
//    slaveGp0.io.axiReset <> fclk0ClockDomain.reset
/*
    val dummy_master = new MasterAxi4SharedEndPlug(hardSoc.PSS_GeneralPurposeAxi)
    val axi4Convertor = new Axi4SharedToAxi3Shared(hardSoc.PSS_GeneralPurposeAxi)
    axi4Convertor.io.output.toAxi4 <> hardSoc.io.S_AXI_GP0
    axi4Convertor.io.input <> dummy_master.io.output
    hardSoc.io.S_AXI_GP0_clk := hardSoc.io.FCLK0_CLK
*/

    io.leds(0) := False //debug0
    io.leds(1) := False //debug1
    io.leds(2) := False //debug2
    io.leds(3) := False //debug3

    io.rgb_led0(0) := False
    io.rgb_led0(1) := False
    io.rgb_led0(2) := False

  }
  val systemClockArea = new ClockingArea(systemClockDomain)
  {
    val softReset = Reg(Bool) init False
    softReset := BufferCC(fclk0ClockArea.fpgaReset_n)

    fclk0ClockDomain.reset := softReset

    //Instanciate and drive the PLL (125 MHz * Mult) / Divide
    val pll = new PLLE2_BASE(clkOut_Mult = 10,      // 1250 MHz
                              clkOut0_Divide = 50)  //  25 MHz
    pll.CLKFBIN := pll.CLKFBOUT // internal loop back
    pll.CLKIN1 := io.sys_clk // input clock 125 MHz
    pll.RST := False
    pll.PWRDWN := False

    val thresholdArea = new ClockingArea(
      ClockDomain(pll.CLKOUT0, frequency = FixedFrequency(25 MHz)))
    {
      val width = 8
      val ledPWM = new PWM(width)
      val brightness = RegInit(U(0, width bits))
      ledPWM.io.duty_cycle <> brightness

      when(io.btns(0))
      {
        brightness := U(width/4, width bits)
      }.otherwise {
        brightness := U(0, width bits)
      }
      io.rgb_led1(0) := ledPWM.io.pwm_out
      io.rgb_led1(1) := ledPWM.io.pwm_out
      io.rgb_led1(2) := ledPWM.io.pwm_out
    }
  }*/
}