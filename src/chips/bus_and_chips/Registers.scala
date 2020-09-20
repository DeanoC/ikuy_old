package bus_and_chips

import scala.collection.mutable.{ArrayBuffer, HashMap}
import spinal.core._

sealed case class AccessType( val typeString : String)

object AccessType {
  def fromString(s : String) : AccessType = {
    s.toLowerCase match {
      case "mixed" => MIXED
      case "wo" => WRITE_ONLY
      case "wtc" => WRITE_TO_CLEAR

      case "ro" => READ_ONLY
      case "clronrd" => CLEAR_ON_READ
      case "raz" => READ_AS_ZERO
      case "rud" => READ_AS_UNDEFINED

      case "rw" => READ_WRITE
      case "clronwr" => CLEAR_ON_WRITE
      case "rwso" => READ_WRITE_SET_ONLY
      case "z" => READ_WRITE_ZERO

      case "nsnsro" => NON_SECURE_READ_ONLY
      case "nsnsrw" => NON_SECURE_READ_WRITE
      case "nsnswo" => NON_SECURE_WRITE_ONLY
      case "nssraz" => NON_SECURE_READ_AS_ZERO
      case "sro" => SECURE_READ_ONLY
      case "srw" => SECURE_READ_WRITE
      case "swo" => SECURE_WRITE_ONLY

      case _ => { println(f"ERROR unknown access type $s%n"); READ_WRITE_ZERO }
    }
  }
}

object MIXED extends AccessType("mixed")
object WRITE_ONLY  extends AccessType("wo")
object WRITE_TO_CLEAR extends AccessType("wtc")

object READ_ONLY extends AccessType("ro")
object CLEAR_ON_READ extends AccessType("clronrd")
object READ_AS_ZERO extends AccessType("raz")
object READ_AS_UNDEFINED extends AccessType("rud")

object READ_WRITE extends AccessType("rw")
object CLEAR_ON_WRITE extends AccessType("clronwr")
object READ_WRITE_SET_ONLY extends AccessType("rwso")
object READ_WRITE_ZERO extends AccessType("z")

object NON_SECURE_READ_ONLY extends AccessType("nsnsro")
object NON_SECURE_READ_WRITE extends AccessType("nsnsrw")
object NON_SECURE_WRITE_ONLY extends AccessType("nsnswo")
object NON_SECURE_READ_AS_ZERO extends AccessType("nssraz")
object SECURE_READ_ONLY extends AccessType("sro")
object SECURE_READ_WRITE extends AccessType("srw")
object SECURE_WRITE_ONLY extends AccessType("swo")

sealed case class RegisterDef(  var name : String, 
                                val description : String,
                                val rtype : AccessType,
                                val width : Int = 32,
                                val default : Long = 0)
{
  var fields = ArrayBuffer[FieldDoc]()
}

sealed class RegisterBanks( val name : String, 
                            val banks : Vector[(String,Long)],
                            val description : String)
{
  var registers = HashMap[String, Register]()
}

// base register whether hard or custom/soft
abstract class Register(val defi : RegisterDef)
{
  // register address (in bytes) in banks register space
  var address : Long = -1
  // who owns this register
  var owner : Chip = null

  def hasRead() = defi.rtype == READ_ONLY || defi.rtype == READ_WRITE

  def hasWrite() = defi.rtype == WRITE_ONLY || defi.rtype == READ_WRITE
}
/*
case class ReadOnlyRegisterDef( override val name : String, 
                                override val description : String,
                                override val default : Long = 0) 
extends RegisterDef( name, description, registerType = READONLY, default)

case class WriteOnlyRegisterDef(  override val name : String, 
                                  override val description : String,
                                  override val default : Long = 0) 
extends RegisterDef( name, description, registerType = WRITEONLY, default)

case class ReadWriteRegisterDef(  override val name : String, 
                                  override val description : String,
                                  override val default : Long = 0)
extends RegisterDef( name, description, registerType = READWRITE, default)
*/
