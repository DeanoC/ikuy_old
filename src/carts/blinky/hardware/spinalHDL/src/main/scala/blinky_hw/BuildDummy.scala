package blinky

import spinal.core._

case class BuildDummy() extends BlackBox {
  addRTLPath("../verilog/main.v")
  addRTLPath("../verilog/ps7_v5_5.v")
  addRTLPath("../verilog/ps7_wrapper_hi.v")
  addRTLPath("../verilog/ps7_wrapper_mid.v")
  addRTLPath("../verilog/ps7_wrapper_lo.v")
}
