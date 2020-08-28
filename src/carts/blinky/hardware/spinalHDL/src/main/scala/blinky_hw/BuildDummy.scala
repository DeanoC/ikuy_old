package blinky

import spinal.core._

case class BuildDummy() extends BlackBox {
  addRTLPath("../verilog/mother.v")
  addRTLPath("../verilog/ps7_v5_5.v")
  addRTLPath("../verilog/ps7_wrapper_hi.v")
  addRTLPath("../verilog/ps7_wrapper_lo.v")
}
