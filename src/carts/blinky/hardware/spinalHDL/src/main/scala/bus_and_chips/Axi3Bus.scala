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
                    val addressSpaceHighBit : Int = 30
                    ) extends Component 
{
    var io = new Bundle 
    {
      val s_axi = slave( Axi4(config) )
      val reset_n = in Bool
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

    def readHandler() : Area = new Area 
    {
        io.s_axi.r.valid := False
        io.s_axi.r.resp := 0
        io.s_axi.r.id := io.s_axi.ar.id
        io.s_axi.r.last := False
        io.s_axi.r.data := 0

        val readyForNewAddr = RegInit(True)
        io.s_axi.ar.ready := readyForNewAddr

        val upperAddress = U(0, 17 bits) // 17+12 == 29 bits for addess (1GB-1B)

        // 4K boundary for axi increments
        val size = RegInit(U(0, 3 bits))
        val fourKPage = RegInit(U(0, 12 bits)) // 12 bit pages for Axi3
        val numberBytes = Reg(UInt(3 bits))
        val beat = RegInit(U(0, 8 bits))
        val burstLength = RegInit(U(0, 8 bits))
        val burstType = Reg(UInt(2 bits))        

        when(readyForNewAddr)
        { 
            when(io.s_axi.ar.valid && io.s_axi.ar.addr(addressSpaceHighBit))
            {
                size := io.s_axi.ar.size
                val arsize = sizeConverter(size)                
                numberBytes := arsize
                upperAddress := io.s_axi.ar.addr(13 to 29)
                fourKPage := io.s_axi.ar.addr(0 until 12) & ~Cat(B"0000_0000_0", (arsize-1)).asUInt
                burstLength := io.s_axi.ar.len
                beat := io.s_axi.ar.len
                burstType := io.s_axi.ar.burst.asUInt
                readyForNewAddr := False
            }
        }.otherwise
        {
            io.s_axi.r.valid := True

            when(beat === 0)
            {
                io.s_axi.r.last := True
            }

            when(io.s_axi.r.ready)
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
                    readyForNewAddr := True
                }
            }

            chips.foreach( chip => {
                val addr = Cat(upperAddress, fourKPage)
                val addrMasked = addr & ~U(chip.addressSpaceMask, 29 bits).asBits
 
                when(addrMasked === U(chip.address, 29 bits).asBits)
                {
                    val registerAddress = addr.asBits.resize(chip.addressSpaceWidth bits) &
                                                            chip.addressSpaceMask
                    switch(registerAddress(2 until chip.addressSpaceWidth)) {
                        chip.registers.filter( f => f._2.hasRead).foreach {
                            case (name, action) =>
                                is(action.index) {
                                    io.s_axi.r.data := action.read()
                                }
                        }
                    }
                }
            })
        }
    }

    def writeHandler() : Area = new Area 
    {
        io.s_axi.b.valid := False
        io.s_axi.b.resp := 0
        io.s_axi.b.id := io.s_axi.aw.id

        val readyForNewAddr = RegInit(True)
        io.s_axi.aw.ready := readyForNewAddr
        io.s_axi.w.ready := ~readyForNewAddr

        val upperAddress = U(0, 17 bits) // 17+12 == 29 bits for addess (1GB-1B)

        // 4K boundary for axi increments
        val size = RegInit(U(0, 3 bits))
        val fourKPage = RegInit(U(0, 12 bits))
        val numberBytes = Reg(UInt(3 bits))
        val beat = RegInit(U(0, 8 bits))
        val burstLength = RegInit(U(0, 8 bits))
        val burstType = Reg(UInt(2 bits))

        when(readyForNewAddr)
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
                readyForNewAddr := False
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
                    io.s_axi.b.valid := True
                    readyForNewAddr := True
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
    } 

    def build(): Unit = 
    {
        println("Adding chips")
        chipsOfBus.foreach( chip => {
            addChip(chip)
        })
         chips.foreach( chip => {
            println(f"Building ${chip.chipName} chip")
            chip.build()
        })


        if( readAccess ) {
            var readArea = readHandler()
            when(!io.reset_n) 
            {
                io.s_axi.ar.ready := False
                io.s_axi.r.valid := False
            }
        } else 
        {
            io.s_axi.ar.ready := False
            io.s_axi.r.valid := False
            io.s_axi.r.payload.id := 0
            io.s_axi.r.payload.data := 0
            io.s_axi.r.payload.resp := 0
            io.s_axi.r.payload.last := False
        }

        if( writeAccess ) {
            var writeArea = writeHandler()       
            when(!io.reset_n) 
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

    Component.current.addPrePopTask(() => {
      build()
    })
}

   
 