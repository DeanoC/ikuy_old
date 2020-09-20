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
  val ps7 = new zynqPS7Wwrapper(config)

  val usesFCLK =  config.useFPGAClock0 | config.useFPGAClock1 | 
                  config.useFPGAClock2 | config.useFPGAClock3 | 
                  config.useFPGAReset0 | config.useFPGAReset1 | 
                  config.useFPGAReset2 | config.useFPGAReset3

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

      val M_AXI_GP0 = master( Axi4(zynqAxis.PSMasterGPAxiConfig) )
      val M_AXI_GP0_clk = in Bool
      val M_AXI_GP0_reset = out Bool

//      val S_AXI_GP0 = slave( Axi4(PSS_GeneralPurposeAxi) )
//      val S_AXI_GP0_clk = in Bool
//      val S_AXI_GP0_reset = out Bool

//      val M_AXI_GP1 = master( Axi4(PSM_GeneralPurposeAxi) )
//      val M_AXI_GP1_clk = in Bool
//      val M_AXI_GP1_reset = out Bool
  }
  // Remove io_ prefix from verilog names
  noIoPrefix()

  io.DDR <> ps7.io.ddr
  io.MIO <> ps7.io.mio 
  io.PS_CLOCK_AND_RESET <> ps7.io.ps_clock_and_reset

  if(config.useFPGAClock0) { io.FPGAClock0 <> ps7.io.fclk.clk0; io.FPGAClockEnable0 <> ps7.io.fclk.clk0En }
  if(config.useFPGAClock1) { io.FPGAClock1 <> ps7.io.fclk.clk1; io.FPGAClockEnable1 <> ps7.io.fclk.clk1En }
  if(config.useFPGAClock2) { io.FPGAClock2 <> ps7.io.fclk.clk2; io.FPGAClockEnable2 <> ps7.io.fclk.clk2En }
  if(config.useFPGAClock3) { io.FPGAClock3 <> ps7.io.fclk.clk3; io.FPGAClockEnable3 <> ps7.io.fclk.clk3En }

  if(config.usePSMasterGP0Axi) io.M_AXI_GP0 <> ps7.io.ps_axi3_master_gp0
  if(config.usePSMasterGP0Axi) io.M_AXI_GP0_clk <> ps7.io.ps_axi3_master_gp0_clk

  ZynqArmRegisters.parseRegisters(this)
  
  // TODO improve pathing
  override def CHeaderPath = "../../../../libraries/zynq_ps/include/zynq_ps/"
  override def DocPath = "../../../../libraries/zynq_ps/docs/"
  
}
