package dissy

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib.bus.amba4.axi._
import scala.collection.mutable.{ArrayBuffer}
import bus_and_chips._

object DisplaySync_sim 
{
  def test(spinalConfig : SpinalConfig): Unit = 
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
      withConfig(spinalConfig)


    var compiled = sc.compile {
      val pixelClock = Bool
      val pixelClockDomain = ClockDomain(pixelClock)

      val dut = new Axi3Slave(
                      config = GeneralPurposeAxi, 
                      chipsOfBus = ArrayBuffer[CustomChip](
                         new DissyCustomChip(FixedFrequency(25.175 MHz))
                      ),
                      addressSpaceHighBit = 30 )
      dut
    }

    compiled.doSim({ dut =>
        dut.clockDomain.forkStimulus(period = 10)
        simSuccess()
    })
  }
}