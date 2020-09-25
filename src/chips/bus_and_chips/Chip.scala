package bus_and_chips

import spinal.core._
import spinal.lib._
import scala.collection.mutable.{ HashMap, ArrayBuffer }

case class ChipID(val name : String, val index : Int)

// chips are things with registers connected on a motherboard
abstract class Chip(  val chipID : ChipID, 
                      val motherboard : Motherboard, 
                      val isHard : Boolean)
extends Component
{
  val description = ""

  val io = new Bundle {}

  var registers = HashMap[String, Register]()

  // add a register space hole
  def addHole( bytesForHole : Int ) : Unit

  def getRegisterByName(name : String) : Register = {
    registers(name)
  }

  // TODO improve pathing
  def LibraryPath = "../libraries"

  val cHeaderSrc = ArrayBuffer[(String,String)]()
  val cSrc = ArrayBuffer[(String,String)]()
  
  def addCHeaderFile(nameAndCode : (String, String)) = cHeaderSrc += nameAndCode 
  def addCSourceFile(nameAndCode : (String, String)) = cSrc += nameAndCode

}

