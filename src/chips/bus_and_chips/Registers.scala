package bus_and_chips

import spinal.core._

sealed trait AccessType
object IGNORE extends AccessType
object READONLY extends AccessType
object WRITEONLY  extends AccessType
object READWRITE extends AccessType

abstract class RegisterDef( 
                        val name : String, 
                        val description : String,
                        val registerType : AccessType,
                        val fields : Vector[FieldDoc],
                        val default : Bits = B"32'h0000_0000"
                      )

case class ReadOnlyRegisterDef(
                        override val name : String, 
                        override val description : String,
                        override val fields : Vector[FieldDoc] = Vector()) 
              extends RegisterDef( name = name, description = description, registerType = READONLY, fields = fields)

case class WriteOnlyRegisterDef(
                        override val name : String, 
                        override val description : String,
                        override val fields : Vector[FieldDoc] = Vector(),
                        override val default : Bits = B"32'h0000_0000") 
              extends RegisterDef( name = name, description = description, registerType = WRITEONLY, fields = fields)

case class ReadWriteRegisterDef(
                        override val name : String, 
                        override val description : String,
                        override val fields : Vector[FieldDoc] = Vector(),
                        override val default : Bits = B"32'h0000_0000")
              extends RegisterDef( name = name, description = description, registerType = READWRITE, fields = fields)

abstract class RegisterAction(   
                        val definition : RegisterDef,
                        val needsStorage : Boolean = true)
{
  // register index in custom chips register space
  var index : Int = -1
  // who owns this register
  var owner : CustomChip = null

  def read() : Bits = { B"32'h0000_0000" }
  def write(data : Bits, byteMask : Bits) : Unit = {}

  def hasRead() = definition.registerType == READONLY ||  
                  definition.registerType == READWRITE

  def hasWrite() = definition.registerType == WRITEONLY ||  
                  definition.registerType == READWRITE
}

case class RegisterReadConstant(override val definition : ReadOnlyRegisterDef) 
        extends RegisterAction(definition = definition, needsStorage = false)
{
}

case class RegisterReadOnly(override val definition : ReadOnlyRegisterDef)
        extends RegisterAction(definition = definition)
{
  override def read(): Bits = owner.getRegisterStorage(definition.name) as(Bits)
}

case class RegisterWriteOnly(override val definition : WriteOnlyRegisterDef)
        extends RegisterAction(definition = definition)
{
  override def write( data : Bits, byteMask : Bits) : Unit = {
      val result = Bits(32 bits)
      result(24 until 32) := byteMask(3) ? data(24 until 32) | B(0, 8 bits)
      result(16 until 24) := byteMask(2) ? data(16 until 24) | B(0, 8 bits)
      result(8 until 16) := byteMask(1) ? data(8 until 16) | B(0, 8 bits)
      result(0 until 8) := byteMask(0) ? data(0 until 8) | B(0, 8 bits)
      owner.getRegisterStorage(definition.name) := result
  }
}


case class RegisterReadWrite(override val definition : ReadWriteRegisterDef)
        extends RegisterAction(definition = definition)
{
  override def read(): Bits = owner.getRegisterStorage(definition.name) as(Bits)

  override def write( data : Bits, byteMask : Bits) : Unit = {
      val exist = owner.getRegisterStorage(definition.name) as(Bits)
      val result = Bits(32 bits)
      result(24 until 32) := byteMask(3) ? data(24 until 32) | exist(24 until 32)
      result(16 until 24) := byteMask(2) ? data(16 until 24) | exist(16 until 24)
      result(8 until 16) := byteMask(1) ? data(8 until 16) | exist(8 until 16)
      result(0 until 8) := byteMask(0) ? data(0 until 8) | exist(0 until 8)
      owner.getRegisterStorage(definition.name) := result
  }
}

