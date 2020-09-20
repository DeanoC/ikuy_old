package bus_and_chips

import spinal.core._
import scala.collection.immutable.{ Vector }
import scala.collection.mutable.{ ArrayBuffer }

sealed class HardRegisterBanks( val name : String, 
                                val banks : Vector[(String,Long)],
                                val description : String,
                                val registers : ArrayBuffer[String] = ArrayBuffer[String]() )

// hard register are simple and can't be changed
sealed case class HardRegister(override val defi : RegisterDef)
extends Register(defi)
