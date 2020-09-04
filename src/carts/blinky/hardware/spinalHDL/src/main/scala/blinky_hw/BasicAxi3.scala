package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._
import spinal.lib.fsm._

class BasicAxi3Slave(config : Axi4Config) extends Component {
    var io = new Bundle {

      val s_axi = slave( Axi4(config) )
      val reset_n = in Bool
    }

    io.s_axi.aw.ready := False
    io.s_axi.w.ready := False

    io.s_axi.b.valid := False
    io.s_axi.b.resp := 0
    io.s_axi.b.id := io.s_axi.ar.id

    io.s_axi.r.valid := False
    io.s_axi.r.resp := 0
    io.s_axi.r.id := io.s_axi.ar.id
    io.s_axi.r.last := False
    io.s_axi.r.data := 0

    val readyForNewAddr = RegInit(True)
    io.s_axi.ar.ready := readyForNewAddr

    // 4K boundary for axi increments
    val upperAddress = U(0x40000, 20 bit) 
    val fourKPage = RegInit(U(0, 12 bits))
    val numberBytes = Reg(UInt(8 bits))
    val burstLength = RegInit(U(0, 8 bits))
    val burstType = Reg(UInt(2 bits))

    when(readyForNewAddr)
    { 
        when(io.s_axi.ar.valid && io.s_axi.ar.addr(30))
        {
            val arsize = B("1").asUInt << io.s_axi.ar.size
            numberBytes := arsize
            fourKPage := io.s_axi.ar.addr(0 until 12) & ~Cat(B"0000", (arsize-1)).asUInt
            burstLength := io.s_axi.ar.len
            burstType := io.s_axi.ar.burst.asUInt
            readyForNewAddr := False
        }
    }.otherwise
    {
        io.s_axi.r.valid := True

        when(burstLength === 0)
        {
            io.s_axi.r.last := True
        }

        when(io.s_axi.r.ready)
        {
            when(burstLength > 0)
            {
                burstLength := burstLength - 1

                switch(burstType) {
                    is(U(1,2 bits)){ 
                        fourKPage := fourKPage + numberBytes; 
                    } // INCR
                    default {
                        // do nothing for fixed and reserved
                    }
                } 
            }.elsewhen(burstLength === 0)
            {
                readyForNewAddr := True
            }
        }

        val addr = Cat(upperAddress, fourKPage)            
        switch(addr(15 downto 0))
        {
            is(0) {
                io.s_axi.r.data := U("32'hDCDCDCDC").asBits
            }
            default{
                io.s_axi.r.data := addr.asBits
            }
        }

    }

    when(!io.reset_n) 
    {       
        io.s_axi.ar.ready := False
        io.s_axi.r.valid := False
   }

}   
 