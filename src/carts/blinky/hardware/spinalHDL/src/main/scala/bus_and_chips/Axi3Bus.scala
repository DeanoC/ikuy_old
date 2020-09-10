package bus_and_chips

import scala.collection.mutable.{ArrayBuffer}
import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._

class Axi3Slave(    val config : Axi4Config,
                    val readAccess : Boolean = true,
                    val writeAccess : Boolean = true,
                    val chipsOfBus : ArrayBuffer[CustomChip] = ArrayBuffer[CustomChip](),
                    val addressSpaceHighBit : Int = 30,
                    val axiFrequency : ClockDomain.ClockFrequency = FixedFrequency(100 MHz)
                    ) extends Component 
{
    var io = new Bundle 
    {
        val s_axi = slave( Axi4(config) )
        val axiClk = in Bool
        val axiReset = in Bool
    }

    var chipBaseAddress = BigInt(0)
    var chips = ArrayBuffer[CustomChip]()

    def addChip(chip : CustomChip) : Unit = 
    {
        chip.bus = this
        chip.address = chipBaseAddress
        chips += chip
        chipBaseAddress += chip.addressSpaceWidth
    }

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

    val axiClockDomain = ClockDomain.internal(
        name = "axiClock",
        frequency = axiFrequency,
        config = ClockDomainConfig (
            clockEdge = RISING,
            resetKind = SYNC,
            resetActiveLevel = HIGH
        )
    )
    axiClockDomain.clock := io.axiClk
    axiClockDomain.reset := io.axiReset

    val axiClockArea = new ClockingArea(axiClockDomain)
    {
        println("Adding chips")
        chipsOfBus.foreach( chip => {
            addChip(chip)
        })

        chips.foreach( chip => {
            println(f"Building ${chip.chipName} chip")
            chip.build()
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

                when(beat === 0)
                {
                    io.s_axi.r.last <> True
                }

                when(io.s_axi.r.ready)
                {
                    when(beat > 0)
                    {
                        readFourKPage := Axi4.incr(
                            address = readFourKPage,
                            burst   = burstType.asBits,
                            len     = burstLength,
                            size    = size,
                            bytePerWord = 4
                        )

                        beat := beat - 1
                    }.elsewhen(beat === 0)
                    {
                        readReadyForNewAddr := True
                    }
                }

                chips.foreach( chip => {
                    val addr = Cat(upperAddress, readFourKPage)
                    val addrMasked = addr & ~U(chip.addressSpaceMask, 29 bits).asBits

                    when(addrMasked === U(chip.address, 29 bits).asBits)
                    {
                        val registerAddress = addr.asBits.resize(chip.addressSpaceWidth bits) &
                                                                chip.addressSpaceMask
                        switch(registerAddress(2 until chip.addressSpaceWidth)) {
                            chip.registers.filter( f => f._2.hasRead).foreach {
                                case (name, action) =>
                                    is(action.index) {
                                        io.s_axi.r.data <> action.read()
                                    }
                            }
                        }
                    }
                })
            }
            when(ClockDomain.current.reset) 
            {
                io.s_axi.ar.ready <> False
                io.s_axi.r.valid <> False
            }
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
            io.s_axi.b.valid <> False
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
            val beat = RegInit(U(0, 8 bits))
            val burstLength = RegInit(U(0, 8 bits))
            val burstType = Reg(UInt(2 bits))

            when(writeReadyForNewAddr)
            { 
                when(io.s_axi.aw.valid && io.s_axi.aw.addr(addressSpaceHighBit))
                {
                    size := io.s_axi.aw.size
                    val awsize = sizeConverter(size)                
                    numberBytes := awsize
                    upperAddress := io.s_axi.ar.addr(13 to 29)
                    fourKPage := io.s_axi.aw.addr(0 until 12) & ~Cat(B"0000_0000_0", (awsize-1)).asUInt
                    burstLength := io.s_axi.aw.len
                    beat := io.s_axi.aw.len
                    burstType := io.s_axi.aw.burst.asUInt
                    writeReadyForNewAddr := False
                }
            }.otherwise
            {
                when(io.s_axi.w.valid && io.s_axi.w.ready)
                {
                    when(beat > 0)
                    {
                        fourKPage := Axi4.incr(
                            address = fourKPage,
                            burst   = burstType.asBits,
                            len     = burstLength,
                            size    = size,
                            bytePerWord = 4
                        )

                        beat := beat - 1
                    }.elsewhen(beat === 0)
                    {
                        io.s_axi.b.valid <> True
                        writeReadyForNewAddr := True
                    }

                    chips.foreach( chip => {
                        val addr = Cat(upperAddress, fourKPage)
                        val addrMasked = addr & ~U(chip.addressSpaceMask, 29 bits).asBits
                        val registerAddress = addr.asBits.resize(chip.addressSpaceWidth bits) &
                                                                chip.addressSpaceMask
                        switch(registerAddress(2 until chip.addressSpaceWidth)) {
                            chip.registers.filter( f => f._2.hasWrite).foreach {
                                case (name, action) =>
                                    is(action.index) {
                                        action.write(io.s_axi.w.data, io.s_axi.w.strb)
                                    }
                            }
                        }
                    })
                }
            }
        
            when(ClockDomain.current.reset)
            {
                io.s_axi.aw.ready := False
                io.s_axi.w.ready := False
                io.s_axi.b.valid := False
            }
        } else 
        {
            io.s_axi.aw.ready := False
            io.s_axi.w.ready := False
            io.s_axi.b.valid := False
            io.s_axi.b.payload.id := 0
            io.s_axi.b.payload.resp := 0            
        }
    }
}