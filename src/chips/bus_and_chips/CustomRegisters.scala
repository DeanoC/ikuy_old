package bus_and_chips

import spinal.core._

// custom registers next (in FPGA and can be extended)
abstract class CustomRegister(override val defi : RegisterDef,
                              val needsStorage : Boolean = true)
extends Register(defi)
{
  def read() : Bits = { B"32'h0000_0000" }
  def write(data : Bits, byteMask : Bits) : Unit = {}

  var storage = if(needsStorage) Reg(Bits(32 bits)) init defi.default else null

}

case class ConstantCustomRegister(override val defi : RegisterDef) 
extends CustomRegister(defi, needsStorage = false)

case class ReadOnlyCustomRegister(override val defi : RegisterDef)
extends CustomRegister(defi)
{
  override def read(): Bits = storage
}

case class WriteOnlyCustomRegister(override val defi : RegisterDef)
extends CustomRegister(defi)
{
  override def write( data : Bits, byteMask : Bits) : Unit = {
      val result = Bits(32 bits)
      result(24 until 32) := byteMask(3) ? data(24 until 32) | B(0, 8 bits)
      result(16 until 24) := byteMask(2) ? data(16 until 24) | B(0, 8 bits)
      result(8 until 16) := byteMask(1) ? data(8 until 16) | B(0, 8 bits)
      result(0 until 8) := byteMask(0) ? data(0 until 8) | B(0, 8 bits)
      storage := result
  }
}

case class ReadWriteCustomRegister(override val defi : RegisterDef)
extends CustomRegister(defi)
{
  override def read(): Bits = storage

  override def write( data : Bits, byteMask : Bits) : Unit = {
      val exist = read()
      val result = Bits(32 bits)
      result(24 until 32) := byteMask(3) ? data(24 until 32) | exist(24 until 32)
      result(16 until 24) := byteMask(2) ? data(16 until 24) | exist(16 until 24)
      result(8 until 16) := byteMask(1) ? data(8 until 16) | exist(8 until 16)
      result(0 until 8) := byteMask(0) ? data(0 until 8) | exist(0 until 8)
      storage := result
  }
}