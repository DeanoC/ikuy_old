package blinky

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib.bus.amba4.axi._
import scala.collection.mutable.{ArrayBuffer}
import bus_and_chips._
import dissy._

object BlinkyTests 
{
  def main(args: Array[String]): Unit = 
  {
    Axi3Bus_sim.test(BuildMain.sc)
//    DisplaySync_sim.test(BuildMain.sc)
  }
}