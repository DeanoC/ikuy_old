package bus_and_chips

import spinal.core._
import spinal.lib._
import scala.collection.mutable
import scala.collection.mutable.{ ArrayBuffer, HashMap}

sealed trait CustomChipSize
object DUO extends CustomChipSize
object TINY extends CustomChipSize
object SMALL  extends CustomChipSize
object MEDIUM extends CustomChipSize
object LARGE  extends CustomChipSize
object HUGE extends CustomChipSize

abstract class CustomChip(  val size : CustomChipSize,
                            val chipName : String 
                          ) extends Component 
{
  // must be POW2 and fit in a signed 32 bit integer
  def addressSpaceSize : Int = size match {
    case DUO => (8 Bytes).intValue
    case TINY => (256 Bytes).intValue
    case SMALL => (4 KiB).intValue
    case MEDIUM => (64 KiB).intValue
    case LARGE => (1 MiB).intValue
    case HUGE => (128 MiB).intValue
  }
  def addressSpaceWidth : Int = log2Up(addressSpaceSize)
  def addressSpaceMask : Int = addressSpaceSize - 1

  var bus : Axi3Slave = null
  var address : BigInt = -1

  var registerIndex = 0
  var registers = HashMap[String, RegisterAction]()
  var registerStorage = HashMap[String, Bits]()

  def addRegister(action : RegisterAction) = 
  {    
    assert(registerIndex < addressSpaceSize/4)
    action.index = registerIndex
    registers += ((action.definition.name, action))
    action.owner = this
    registerIndex += 1
  }

  // add a register space hole
  def addHole( bytesForHole : Int ) = registerIndex += bytesForHole / 4

  def getRegisterStorage(name : String) : Bits = registerStorage(name)

  def build() : Unit = 
  {
    for((name, action) <- registers) {
      if(action.needsStorage)
      {
          val reg = Reg(Bits(32 bits)) init action.definition.default
          registerStorage += ((name, reg))
      }
    }
  }
}