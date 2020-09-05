package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._
import spinal.lib.fsm._

class BasicAxi3Slave(   config : Axi4Config,
                        addressSpaceHighBit : Int = 30
) extends Component {
    var io = new Bundle {

      val s_axi = slave( Axi4(config) )
      val reset_n = in Bool
    }

    val upperAddress = U(1L << (addressSpaceHighBit-12), 20 bit) 
    val data0 = Reg(Bits(32 bits)) init(B"32'xDCDCDCDC")

    var readArea = new Area {
        io.s_axi.r.valid := False
        io.s_axi.r.resp := 0
        io.s_axi.r.id := io.s_axi.ar.id
        io.s_axi.r.last := False
        io.s_axi.r.data := 0

        val readyForNewAddr = RegInit(True)
        io.s_axi.ar.ready := readyForNewAddr

        // 4K boundary for axi increments
        val size = RegInit(U(0, 3 bits))
        val fourKPage = RegInit(U(0, 12 bits))
        val numberBytes = Reg(UInt(8 bits))
        val beat = RegInit(U(0, 8 bits))
        val burstLength = RegInit(U(0, 8 bits))
        val burstType = Reg(UInt(2 bits))

        when(readyForNewAddr)
        { 
            when(io.s_axi.ar.valid && io.s_axi.ar.addr(addressSpaceHighBit))
            {
                size := io.s_axi.ar.size
                val arsize = B("1").asUInt << io.s_axi.ar.size
                numberBytes := arsize
                fourKPage := io.s_axi.ar.addr(0 until 12) & ~Cat(B"0000", (arsize-1)).asUInt
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

            val addr = Cat(upperAddress, fourKPage)            
            switch(addr(15 downto 0))
            {
                is(0) {
                    io.s_axi.r.data := data0
                }
                default{
                    io.s_axi.r.data := addr.asBits
                }
            }
        }
    }

    var writeArea = new Area {
        io.s_axi.b.valid := False
        io.s_axi.b.resp := 0
        io.s_axi.b.id := io.s_axi.aw.id

        val readyForNewAddr = RegInit(True)
        io.s_axi.aw.ready := readyForNewAddr
        io.s_axi.w.ready := ~readyForNewAddr

        // 4K boundary for axi increments
        val size = RegInit(U(0, 3 bits))
        val fourKPage = RegInit(U(0, 12 bits))
        val numberBytes = Reg(UInt(8 bits))
        val beat = RegInit(U(0, 8 bits))
        val burstLength = RegInit(U(0, 8 bits))
        val burstType = Reg(UInt(2 bits))

        val mask3 = UInt(8 bits).setAllTo( io.s_axi.w.strb(3)).asBits
        val mask2 = UInt(8 bits).setAllTo( io.s_axi.w.strb(2)).asBits
        val mask1 = UInt(8 bits).setAllTo( io.s_axi.w.strb(1)).asBits
        val mask0 = UInt(8 bits).setAllTo( io.s_axi.w.strb(0)).asBits

        when(readyForNewAddr)
        { 
            when(io.s_axi.aw.valid && io.s_axi.aw.addr(addressSpaceHighBit))
            {
                size := io.s_axi.aw.size
                val awsize = B("1").asUInt << io.s_axi.aw.size
                numberBytes := awsize
                fourKPage := io.s_axi.aw.addr(0 until 12) & ~Cat(B"0000", (awsize-1)).asUInt
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

                val addr = Cat(upperAddress, fourKPage)            
                switch(addr(15 downto 0))
                {
                    is(0) {
                            data0 := Cat( io.s_axi.w.data(24 until 32) & mask3,
                                        io.s_axi.w.data(16 until 24) & mask2,
                                        io.s_axi.w.data(8 until 16) & mask1,
                                        io.s_axi.w.data(0 until 8) & mask0
                        )
                    }
                }
            }
        } 
    }

    when(!io.reset_n) 
    {       
        io.s_axi.ar.ready := False
        io.s_axi.r.valid := False

        io.s_axi.aw.ready := False
        io.s_axi.w.ready := False
        io.s_axi.b.valid := False
   }

}   
 