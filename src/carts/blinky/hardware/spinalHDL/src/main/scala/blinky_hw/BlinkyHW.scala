package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._
import spinal.lib.blackbox.xilinx.s7._

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

class Blinky extends Component {

  val io = new Bundle {
    val leds = out Bits(4 bits)
    val rgb_led0 = out Bits(3 bits)
    val rgb_led1 = out Bits(3 bits)
    val btns = in Bits(4 bits)
    val sys_clk = in Bool

    val DDR = inout(DdrInterface())
  } 

  // Remove io_ prefix from verilog names
  noIoPrefix()

  val systemClockDomain = ClockDomain(
    clock = io.sys_clk,
    frequency = FixedFrequency(125 MHz)
  )

  val hardSoc = new ps7_axi_wrapper()
  hardSoc.io.DDR_ARB <> 0
  hardSoc.io.DDR <> io.DDR

  val fclk0ClockDomain = ClockDomain(
    clock = hardSoc.io.FCLK0_CLK,
    reset = hardSoc.io.FCLK0_RESET,
    frequency = FixedFrequency(100 MHz),
    config = ClockDomainConfig (
      clockEdge = RISING,
      resetKind = SYNC,
      resetActiveLevel = HIGH
    )
  )

  val fclk0ClockArea = new ClockingArea(fclk0ClockDomain)
  {
/*    val ram = Axi4SharedOnChipRam(
      dataWidth = 32,
      byteCount = 4 KiB,
      idWidth = 12
    )
    // Map the APB peripheral bus onto the AXI4 address space using a crossboar
    val axiCrossbar = Axi4CrossbarFactory()
    axiCrossbar.addSlaves(
      ram.io.axi       -> (0x40000000L, 4 kB)
    )

    val shared_M_AXI_GP0 = hardSoc.io.M_AXI_GP0.toShared
    axiCrossbar.addConnections( 
       shared_M_AXI_GP0 -> List(ram.io.axi)
      )
    axiCrossbar.build()
*/

    val slaveGp0 = new BasicAxi3Slave(
                      config = hardSoc.GeneralPurposeAxi, 
                      addressSpaceHighBit = 30 // 0x40000000 address range
                      )
    hardSoc.io.M_AXI_GP0_clk := hardSoc.io.FCLK0_CLK
    slaveGp0.io.s_axi <> hardSoc.io.M_AXI_GP0
    slaveGp0.io.reset_n := ~ClockDomain.current.reset

    val slaveGp1 = new BasicAxi3Slave(
                      config = hardSoc.GeneralPurposeAxi, 
                      addressSpaceHighBit = 31 // 0x80000000 address range
                      )
    hardSoc.io.M_AXI_GP1_clk := hardSoc.io.FCLK0_CLK
    slaveGp1.io.s_axi <> hardSoc.io.M_AXI_GP1
    slaveGp1.io.reset_n := ~ClockDomain.current.reset

    val debug0 = RegInit(False)
    when(slaveGp0.io.s_axi.w.data === U("32'x0000_0000").asBits) {
      debug0 := True
    }
    val debug1 = RegInit(False)
    when(slaveGp0.io.s_axi.w.valid) {
      debug1 := True
    }
    val debug2 = RegInit(False)
    when(slaveGp0.io.s_axi.w.ready) {
      debug2 := True
    }
    val debug3 = RegInit(False)
    when(hardSoc.io.M_AXI_GP0.r.valid) {
      debug3 := True
    }

    io.leds(0) := debug0
    io.leds(1) := debug1
    io.leds(2) := debug2
    io.leds(3) := debug3

    io.rgb_led0(0) := False
    io.rgb_led0(1) := False
    io.rgb_led0(2) := False

  }


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

}