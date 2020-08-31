package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._


class PWM(width : Int) extends Component {
  var io = new Bundle {
    // duty_cycle is the threshold value where the bit is on
    // UInt(width-1) = 100%
    // UInt(0) = 0%   
    val duty_cycle = in UInt(width bits)
    val pwm_out = out Bool
  }
  val counter = Reg(UInt(width bits))
  counter := (counter << 1).resize(width)
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
  
  val hardSoc = new ps7_wrapper()
  hardSoc.io.DDR_ARB <> 0
  hardSoc.io.DDR <> io.DDR
  
  //Instanciate and drive the PLL (125 MHz * Mult) / Divide
  val pll = new PLLE2_BASE(clkOut_Mult = 10,      // 1250 MHz
                            clkOut0_Divide = 50)  //  25 MHz
  pll.CLKFBIN := pll.CLKFBOUT // internal loop back
  pll.CLKIN1 := io.sys_clk // input clock 125 MHz
  pll.RST := False

  val systemClockDomain = ClockDomain(
    clock = io.sys_clk,
    frequency = FixedFrequency(125 MHz)
  )

  val thresholdArea = new ClockingArea(
    ClockDomain(pll.CLKOUT0, frequency = FixedFrequency(25 MHz)))
  {
    val width = 4
    val ledPWM = new PWM(width)
    val brightness = RegInit(U(0, 4 bits))

    ledPWM.io.pwm_out <> io.rgb_led0(2)
    ledPWM.io.duty_cycle <> brightness

    when(io.btns(0))
    {
      brightness := U"4'h8"
    }.otherwise {
      brightness := U"4'h0"
    }
  }
  val systemArea = new ClockingArea(systemClockDomain)
  {
  }


  io.leds(0) := False
  io.leds(1) := False
  io.leds(2) := False
  io.leds(3) := False

  io.rgb_led0(0) := False;
  io.rgb_led0(1) := False;
  io.rgb_led1(0) := False;
  io.rgb_led1(1) := False;
  io.rgb_led1(2) := False;

}