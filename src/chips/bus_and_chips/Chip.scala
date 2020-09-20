package bus_and_chips

import spinal.core._
import spinal.lib._
import scala.collection.mutable.{ HashMap }

case class ChipID(val name : String, val index : Int)

// chips are things with registers connected on a motherboard
abstract class Chip( val chipID : ChipID, val motherboard : Motherboard, val isHard : Boolean)
extends Component
{
  val io = new Bundle {}

  var registers = HashMap[String, Register]()

  // add a register space hole
  def addHole( bytesForHole : Int ) : Unit

  // called in addRegisters to add an register
  def addRegister(register : Register) : Unit

  def getRegisterByName(name : String) : Register = {
    registers(name)
  }

  def CHeaderPath : String
  def DocPath : String 

}

