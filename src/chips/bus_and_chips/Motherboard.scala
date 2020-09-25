package bus_and_chips

import spinal.core._

import scala.collection.mutable.{ArrayBuffer, HashMap}

sealed trait ChipBusConnection 
{
  val wires : Array[String] = null
}

object PRIVATE_BUS_CONN extends ChipBusConnection
{
  override val wires = Array[String]()
}

object FULL_DUPLUX_CONN extends ChipBusConnection
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


class Motherboard()
extends Component
{
  val io = new Bundle {
  }

  val customChipGenerators = HashMap[ChipID,  (ChipID, Motherboard) => CustomChip]()
  val hardChipGenerators = HashMap[ChipID,  (ChipID, Motherboard) => HardChip]()
  val busGenerators = HashMap[BusID, (BusID, Motherboard) => Axi3Slave]()

  var chips : HashMap[ChipID, Chip] = null
  private var buses : HashMap[BusID, Axi3Slave] = null

  private var busChipConnections = ArrayBuffer[(ChipID, ChipBusConnection, BusID)]()

  def addCustomChip(name : String, chipGenerator : (ChipID, Motherboard) => CustomChip) : ChipID = 
  {
    val chipID = ChipID(name, customChipGenerators.size)
    customChipGenerators += (chipID -> chipGenerator)
    chipID
  }

  def addHardChip(name : String, chipGenerator : (ChipID, Motherboard) => HardChip) : ChipID = 
  {
    val chipID = ChipID(name, hardChipGenerators.size)
    hardChipGenerators += (chipID -> chipGenerator)
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

  def isChipHard(chipID : ChipID) : Boolean = {
    assert(chips != null)
    chips(chipID).isHard
  }

  def getChipByID(chipID : ChipID) : Chip = {
    assert(chips != null)
    chips(chipID)
  }

  def getHardChipByID(chipID : ChipID) : HardChip = {
    assert(isChipHard(chipID))
    chips(chipID).asInstanceOf[HardChip]
  }

  def getCustomChipByID(chipID : ChipID) : CustomChip = {
    assert(!isChipHard(chipID))
    chips(chipID).asInstanceOf[CustomChip]
  }

  def getBusByID(busID : BusID) : Axi3Slave = {
    assert(buses != null)
    buses(busID)
  }

  def build_stage1() = 
  {
    chips = new HashMap[ChipID, Chip]()
    buses = new HashMap[BusID, Axi3Slave]()

    // create the hard chips first
    hardChipGenerators.foreach{ case (chipID, cg) => {
      val chip = cg(chipID, this)
      assert(chip != null)
      chips += (chipID -> chip)
    }}
  }

  def build_stage2(busClockDomain : ClockDomain) = 
  {
    // create the chips 
    // will create io for each bus they will be connected to
    customChipGenerators.foreach{ case (chipID, cg) => {
      val chip = cg(chipID, this)

      val busClk = chip.io.get("busClk")
      if(busClk.isDefined) busClk.get := busClockDomain.clock
      val busReset_n = chip.io.get("busReset_n")
      if(busReset_n.isDefined) busReset_n.get := busClockDomain.reset

      assert(chip != null)
      chips += (chipID -> chip)
    }}

    // create the buses
    // will create io for each chip they will be connected to
    busGenerators.foreach{ case (busID, bg) => {
      val bus = bg(busID, this)
      buses += busID -> bus
      val busClk = bus.io.get("busClk")
      if(busClk.isDefined) busClk.get := busClockDomain.clock
      val busReset_n = bus.io.get("busReset_n")
      if(busReset_n.isDefined) busReset_n.get := busClockDomain.reset
    }}

    // now connect buses and chips
    chips.foreach{ case (c, chip) => {
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
    }}

    // generate headers and docs
    chips.foreach{ case (c, chip) => {
      CHeaderRegisterOutput.generateHeaders(chip)
      MarkdownRegisterOutput.generateMarkdowns(chip)
    }}
  }
}
