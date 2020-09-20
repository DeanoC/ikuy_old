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

  case class DebugReflectAddressRegister(override val defi : RegisterDef)
  extends CustomRegister(defi, needsStorage = false)
  {
    override def read(): Bits = B(address, 32 bits)
  }

  addRegister( 
    ReadWriteCustomRegister(  
      RegisterDef(name = "Test0",
                  rtype = READ_WRITE,
                  description = "A 32 bit R/W register to test bus is working",
                  default = 0xDCDCDCDCL) 
    ) 
  )
    
  for(r <- 1 until size.addressSpaceSize/4)
  {
    addRegister( 
      DebugReflectAddressRegister( 
        RegisterDef(name = s"Reflect${r}",
                    rtype = READ_ONLY,
                    description = "Returns the address of this register" ) 
        ) 
    )
  }

  connect()

}
