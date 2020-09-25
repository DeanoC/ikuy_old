package bus_and_chips

import spinal.core._
import spinal.lib._
import scala.collection.immutable.{ Vector }
import scala.collection.mutable.{ ArrayBuffer }

// a hard chip is non FPGA chip on hybrid FPGA (like Zynq)
abstract class HardChip(override val chipID : ChipID,
                        override val motherboard : Motherboard)
extends Chip(chipID, motherboard, true)
{
  val registerBanks = ArrayBuffer[HardRegisterBanks]()

  def addRegisterBanks(name : String, banks : Vector[(String, Long)], description : String) : Unit = 
  {
    registerBanks += new HardRegisterBanks( name, banks, description)
  }

  def addRegister(register : HardRegister) : HardRegister = {
    register.defi.name = registerBanks.last.name + "_" + register.defi.name
    registers += ((register.defi.name, register))
    register.owner = this
    registerBanks.last.registers += register.defi.name
    register
  }

  override def addHole( bytesForHole : Int ) : Unit =
  {

  }
}
