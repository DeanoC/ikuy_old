package bus_and_chips

trait FieldDesc 
{ 
  def describe() : String 
  def longDescribe() : String
}

case class StringFieldDesc(val desc : String, val longdesc : String = "")
extends FieldDesc
{
  def describe(): String = desc
  def longDescribe(): String = longdesc
}

sealed case class BitsDesc(val text : String)
{
  val singleBit = text.split(":").length < 2
  val hi : Int = Integer.parseInt( text.split(":")(0) )
  val lo : Int = if(singleBit) hi else Integer.parseInt( text.split(":")(1) )
  val bitCount : Int = (hi - lo)+1
  val mask : Long = ((1 << bitCount)-1).toLong << lo.toLong

  // sanity check
  if(singleBit) assert(bitCount == 1)
}

sealed case class FieldDoc( val name : String,
                            val bits : BitsDesc,
                            val fieldType : AccessType,
                            val desc : FieldDesc)
