package bus_and_chips

import spinal.core._

class DebugCustomChip extends CustomChip( size = DUO, chipName = "Debug" )
{
  case class DebugReflectAddressRegister(override val definition : ReadOnlyRegisterDef) 
        extends RegisterAction(definition = definition, needsStorage = false)
  {
    override def read(): Bits = 
      B(((1L << owner.bus.addressSpaceHighBit) | owner.address | (index*4)), 32 bits)
  }

  override def build() : Unit = 
  {
    addRegister( RegisterReadWrite(
          ReadWriteRegisterDef( name = "Test0",
              description = "A 32 bit R/W register to test bus is working",
              default = B"32'xDCDC_DCDC") ) )
      
    for(r <- 1 until addressSpaceSize/4)
    {
      addRegister( DebugReflectAddressRegister(
          ReadOnlyRegisterDef(name = s"Reflect${r}",
              description = "Returns the address of this register") ) )
    }
    super.build()
  }
}
