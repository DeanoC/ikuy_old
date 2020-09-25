package bus_and_chips

import spinal.core._
import spinal.lib._
import scala.collection.mutable.{ HashMap }

sealed trait CustomChipSize
{
  // must be POW2 and fit in a signed 32 bit integer
  def addressSpaceSize : Int = this match {
    case DUO => (8 Bytes).intValue
    case TINY => (256 Bytes).intValue
    case SMALL => (4 KiB).intValue
    case MEDIUM => (64 KiB).intValue
    case LARGE => (1 MiB).intValue
    case HUGE => (128 MiB).intValue
  }

  def addressSpaceWidth : Int = log2Up(this.addressSpaceSize)
  def addressSpaceMask : Int = this.addressSpaceSize - 1
}

object DUO extends CustomChipSize
object TINY extends CustomChipSize
object SMALL  extends CustomChipSize
object MEDIUM extends CustomChipSize
object LARGE  extends CustomChipSize
object HUGE extends CustomChipSize

// a custom chip is a FPGA HDL connected on to the motherboard by busses
abstract class CustomChip(val size : CustomChipSize,
                          override val chipID : ChipID,
                          override val motherboard : Motherboard)
extends Chip(chipID, motherboard, false)
{
  class CustomChipBaseIO extends Bundle 
  {
    val busClk = in Bool
    val busReset_n = in Bool
  }

  var registerAddress = 0

  def addRegister(register : CustomRegister) : CustomRegister = 
  {
    assert(registerAddress < size.addressSpaceSize)
    register.address = registerAddress
    registers += ((register.defi.name, register))
    register.owner = this    
    registerAddress += 4
    register
  }

  def addRegister(regDef : RegisterDef) : CustomRegister = 
  {
    addRegister(
      regDef.rtype match 
      {
        case MIXED => ReadWriteCustomRegister(regDef)
        case WRITE_ONLY => WriteOnlyCustomRegister(regDef)
        case WRITE_TO_CLEAR => WriteToClearCustomRegister(regDef)
        case READ_ONLY => ReadOnlyCustomRegister(regDef)
        case CLEAR_ON_READ => ClearOnReadCustomRegister(regDef)
        case READ_AS_ZERO => ReadAsZeroCustomRegister(regDef)
        case READ_AS_UNDEFINED => ReadOnlyCustomRegister(regDef)
        case READ_WRITE => ReadWriteCustomRegister(regDef)
        case CLEAR_ON_WRITE => WriteToClearCustomRegister(regDef)
  //      case READ_WRITE_SET_ONLY => WriteOnlyCustomRegister(regDef)
  //      case READ_WRITE_ZERO => 

  //      case NON_SECURE_READ_ONLY => 
  //      case NON_SECURE_READ_WRITE => 
  //      case NON_SECURE_WRITE_ONLY => 
  //      case NON_SECURE_READ_AS_ZERO => 
  //      case SECURE_READ_ONLY => 
  //      case SECURE_READ_WRITE => 
  //      case SECURE_WRITE_ONLY => 
          case _ => { println("ERROR Register Type not suppoerted yet\n"); assert(false); null}
      })
  }

  override def addHole( bytesForHole : Int ) : Unit = registerAddress += bytesForHole

  def connect() : Unit = {
    val buses = motherboard.getBusesConnectedToChip(chipID)
    buses.foreach( b => {
      // read interface
      val craddr = in Bits(size.addressSpaceWidth bits)
      val crdata = out Bits(32 bits)
      io.add(craddr, s"${b.name}_read_address")
      io.add(crdata, s"${b.name}_read_data")
      switch(craddr(2 until size.addressSpaceWidth)) {
        registers.filter(_._2.hasRead).foreach( r => {
          val action = r._2.asInstanceOf[CustomRegister]
          is(action.address/4) { crdata := action.read() }
        })
        default { crdata := 0 }
      }
      // write interface
      val cwren = in Bool
      val cwraddr = in Bits(size.addressSpaceWidth bits)
      val cwrdata = in Bits(32 bits)
      val cwrstrb = in Bits(4 bits)
      io.add(cwren, s"${b.name}_write_enable")
      io.add(cwraddr, s"${b.name}_write_address")
      io.add(cwrdata, s"${b.name}_write_data")
      io.add(cwrstrb, s"${b.name}_write_strb")
      when(cwren) {
        switch(cwraddr(2 until size.addressSpaceWidth)) {
          registers.filter(_._2.hasWrite).foreach( r => {
            val action = r._2.asInstanceOf[CustomRegister]
            is(action.address/4) {
              action.write(cwrdata, cwrstrb) 
            }
          })
        }
      }      
    })
  }
}