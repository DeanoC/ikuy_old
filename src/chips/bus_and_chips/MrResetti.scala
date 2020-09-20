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

  case class ResetFPGARegister(override val defi : RegisterDef) 
        extends CustomRegister(defi, needsStorage = false)
  {
    override def write( data : Bits, byteMask : Bits) : Unit = 
    {
      resetCounter := U(0x3FF, 10 bits)
    }
  }

  when(resetCounter > 0)
  {
    resetCounter := resetCounter - 1
  }

  val reset_n = out Bool()
  io.add(reset_n, "reset_n")
  reset_n := (resetCounter === 0)

  addRegister( 
    ResetFPGARegister(
      RegisterDef(name = s"ResetFPGA",
                  rtype = WRITE_ONLY,
                  description = "Any write to this, we force a FPGA reset") ) )

  connect()
   
}