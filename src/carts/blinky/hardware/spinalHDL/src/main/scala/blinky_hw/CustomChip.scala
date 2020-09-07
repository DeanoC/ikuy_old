package blinky

import spinal.core._
import spinal.lib._
import scala.collection.mutable
import scala.collection.mutable.{ ArrayBuffer, HashMap}

sealed trait CustomChipSize
object TINY extends CustomChipSize
object SMALL  extends CustomChipSize
object MEDIUM extends CustomChipSize
object LARGE  extends CustomChipSize
object HUGE extends CustomChipSize

trait RegisterAction
{
  val name : String
  val documentation : String

  var address : BigInt = -1
  var owner : CustomChip = null

  val needsStorage : Boolean = true
  val hasRead : Boolean = false
  val hasWrite : Boolean = false
  val default : Bits = B"32'h0000_0000"
  
  // note addr is in custom chip address apce (so masked by sizeMask)
  def read() : Bits = { B"32'h0000_0000" }
  def write(data : Bits, byteMask : Bits) : Unit = {}
}

case class RegisterReadConstant(  override val name : String,
                                  override val documentation : String,
                                  override val hasRead : Boolean = true,
                                  override val needsStorage : Boolean = false,
                                  value : Bits
                                ) extends RegisterAction
{
  override val default = value
}
case class RegisterReadWrite(   override val name : String,
                                override val documentation : String,
                                override val hasRead : Boolean = true,
                                override val hasWrite : Boolean = true,
                                override val default : Bits 
                            ) extends RegisterAction
{
  override def read(): Bits = owner.getRegisterStorage(name)

  override def write( data : Bits, 
                      byteMask : Bits) : Unit = {
      val exist = owner.getRegisterStorage(name)
      val result = Bits(32 bits)
      result(24 until 32) := byteMask(3) ? data(24 until 32) | exist(24 until 32)
      result(16 until 24) := byteMask(2) ? data(16 until 24) | exist(16 until 24)
      result(8 until 16) := byteMask(1) ? data(8 until 16) | exist(8 until 16)
      result(0 until 8) := byteMask(0) ? data(0 until 8) | exist(0 until 8)
      owner.getRegisterStorage(name) := result
  }
}

abstract class CustomChip(  val size : CustomChipSize,
                            val chipName : String 
                          ) extends Area 
{
  def addressSpaceWidth : Int = size match {
    case TINY => 8      // 256B address space
    case SMALL => 12    // 4KB address space
    case MEDIUM => 16   // 6KB address space
    case LARGE => 20    // 1MB address space
    case HUGE => 27     // 128MB address space
  }

  def addressSpaceMask : Int = (1 << addressSpaceWidth) - 1

  var bus : BasicAxi3Slave = null
  var address : BigInt = -1

  var registerBaseAddress = BigInt(0)
  var registers = HashMap[String, RegisterAction]()
  var registerStorage = HashMap[String, Bits]()

  def addRegister(action : RegisterAction) = 
  {    
    assert(registerBaseAddress < (1 << addressSpaceWidth))
    action.address = registerBaseAddress
    registers += ((action.name, action))
    action.owner = this
    registerBaseAddress += 4
  }

  def getRegisterStorage(name : String) : Bits = registerStorage(name)

  def build() : Unit = 
  {
    println(s"build")
    for((name, action) <- registers) {
      if(action.needsStorage)
      {
          val reg = Reg(Bits(32 bits)) init action.default
          registerStorage += ((name, reg))
      }
    }
  }
}