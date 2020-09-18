import sbt._

object Ikuy { object Chips {
//lazy val busAndChips = ProjectRef(uri("git://github.com/deanoc/ikuy_chips_core_bus_and_chips#master"), "core")
  lazy val busAndChips = ProjectRef(file("../../../../chips/bus_and_chips"), "all")
  lazy val zynq_hard_soc = ProjectRef(file("../../../../chips/zynq_hard_soc"), "all")
  
}}