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
  override val description: String = 
    """This chip represents the hard Arm A9 mpcore SoC in Zynq FPGAs.
      |The SoC contains a lot of other hard cores apart from just the ARM processors themselves.
      |You can choose which parts of the SoC are exposed to the FPGA via the ZynqSoCConfig.
      |It has a total of 9 AXI3+ buses. These aren't quite AXI4 in HW but are close enough that simple adaptions allow them to connect to AXI4.
      |There are 3 bundles that must be connected at the toplevel.
      |Normaly at least a AXI bus and an FCLK would be needed, these are PS_CLOCK_AND_RESET, DDR and MIO.
      |This also produces the CPU C headers and documentation for the SoC cores that are exposed on the CPU side. Your board probably doesn't connect all of these externally. Linking with CMAKE with the zynq_ps project to use these from ARMs.
      |""".stripMargin


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
      val FPGAClock1 = (out Bool()) genIf config.useFPGAClock1
      val FPGAClock2 = (out Bool()) genIf config.useFPGAClock2
      val FPGAClock3 = (out Bool()) genIf config.useFPGAClock3

      val FPGAClockTrigger0_n = (in Bool()) genIf config.useFPGAClockTrigger0
      val FPGAClockTrigger1_n = (in Bool()) genIf config.useFPGAClockTrigger1
      val FPGAClockTrigger2_n = (in Bool()) genIf config.useFPGAClockTrigger2
      val FPGAClockTrigger3_n = (in Bool()) genIf config.useFPGAClockTrigger3

      val FPGAReset0_n = (out Bool()) genIf config.useFPGAReset0
      val FPGAReset1_n = (out Bool()) genIf config.useFPGAReset1
      val FPGAReset2_n = (out Bool()) genIf config.useFPGAReset2
      val FPGAReset3_n = (out Bool()) genIf config.useFPGAReset3

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

  if(config.useFPGAClock0) io.FPGAClock0 <> ps7.io.fclk.clk0  
  if(config.useFPGAClock1) io.FPGAClock1 <> ps7.io.fclk.clk1
  if(config.useFPGAClock2) io.FPGAClock2 <> ps7.io.fclk.clk2
  if(config.useFPGAClock3) io.FPGAClock3 <> ps7.io.fclk.clk3

  if(config.useFPGAClockTrigger0) io.FPGAClockTrigger0_n <> ps7.io.fclk.clk1Trig0_n
  if(config.useFPGAClockTrigger1) io.FPGAClockTrigger1_n <> ps7.io.fclk.clk1Trig1_n
  if(config.useFPGAClockTrigger2) io.FPGAClockTrigger2_n <> ps7.io.fclk.clk1Trig2_n
  if(config.useFPGAClockTrigger3) io.FPGAClockTrigger3_n <> ps7.io.fclk.clk1Trig3_n

  if(config.useFPGAReset0) io.FPGAReset0_n <> ps7.io.fclk.reset0_n
  if(config.useFPGAReset1) io.FPGAReset1_n <> ps7.io.fclk.reset1_n
  if(config.useFPGAReset2) io.FPGAReset2_n <> ps7.io.fclk.reset2_n
  if(config.useFPGAReset3) io.FPGAReset3_n <> ps7.io.fclk.reset3_n

  if(config.usePSMasterGP0Axi) io.M_AXI_GP0 <> ps7.io.ps_axi3_master_gp0
  if(config.usePSMasterGP0Axi) io.M_AXI_GP0_clk <> ps7.io.ps_axi3_master_gp0_clk

  ZynqArmRegisters.parseRegisters(this)

  ZynqArmA9CCode.addToChip(this)
  ZynqL1CacheCCode.addToChip(this)
  ZynqMemoryMap.addToChip(this) 
  
}
