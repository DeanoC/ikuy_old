package blinky

import spinal.core._
import spinal.lib._

class Blinky extends Component {

  // dummy module to bring in the main and ps7 verilog
  val buildDummy = new BuildDummy()

  val io = new Bundle {
    val leds = out Bits(4 bits)
    val rgb_led0 = out Bits(3 bits)
    val rgb_led1 = out Bits(3 bits)

    // General Purporse 0 Axi4 PS master to PL slave 
    //val PS_M_AXI_GP0 = slave( Axi4(zynqAxiConfig) )

    // General Purporse 1 Axi4 PS master to PL slave 
//    val M_AXI_GP1 = slave( Axi4(axiConfig) )
  } 
  // Remove io_ prefix from verilog names
  noIoPrefix()

  io.leds(0) := True // io.PS_M_AXI_GP0.ar.valid
  io.leds(1) := True // io.PS_M_AXI_GP0.ar.ready
  io.leds(2) := False
  io.leds(3) := False

  io.rgb_led0(0) := True;
  io.rgb_led0(1) := False;
  io.rgb_led0(2) := False;
  io.rgb_led1(0) := False;
  io.rgb_led1(1) := True;
  io.rgb_led1(2) := False;

}