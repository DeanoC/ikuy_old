package blinky

import spinal.core._
import spinal.lib._

//Hardware definition
object PlayDefaultClockDomain {

  class Blinky extends Component {
    val io = new Bundle {
      val leds = out Bits(4 bits)
    }

    // Remove io_ prefix from verilog names
    noIoPrefix()

    val count = Reg(UInt(21 bits))
    count := count + 1

    io.leds(0) := (count > 65536)
    io.leds(1) := (count < 65536)
    io.leds(2) := False
    io.leds(3) := False

    // dummy module to bring in the main and ps7 verilog
    val buildDummy = new BuildDummy()
  }

  def main(args: Array[String]): Unit = {
    var sc = SpinalConfig(
      mode = Verilog,
      targetDirectory="~/ikuy/build/carts/blinky/"
    )
    var rtl = sc.generate(ClockDomain.external("", withReset = true)(new Blinky))
    rtl.mergeRTLSource("/home/deano/ikuy/build/carts/blinky/external")
    rtl.printPruned()

    MyVivadoFlow(
      vivadoPath = "/opt/Xilinx/Vivado/2020.1/bin",
      workspacePath = "/home/deano/ikuy/build/carts/blinky/hardware/workspace/",
      modulePath = "/home/deano/ikuy/build/carts/blinky/Blinky.v",
      mergedPath = "/home/deano/ikuy/build/carts/blinky/external.v",
      family = "Artix 7",
      device = "xc7z020clg400-1",
    )
  }

}
