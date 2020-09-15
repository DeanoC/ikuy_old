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

  case class DebugReflectAddressRegister(override val definition : ReadOnlyRegisterDef) 
        extends RegisterAction(definition = definition, needsStorage = false)
  {
    override def read(): Bits = B(index*4, 32 bits)
  }

  override def addRegisters(): Unit = 
  {
    addRegister( RegisterReadWrite(
          ReadWriteRegisterDef( name = "Test0",
              description = "A 32 bit R/W register to test bus is working",
              default = B"32'xDCDC_DCDC") ) )
      
    for(r <- 1 until size.addressSpaceSize/4)
    {
      addRegister( DebugReflectAddressRegister(
          ReadOnlyRegisterDef(name = s"Reflect${r}",
              description = "Returns the address of this register") ) )
    }
  }

}
