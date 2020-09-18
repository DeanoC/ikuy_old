package zynq_hard_soc

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._
import bus_and_chips._


class zynqHardSoC(
  override val chipID : ChipID,
  override val motherboard : Motherboard,
  val config : zynqSoCConfig
)
extends HardChip(chipID, motherboard) {
  val ps7 = new zynqPS7Wwrapper(config = config)

  val usesFCLK =  config.useFPGAClock0 | config.useFPGAClock1 | 
                  config.useFPGAClock2 | config.useFPGAClock3 | 
                  config.useFPGAReset0 | config.useFPGAReset1 | 
                  config.useFPGAReset2 | config.useFPGAReset3

  if(config.useI2C0) addToSoC(ZYNQ_I2C, 0)
  if(config.useI2C1) addToSoC(ZYNQ_I2C, 1)

  override def addRegisters(): Unit = 
  {
  }

  override val io = new Bundle {
      val PS_CLOCK_AND_RESET = master( zynqPSClockAndReset() )

      val MIO = master( zynqMIO() )

      val DDR_ARB = in Bits(4 bits) genIf config.useDDR_ARB

      val FPGAClock0 = (out Bool()) genIf config.useFPGAClock0
      val FPGAClockEnable0 = (in Bool()) genIf config.useFPGAClock0
      val FPGAClock1 = (out Bool()) genIf config.useFPGAClock1
      val FPGAClockEnable1 = (in Bool()) genIf config.useFPGAClock1
      val FPGAClock2 = (out Bool()) genIf config.useFPGAClock2
      val FPGAClockEnable2 = (in Bool()) genIf config.useFPGAClock2
      val FPGAClock3 = (out Bool()) genIf config.useFPGAClock3
      val FPGAClockEnable3 = (in Bool()) genIf config.useFPGAClock3

      val FPGAReset0 = (out Bool()) genIf config.useFPGAReset0
      val FPGAReset1 = (out Bool()) genIf config.useFPGAReset1
      val FPGAReset2 = (out Bool()) genIf config.useFPGAReset2
      val FPGAReset3 = (out Bool()) genIf config.useFPGAReset3

      val DDR = master( zynqDDR() )

//      val M_AXI_GP0 = master( Axi4(ps7.PSMasterGPAxiConfig) )
//      val M_AXI_GP0_clk = in Bool
//      val M_AXI_GP0_reset = out Bool

//      val S_AXI_GP0 = slave( Axi4(PSS_GeneralPurposeAxi) )
//      val S_AXI_GP0_clk = in Bool
//      val S_AXI_GP0_reset = out Bool

//      val M_AXI_GP1 = master( Axi4(PSM_GeneralPurposeAxi) )
//      val M_AXI_GP1_clk = in Bool
//      val M_AXI_GP1_reset = out Bool
  }
  // Remove io_ prefix from verilog names
  noIoPrefix()

  def addToSoC( chipType : ZynqSocChips, 
                index : Int = 0)
  {
    chipType match {
      case ZYNQ_ETHERNET => 
      case ZYNQ_TRIPLE_TIMER =>
      case ZYNQ_WATCH_DOG =>
      case ZYNQ_SPI =>
      case ZYNQ_I2C =>
      case ZYNQ_CAN =>
      case ZYNQ_UART =>
      case ZYNQ_SDIO =>
      case ZYNQ_USB =>
      case ZYNQ_DMA =>
    }
  }

  io.DDR <> ps7.io.ddr
  io.MIO <> ps7.io.mio 
  io.PS_CLOCK_AND_RESET <> ps7.io.ps_clock_and_reset

}
