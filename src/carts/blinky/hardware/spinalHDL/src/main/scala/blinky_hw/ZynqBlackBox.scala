package blinky

import spinal.core._
import spinal.lib._
import spinal.lib.io._
import spinal.lib.bus.amba4.axi._


case class PLLE2_BASE(
  bandwidth : String = "OPTIMIZED",
  startUpWait : String = "FALSE",
  clkIn1_Period : Double = 0.0, // 0.938 to 52.631ns
  clkOut_Mult : Int = 2,
  clkOut0_Divide : Int = 1,
  clkOut0_Phase : Double = 0.0,
  clkOut0_DutyCycle : Double = 0.5,
  clkOut1_Divide : Int = 1,
  clkOut1_Phase : Double  = 0.0,
  clkOut1_DutyCycle : Double = 0.5,
  clkOut2_Divide : Int = 1,
  clkOut2_Phase : Double  = 0.0,
  clkOut2_DutyCycle : Double = 0.5,
  clkOut3_Divide : Int = 1,
  clkOut3_Phase : Double  = 0.0,
  clkOut3_DutyCycle : Double = 0.5,
  clkOut4_Divide : Int = 1,
  clkOut4_Phase : Double  = 0.0,
  clkOut4_DutyCycle : Double = 0.5,
  clkOut5_Divide : Int = 1,
  clkOut5_Phase : Double  = 0.0,
  clkOut5_DutyCycle : Double = 0.5
  ) extends BlackBox{

  addGeneric("BANDWIDTH", bandwidth )
  addGeneric("STARTUP_WAIT", startUpWait )
  addGeneric("CLKIN1_PERIOD", clkIn1_Period )
  addGeneric("CLKFBOUT_MULT", clkOut_Mult )

  addGeneric("CLKOUT0_DIVIDE", clkOut0_Divide )
  addGeneric("CLKOUT0_PHASE", clkOut0_Phase )
  addGeneric("CLKOUT0_DUTY_CYCLE", clkOut0_DutyCycle )

  addGeneric("CLKOUT1_DIVIDE", clkOut1_Divide )
  addGeneric("CLKOUT1_PHASE", clkOut1_Phase )
  addGeneric("CLKOUT1_DUTY_CYCLE", clkOut1_DutyCycle )

  addGeneric("CLKOUT2_DIVIDE", clkOut2_Divide )
  addGeneric("CLKOUT2_PHASE", clkOut2_Phase )
  addGeneric("CLKOUT2_DUTY_CYCLE", clkOut2_DutyCycle )

  addGeneric("CLKOUT3_DIVIDE", clkOut3_Divide )
  addGeneric("CLKOUT3_PHASE", clkOut3_Phase )
  addGeneric("CLKOUT3_DUTY_CYCLE", clkOut3_DutyCycle )

  addGeneric("CLKOUT4_DIVIDE", clkOut4_Divide )
  addGeneric("CLKOUT4_PHASE", clkOut3_Phase )
  addGeneric("CLKOUT4_DUTY_CYCLE", clkOut4_DutyCycle )

  addGeneric("CLKOUT5_DIVIDE", clkOut5_Divide )
  addGeneric("CLKOUT5_PHASE", clkOut5_Phase )
  addGeneric("CLKOUT5_DUTY_CYCLE", clkOut5_DutyCycle )

  val CLKIN1 = in Bool
  val CLKFBIN = in Bool
  val CLKFBOUT = out Bool

  val RST = in Bool
  val LOCKED = out Bool

  val CLKOUT0  = out Bool
  val CLKOUT1  = out Bool
  val CLKOUT2  = out Bool
  val CLKOUT3  = out Bool
  val CLKOUT4  = out Bool
  val CLKOUT5  = out Bool
  val PWRDWN = in Bool
}

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
  }
  // Remove io_ prefix from verilog names
  noIoPrefix()

  addRTLPath("../verilog/blinky_zynqy.v")
  addRTLPath("../verilog/ps7_axi_wrapper.v")
  addRTLPath("../verilog/ps7_wrapper.v")
  addRTLPath("../verilog/ps7_blackbox.v")
}
