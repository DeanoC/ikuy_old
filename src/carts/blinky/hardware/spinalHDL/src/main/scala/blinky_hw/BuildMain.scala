package blinky
import spinal.core._
import spinal.lib.io._

object BuildMain {
    val sc = SpinalConfig(
      mode = Verilog,
      mergeAsyncProcess = true,
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = BOOT),
      defaultClockDomainFrequency = FixedFrequency(125 MHz),
      targetDirectory = "~/ikuy/build/carts/blinky/"
    )

  def main(args: Array[String]): Unit = {
    var rtl = sc.generate(InOutWrapper(new Blinky))
    rtl.mergeRTLSource("/home/deano/ikuy/build/carts/blinky/external")
    rtl.printPruned()

    // TODO mmProcessing of memory maps docs
    // https://github.com/plex1/memoryMapProcessing

    MyVivadoFlow(
      vivadoPath = "/opt/Xilinx/Vivado/2020.1/bin",
      workspacePath = "/home/deano/ikuy/build/carts/blinky/hardware/workspace/",
      modulePath = "/home/deano/ikuy/build/carts/blinky/Blinky.v",
      mergedPath = "/home/deano/ikuy/build/carts/blinky/external.v",
      family = "Artix 7",
      device = "xc7z020clg400-1"
    )
  }
}
