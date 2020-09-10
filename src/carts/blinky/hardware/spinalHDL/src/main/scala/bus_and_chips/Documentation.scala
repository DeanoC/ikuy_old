package bus_and_chips

import scala.collection.immutable.Vector

trait FieldDescription
{
  def describe() : String
}

case class StringFieldDescription(val desc : String ) extends FieldDescription
{
  def describe(): String = desc
}

case class FieldEnumValue(val name : String, val value : Int)

case class EnumFieldDescription(val desc : String, 
                                val enums : Vector[FieldEnumValue] ) 
                        extends FieldDescription
{
  def describe(): String = {
    var enumString : String = ""
    for( e <- enums ) {
//        enumString += 
    }
    enumString
  }
}



sealed abstract class FieldDocBase(  val bits : String,
                                val fieldType : AccessType,
                                val description : String )

case class ReservedField(override val bits : String) extends FieldDocBase(bits, IGNORE, "Reserved")


case class ReadOnlyField(override val bits : String, override val description : String) extends FieldDocBase(bits, READONLY, description)


case class WriteOnlyField(override val bits : String, override val description : String) extends FieldDocBase(bits, WRITEONLY, description)


case class ReadWriteField(override val bits : String, override val description : String) extends FieldDocBase(bits, READWRITE, description)

