package bus_and_chips

import spinal.core._
import spinal.lib._
import scala.collection.mutable
import scala.collection.mutable.{ ArrayBuffer, HashMap}

case class ChipID(val name : String, val index : Int)

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

abstract class CustomChip(  val size : CustomChipSize,
                            val chipID : ChipID,
                            val motherboard : Motherboard)
extends Component 
{
  val io = new Bundle {}

  // subclasses should override this to add register to this chip
  def addRegisters() : Unit 

  var registerIndex = 0
  var registers = HashMap[String, RegisterAction]()
  var registerStorage = HashMap[String, Data]()

  addRegisters()

  val buses = motherboard.getBusesConnectedToChip(chipID)
  buses.foreach( b => {
    // read interface
    val craddr = in Bits(size.addressSpaceWidth bits)
    val crdata = out Bits(32 bits)
    io.add(craddr, s"${b.name}_read_address")
    io.add(crdata, s"${b.name}_read_data")
    switch(craddr(2 until size.addressSpaceWidth)) {
      registers.filter(_._2.hasRead).foreach( r => {
        val action : RegisterAction = r._2
        is(action.index) { crdata := action.read() }
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
          val action : RegisterAction = r._2
          is(action.index) {
            action.write(cwrdata, cwrstrb) 
          }
        })
      }
    }
  })

  def addRegister(action : RegisterAction) = 
  {
    assert(registerIndex < size.addressSpaceSize/4)

    action.index = registerIndex
    val name = action.definition.name
    registers += ((name, action))
    action.owner = this
    if(action.needsStorage)
    {
        var reg = Reg(Bits(32 bits)) init action.definition.default
        registerStorage += ((name, reg.asData))
    }
    registerIndex += 1
  }

  def getRegisterStorage(name : String) : Data = registerStorage(name)

  // add a register space hole
  def addHole( bytesForHole : Int ) = registerIndex += bytesForHole / 4
  
}