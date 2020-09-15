package bus_and_chips

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib.bus.amba4.axi._
import scala.collection.mutable.{ArrayBuffer}
import bus_and_chips._

class Axi3Slave_simMB
extends Motherboard
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

  val buggyBoyID = addChip(
              "BuggyBoy",
              (chipID : ChipID, mb : Motherboard) => 
              { 
                new DebugCustomChip(chipID = chipID, motherboard = mb) 
              })

  val slaveGp0ID = addBus(
                  "slaveGp0", 
                  (busID : BusID, mb : Motherboard) => { 
                    new Axi3Slave(    
                      config = GeneralPurposeAxi,
                      addressSpaceHighBit = 30, // 0x40000000 address range
                      busID = busID,
                      motherboard = mb)
                  })
  connectChipToBus( buggyBoyID, 
                    CHIP_BUS_FULL_DUPLUX_CONNECTION, 
                    slaveGp0ID)
  build()
}

object Axi3Bus_sim 
{
  def test(spinalConfig : SpinalConfig): Unit = 
  {
    val sc = SimConfig.
      withWave.
      workspacePath("~/ikuy/build/carts/blinky/hardware/sim/workspace").
      withConfig(spinalConfig)
    sc.compile({
      val dut = new Axi3Slave_simMB
      val slaveGp0 = dut.getBusByID(dut.slaveGp0ID)
      slaveGp0.io.simPublic()
      dut
    }).doSim({ dut =>
        dut.clockDomain.forkStimulus(period = 10)
        
        val slaveGp0 = dut.getBusByID(dut.slaveGp0ID)

        slaveGp0.io.s_axi.ar.valid #= false
        slaveGp0.io.s_axi.aw.valid #= false
        slaveGp0.io.s_axi.w.valid #= false
        slaveGp0.io.s_axi.r.ready #= false
        slaveGp0.io.s_axi.b.ready #= false

        // place a burst read of 2 32 bit values using increment mode
        assert(slaveGp0.io.s_axi.r.valid.toBoolean == false)
        slaveGp0.io.s_axi.ar.valid #= true
        slaveGp0.io.s_axi.ar.addr #= 0x40000000L
        slaveGp0.io.s_axi.ar.size #= 2
        slaveGp0.io.s_axi.ar.len #= 1
        slaveGp0.io.s_axi.ar.burst #= 1

        // slave has placed 1st 32 bit on the bus and marked its valid
        slaveGp0.clockDomain.waitActiveEdgeWhere(slaveGp0.io.s_axi.ar.ready.toBoolean)
        slaveGp0.clockDomain.waitActiveEdgeWhere(slaveGp0.io.s_axi.r.valid.toBoolean)
        slaveGp0.io.s_axi.ar.valid #= false

        assert(slaveGp0.io.s_axi.r.data.toBigInt == 0xDCDCDCDCL)
        assert(slaveGp0.io.s_axi.r.last.toBoolean == false)

        // inform slave we have read it
        // this tests an unready master
        // A good master would be ready when placing the 
        // address on the bus saving a cycle here
        slaveGp0.io.s_axi.r.ready #= true
        slaveGp0.clockDomain.waitActiveEdge()

        assert(slaveGp0.io.s_axi.r.data.toBigInt == 0xDCDCDCDCL)
        assert(slaveGp0.io.s_axi.r.last.toBoolean == false)

        slaveGp0.clockDomain.waitActiveEdgeWhere(slaveGp0.io.s_axi.r.last.toBoolean)

        // slave sends the next 32 bit and marks it as the last
        assert(slaveGp0.io.s_axi.r.data.toBigInt == 0x00000004L)
        slaveGp0.io.s_axi.r.ready #= false
        assert(slaveGp0.io.s_axi.r.last.toBoolean == true)

        // place another read address that isn't for this slave 
        slaveGp0.clockDomain.waitActiveEdge()
        assert(slaveGp0.io.s_axi.r.valid.toBoolean == false)
        slaveGp0.io.s_axi.ar.valid #= true
        slaveGp0.io.s_axi.ar.addr #= 0x0

        // check the slave didn't respond
        slaveGp0.clockDomain.waitActiveEdge()
        assert(slaveGp0.io.s_axi.ar.valid.toBoolean == true)
        assert(slaveGp0.io.s_axi.ar.ready.toBoolean == true)
        assert(slaveGp0.io.s_axi.r.valid.toBoolean == false)
        slaveGp0.clockDomain.waitActiveEdge()

        // lets try a 1 32 bit write with not byte masking
        slaveGp0.io.s_axi.aw.valid #= true
        slaveGp0.io.s_axi.aw.addr #= 0x40000000L
        slaveGp0.io.s_axi.aw.size #= 2
        slaveGp0.io.s_axi.aw.len #= 0
        slaveGp0.io.s_axi.aw.burst #= 1
        slaveGp0.io.s_axi.w.valid #= true
        slaveGp0.io.s_axi.w.last #= true
        slaveGp0.io.s_axi.w.strb #= 0xF
        slaveGp0.io.s_axi.w.data #= 0xFAFBFCFDL
        slaveGp0.clockDomain.waitActiveEdge()
        slaveGp0.io.s_axi.ar.valid #= true
        slaveGp0.io.s_axi.ar.addr #= 0x40000000L
        slaveGp0.io.s_axi.ar.size #= 2
        slaveGp0.io.s_axi.ar.len #= 0
        slaveGp0.io.s_axi.ar.burst #= 1
        slaveGp0.io.s_axi.r.ready #= true
        slaveGp0.clockDomain.waitActiveEdgeWhere(slaveGp0.io.s_axi.r.valid.toBoolean)
        assert(slaveGp0.io.s_axi.r.data.toBigInt == 0xFAFBFCFDL)
        assert(slaveGp0.io.s_axi.r.last.toBoolean == true)

        // lets try a 1 32 bit write with mask of top two bytes
        slaveGp0.io.s_axi.aw.valid #= true
        slaveGp0.io.s_axi.aw.addr #= 0x40000000L
        slaveGp0.io.s_axi.aw.size #= 2
        slaveGp0.io.s_axi.aw.len #= 0
        slaveGp0.io.s_axi.aw.burst #= 1
        slaveGp0.io.s_axi.w.valid #= true
        slaveGp0.io.s_axi.w.last #= true
        slaveGp0.io.s_axi.w.strb #= 0x3
        slaveGp0.io.s_axi.w.data #= 0x0A0B0C0DL
        slaveGp0.clockDomain.waitActiveEdge()
        slaveGp0.io.s_axi.aw.valid #= false
        slaveGp0.io.s_axi.w.valid #= false
        slaveGp0.clockDomain.waitActiveEdge()
        slaveGp0.io.s_axi.ar.valid #= true
        slaveGp0.io.s_axi.ar.addr #= 0x40000000L
        slaveGp0.io.s_axi.ar.size #= 2
        slaveGp0.io.s_axi.ar.len #= 0
        slaveGp0.io.s_axi.ar.burst #= 1
        slaveGp0.clockDomain.waitActiveEdgeWhere(slaveGp0.io.s_axi.r.valid.toBoolean)
        assert(slaveGp0.io.s_axi.r.data.toBigInt == 0xFAFB0C0DL)

        simSuccess()
    })
  }
}