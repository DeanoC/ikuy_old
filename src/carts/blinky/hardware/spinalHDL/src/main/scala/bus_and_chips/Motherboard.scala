package bus_and_chips

import spinal.core._

import scala.collection.mutable.{ArrayBuffer, HashMap}

sealed trait ChipBusConnection 
{
  val wires : Array[String] = null
}

object CHIP_BUS_FULL_DUPLUX_CONNECTION extends ChipBusConnection
{
  override val wires = Array(
    "read_address",
    "read_data",
    "write_enable",
    "write_address",
    "write_data",
    "write_strb"
  )
}


case class Motherboard()
extends Component
{
  val io = new Bundle {
  }

  val chipGenerators = HashMap[ChipID,  (ChipID, Motherboard) => CustomChip]()
  val busGenerators = HashMap[BusID, (BusID, Motherboard) => Axi3Slave]()

  private var chips : HashMap[ChipID, CustomChip] = null
  private var buses : HashMap[BusID, Axi3Slave] = null

  private var busChipConnections = ArrayBuffer[(ChipID, ChipBusConnection, BusID)]()

  def addChip(name : String, chipGenerator : (ChipID, Motherboard) => CustomChip) : ChipID = 
  {
    val chipID = ChipID(name, chipGenerators.size)
    chipGenerators += chipID -> chipGenerator
    chipID
  }

  def addBus(name : String, busGenerator : (BusID, Motherboard) => Axi3Slave) : BusID = 
  {
    val busID = BusID(name, busGenerators.size)
    busGenerators += busID -> busGenerator
    busID
  }

  def connectChipToBus( chipID : ChipID, 
                        connection : ChipBusConnection, 
                        busID : BusID) = 
  {
    busChipConnections += ((chipID, connection, busID))
  }

  def getChipsConnectedToBus(busID : BusID) : Array[ChipID] = {
    busChipConnections.filter(_._3 == busID).map(_._1).toArray
  }
  def getBusesConnectedToChip(chipID : ChipID) : Array[BusID] = {
    busChipConnections.filter(_._1 == chipID).map(_._3).toArray
  }

  def getConnectionBetweenChipAndBus(chipID : ChipID, busID : BusID ) : ChipBusConnection = {
    val a : Array[ChipBusConnection]= busChipConnections.filter( p => p._1 == chipID && p._3 == busID ).map(_._2).toArray
    assert(!a.isEmpty) 
    a(0)
  }

  def getChipByID(chipID : ChipID) : CustomChip = {
    assert(chips != null)
    chips(chipID)
  }

  def getBusByID(busID : BusID) : Axi3Slave = {
    assert(buses != null)
    buses(busID)
  }

  def build() = 
  {
    chips = new HashMap[ChipID, CustomChip]()
    buses = new HashMap[BusID, Axi3Slave]()

    // create the chips 
    // will create io for each bus they will be connected to
    chipGenerators.foreach( { case (chipID, cg) => {
      chips += chipID -> cg(chipID, this)
    }})

    // create the buses
    // will create io for each chip they will be connected to
    busGenerators.foreach( { case (busID, bg) => {
      buses += busID -> bg(busID, this)
    }})

    // now connect buses and chips
    chips.foreach( { case (c, chip) => {
        val busIDs = getBusesConnectedToChip(c)
        busIDs.foreach( b => {
          val bus = getBusByID(b)
          val connection = getConnectionBetweenChipAndBus(c, b)
          connection.wires.foreach( n => {
            val cOption = chip.io.get(s"${b.name}_${n}")
            val bOption = bus.io.get(s"${c.name}_${n}")
            if(cOption.isDefined && bOption.isDefined)
              cOption.get <> bOption.get
            else println(s"ERROR ${c.name}_${n}=${cOption} or ${b.name}_${n}=${bOption} not found")
          })
        })
    }})
  }
}
