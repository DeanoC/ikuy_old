package bus_and_chips

import spinal.core._

class DebugCustomChip(
  override val chipID : ChipID,
  override val motherboard : Motherboard
)
extends CustomChip( size = DUO,  
                    chipID = chipID,
                    motherboard = motherboard)
{
  override val description: String = 
    """A test chip that is used to check bus is working okay.
      |Provides 2 registers, one that can store a 32 bit value
      |and the other which returns a constant that is the local
      |address of the register (0x4) currently""".stripMargin


  case class DebugReflectAddressRegister(override val defi : RegisterDef)
  extends CustomRegister(defi, needsStorage = false)
  {
    override def read(): Bits = B(address, 32 bits)
  }

  addRegister( RegisterDef(name = "Test0",
                  rtype = READ_WRITE,
                  description = "A 32 bit R/W register to test bus is working",
                  default = 0xDCDCDCDCL) )
    
  for(r <- 1 until size.addressSpaceSize/4)
  {
    addRegister( DebugReflectAddressRegister( RegisterDef(
                  name = s"Reflect${r}",
                  rtype = READ_ONLY,
                  description = "Returns the address of this register" ) 
                ) )
  }

  connect()
}
