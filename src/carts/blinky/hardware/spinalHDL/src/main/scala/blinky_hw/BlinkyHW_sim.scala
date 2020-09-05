package blinky

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib.bus.amba4.axi._

object DutTests 
{
  def main(args: Array[String]): Unit = 
  {
    val GeneralPurposeAxi =  Axi4Config(                  
                      addressWidth = 32,
                      dataWidth = 32,
                      idWidth = 12,
                      useId  = true,
                      useRegion = false,
                      useBurst = true,
                      useLock = true,
                      useCache = true,
                      useSize = true,
                      useQos  = true,
                      useLen  = true,
                      useLast = true,
                      useResp = true,
                      useProt = true,
                      useStrb = true    
    )
    var sc = SimConfig.
      withWave.
      workspacePath("~/ikuy/build/carts/blinky/hardware/sim/workspace").
      withConfig(BuildMain.sc)

    var compiled = sc.compile {
      val dut = new BasicAxi3Slave(GeneralPurposeAxi)
      dut
    }

    compiled.doSim({ dut =>
        dut.io.reset_n := dut.clockDomain.reset
        dut.clockDomain.forkStimulus(period = 10)

        dut.io.s_axi.ar.valid #= false
        dut.io.s_axi.aw.valid #= false
        dut.io.s_axi.w.valid #= false
        dut.io.s_axi.r.ready #= false
        dut.io.s_axi.b.ready #= false

        // place a burst read of 2 32 bit values using increment mode
        assert(dut.io.s_axi.r.valid.toBoolean == false)
        dut.io.reset_n #= true
        dut.io.s_axi.ar.valid #= true
        dut.io.s_axi.ar.addr #= 0x40000000
        dut.io.s_axi.ar.size #= 2
        dut.io.s_axi.ar.len #= 1
        dut.io.s_axi.ar.burst #= 1

        // slave has placed 1st 32 bit on the bus and marked its valid
        dut.clockDomain.waitActiveEdgeWhere(dut.io.s_axi.ar.ready.toBoolean)
        dut.clockDomain.waitActiveEdgeWhere(dut.io.s_axi.r.valid.toBoolean)
        dut.io.s_axi.ar.valid #= false
        println(f"${dut.io.s_axi.r.data.toBigInt}%x")

        assert(dut.io.s_axi.r.data.toBigInt == 0xDCDCDCDCL)
        assert(dut.io.s_axi.r.last.toBoolean == false)

        // inform slave we have read it
        // this tests an unready master
        // A good master would be ready when placing the 
        // address on the bus saving a cycle here
        dut.io.s_axi.r.ready #= true
        dut.clockDomain.waitActiveEdge()

        assert(dut.io.s_axi.r.data.toBigInt == 0xDCDCDCDCL)
        assert(dut.io.s_axi.r.last.toBoolean == false)

        dut.clockDomain.waitActiveEdgeWhere(dut.io.s_axi.r.last.toBoolean)

        // slave sends the next 32 bit and marks it as the last
        assert(dut.io.s_axi.r.data.toBigInt == 0x40000004L)
        dut.io.s_axi.r.ready #= false

        // place another read address that isn't for this slave 
        dut.clockDomain.waitActiveEdge()
        assert(dut.io.s_axi.r.valid.toBoolean == false)
        dut.io.s_axi.ar.valid #= true
        dut.io.s_axi.ar.addr #= 0x0

        // check the slave didn't respond
        dut.clockDomain.waitActiveEdge()
        assert(dut.io.s_axi.ar.valid.toBoolean == true)
        assert(dut.io.s_axi.ar.ready.toBoolean == true)
        assert(dut.io.s_axi.r.valid.toBoolean == false)
        dut.clockDomain.waitActiveEdge()

        // lets try a 1 32 bit write with mask of top two bytes
        dut.io.s_axi.aw.valid #= true
        dut.io.s_axi.aw.addr #= 0x40000000
        dut.io.s_axi.aw.size #= 2
        dut.io.s_axi.aw.len #= 0
        dut.io.s_axi.aw.burst #= 1
        dut.io.s_axi.w.valid #= true
        dut.io.s_axi.w.last #= true
        dut.io.s_axi.w.strb #= 0x3
        dut.io.s_axi.w.data #= 0x0A0B0C0D
        dut.clockDomain.waitActiveEdge()
        dut.clockDomain.waitActiveEdge()
        dut.io.s_axi.aw.valid #= false
        dut.io.s_axi.w.valid #= false
        dut.clockDomain.waitActiveEdge()
        dut.clockDomain.waitActiveEdge()
        dut.io.s_axi.ar.valid #= true
        dut.io.s_axi.ar.addr #= 0x40000000
        dut.io.s_axi.ar.size #= 2
        dut.io.s_axi.ar.len #= 0
        dut.io.s_axi.ar.burst #= 1
        dut.clockDomain.waitActiveEdgeWhere(dut.io.s_axi.r.valid.toBoolean)
        assert(dut.io.s_axi.r.data.toBigInt == 0x00000C0DL)

        dut.clockDomain.waitActiveEdge()
        simSuccess()
    })
  }
}