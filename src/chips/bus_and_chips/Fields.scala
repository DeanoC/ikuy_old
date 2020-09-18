package bus_and_chips

import scala.collection.immutable.Vector

trait FieldDesc
{
  def describe() : String
}

case class StringFieldDesc(val desc : String) extends FieldDesc
{
  def describe(): String = desc
}

sealed abstract class FieldDoc( val bits : String,
                                val fieldType : AccessType,
                                val description : String )

case class ReservedField(override val bits : String) 
extends FieldDoc(bits, IGNORE, "Reserved")

case class ReadOnlyField(override val bits : String, override val description : String) 
extends FieldDoc(bits, READONLY, description)

case class WriteOnlyField(override val bits : String, override val description : String) 
extends FieldDoc(bits, WRITEONLY, description)

case class ReadWriteField(override val bits : String, override val description : String)
extends FieldDoc(bits, READWRITE, description)
