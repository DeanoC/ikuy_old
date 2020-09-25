package zynq_hard_soc

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi.{Axi4, Axi4Config}

case class zynqSoCConfig(
  useEthernet0 : Boolean = false,
  useEthernet1 : Boolean = false,

  useTripleTimer0 : Boolean = false,
  useTripleTimer1 : Boolean = false,

  useWatchDog : Boolean = false,

  useSPI0 : Boolean = false,
  useSPI1 : Boolean = false,

  useI2C0 : Boolean = false,
  useI2C1 : Boolean = false,

  useCAN0 : Boolean = false,
  useCAN1 : Boolean = false,

  useUART0 : Boolean = false,
  useUART1 : Boolean = false,

  useSDIO0 : Boolean = false,
  useSDIO1 : Boolean = false,

  useGPIO : Boolean = false,

  useTrace : Boolean = false,

  usePJTAG : Boolean = false,

  useUSB0 : Boolean = false,
  useUSB1 : Boolean = false,

  useSRAM_INTERRUPT : Boolean = false,

  useFPGAClock0 : Boolean = false,
  useFPGAClock1 : Boolean = false,
  useFPGAClock2 : Boolean = false,
  useFPGAClock3 : Boolean = false,
  useFPGAClockTrigger0 : Boolean = false,
  useFPGAClockTrigger1 : Boolean = false,
  useFPGAClockTrigger2 : Boolean = false,
  useFPGAClockTrigger3 : Boolean = false,
  useFPGAReset0 : Boolean = false,
  useFPGAReset1 : Boolean = false,
  useFPGAReset2 : Boolean = false,
  useFPGAReset3 : Boolean = false,

  useIdle : Boolean = false,

  useEvents : Boolean = false,

  useDDR_ARB : Boolean = false,

  usePLTrace : Boolean = false,

  useCrossTrigger : Boolean = false,

  useDMA0 : Boolean = false,
  useDMA1 : Boolean = false,
  useDMA2 : Boolean = false,
  useDMA3 : Boolean = false,

  useInterrupts : Boolean = false,

  usePSMasterGP0Axi : Boolean = false,
  usePSMasterGP1Axi : Boolean = false,
  useFPGAMasterGP0Axi : Boolean = false,
  useFPGAMasterGP1Axi : Boolean = false,
  useFPGAMasterACPAxi : Boolean = false,
  useFPGAMasterHP0Axi : Boolean = false,
  useFPGAMasterHP1Axi : Boolean = false,
  useFPGAMasterHP2Axi : Boolean = false,
  useFPGAMasterHP3Axi : Boolean = false
)

case class zynqEthernet() extends Bundle
{
  val gmiirxclk = in Bool
  val gmiicrs = in Bool
  val gmiicol = in Bool
  val extintin = in Bool
  val gmiirxd = in Bits (8 bits)
  val gmiirxer = in Bool
  val gmiirxdv = in Bool
  val gmiitxclk = in Bool
  val gmiitxd = out Bits(8 bits)
  val gmiitxen = out Bool
  val gmiitxer = out Bool
  val mdiomdc = out Bool
  val mdioi = in Bool
  val mdioo = out Bool
  val mdiotn = out Bool
  val ptpsyncframetx = out Bool
  val ptpdelayreqtx = out Bool
  val ptppdelayreqtx = out Bool
  val ptppdelayresptx = out Bool
  val softx = out Bool
  val ptpsyncframerx = out Bool
  val ptpdelayreqrx = out Bool
  val ptppdelayreqrx = out Bool
  val ptppdelayresprx = out Bool
  val softrx = out Bool
}

case class zynqTripleTimer() extends Bundle
{
  val clk = in Bits(3 bits)
  val wave = out Bits(3 bits)
}

case class zynqWatchDog() extends Bundle
{
  val clk = in Bool
  val rst = out Bool
}

case class zynqSPI() extends Bundle
{
  val sclk_i = in Bool
  val sclk_o = out Bool
  val sclk_t = out Bool
  val mosi_i = in Bool
  val mosi_o = out Bool
  val mosi_t = out Bool
  val miso_i = in Bool
  val miso_o = out  Bool
  val miso_t = out Bool
  val ss_i = in Bool
  val ss_o = out Bits(3 bits)
  val ss_t = out Bool
}

case class zynqI2C() extends Bundle
{
  val scl_i = in Bool
  val scl_o = out Bool
  val scl_t = out Bool
  val sda_i = in Bool
  val sda_o = out Bool
  val sda_t = out Bool
}

case class zynqCAN() extends Bundle
{
  val phy_tx = out Bool
  val phy_rx = in Bool
}

case class zynqUART() extends Bundle
{
  val tx = out Bool
  val rx = in Bool
  val ctsn = in Bool
  val rtsn = out Bool
  val dsrn = in Bool
  val dcdn = in Bool
  val rin = in Bool
  val dtrn = out Bool
}

case class zynqSDIO() extends Bundle
{
  val clk = out Bool
  val clk_fb = in Bool
  val cmd_o = out Bool
  val cmd_i = in Bool
  val cmd_t = out Bool
  val data_i = in Bits(4 bits)
  val data_o = out Bits(4 bits)
  val data_t = out Bits(4 bits)
  val cdn = in Bool
  val wp = in Bool
  val led = out Bool
  val buspow = out Bool
  val busvolt = out Bits(3 bits)
}

case class zynqGPIO() extends Bundle
{
  val i = in Bits(64 bits)
  val o = out Bits(64 bits)
  val t = out Bits(64 bits)
}

case class zynqMIO() extends Bundle with IMasterSlave
{
  val mio = Analog(Bits(54 bits))

  override def asMaster() : Unit = {
    inout(mio)
  }
}

case class zynqTrace() extends Bundle
{
  val clk = in Bool
  val ctl = out Bool
  val data = out Bits(32 bits)

}

case class zynqPJTAG() extends Bundle
{
  val tck = in Bool
  val tms = in Bool
  val td_i = in Bool
  val td_o = out Bool
  val td_t = out Bool
}

case class zynqUSB() extends Bundle
{
  val port_indctl = out Bits(2 bits)
  val vbus_pwrfault = in Bool
  val vbus_pwrselect = out Bool
}

case class zynqFCLK() extends Bundle
{
  val clk0 = out Bool
  val clk1 = out Bool
  val clk2 = out Bool
  val clk3 = out Bool

  val clk1Trig0_n = in Bool
  val clk1Trig1_n = in Bool
  val clk1Trig2_n = in Bool
  val clk1Trig3_n = in Bool

  val reset0_n = out Bool
  val reset1_n = out Bool
  val reset2_n = out Bool
  val reset3_n = out Bool
}

case class zynqEvent() extends Bundle
{
  val event_i = in Bool
  val event_o = out Bool
  val standbywfe = out Bits(2 bits)
  val standbywfi = out Bits(2 bits)
}

case class zynqPLTrace() extends Bundle
{
  val clk = in Bool
  val valid = in Bool
  val id = in Bits(4 bits)
  val data	= in Bits(32 bits)
}

case class zynqCrossTrigger() extends Bundle
{
  val f2p_trig = in Bits(4 bits)
  val f2p_trigack = out Bits(4 bits)
  val f2p_debug = in Bits(32 bits)
  val p2f_trig = out Bits(4 bits)
  val p2f_trigack = in Bits(4 bits)
  val p2f_debug = out Bits(32 bits)
}

case class zynqDMA() extends Bundle
{
  val daready = in Bool
  val datype = out Bits(2 bits)
  val davalid = out Bool
  val drlast = in Bool
  val drready = out Bool
  val drtype = in Bits(2 bits)
  val drvalid = in Bool
  val aclk = in Bool
}

case class zynqInterrupts() extends Bundle
{
  val f2p_68to61 = in Bits(8 bits)
  val f2p_91to84 = in Bits(8 bits)
  val f2p_core0_n = in Bool
  val f2p_core1_n = in Bool
  val f2p_core0_fiq_n = in Bool
  val f2p_core1_fiq_n = in Bool
  val p2f_dmac_abort = out Bool
  val p2f_dmac0 = out Bool
  val p2f_dmac1 = out Bool
  val p2f_dmac2 = out Bool
  val p2f_dmac3 = out Bool
  val p2f_dmac4 = out Bool
  val p2f_dmac5 = out Bool
  val p2f_dmac6 = out Bool
  val p2f_dmac7 = out Bool

  val p2f_smc = out Bool
  val p2f_qspi = out Bool
  val p2f_cti = out Bool
  val p2f_gpio = out Bool
  val p2f_usb0 = out Bool
  val p2f_usb1 = out Bool
  val p2f_enet0 = out Bool
  val p2f_enet1 = out Bool
  val p2f_enet_wake0 = out Bool
  val p2f_enet_wake1 = out Bool
  val p2f_sdio0 = out Bool
  val p2f_sdio1 = out Bool
  val p2f_i2c0 = out Bool
  val p2f_i2c1 = out Bool
  val p2f_spi0 = out Bool
  val p2f_spi1 = out Bool
  val p2f_uart0 = out Bool
  val p2f_uart1 = out Bool
  val p2f_can0 = out Bool
  val p2f_can1 = out Bool
}

case class zynqPSClockAndReset() extends Bundle with IMasterSlave
{
  val ps_clk = Analog(Bool)
  val ps_por_b = Analog(Bool)
  val ps_srst_b = Analog(Bool)
  override def asMaster() : Unit = {
    inout(ps_clk, ps_por_b, ps_srst_b)
  }
}

case class zynqDDR() extends Bundle with IMasterSlave
{
  // why are some of these wires marked as Analog/inout when they should be out?
  // Cos vivido complains if they aren't because it infers a BIBUF which is only for inout

  val addr = Analog(Bits(15 bits))
  val bankaddr = Analog(Bits(3 bits))
  val cas_n = Analog(Bool)
  val cke = Analog(Bool)
  val clk_n = Analog(Bool)
  val clk = Analog(Bool)
  val cs_n = Analog(Bool)

  val dm = Analog(Bits(4 bits))

  val dq = Analog(Bits(32 bits))
  val dqs_n = Analog(Bits(4 bits))
  val dqs = Analog(Bits(4 bits))

  val drstb = Analog(Bool)
  val odt = Analog(Bool)
  val ras_n = Analog(Bool)
  val vrn = Analog(Bool)
  val vrp = Analog(Bool)
  val web = Analog(Bool)

  override def asMaster() : Unit = {
    inout(addr, bankaddr, cas_n, cke, clk_n, clk, cs_n, dm,drstb, odt, ras_n)
    inout(dq, dqs_n, dqs, vrn, vrp, web)
  }
}

object zynqAxis
{
  val PSMasterGPAxiConfig = Axi4Config( addressWidth = 32,
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
                                        useStrb = true )

  val FPGAMasterGPAxiConfig = Axi4Config( addressWidth = 32,
                                          dataWidth = 32,
                                          idWidth = 6,
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
                                          useStrb = true)

                                          
  val FPGAMasterACPAxiConfig = Axi4Config( addressWidth = 32,
                                          dataWidth = 32,
                                          idWidth = 6,
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
                                          useStrb = true)

                                          
  val FPGAMasterHPAxiConfig = Axi4Config( addressWidth = 32,
                                          dataWidth = 32,
                                          idWidth = 6,
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
                                          useStrb = true)
}

class zynqPS7Wwrapper(
  config : zynqSoCConfig
)
extends Component
{
                                          
  val usesFCLK =  config.useFPGAClock0 | config.useFPGAClock1 | 
                  config.useFPGAClock2 | config.useFPGAClock3 | 
                  config.useFPGAClockTrigger0 | config.useFPGAClockTrigger1 | 
                  config.useFPGAClockTrigger2 | config.useFPGAClockTrigger3
                  config.useFPGAReset0 | config.useFPGAReset1 | 
                  config.useFPGAReset2 | config.useFPGAReset3

  val io = new Bundle{
    val eth0 = zynqEthernet() genIf config.useEthernet0
    val eth1 = zynqEthernet() genIf config.useEthernet1

    val ttc0 = zynqTripleTimer() genIf config.useTripleTimer0
    val ttc1 = zynqTripleTimer() genIf config.useTripleTimer1

    val wdt = zynqWatchDog() genIf config.useWatchDog

    val spi0 = zynqSPI() genIf config.useSPI0
    val spi1 = zynqSPI() genIf config.useSPI1

    val i2c0 = zynqI2C() genIf config.useI2C0
    val i2c1 = zynqI2C() genIf config.useI2C1

    val can1 = zynqCAN() genIf config.useCAN1
    val can0 = zynqCAN() genIf config.useCAN0

    val uart0 = zynqUART() genIf config.useUART0
    val uart1 = zynqUART() genIf config.useUART1

    val sdio0 = zynqSDIO() genIf config.useSDIO0
    val sdio1 = zynqSDIO() genIf config.useSDIO1

    val gpio = zynqGPIO() genIf config.useGPIO

    val trace = zynqTrace() genIf config.useTrace

    val pjtag = zynqPJTAG() genIf config.usePJTAG

    val usb0 = zynqUSB() genIf config.useUSB0
    val usb1 = zynqUSB() genIf config.useUSB1

    val sram_intin = (in Bool) genIf config.useSRAM_INTERRUPT

    val fclk = zynqFCLK() genIf usesFCLK

    val fpga_idle_n = (in Bool) genIf config.useIdle

    val event = zynqEvent() genIf config.useEvents

    val ddr_arb = (in Bits(4 bits)) genIf config.useDDR_ARB

    val pl_trace = zynqPLTrace() genIf config.usePLTrace

    val cross_trigger = zynqCrossTrigger() genIf config.useCrossTrigger

    val dma0 = zynqDMA() genIf config.useDMA0
    val dma1 = zynqDMA() genIf config.useDMA1
    val dma2 = zynqDMA() genIf config.useDMA2
    val dma3 = zynqDMA() genIf config.useDMA3

    val irq = zynqInterrupts() genIf config.useInterrupts

    val ps_axi3_master_gp0 = slave( Axi4(zynqAxis.PSMasterGPAxiConfig) ) genIf config.usePSMasterGP0Axi
    val ps_axi3_master_gp0_clk = (in Bool) genIf config.usePSMasterGP0Axi
    val ps_axi3_master_gp1 = slave( Axi4(zynqAxis.PSMasterGPAxiConfig) ) genIf config.usePSMasterGP1Axi
    val ps_axi3_master_gp1_clk = (in Bool) genIf config.usePSMasterGP1Axi
    val fpga_axi3_master_gp0 = master( Axi4(zynqAxis.FPGAMasterGPAxiConfig) ) genIf config.useFPGAMasterGP0Axi
    val fpga_axi3_master_gp1 = master( Axi4(zynqAxis.FPGAMasterGPAxiConfig) ) genIf config.useFPGAMasterGP1Axi
    val fpga_axi3_master_acp = master( Axi4(zynqAxis.FPGAMasterACPAxiConfig) ) genIf config.useFPGAMasterACPAxi
    val fpga_axi3_master_hp0 = master( Axi4(zynqAxis.FPGAMasterHPAxiConfig) ) genIf config.useFPGAMasterHP0Axi
    val fpga_axi3_master_hp1 = master( Axi4(zynqAxis.FPGAMasterHPAxiConfig) ) genIf config.useFPGAMasterHP1Axi
    val fpga_axi3_master_hp2 = master( Axi4(zynqAxis.FPGAMasterHPAxiConfig) ) genIf config.useFPGAMasterHP2Axi
    val fpga_axi3_master_hp3 = master( Axi4(zynqAxis.FPGAMasterHPAxiConfig) ) genIf config.useFPGAMasterHP3Axi

    // require connections
    val ps_clock_and_reset = master(zynqPSClockAndReset())
    val ddr = master(zynqDDR())
    val mio = master(zynqMIO())
  }

  val ps7 = new PS7

  if(config.useEthernet0)
  {
    ps7.io.EMIOENET0GMIIRXCLK <> io.eth0.gmiirxclk
  }
  else
  {
    ps7.io.EMIOENET0GMIIRXCLK := False
    ps7.io.EMIOENET0GMIICRS := False
    ps7.io.EMIOENET0GMIICOL := False
    ps7.io.EMIOENET0EXTINTIN := False
    ps7.io.EMIOENET0GMIIRXD := B(0)
    ps7.io.EMIOENET0GMIIRXER := False
    ps7.io.EMIOENET0GMIIRXDV := False
    ps7.io.EMIOENET0GMIITXCLK := False
    ps7.io.EMIOENET0MDIOI := False
  }

  if(config.useEthernet1)
  {
    ps7.io.EMIOENET1GMIIRXCLK <> io.eth1.gmiirxclk
  }
  else
  {
    ps7.io.EMIOENET1GMIIRXCLK := False
    ps7.io.EMIOENET1GMIICRS := False
    ps7.io.EMIOENET1GMIICOL := False
    ps7.io.EMIOENET1EXTINTIN := False
    ps7.io.EMIOENET1GMIIRXD := B(0)
    ps7.io.EMIOENET1GMIIRXER := False
    ps7.io.EMIOENET1GMIIRXDV := False
    ps7.io.EMIOENET1GMIITXCLK := False
    ps7.io.EMIOENET1MDIOI := False
  }

  if(config.useTripleTimer0)
  {
    ps7.io.EMIOTTC0CLKI <> io.ttc0.clk
    ps7.io.EMIOTTC0WAVEO <> io.ttc0.wave
  }
  else
  {
    ps7.io.EMIOTTC0CLKI := B(0)
  }

  if(config.useTripleTimer1)
  {
    ps7.io.EMIOTTC1CLKI <> io.ttc1.clk
    ps7.io.EMIOTTC1WAVEO <> io.ttc1.wave
  }
  else
  {
    ps7.io.EMIOTTC1CLKI := B(0)
  }

  if(config.useWatchDog)
  {
    ps7.io.EMIOWDTCLKI <> io.wdt.clk
    ps7.io.EMIOWDTRSTO <> io.wdt.rst
  }
  else
  {
    ps7.io.EMIOWDTCLKI := False
  }

  if(config.useSPI0)
  {
  	ps7.io.EMIOSPI0SCLKI <> io.spi0.sclk_i
	  ps7.io.EMIOSPI0SCLKO <> io.spi0.sclk_o
	  ps7.io.EMIOSPI0SCLKTN <> io.spi0.sclk_t
	  ps7.io.EMIOSPI0MI   <> io.spi0.miso_i
	  ps7.io.EMIOSPI0MO   <> io.spi0.mosi_o
	  ps7.io.EMIOSPI0MOTN <> io.spi0.mosi_t
	  ps7.io.EMIOSPI0SI   <> io.spi0.mosi_i
    ps7.io.EMIOSPI0SO   <> io.spi0.miso_o
	  ps7.io.EMIOSPI0STN  <> io.spi0.miso_t
	  ps7.io.EMIOSPI0SSIN <> io.spi0.ss_i
	  ps7.io.EMIOSPI0SSON <> io.spi0.ss_o
	  ps7.io.EMIOSPI0SSNTN <> io.spi0.ss_t
  }
  else
  {
  	ps7.io.EMIOSPI0SCLKI <> False
	  ps7.io.EMIOSPI0MI   <> False
	  ps7.io.EMIOSPI0SI   <> False
	  ps7.io.EMIOSPI0SSIN <> False
  }

  if(config.useSPI1)
  {
  	ps7.io.EMIOSPI1SCLKI <> io.spi1.sclk_i
	  ps7.io.EMIOSPI1SCLKO <> io.spi1.sclk_o
	  ps7.io.EMIOSPI1SCLKTN <> io.spi1.sclk_t
	  ps7.io.EMIOSPI1MI   <> io.spi1.miso_i
	  ps7.io.EMIOSPI1MO   <> io.spi1.mosi_o
	  ps7.io.EMIOSPI1MOTN <> io.spi1.mosi_t
	  ps7.io.EMIOSPI1SI   <> io.spi1.mosi_i
    ps7.io.EMIOSPI1SO   <> io.spi1.miso_o
	  ps7.io.EMIOSPI1STN  <> io.spi1.miso_t
	  ps7.io.EMIOSPI1SSIN <> io.spi1.ss_i
	  ps7.io.EMIOSPI1SSON <> io.spi1.ss_o
	  ps7.io.EMIOSPI1SSNTN <> io.spi1.ss_t
  }
  else
  {
  	ps7.io.EMIOSPI1SCLKI <> False
	  ps7.io.EMIOSPI1MI   <> False
	  ps7.io.EMIOSPI1SI   <> False
	  ps7.io.EMIOSPI1SSIN <> False
  }

  if(config.useI2C0)
  {
    ps7.io.EMIOI2C0SCLI <> io.i2c0.scl_i
    ps7.io.EMIOI2C0SCLO <> io.i2c0.scl_o
    ps7.io.EMIOI2C0SCLTN <> io.i2c0.scl_t
    ps7.io.EMIOI2C0SDAI <> io.i2c0.sda_i
    ps7.io.EMIOI2C0SDAO <> io.i2c0.sda_o
    ps7.io.EMIOI2C0SDATN <> io.i2c0.sda_t
  }
  else
  {
    ps7.io.EMIOI2C0SCLI <> False
    ps7.io.EMIOI2C0SDAI <> False
  }

  if(config.useI2C1)
  {
    ps7.io.EMIOI2C1SCLI <> io.i2c1.scl_i
    ps7.io.EMIOI2C1SCLO <> io.i2c1.scl_o
    ps7.io.EMIOI2C1SCLTN <> io.i2c1.scl_t
    ps7.io.EMIOI2C1SDAI <> io.i2c1.sda_i
    ps7.io.EMIOI2C1SDAO <> io.i2c1.sda_o
    ps7.io.EMIOI2C1SDATN <> io.i2c1.sda_t
  }
  else
  {
    ps7.io.EMIOI2C1SCLI <> False
    ps7.io.EMIOI2C1SDAI <> False
  }

  if(config.useCAN0)
  {
    ps7.io.EMIOCAN0PHYTX <> io.can0.phy_tx
    ps7.io.EMIOCAN0PHYRX <> io.can0.phy_rx
  }
  else
  {
    ps7.io.EMIOCAN0PHYRX <> False
  }

  if(config.useCAN1)
  {
    ps7.io.EMIOCAN1PHYTX <> io.can1.phy_tx
    ps7.io.EMIOCAN1PHYRX <> io.can1.phy_rx
  }
  else
  {
    ps7.io.EMIOCAN1PHYRX <> False
  }

  if(config.useUART0)
  {
    ps7.io.EMIOUART0TX <> io.uart0.tx
	  ps7.io.EMIOUART0RX <> io.uart0.rx
	  ps7.io.EMIOUART0CTSN <> io.uart0.ctsn
	  ps7.io.EMIOUART0RTSN <> io.uart0.rtsn
	  ps7.io.EMIOUART0DSRN <> io.uart0.dsrn
	  ps7.io.EMIOUART0DCDN <> io.uart0.dcdn
	  ps7.io.EMIOUART0RIN <> io.uart0.rin
    ps7.io.EMIOUART0DTRN <> io.uart0.dtrn
  }
  else
  {
	  ps7.io.EMIOUART0RX <> False
	  ps7.io.EMIOUART0CTSN <> False
	  ps7.io.EMIOUART0DSRN <> False
	  ps7.io.EMIOUART0DCDN <> False
	  ps7.io.EMIOUART0RIN <> False
  }

  if(config.useUART1)
  {
    ps7.io.EMIOUART1TX <> io.uart1.tx
	  ps7.io.EMIOUART1RX <> io.uart1.rx
	  ps7.io.EMIOUART1CTSN <> io.uart1.ctsn
	  ps7.io.EMIOUART1RTSN <> io.uart1.rtsn
	  ps7.io.EMIOUART1DSRN <> io.uart1.dsrn
	  ps7.io.EMIOUART1DCDN <> io.uart1.dcdn
	  ps7.io.EMIOUART1RIN <> io.uart1.rin
    ps7.io.EMIOUART1DTRN <> io.uart1.dtrn
  }
  else
  {
	  ps7.io.EMIOUART1RX <> False
	  ps7.io.EMIOUART1CTSN <> False
	  ps7.io.EMIOUART1DSRN <> False
	  ps7.io.EMIOUART1DCDN <> False
	  ps7.io.EMIOUART1RIN <> False
  }

  if(config.useSDIO0)
  {
    ps7.io.EMIOSDIO0CLK <> io.sdio0.clk
	  ps7.io.EMIOSDIO0CLKFB <> io.sdio0.clk_fb
    ps7.io.EMIOSDIO0CMDO <> io.sdio0.cmd_o
	  ps7.io.EMIOSDIO0CMDI <> io.sdio0.cmd_i
    ps7.io.EMIOSDIO0CMDTN <> io.sdio0.cmd_t
	  ps7.io.EMIOSDIO0DATAI <> io.sdio0.data_i
	  ps7.io.EMIOSDIO0DATAO <> io.sdio0.data_o
	  ps7.io.EMIOSDIO0DATATN <> io.sdio0.data_t
	  ps7.io.EMIOSDIO0CDN <> io.sdio0.cdn
	  ps7.io.EMIOSDIO0WP <> io.sdio0.wp
	  ps7.io.EMIOSDIO0LED <> io.sdio0.led
	  ps7.io.EMIOSDIO0BUSPOW <> io.sdio0.buspow
	  ps7.io.EMIOSDIO0BUSVOLT <> io.sdio0.busvolt
  }
  else
  {
	  ps7.io.EMIOSDIO0CLKFB <> False
	  ps7.io.EMIOSDIO0CMDI <> False
	  ps7.io.EMIOSDIO0DATAI <> 0
	  ps7.io.EMIOSDIO0CDN <> False
	  ps7.io.EMIOSDIO0WP <> False
  }

  if(config.useSDIO1)
  {
    ps7.io.EMIOSDIO1CLK <> io.sdio1.clk
	  ps7.io.EMIOSDIO1CLKFB <> io.sdio1.clk_fb
    ps7.io.EMIOSDIO1CMDO <> io.sdio1.cmd_o
	  ps7.io.EMIOSDIO1CMDI <> io.sdio1.cmd_i
    ps7.io.EMIOSDIO1CMDTN <> io.sdio1.cmd_t
	  ps7.io.EMIOSDIO1DATAI <> io.sdio1.data_i
	  ps7.io.EMIOSDIO1DATAO <> io.sdio1.data_o
	  ps7.io.EMIOSDIO1DATATN <> io.sdio1.data_t
	  ps7.io.EMIOSDIO1CDN <> io.sdio1.cdn
	  ps7.io.EMIOSDIO1WP <> io.sdio1.wp
	  ps7.io.EMIOSDIO1LED <> io.sdio1.led
	  ps7.io.EMIOSDIO1BUSPOW <> io.sdio1.buspow
	  ps7.io.EMIOSDIO1BUSVOLT <> io.sdio1.busvolt
  }
  else
  {
	  ps7.io.EMIOSDIO1CLKFB <> False
	  ps7.io.EMIOSDIO1CMDI <> False
	  ps7.io.EMIOSDIO1DATAI <> 0
	  ps7.io.EMIOSDIO1CDN <> False
	  ps7.io.EMIOSDIO1WP <> False
  }

  if(config.useGPIO)
  {
    ps7.io.EMIOGPIOI <> io.gpio.i
    ps7.io.EMIOGPIOO <> io.gpio.o
    ps7.io.EMIOGPIOTN <> io.gpio.t
  }
  else
  {
    ps7.io.EMIOGPIOI <> 0
  }

  ps7.io.MIO <> io.mio.mio

  if(config.useTrace)
  {
    ps7.io.EMIOTRACECLK <> io.trace.clk
    ps7.io.EMIOTRACECTL <> io.trace.ctl
    ps7.io.EMIOTRACEDATA <> io.trace.data
  }
  else
  {
    ps7.io.EMIOTRACECLK <> False
  }

  if(config.usePJTAG)
  {
	  ps7.io.EMIOPJTAGTCK <> io.pjtag.tck
	  ps7.io.EMIOPJTAGTMS <> io.pjtag.tms
	  ps7.io.EMIOPJTAGTDI <> io.pjtag.td_i
    ps7.io.EMIOPJTAGTDO <> io.pjtag.td_o
	  ps7.io.EMIOPJTAGTDTN<> io.pjtag.td_t
  }
  else
  {
	  ps7.io.EMIOPJTAGTCK <> False
	  ps7.io.EMIOPJTAGTMS <> False
	  ps7.io.EMIOPJTAGTDI <> False
  }

  if(config.useUSB0)
  {
    ps7.io.EMIOUSB0PORTINDCTL <> io.usb0.port_indctl
    ps7.io.EMIOUSB0VBUSPWRFAULT <> io.usb0.vbus_pwrfault
    ps7.io.EMIOUSB0VBUSPWRSELECT <> io.usb0.vbus_pwrselect
  }
  else
  {
    ps7.io.EMIOUSB0VBUSPWRFAULT <> False
  }

  if(config.useUSB1)
  {
    ps7.io.EMIOUSB1PORTINDCTL <> io.usb1.port_indctl
    ps7.io.EMIOUSB1VBUSPWRFAULT <> io.usb1.vbus_pwrfault
    ps7.io.EMIOUSB1VBUSPWRSELECT <> io.usb1.vbus_pwrselect
  }
  else
  {
    ps7.io.EMIOUSB1VBUSPWRFAULT <> False
  }

  if(config.useSRAM_INTERRUPT) ps7.io.EMIOSRAMINTIN <> io.sram_intin
  else ps7.io.EMIOSRAMINTIN <> False

  if(usesFCLK)
  {
    val trig0_n = Bool
    val trig1_n = Bool
    val trig2_n = Bool
    val trig3_n = Bool

    if(config.useFPGAClockTrigger0) trig0_n := io.fclk.clk1Trig0_n else trig0_n := True
    if(config.useFPGAClockTrigger1) trig1_n := io.fclk.clk1Trig1_n else trig1_n := True
    if(config.useFPGAClockTrigger2) trig2_n := io.fclk.clk1Trig2_n else trig2_n := True
    if(config.useFPGAClockTrigger3) trig3_n := io.fclk.clk1Trig3_n else trig3_n := True

    io.fclk.clk0 := ps7.io.FCLKCLK(0)
    io.fclk.clk1 := ps7.io.FCLKCLK(1)
    io.fclk.clk2 := ps7.io.FCLKCLK(2)
    io.fclk.clk3 := ps7.io.FCLKCLK(3)
    ps7.io.FCLKCLKTRIGN <> trig3_n ## trig2_n ## trig1_n ## trig0_n
    io.fclk.reset0_n := ps7.io.FCLKRESETN(0)
    io.fclk.reset1_n := ps7.io.FCLKRESETN(1)
    io.fclk.reset2_n := ps7.io.FCLKRESETN(2)
    io.fclk.reset3_n := ps7.io.FCLKRESETN(3)
  }
  else
  {
    ps7.io.FCLKCLKTRIGN <> 0
  }

  if(config.useIdle) ps7.io.FPGAIDLEN <> io.fpga_idle_n
  else ps7.io.FPGAIDLEN <> False

  if(config.useEvents)
  {
    ps7.io.EVENTEVENTI <> io.event.event_i
    ps7.io.EVENTEVENTO <> io.event.event_o
    ps7.io.EVENTSTANDBYWFE <> io.event.standbywfe
    ps7.io.EVENTSTANDBYWFI <> io.event.standbywfi
  }
  else
  {
    ps7.io.EVENTEVENTI <> False
  }

  if(config.useDDR_ARB) ps7.io.DDRARB <> io.ddr_arb
  else ps7.io.DDRARB <> 0

  if(config.usePLTrace)
  {
    ps7.io.FTMDTRACEINDATA <> io.pl_trace.data
    ps7.io.FTMDTRACEINVALID <> io.pl_trace.valid
    ps7.io.FTMDTRACEINCLOCK <> io.pl_trace.clk
    ps7.io.FTMDTRACEINATID <> io.pl_trace.id
  }
  else
  {
    ps7.io.FTMDTRACEINDATA <> 0
    ps7.io.FTMDTRACEINVALID <> False
    ps7.io.FTMDTRACEINCLOCK <> False
    ps7.io.FTMDTRACEINATID <> 0
  }
  if(config.useCrossTrigger)
  {
    ps7.io.FTMTF2PTRIG <> io.cross_trigger.f2p_trig
	  ps7.io.FTMTF2PTRIGACK <> io.cross_trigger.f2p_trigack
	  ps7.io.FTMTF2PDEBUG <> io.cross_trigger.f2p_debug
    ps7.io.FTMTP2FTRIG <> io.cross_trigger.p2f_trig
	  ps7.io.FTMTP2FTRIGACK <> io.cross_trigger.p2f_trigack
    ps7.io.FTMTP2FDEBUG <> io.cross_trigger.p2f_debug
  }
  else
  {
    ps7.io.FTMTF2PTRIG <> 0
	  ps7.io.FTMTF2PDEBUG <> 0
	  ps7.io.FTMTP2FTRIGACK <> 0
  }

  if(config.useDMA0)
  {
	  ps7.io.DMA0DAREADY <> io.dma0.daready
	  ps7.io.DMA0DATYPE <> io.dma0.datype
	  ps7.io.DMA0DAVALID <> io.dma0.davalid
	  ps7.io.DMA0DRLAST <> io.dma0.drlast
	  ps7.io.DMA0DRREADY <> io.dma0.drready
    ps7.io.DMA0DRTYPE <> io.dma0.drtype
    ps7.io.DMA0DRVALID <> io.dma0.drvalid
    ps7.io.DMA0ACLK <> io.dma0.aclk
  }
  else
  {
    ps7.io.DMA0DAREADY <> False
	  ps7.io.DMA0DRLAST <> False
    ps7.io.DMA0DRTYPE <> 0
    ps7.io.DMA0DRVALID <> False
    ps7.io.DMA0ACLK <> False
  }

  if(config.useDMA1)
  {
	  ps7.io.DMA1DAREADY <> io.dma1.daready
	  ps7.io.DMA1DATYPE <> io.dma1.datype
	  ps7.io.DMA1DAVALID <> io.dma1.davalid
	  ps7.io.DMA1DRLAST <> io.dma1.drlast
	  ps7.io.DMA1DRREADY <> io.dma1.drready
    ps7.io.DMA1DRTYPE <> io.dma1.drtype
    ps7.io.DMA1DRVALID <> io.dma1.drvalid
    ps7.io.DMA1ACLK <> io.dma1.aclk
  }
  else
  {
    ps7.io.DMA1DAREADY <> False
	  ps7.io.DMA1DRLAST <> False
    ps7.io.DMA1DRTYPE <> 0
    ps7.io.DMA1DRVALID <> False
    ps7.io.DMA1ACLK <> False
  }

  if(config.useDMA2)
  {
	  ps7.io.DMA2DAREADY <> io.dma2.daready
	  ps7.io.DMA2DATYPE <> io.dma2.datype
	  ps7.io.DMA2DAVALID <> io.dma2.davalid
	  ps7.io.DMA2DRLAST <> io.dma2.drlast
	  ps7.io.DMA2DRREADY <> io.dma2.drready
    ps7.io.DMA2DRTYPE <> io.dma2.drtype
    ps7.io.DMA2DRVALID <> io.dma2.drvalid
    ps7.io.DMA2ACLK <> io.dma2.aclk
  }
  else
  {
    ps7.io.DMA2DAREADY <> False
	  ps7.io.DMA2DRLAST <> False
    ps7.io.DMA2DRTYPE <> 0
    ps7.io.DMA2DRVALID <> False
    ps7.io.DMA2ACLK <> False
  }

  if(config.useDMA3)
  {
	  ps7.io.DMA3DAREADY <> io.dma3.daready
	  ps7.io.DMA3DATYPE <> io.dma3.datype
	  ps7.io.DMA3DAVALID <> io.dma3.davalid
	  ps7.io.DMA3DRLAST <> io.dma3.drlast
	  ps7.io.DMA3DRREADY <> io.dma3.drready
    ps7.io.DMA3DRTYPE <> io.dma3.drtype
    ps7.io.DMA3DRVALID <> io.dma3.drvalid
    ps7.io.DMA3ACLK <> io.dma3.aclk
  }
  else
  {
    ps7.io.DMA3DAREADY <> False
	  ps7.io.DMA3DRLAST <> False
    ps7.io.DMA3DRTYPE <> 0
    ps7.io.DMA3DRVALID <> False
    ps7.io.DMA3ACLK <> False
  }

  if(config.useInterrupts)
  {
    ps7.io.IRQF2P(0 to 8) <> io.irq.f2p_68to61
    ps7.io.IRQF2P(8 to 16) <> io.irq.f2p_91to84
    ps7.io.IRQF2P(16) <> io.irq.f2p_core0_n
    ps7.io.IRQF2P(17) <> io.irq.f2p_core1_n
    ps7.io.IRQF2P(18) <> io.irq.f2p_core0_fiq_n
    ps7.io.IRQF2P(19) <> io.irq.f2p_core1_fiq_n

    ps7.io.IRQP2F(28) <> io.irq.p2f_dmac_abort
    ps7.io.IRQP2F(27) <> io.irq.p2f_dmac7
    ps7.io.IRQP2F(26) <> io.irq.p2f_dmac6
    ps7.io.IRQP2F(25) <> io.irq.p2f_dmac5
    ps7.io.IRQP2F(24) <> io.irq.p2f_dmac4
    ps7.io.IRQP2F(23) <> io.irq.p2f_dmac3
    ps7.io.IRQP2F(22) <> io.irq.p2f_dmac2
    ps7.io.IRQP2F(21) <> io.irq.p2f_dmac1
    ps7.io.IRQP2F(20) <> io.irq.p2f_dmac0
    ps7.io.IRQP2F(19) <> io.irq.p2f_smc
    ps7.io.IRQP2F(18) <> io.irq.p2f_qspi
    ps7.io.IRQP2F(17) <> io.irq.p2f_cti
    ps7.io.IRQP2F(16) <> io.irq.p2f_gpio
    ps7.io.IRQP2F(15) <> io.irq.p2f_usb0
    ps7.io.IRQP2F(14) <> io.irq.p2f_enet0
    ps7.io.IRQP2F(13) <> io.irq.p2f_enet_wake0
    ps7.io.IRQP2F(12) <> io.irq.p2f_sdio0
    ps7.io.IRQP2F(11) <> io.irq.p2f_i2c0
    ps7.io.IRQP2F(10) <> io.irq.p2f_spi0
    ps7.io.IRQP2F( 9) <> io.irq.p2f_uart0
    ps7.io.IRQP2F( 8) <> io.irq.p2f_can0
    ps7.io.IRQP2F( 7) <> io.irq.p2f_usb1
    ps7.io.IRQP2F( 6) <> io.irq.p2f_enet1
    ps7.io.IRQP2F( 5) <> io.irq.p2f_enet_wake1
    ps7.io.IRQP2F( 4) <> io.irq.p2f_sdio1
    ps7.io.IRQP2F( 3) <> io.irq.p2f_i2c1
    ps7.io.IRQP2F( 2) <> io.irq.p2f_spi1
    ps7.io.IRQP2F( 1) <> io.irq.p2f_uart1
    ps7.io.IRQP2F( 0) <> io.irq.p2f_can1
  }
  else
  {
    ps7.io.IRQF2P <> 0
  }

  ps7.io.PSCLK <> io.ps_clock_and_reset.ps_clk
  ps7.io.PSPORB <> io.ps_clock_and_reset.ps_por_b
  ps7.io.PSSRSTB <> io.ps_clock_and_reset.ps_srst_b

  if(config.usePSMasterGP0Axi)
  {
    ps7.io.MAXIGP0ACLK <> io.ps_axi3_master_gp0_clk
//    ps7.io.MAXIGP0ARESETN <> ClockDomain.current.reset
    val ps_axi3_master_gp0 = master(io.ps_axi3_master_gp0)

    ps7.io.MAXIGP0AWID <> ps_axi3_master_gp0.aw.id
    ps7.io.MAXIGP0AWADDR <> ps_axi3_master_gp0.aw.addr
    ps7.io.MAXIGP0AWLEN.resize(8) <> ps_axi3_master_gp0.aw.len
    ps7.io.MAXIGP0AWSIZE.resize(3) <> ps_axi3_master_gp0.aw.size
    ps7.io.MAXIGP0AWBURST <> ps_axi3_master_gp0.aw.burst
    ps7.io.MAXIGP0AWLOCK.resize(1) <> ps_axi3_master_gp0.aw.lock
    ps7.io.MAXIGP0AWCACHE <> ps_axi3_master_gp0.aw.cache
    ps7.io.MAXIGP0AWPROT <> ps_axi3_master_gp0.aw.prot
    ps7.io.MAXIGP0AWVALID <> ps_axi3_master_gp0.aw.valid
    ps7.io.MAXIGP0AWREADY <> ps_axi3_master_gp0.aw.ready
//isn't used by Axi4    ps7.io.MAXIGP0WID <> io.ps_axi3_master_gp0.w.id
    ps7.io.MAXIGP0WDATA <> ps_axi3_master_gp0.w.data
    ps7.io.MAXIGP0WSTRB <> ps_axi3_master_gp0.w.strb
    ps7.io.MAXIGP0WLAST <> ps_axi3_master_gp0.w.last
    ps7.io.MAXIGP0WVALID <> ps_axi3_master_gp0.w.valid
    ps7.io.MAXIGP0WREADY <> ps_axi3_master_gp0.w.ready
    ps7.io.MAXIGP0BID <> ps_axi3_master_gp0.b.id
    ps7.io.MAXIGP0BRESP <> ps_axi3_master_gp0.b.resp
    ps7.io.MAXIGP0BVALID <> ps_axi3_master_gp0.b.valid
    ps7.io.MAXIGP0BREADY <> ps_axi3_master_gp0.b.ready
    ps7.io.MAXIGP0ARID <> ps_axi3_master_gp0.ar.id
    ps7.io.MAXIGP0ARADDR <> ps_axi3_master_gp0.ar.addr
    ps7.io.MAXIGP0ARLEN.resize(8) <> ps_axi3_master_gp0.ar.len
    ps7.io.MAXIGP0ARSIZE.resize(3) <> ps_axi3_master_gp0.ar.size
    ps7.io.MAXIGP0ARBURST <> ps_axi3_master_gp0.ar.burst
    ps7.io.MAXIGP0ARLOCK.resize(1) <> ps_axi3_master_gp0.ar.lock
    ps7.io.MAXIGP0ARCACHE <> ps_axi3_master_gp0.ar.cache
    ps7.io.MAXIGP0ARPROT <> ps_axi3_master_gp0.ar.prot
    ps7.io.MAXIGP0ARVALID <> ps_axi3_master_gp0.ar.valid
    ps7.io.MAXIGP0ARREADY <> ps_axi3_master_gp0.ar.ready
    ps7.io.MAXIGP0RID <> ps_axi3_master_gp0.r.id
    ps7.io.MAXIGP0RDATA <> ps_axi3_master_gp0.r.data
    ps7.io.MAXIGP0RRESP <> ps_axi3_master_gp0.r.resp
    ps7.io.MAXIGP0RLAST <> ps_axi3_master_gp0.r.last
    ps7.io.MAXIGP0RVALID <> ps_axi3_master_gp0.r.valid
    ps7.io.MAXIGP0RREADY <> ps_axi3_master_gp0.r.ready
    ps7.io.MAXIGP0AWQOS <> ps_axi3_master_gp0.aw.qos
    ps7.io.MAXIGP0ARQOS <> ps_axi3_master_gp0.ar.qos
  }
  else
  {
    ps7.io.MAXIGP0ACLK <> False
    ps7.io.MAXIGP0AWREADY <> False
    ps7.io.MAXIGP0WREADY <> False
    ps7.io.MAXIGP0BID <> 0
    ps7.io.MAXIGP0BRESP <> 0
    ps7.io.MAXIGP0BVALID <> False
    ps7.io.MAXIGP0ARREADY <> False   
    ps7.io.MAXIGP0RID <> 0
    ps7.io.MAXIGP0RDATA <> 0
    ps7.io.MAXIGP0RRESP <> 0
    ps7.io.MAXIGP0RLAST <> False
    ps7.io.MAXIGP0RVALID <> False
  }

  if(config.usePSMasterGP1Axi)
  {
    ps7.io.MAXIGP1ACLK <> io.ps_axi3_master_gp1_clk
    ps7.io.MAXIGP1ARESETN <> ClockDomain.current.reset

    ps7.io.MAXIGP1AWID <> io.ps_axi3_master_gp1.aw.id
    ps7.io.MAXIGP1AWADDR <> io.ps_axi3_master_gp1.aw.addr
    ps7.io.MAXIGP1AWLEN <> io.ps_axi3_master_gp1.aw.len
    ps7.io.MAXIGP1AWSIZE <> io.ps_axi3_master_gp1.aw.size
    ps7.io.MAXIGP1AWBURST <> io.ps_axi3_master_gp1.aw.burst
    ps7.io.MAXIGP1AWLOCK <> io.ps_axi3_master_gp1.aw.lock
    ps7.io.MAXIGP1AWCACHE <> io.ps_axi3_master_gp1.aw.cache
    ps7.io.MAXIGP1AWPROT <> io.ps_axi3_master_gp1.aw.prot
    ps7.io.MAXIGP1AWVALID <> io.ps_axi3_master_gp1.aw.valid
    ps7.io.MAXIGP1AWREADY <> io.ps_axi3_master_gp1.aw.ready
//isn't used by A1i4    ps7.io.MAXIGP0WID <> io.ps_axi3_master_gp1.w.id
    ps7.io.MAXIGP1WDATA <> io.ps_axi3_master_gp1.w.data
    ps7.io.MAXIGP1WSTRB <> io.ps_axi3_master_gp1.w.strb
    ps7.io.MAXIGP1WLAST <> io.ps_axi3_master_gp1.w.last
    ps7.io.MAXIGP1WVALID <> io.ps_axi3_master_gp1.w.valid
    ps7.io.MAXIGP1WREADY <> io.ps_axi3_master_gp1.w.ready
    ps7.io.MAXIGP1BID <> io.ps_axi3_master_gp1.b.id
    ps7.io.MAXIGP1BRESP <> io.ps_axi3_master_gp1.b.resp
    ps7.io.MAXIGP1BVALID <> io.ps_axi3_master_gp1.b.valid
    ps7.io.MAXIGP1BREADY <> io.ps_axi3_master_gp1.b.ready
    ps7.io.MAXIGP1ARID <> io.ps_axi3_master_gp1.ar.id
    ps7.io.MAXIGP1ARADDR <> io.ps_axi3_master_gp1.ar.addr
    ps7.io.MAXIGP1ARLEN <> io.ps_axi3_master_gp1.ar.len
    ps7.io.MAXIGP1ARSIZE <> io.ps_axi3_master_gp1.ar.size
    ps7.io.MAXIGP1ARBURST <> io.ps_axi3_master_gp1.ar.burst
    ps7.io.MAXIGP1ARLOCK <> io.ps_axi3_master_gp1.ar.lock
    ps7.io.MAXIGP1ARCACHE <> io.ps_axi3_master_gp1.ar.cache
    ps7.io.MAXIGP1ARPROT <> io.ps_axi3_master_gp1.ar.prot
    ps7.io.MAXIGP1ARVALID <> io.ps_axi3_master_gp1.ar.valid
    ps7.io.MAXIGP1ARREADY <> io.ps_axi3_master_gp1.ar.ready
    ps7.io.MAXIGP1RID <> io.ps_axi3_master_gp1.r.id
    ps7.io.MAXIGP1RDATA <> io.ps_axi3_master_gp1.r.data
    ps7.io.MAXIGP1RRESP <> io.ps_axi3_master_gp1.r.resp
    ps7.io.MAXIGP1RLAST <> io.ps_axi3_master_gp1.r.last
    ps7.io.MAXIGP1RVALID <> io.ps_axi3_master_gp1.r.valid
    ps7.io.MAXIGP1RREADY <> io.ps_axi3_master_gp1.r.ready
    ps7.io.MAXIGP1AWQOS <> io.ps_axi3_master_gp1.aw.qos
    ps7.io.MAXIGP1ARQOS <> io.ps_axi3_master_gp1.ar.qos
  }
  else
  {
    ps7.io.MAXIGP1ACLK <> False
    ps7.io.MAXIGP1AWREADY <> False
    ps7.io.MAXIGP1WREADY <> False
    ps7.io.MAXIGP1BID <> 0
    ps7.io.MAXIGP1BRESP <> 0
    ps7.io.MAXIGP1BVALID <> False
    ps7.io.MAXIGP1ARREADY <> False   
    ps7.io.MAXIGP1RID <> 0
    ps7.io.MAXIGP1RDATA <> 0
    ps7.io.MAXIGP1RRESP <> 0
    ps7.io.MAXIGP1RLAST <> False
    ps7.io.MAXIGP1RVALID <> False
  }

  if(config.useFPGAMasterGP0Axi)
  {
    ps7.io.SAXIGP0ACLK <> ClockDomain.current.clock
    ps7.io.SAXIGP0ARESETN <> ClockDomain.current.reset

    ps7.io.SAXIGP0AWID <> io.fpga_axi3_master_gp0.aw.id
    ps7.io.SAXIGP0AWADDR <> io.fpga_axi3_master_gp0.aw.addr
    ps7.io.SAXIGP0AWLEN <> io.fpga_axi3_master_gp0.aw.len
    ps7.io.SAXIGP0AWSIZE <> io.fpga_axi3_master_gp0.aw.size
    ps7.io.SAXIGP0AWBURST <> io.fpga_axi3_master_gp0.aw.burst
    ps7.io.SAXIGP0AWLOCK <> io.fpga_axi3_master_gp0.aw.lock
    ps7.io.SAXIGP0AWCACHE <> io.fpga_axi3_master_gp0.aw.cache
    ps7.io.SAXIGP0AWPROT <> io.fpga_axi3_master_gp0.aw.prot
    ps7.io.SAXIGP0AWVALID <> io.fpga_axi3_master_gp0.aw.valid
    ps7.io.SAXIGP0AWREADY <> io.fpga_axi3_master_gp0.aw.ready
    // fake for axi3
    val fakeWid = Reg(io.ps_axi3_master_gp0.aw.id.clone())
    ps7.io.SAXIGP0WID <> fakeWid
    when(io.ps_axi3_master_gp0.aw.valid)
    {
      fakeWid := io.ps_axi3_master_gp0.aw.id
    }

    ps7.io.SAXIGP0WDATA <> io.fpga_axi3_master_gp0.w.data
    ps7.io.SAXIGP0WSTRB <> io.fpga_axi3_master_gp0.w.strb
    ps7.io.SAXIGP0WLAST <> io.fpga_axi3_master_gp0.w.last
    ps7.io.SAXIGP0WVALID <> io.fpga_axi3_master_gp0.w.valid
    ps7.io.SAXIGP0WREADY <> io.fpga_axi3_master_gp0.w.ready
    ps7.io.SAXIGP0BID <> io.fpga_axi3_master_gp0.b.id
    ps7.io.SAXIGP0BRESP <> io.fpga_axi3_master_gp0.b.resp
    ps7.io.SAXIGP0BVALID <> io.fpga_axi3_master_gp0.b.valid
    ps7.io.SAXIGP0BREADY <> io.fpga_axi3_master_gp0.b.ready
    ps7.io.SAXIGP0ARID <> io.fpga_axi3_master_gp0.ar.id
    ps7.io.SAXIGP0ARADDR <> io.fpga_axi3_master_gp0.ar.addr
    ps7.io.SAXIGP0ARLEN <> io.fpga_axi3_master_gp0.ar.len
    ps7.io.SAXIGP0ARSIZE <> io.fpga_axi3_master_gp0.ar.size
    ps7.io.SAXIGP0ARBURST <> io.fpga_axi3_master_gp0.ar.burst
    ps7.io.SAXIGP0ARLOCK <> io.fpga_axi3_master_gp0.ar.lock
    ps7.io.SAXIGP0ARCACHE <> io.fpga_axi3_master_gp0.ar.cache
    ps7.io.SAXIGP0ARPROT <> io.fpga_axi3_master_gp0.ar.prot
    ps7.io.SAXIGP0ARVALID <> io.fpga_axi3_master_gp0.ar.valid
    ps7.io.SAXIGP0ARREADY <> io.fpga_axi3_master_gp0.ar.ready
    ps7.io.SAXIGP0RID <> io.fpga_axi3_master_gp0.r.id
    ps7.io.SAXIGP0RDATA <> io.fpga_axi3_master_gp0.r.data
    ps7.io.SAXIGP0RRESP <> io.fpga_axi3_master_gp0.r.resp
    ps7.io.SAXIGP0RLAST <> io.fpga_axi3_master_gp0.r.last
    ps7.io.SAXIGP0RVALID <> io.fpga_axi3_master_gp0.r.valid
    ps7.io.SAXIGP0RREADY <> io.fpga_axi3_master_gp0.r.ready
    ps7.io.SAXIGP0AWQOS <> io.fpga_axi3_master_gp0.aw.qos
    ps7.io.SAXIGP0ARQOS <> io.fpga_axi3_master_gp0.ar.qos
  }
  else
  {
    ps7.io.SAXIGP0ACLK := False
    ps7.io.SAXIGP0AWID := 0
    ps7.io.SAXIGP0AWADDR := 0
    ps7.io.SAXIGP0AWLEN := 0
    ps7.io.SAXIGP0AWSIZE := 0
    ps7.io.SAXIGP0AWBURST := 0
    ps7.io.SAXIGP0AWLOCK := 0
    ps7.io.SAXIGP0AWCACHE := 0
    ps7.io.SAXIGP0AWPROT := 0
    ps7.io.SAXIGP0AWVALID := False
    ps7.io.SAXIGP0WDATA := 0
    ps7.io.SAXIGP0WSTRB := 0
    ps7.io.SAXIGP0WLAST := False
    ps7.io.SAXIGP0WVALID := False 
    ps7.io.SAXIGP0BREADY := False
    ps7.io.SAXIGP0ARID := 0
    ps7.io.SAXIGP0ARADDR := 0
    ps7.io.SAXIGP0ARLEN := 0
    ps7.io.SAXIGP0ARSIZE := 0
    ps7.io.SAXIGP0ARBURST := 0
    ps7.io.SAXIGP0ARLOCK := 0
    ps7.io.SAXIGP0ARCACHE := 0
    ps7.io.SAXIGP0ARPROT := 0
    ps7.io.SAXIGP0ARVALID := False
    ps7.io.SAXIGP0RREADY := False
    ps7.io.SAXIGP0AWQOS := 0
    ps7.io.SAXIGP0ARQOS := 0
  }
  
  io.ddr.addr <> ps7.io.DDRA
  io.ddr.bankaddr <> ps7.io.DDRBA
  io.ddr.cas_n <> ps7.io.DDRCASB
  io.ddr.cke <> ps7.io.DDRCKE
  io.ddr.clk_n <> ps7.io.DDRCKN
  io.ddr.clk <> ps7.io.DDRCKP
  io.ddr.cs_n <> ps7.io.DDRCSB
  io.ddr.dm <> ps7.io.DDRDM
  io.ddr.dq <> ps7.io.DDRDQ
  io.ddr.dqs_n <> ps7.io.DDRDQSN
  io.ddr.dqs <> ps7.io.DDRDQSP
  io.ddr.drstb <> ps7.io.DDRDRSTB
  io.ddr.odt <> ps7.io.DDRODT
  io.ddr.ras_n <> ps7.io.DDRRASB
  io.ddr.vrn <> ps7.io.DDRVRN
  io.ddr.vrp <> ps7.io.DDRVRP
  io.ddr.web <> ps7.io.DDRWEB
}
