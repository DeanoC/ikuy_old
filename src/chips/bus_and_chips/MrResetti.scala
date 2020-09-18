package bus_and_chips

import spinal.core._
import bus_and_chips._

class MrRessetiChip(
  override val chipID : ChipID,
  override val motherboard : Motherboard
) 
extends CustomChip( size = DUO, 
                    chipID = chipID,
                    motherboard = motherboard )
{  
  lazy val resetCounter = Reg(UInt(10 bits)) init 0

  case class ResetFPGARegister(override val definition : WriteOnlyRegisterDef) 
        extends RegisterAction(definition = definition, needsStorage = false)
  {
    override def write( data : Bits, byteMask : Bits) : Unit = 
    {
      resetCounter := U(0x3FF, 10 bits)
    }
  }
  case class InResetFPGARegister(override val definition : ReadOnlyRegisterDef) 
        extends RegisterAction(definition = definition, needsStorage = false)
  {
    override def read() : Bits = 
    {
      (resetCounter === 0).asBits(32 bits)
    }
  }

  when(resetCounter > 0)
  {
    resetCounter := resetCounter - 1
  }

  override def addRegisters(): Unit = 
  {
    val reset_n = out Bool()
    io.add(reset_n, "reset_n")
    reset_n := (resetCounter === 0)

    addRegister( ResetFPGARegister(
        WriteOnlyRegisterDef(name = s"ResetFPGA",
            description = "Any write to this, we force a FPGA reset") ) )

    addRegister( InResetFPGARegister(
        ReadOnlyRegisterDef(name = s"ResetFPGAStatus",
            description = "Not 0 if system is currently in reset") ) )

  }
   
}