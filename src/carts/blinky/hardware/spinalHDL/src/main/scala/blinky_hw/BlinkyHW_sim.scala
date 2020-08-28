package blinky

import spinal.sim._
import spinal.core.sim._

object DutTests 
{
  def main(args: Array[String]): Unit = 
  {
    var rtl = BuildMain.sc.generate(new Blinky)
    SimConfig.
      withWave.
      workspacePath("/home/deano/ikuy/build/carts/blinky/hardware/workspace/sim").
      withConfig(BuildMain.sc).
      compile(rtl).
      doSim(
      { dut =>
          dut.clockDomain.forkStimulus(period = 10)
          sleep(1000)
          simSuccess()
      })
  }
}