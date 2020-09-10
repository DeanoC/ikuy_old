package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._

case class DdrInterface() extends Bundle{
    val CAS_n = Analog(Bool())
    val CKE = Analog(Bool())
    val Clk_n = Analog(Bool())
    val Clk = Analog(Bool())
    val CS_n = Analog(Bool())
    val DRSTB = Analog(Bool())
    val ODT = Analog(Bool())
    val RAS_n = Analog(Bool())
    val WEB = Analog(Bool())
    val BankAddr = Analog(Bits(3 bits))
    val Addr = Analog(Bits(15 bits))
    val VRN = Analog(Bool())
    val VRP = Analog(Bool())
    val DM = Analog(Bits(4 bits))
    val DQ = Analog(Bits(32 bits))
    val DQS_n = Analog(Bits(4 bits))
    val DQS = Analog(Bits(4 bits))
}

case class ps7_axi_wrapper() extends BlackBox {
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

  val io = new Bundle {
      val PS_SYSTEM_RESET = out Bool()
      val PS_CLK = out Bool()
      val PS_POWER_ON_RESET = out Bool()
      val DDR_ARB = in Bits(4 bits)
      val DDR = inout(DdrInterface())

      val FCLK0_CLK = out Bool()
      val FCLK0_RESET = out Bool()

      val M_AXI_GP0 = master( Axi4(GeneralPurposeAxi) )
      val M_AXI_GP0_clk = in Bool
      val M_AXI_GP0_reset = out Bool

//      val M_AXI_GP1 = master( Axi4(GeneralPurposeAxi) )
//      val M_AXI_GP1_clk = in Bool
//      val M_AXI_GP1_reset = out Bool
  }
  // Remove io_ prefix from verilog names
  noIoPrefix()

  addRTLPath("../verilog/blinky_zynqy.v")
  addRTLPath("../verilog/ps7_axi_wrapper.v")
  addRTLPath("../verilog/ps7_wrapper.v")
  addRTLPath("../verilog/ps7_blackbox.v")
}
