package bus_and_chips

import scala.collection.mutable.{HashMap, ArrayBuffer}
import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._

case class BusID(val name : String, val index : Int)
{
  var busAddress : Long = 0

  def allocate(size : CustomChipSize) : Long = {
    val addr = busAddress
    busAddress += size.addressSpaceSize
    addr
  }
}

class Axi3Slave(  val config : Axi4Config,
                  val addressSpaceHighBit : Int,
                  val busID : BusID,
                  val motherboard : Motherboard,
                  val readAccess : Boolean = true,
                  val writeAccess : Boolean = true ) 
extends Component
{
  var io = new Bundle
  {
    val s_axi = slave( Axi4(config) )
  }

  var chipBaseAddress = 0L

  def sizeConverter(sizeVal : UInt) : UInt =
  {
    var arsize = UInt(3 bits)
    switch(sizeVal) {
      is(0) { arsize := U"3'h1" }
      is(1) { arsize := U"3'h2" }
      default { arsize := U"3'h4" }
    }
    arsize
  }

  val bus = this
  val chipAddresses = HashMap[ChipID, Long]()

  val chips = motherboard.getChipsConnectedToBus(busID)
  chips.filter( p => !motherboard.isChipHard(p)).foreach( c => {
    val chip = motherboard.getCustomChipByID(c)
    chipAddresses += c -> busID.allocate(chip.size)

    val connection = motherboard.getConnectionBetweenChipAndBus(c, busID)
    connection match {
      case FULL_DUPLUX_CONN => {
        val raddr = out Bits(chip.size.addressSpaceWidth bits)
        val rdata = in Bits(32 bits)
        io.add(raddr, s"${c.name}_read_address")
        io.add(rdata, s"${c.name}_read_data")
        raddr := B(0, chip.size.addressSpaceWidth bits)
        val wren = out Bool
        val wraddr = out Bits(chip.size.addressSpaceWidth bits)
        val wrdata = out Bits(32 bits)
        val wrstrb = out Bits(4 bits)
        io.add(wren, s"${c.name}_write_enable")
        io.add(wraddr, s"${c.name}_write_address")
        io.add(wrdata, s"${c.name}_write_data")
        io.add(wrstrb, s"${c.name}_write_strb")
        wren := False
        wraddr := B(0, chip.size.addressSpaceWidth bits)
        wrdata := B(0, 32 bits)
        wrstrb := B(0, 4 bits)
      }
      case _ => {
        println(s"ERROR ${connection} not supported on bus ${busID.name}")
      }
    }
  })

  if( readAccess )
  {
    io.s_axi.r.valid <> False
    io.s_axi.r.resp <> 0
    val arid = Reg(UInt(12 bits))
    when(io.s_axi.ar.valid)
    {
      arid := io.s_axi.ar.id
    }
    io.s_axi.r.id := arid
    io.s_axi.r.last <> False
    io.s_axi.r.data <> 0

    val readReadyForNewAddr = Reg(Bool) init True
    io.s_axi.ar.ready := readReadyForNewAddr

    // 4K boundary for axi increments
    val size = Reg(UInt(3 bits))
    val readFourKPage = Reg(UInt(12 bits)) //12 bit pages for Axi3
    val numberBytes = Reg(UInt(3 bits))
    val beat = RegInit(U(0, 8 bits))
    val burstLength = RegInit(U(0, 8 bits))
    val burstType = Reg(UInt(2 bits))
    val upperAddress = U(0, 17 bits) // 17+12 == 29 bits for addess (1GB-1B)
    when(readReadyForNewAddr)
    {
      when(io.s_axi.ar.valid && io.s_axi.ar.addr(addressSpaceHighBit))
      {
        size <> io.s_axi.ar.size
        val arsize = sizeConverter(size)
        numberBytes := arsize
        upperAddress := io.s_axi.ar.addr(13 to 29)
        readFourKPage := (io.s_axi.ar.addr(0 until 12) & ~Cat(B"0000_0000_0", (arsize-1)).asUInt)
        burstLength := io.s_axi.ar.len
        beat := io.s_axi.ar.len
        burstType := io.s_axi.ar.burst.asUInt
        readReadyForNewAddr := False
      }
    }.otherwise
    {
      io.s_axi.r.valid := True

      when(io.s_axi.r.ready)
      {
        when(beat > 0)
        {
          readFourKPage := Axi4.incr( address = readFourKPage,
                                      burst   = burstType.asBits,
                                      len     = burstLength,
                                      size    = size,
                                      bytePerWord = 4
          )

          beat := beat - 1
        }.elsewhen(beat === 0)
        {
          io.s_axi.r.last <> True
          readReadyForNewAddr := True
        }
      }
      io.s_axi.r.data := 0

      val chips = motherboard.getChipsConnectedToBus(busID)
      chips.filter( p => !motherboard.isChipHard(p)).foreach( c => {
        val chip = motherboard.getCustomChipByID(c)
        val csize = chip.size
        val addr = Cat(upperAddress, readFourKPage)
        val addrMasked = addr & ~U(csize.addressSpaceMask, 29 bits).asBits
        val connection = motherboard.getConnectionBetweenChipAndBus(c, busID)

        when(addrMasked === U(chipAddresses(c), 29 bits).asBits)
        {
            val registerAddress = addr.asBits.resize(csize.addressSpaceWidth bits) & csize.addressSpaceMask
            connection match {
                case FULL_DUPLUX_CONN => {
                  val bRaddrOption = bus.io.get(s"${c.name}_read_address")
                  if(bRaddrOption.isDefined) bRaddrOption.get := registerAddress
                  val bRdataOption = bus.io.get(s"${c.name}_read_data")
                  if(bRdataOption.isDefined) io.s_axi.r.data.asData := bRdataOption.get
                }
                case _ => {
                  println(s"ERROR ${connection} not supported on bus ${busID.name}")
                }
            }
        }
      })
    }

/*        if(ClockDomain.current.reset != null)
      {
          when(ClockDomain.current.reset)
          {
              io.s_axi.ar.ready <> False
              io.s_axi.r.valid <> False
          }
      }*/
  } else
  {
    io.s_axi.ar.ready <> False
    io.s_axi.r.valid <> False
    io.s_axi.r.payload.id <> 0
    io.s_axi.r.payload.data <> 0
    io.s_axi.r.payload.resp <> 0
    io.s_axi.r.payload.last <> False
  }

  if( writeAccess )
  {
    val bValidRegister = RegInit(False)
    io.s_axi.b.valid <> bValidRegister
    io.s_axi.b.resp <> 0
    val bid = Reg(UInt(12 bits))
    when(io.s_axi.aw.valid)
    {
      bid := io.s_axi.aw.id
    }
    io.s_axi.b.id := bid

    val writeReadyForNewAddr = RegInit(True)
    io.s_axi.aw.ready := writeReadyForNewAddr
    io.s_axi.w.ready := ~writeReadyForNewAddr

    val upperAddress = U(0, 17 bits) // 17+12 == 29 bits for addess (1GB-1B)

    // 4K boundary for axi increments
    val size = Reg(UInt(3 bits))
    val fourKPage = Reg(UInt(12 bits))
    val numberBytes = Reg(UInt(3 bits))
    val burstLength = RegInit(U(0, 8 bits))
    val burstType = Reg(UInt(2 bits))

    when(writeReadyForNewAddr)
    {
      when(io.s_axi.aw.valid && io.s_axi.aw.addr(addressSpaceHighBit))
      {
        size := io.s_axi.aw.size
        val awsize = sizeConverter(size)
        numberBytes := awsize
        upperAddress := io.s_axi.aw.addr(13 to 29)
        fourKPage := io.s_axi.aw.addr(0 until 12) & ~Cat(B"0000_0000_0", (awsize-1)).asUInt
        burstLength := io.s_axi.aw.len
        burstType := io.s_axi.aw.burst.asUInt
        writeReadyForNewAddr := False
      }
    }.otherwise
    {
      when(io.s_axi.w.valid)
      {
        when(!io.s_axi.w.last)
        {
          fourKPage := Axi4.incr( address = fourKPage,
                                  burst   = burstType.asBits,
                                  len     = burstLength,
                                  size    = size,
                                  bytePerWord = 4
          )
        }
        .otherwise
        {
          bValidRegister := True
        }
      }

      when(io.s_axi.b.valid && io.s_axi.b.ready)
      {
        bValidRegister := False
        writeReadyForNewAddr := True
      }

      val chips = motherboard.getChipsConnectedToBus(busID)
      chips.filter( p => !motherboard.isChipHard(p)).foreach( c => {
        val chip = motherboard.getCustomChipByID(c)
        val csize = chip.size
        val addr = Cat(upperAddress, fourKPage)
        val addrMasked = addr & ~U(csize.addressSpaceMask, 29 bits).asBits
        val connection = motherboard.getConnectionBetweenChipAndBus(c, busID)

        when(addrMasked === U(chipAddresses(c), 29 bits).asBits)
        {
          val registerAddress = addr.asBits.resize(csize.addressSpaceWidth bits) & csize.addressSpaceMask
          connection match {
            case FULL_DUPLUX_CONN => {
              val bWenOption = bus.io.get(s"${c.name}_write_enable")
              if(bWenOption.isDefined) bWenOption.get := True
              val bWaddrOption = bus.io.get(s"${c.name}_write_address")
              if(bWaddrOption.isDefined) bWaddrOption.get := registerAddress
              val bWdataOption = bus.io.get(s"${c.name}_write_data")
              if(bWdataOption.isDefined) bWdataOption.get := io.s_axi.w.data
              val bWstrbOption = bus.io.get(s"${c.name}_write_strb")
              if(bWstrbOption.isDefined) bWstrbOption.get := io.s_axi.w.strb
            }
            case _ => {
              println(s"ERROR ${connection} not supported on bus ${busID.name}")
            }
          }
        }
      })
    }

/*        if(ClockDomain.current.reset != null)
    {
        when(ClockDomain.current.reset)
        {
            io.s_axi.aw.ready := False
            io.s_axi.w.ready := False
            io.s_axi.b.valid := False
        }
    }*/
  } else
  {
    io.s_axi.aw.ready := False
    io.s_axi.w.ready := False
    io.s_axi.b.valid := False
    io.s_axi.b.payload.id := 0
    io.s_axi.b.payload.resp := 0
  }
}

