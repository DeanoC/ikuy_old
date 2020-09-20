package zynq_hard_soc

import spinal.core._

case class PS7() 
extends BlackBox 
{
  // Remove io_ prefix from verilog names
  noIoPrefix()

  val io = new Bundle 
  {
    // 2x gigabit ethernet
    val EMIOENET0GMIIRXCLK = in Bool
    val EMIOENET0GMIICRS = in Bool
    val EMIOENET0GMIICOL = in Bool
    val EMIOENET0EXTINTIN = in Bool       
    val EMIOENET0GMIIRXD = in Bits (8 bits)
    val EMIOENET0GMIIRXER = in Bool
    val EMIOENET0GMIIRXDV = in Bool  
    val EMIOENET0GMIITXCLK = in Bool
    val EMIOENET0GMIITXD = out Bits(8 bits)
    val EMIOENET0GMIITXEN = out Bool
    val EMIOENET0GMIITXER = out Bool    
    val EMIOENET0MDIOMDC = out Bool
    val EMIOENET0MDIOI = in Bool
    val EMIOENET0MDIOO = out Bool
    val EMIOENET0MDIOTN = out Bool  
    val EMIOENET0PTPSYNCFRAMETX = out Bool
    val EMIOENET0PTPDELAYREQTX = out Bool
    val EMIOENET0PTPPDELAYREQTX = out Bool
    val EMIOENET0PTPPDELAYRESPTX = out Bool
    val EMIOENET0SOFTX = out Bool
    val EMIOENET0PTPSYNCFRAMERX = out Bool
    val EMIOENET0PTPDELAYREQRX = out Bool
    val EMIOENET0PTPPDELAYREQRX = out Bool
    val EMIOENET0PTPPDELAYRESPRX = out Bool
    val EMIOENET0SOFRX = out Bool

    val EMIOENET1GMIIRXCLK = in Bool
    val EMIOENET1GMIICRS = in Bool
    val EMIOENET1GMIICOL = in Bool
    val EMIOENET1EXTINTIN = in Bool       
    val EMIOENET1GMIIRXD = in Bits(8 bits)
    val EMIOENET1GMIIRXER = in Bool
    val EMIOENET1GMIIRXDV = in Bool  
    val EMIOENET1GMIITXCLK = in Bool
    val EMIOENET1GMIITXD = out Bits(8 bits)
    val EMIOENET1GMIITXEN = out Bool
    val EMIOENET1GMIITXER = out Bool    
    val EMIOENET1MDIOMDC = out Bool
    val EMIOENET1MDIOI = in Bool
    val EMIOENET1MDIOO = out Bool
    val EMIOENET1MDIOTN = out Bool  
    val EMIOENET1PTPSYNCFRAMETX = out Bool
    val EMIOENET1PTPDELAYREQTX = out Bool
    val EMIOENET1PTPPDELAYREQTX = out Bool
    val EMIOENET1PTPPDELAYRESPTX = out Bool
    val EMIOENET1SOFTX = out Bool
    val EMIOENET1PTPSYNCFRAMERX = out Bool
    val EMIOENET1PTPDELAYREQRX = out Bool
    val EMIOENET1PTPPDELAYREQRX = out Bool
    val EMIOENET1PTPPDELAYRESPRX = out Bool
    val EMIOENET1SOFRX = out Bool
        
    // 2 x triple timers
    val EMIOTTC0WAVEO = out Bits(3 bits)
    val EMIOTTC0CLKI = in Bits(3 bits)
    val EMIOTTC1WAVEO = out Bits(3 bits)
    val EMIOTTC1CLKI = in Bits(3 bits)
        
    // Watch Dog
    val EMIOWDTCLKI = in Bool
    val EMIOWDTRSTO = out Bool

    // 2x SPI
    val EMIOSPI0SCLKI = in Bool
    val EMIOSPI0SCLKO = out Bool
    val EMIOSPI0SCLKTN = out Bool
    val EMIOSPI0MI = in Bool
    val EMIOSPI0MO = out Bool
    val EMIOSPI0MOTN = out Bool
    val EMIOSPI0SI = in Bool
    val EMIOSPI0SO = out  Bool
    val EMIOSPI0STN = out Bool
    val EMIOSPI0SSIN = in Bool
    val EMIOSPI0SSON = out Bits(3 bits)
    val EMIOSPI0SSNTN = out Bool

    val EMIOSPI1SCLKI = in Bool
    val EMIOSPI1SCLKO = out Bool
    val EMIOSPI1SCLKTN = out Bool
    val EMIOSPI1MI = in Bool
    val EMIOSPI1MO = out Bool
    val EMIOSPI1MOTN = out Bool
    val EMIOSPI1SI = in Bool
    val EMIOSPI1SO = out  Bool
    val EMIOSPI1STN = out Bool
    val EMIOSPI1SSIN = in Bool
    val EMIOSPI1SSON = out Bits(3 bits)
    val EMIOSPI1SSNTN = out Bool

    // 2x I2C
    val EMIOI2C0SCLI = in Bool
    val EMIOI2C0SCLO = out Bool
    val EMIOI2C0SCLTN = out Bool
    val EMIOI2C0SDAI = in Bool
    val EMIOI2C0SDAO = out Bool
    val EMIOI2C0SDATN = out Bool

    val EMIOI2C1SCLI = in Bool
    val EMIOI2C1SCLO = out Bool
    val EMIOI2C1SCLTN = out Bool
    val EMIOI2C1SDAI = in Bool
    val EMIOI2C1SDAO = out Bool
    val EMIOI2C1SDATN = out Bool

    // 2x CAN
    val EMIOCAN0PHYTX = out Bool
    val EMIOCAN0PHYRX = in Bool
    val EMIOCAN1PHYTX = out Bool
    val EMIOCAN1PHYRX = in Bool

    // 2XUART
    val EMIOUART0TX = out Bool
    val EMIOUART0RX = in Bool
    val EMIOUART0CTSN = in Bool
    val EMIOUART0RTSN = out Bool
    val EMIOUART0DSRN = in Bool
    val EMIOUART0DCDN = in Bool
    val EMIOUART0RIN = in Bool
    val EMIOUART0DTRN = out Bool

    val EMIOUART1TX = out Bool
    val EMIOUART1RX = in Bool
    val EMIOUART1CTSN = in Bool
    val EMIOUART1RTSN = out Bool
    val EMIOUART1DSRN = in Bool
    val EMIOUART1DCDN = in Bool
    val EMIOUART1RIN = in Bool
    val EMIOUART1DTRN = out Bool

        
    // 2x SDIO
    val EMIOSDIO0CLK = out Bool
    val EMIOSDIO0CLKFB = in Bool
    val EMIOSDIO0CMDO = out Bool
    val EMIOSDIO0CMDI = in Bool
    val EMIOSDIO0CMDTN = out Bool
    val EMIOSDIO0DATAI = in Bits(4 bits)
    val EMIOSDIO0DATAO = out Bits(4 bits)
    val EMIOSDIO0DATATN = out Bits(4 bits)
    val EMIOSDIO0CDN = in Bool
    val EMIOSDIO0WP = in Bool
    val EMIOSDIO0LED = out Bool
    val EMIOSDIO0BUSPOW = out Bool
    val EMIOSDIO0BUSVOLT = out Bits(3 bits)

    val EMIOSDIO1CLK = out Bool
    val EMIOSDIO1CLKFB = in Bool
    val EMIOSDIO1CMDO = out Bool
    val EMIOSDIO1CMDI = in Bool
    val EMIOSDIO1CMDTN = out Bool
    val EMIOSDIO1DATAI = in Bits(4 bits)
    val EMIOSDIO1DATAO = out Bits(4 bits)
    val EMIOSDIO1DATATN = out Bits(4 bits)
    val EMIOSDIO1CDN = in Bool
    val EMIOSDIO1WP = in Bool
    val EMIOSDIO1LED = out Bool
    val EMIOSDIO1BUSPOW = out Bool
    val EMIOSDIO1BUSVOLT = out Bits(3 bits)

    // gpio 
    val EMIOGPIOI = in Bits(64 bits)
    val EMIOGPIOO = out Bits(64 bits)
    val EMIOGPIOTN = out Bits(64 bits)

    // Multiplexed I/O
    val MIO = inout(Analog(Bits(54 bits)))

    // FTPORT (trace)
    val EMIOTRACECLK = in Bool
    val EMIOTRACECTL = out Bool   
    val EMIOTRACEDATA = out Bits(32 bits)

    // pjtag
    val EMIOPJTAGTCK = in Bool
    val EMIOPJTAGTMS = in Bool
    val EMIOPJTAGTDI = in Bool
    val EMIOPJTAGTDO = out Bool 
    val EMIOPJTAGTDTN = out Bool
    
    // 2x USB 
    val EMIOUSB0PORTINDCTL = out Bits(2 bits)
    val EMIOUSB0VBUSPWRFAULT = in Bool
    val EMIOUSB0VBUSPWRSELECT = out Bool
    val EMIOUSB1PORTINDCTL = out Bits(2 bits)
    val EMIOUSB1VBUSPWRFAULT = in Bool
    val EMIOUSB1VBUSPWRSELECT = out Bool

    // SRAM
    val EMIOSRAMINTIN = in Bool

    // PL Clock and Reset
    val FCLKCLK = out Bits(4 bits)
    val FCLKCLKTRIGN = in Bits(4 bits)
    val FCLKRESETN = out Bits(4 bits)

    // PL idle
    val FPGAIDLEN = in Bool
    val EVENTEVENTI = in Bool

    // events
    val EVENTEVENTO = out Bool
    val EVENTSTANDBYWFE = out Bits(2 bits)
    val EVENTSTANDBYWFI = out Bits(2 bits)

    // DDR ARB
    val DDRARB = in Bits(4 bits)

    // PL Trace
    val FTMDTRACEINDATA	= in Bits(32 bits)       
    val FTMDTRACEINVALID = in Bool
    val FTMDTRACEINCLOCK = in Bool	       
    val FTMDTRACEINATID = in Bits(4 bits)

    // Cross Trigger
    val FTMTF2PTRIG = in Bits(4 bits)
    val FTMTF2PTRIGACK = out Bits(4 bits)
    val FTMTF2PDEBUG = in Bits(32 bits)
    val FTMTP2FTRIG = out Bits(4 bits)
    val FTMTP2FTRIGACK = in Bits(4 bits) 
    val FTMTP2FDEBUG = out Bits(32 bits)

    // 4x DMA
    val DMA0DAREADY = in Bool
    val DMA0DATYPE = out Bits(2 bits) 
    val DMA0DAVALID = out Bool
    val DMA0DRLAST = in Bool
    val DMA0DRREADY = out Bool
    val DMA0DRTYPE = in Bits(2 bits)
    val DMA0DRVALID = in Bool
    val DMA0ACLK = in Bool
      
    val DMA0RSTN = out Bool 

    val DMA1DAREADY = in Bool
    val DMA1DATYPE = out Bits(2 bits) 
    val DMA1DAVALID = out Bool
    val DMA1DRLAST = in Bool
    val DMA1DRREADY = out Bool
    val DMA1DRTYPE = in Bits(2 bits)
    val DMA1DRVALID = in Bool
    val DMA1ACLK = in Bool
    val DMA1RSTN = out Bool 
      
    val DMA2DAREADY = in Bool
    val DMA2DATYPE = out Bits(2 bits) 
    val DMA2DAVALID = out Bool
    val DMA2DRLAST = in Bool
    val DMA2DRREADY = out Bool
    val DMA2DRTYPE = in Bits(2 bits)
    val DMA2DRVALID = in Bool
    val DMA2ACLK = in Bool
    val DMA2RSTN = out Bool 
      
    val DMA3DAREADY = in Bool
    val DMA3DAVALID = out Bool
    val DMA3DATYPE = out Bits(2 bits) 
    val DMA3DRLAST = in Bool
    val DMA3DRREADY = out Bool
    val DMA3DRTYPE = in Bits(2 bits)
    val DMA3DRVALID = in Bool
    val DMA3ACLK = in Bool   
    val DMA3RSTN = out Bool 

    // Interrupts
    val IRQF2P = in Bits(20 bits)
    val IRQP2F = out Bits(29 bits)

    // Misc
    val PSCLK = inout(Analog(Bool))
    val PSPORB = inout(Analog(Bool))
    val PSSRSTB = inout(Analog(Bool))

    // DDR
    val DDRA = inout(Analog(Bits(15 bits)))
    val DDRBA = inout(Analog(Bits(3 bits)))
    val DDRCASB = inout(Analog(Bool))
    val DDRCKE = inout(Analog(Bool))
    val DDRCKN = inout(Analog(Bool))
    val DDRCKP = inout(Analog(Bool))
    val DDRCSB = inout(Analog(Bool))
    val DDRDM = inout(Analog(Bits(4 bits)))
    val DDRDQ = inout(Analog(Bits(32 bits)))
    val DDRDQSN = inout(Analog(Bits(4 bits)))
    val DDRDQSP = inout(Analog(Bits(4 bits)))
    val DDRDRSTB = inout(Analog(Bool))
    val DDRODT = inout(Analog(Bool))
    val DDRRASB = inout(Analog(Bool)) 
    val DDRVRN = inout(Analog(Bool))
    val DDRVRP = inout(Analog(Bool))
    val DDRWEB = inout(Analog(Bool))
      
    // 2 x PS Master PL Slave General Purpose Axi3 ports
    val MAXIGP0ACLK = in Bool
    val MAXIGP0AWID = out UInt(12 bits)
    val MAXIGP0AWADDR = out UInt(32 bits)
    val MAXIGP0AWLEN = out UInt(4 bits)
    val MAXIGP0AWSIZE = out UInt(2 bits)
    val MAXIGP0AWBURST = out Bits(2 bits)
    val MAXIGP0AWLOCK = out Bits(2 bits)
    val MAXIGP0AWCACHE = out Bits(4 bits)
    val MAXIGP0AWPROT = out Bits(3 bits)
    val MAXIGP0AWVALID = out Bool
    val MAXIGP0AWREADY = in Bool
    val MAXIGP0WID = out UInt(12 bits)
    val MAXIGP0WDATA = out Bits(32 bits)
    val MAXIGP0WSTRB = out Bits(4 bits)
    val MAXIGP0WLAST = out Bool
    val MAXIGP0WVALID = out Bool 
    val MAXIGP0WREADY = in Bool
    val MAXIGP0BID = in UInt(12 bits)
    val MAXIGP0BRESP = in Bits(2 bits)
    val MAXIGP0BVALID = in Bool
    val MAXIGP0BREADY = out Bool
    val MAXIGP0ARID = out UInt(12 bits)
    val MAXIGP0ARADDR = out UInt(32 bits)
    val MAXIGP0ARLEN = out UInt(4 bits)
    val MAXIGP0ARSIZE = out UInt(2 bits)
    val MAXIGP0ARBURST = out Bits(2 bits)
    val MAXIGP0ARLOCK = out Bits(2 bits)
    val MAXIGP0ARCACHE = out Bits(4 bits)
    val MAXIGP0ARPROT = out Bits(3 bits)
    val MAXIGP0ARVALID = out Bool
    val MAXIGP0ARREADY = in Bool   
    val MAXIGP0RID = in UInt(12 bits)
    val MAXIGP0RDATA = in Bits(32 bits)
    val MAXIGP0RRESP = in Bits(2 bits)
    val MAXIGP0RLAST = in Bool
    val MAXIGP0RVALID = in Bool
    val MAXIGP0RREADY = out Bool
    val MAXIGP0AWQOS = out Bits(4 bits)
    val MAXIGP0ARQOS = out Bits(4 bits)
    val MAXIGP0ARESETN = out Bool
      
    val MAXIGP1ACLK = in Bool
    val MAXIGP1AWID = out UInt(12 bits)
    val MAXIGP1AWADDR = out UInt(32 bits)
    val MAXIGP1AWLEN = out UInt(4 bits)
    val MAXIGP1AWSIZE = out UInt(2 bits)
    val MAXIGP1AWBURST = out Bits(2 bits)
    val MAXIGP1AWLOCK = out Bits(2 bits)
    val MAXIGP1AWCACHE = out Bits(4 bits)
    val MAXIGP1AWPROT = out Bits(3 bits)
    val MAXIGP1AWVALID = out Bool
    val MAXIGP1AWREADY = in Bool
    val MAXIGP1WID = out UInt(12 bits)
    val MAXIGP1WDATA = out Bits(32 bits)
    val MAXIGP1WSTRB = out Bits(4 bits)
    val MAXIGP1WLAST = out Bool
    val MAXIGP1WVALID = out Bool 
    val MAXIGP1WREADY = in Bool
    val MAXIGP1BID = in UInt(12 bits)
    val MAXIGP1BRESP = in Bits(2 bits)
    val MAXIGP1BVALID = in Bool
    val MAXIGP1BREADY = out Bool
    val MAXIGP1ARID = out UInt(12 bits)
    val MAXIGP1ARADDR = out UInt(32 bits)
    val MAXIGP1ARLEN = out UInt(4 bits)
    val MAXIGP1ARSIZE = out UInt(2 bits)
    val MAXIGP1ARBURST = out Bits(2 bits)
    val MAXIGP1ARLOCK = out Bits(2 bits)
    val MAXIGP1ARCACHE = out Bits(4 bits)
    val MAXIGP1ARPROT = out Bits(3 bits)
    val MAXIGP1ARVALID = out Bool
    val MAXIGP1ARREADY = in Bool   
    val MAXIGP1RID = in UInt(12 bits)
    val MAXIGP1RDATA = in Bits(32 bits)
    val MAXIGP1RRESP = in Bits(2 bits)
    val MAXIGP1RLAST = in Bool
    val MAXIGP1RVALID = in Bool
    val MAXIGP1RREADY = out Bool
    val MAXIGP1AWQOS = out Bits(4 bits)
    val MAXIGP1ARQOS = out Bits(4 bits)
    val MAXIGP1ARESETN = out Bool

    // 2 x PS Slave PL Master General Purpose Axi3 ports
    val SAXIGP0ACLK = in Bool
    val SAXIGP0AWID = in UInt(6 bits)
    val SAXIGP0AWADDR = in UInt(32 bits)
    val SAXIGP0AWLEN = in UInt(4 bits)
    val SAXIGP0AWSIZE = in UInt(2 bits)
    val SAXIGP0AWBURST = in Bits(2 bits)
    val SAXIGP0AWLOCK = in Bits(2 bits)
    val SAXIGP0AWCACHE = in Bits(4 bits)
    val SAXIGP0AWPROT = in Bits(3 bits)
    val SAXIGP0AWVALID = in Bool
    val SAXIGP0AWREADY = out Bool
    val SAXIGP0WID = out UInt(6 bits)
    val SAXIGP0WDATA = in Bits(32 bits)
    val SAXIGP0WSTRB = in Bits(4 bits)
    val SAXIGP0WLAST = in Bool
    val SAXIGP0WVALID = in Bool 
    val SAXIGP0WREADY = out Bool
    val SAXIGP0BID = out UInt(6 bits)
    val SAXIGP0BRESP = out Bits(2 bits)
    val SAXIGP0BVALID = out Bool
    val SAXIGP0BREADY = in Bool
    val SAXIGP0ARID = in UInt(6 bits)
    val SAXIGP0ARADDR = in UInt(32 bits)
    val SAXIGP0ARLEN = in UInt(4 bits)
    val SAXIGP0ARSIZE = in UInt(2 bits)
    val SAXIGP0ARBURST = in Bits(2 bits)
    val SAXIGP0ARLOCK = in Bits(2 bits)
    val SAXIGP0ARCACHE = in Bits(4 bits)
    val SAXIGP0ARPROT = in Bits(3 bits)
    val SAXIGP0ARVALID = in Bool
    val SAXIGP0ARREADY = out Bool   
    val SAXIGP0RID = out UInt(6 bits)
    val SAXIGP0RDATA = out Bits(32 bits)
    val SAXIGP0RRESP = out Bits(2 bits)
    val SAXIGP0RLAST = out Bool
    val SAXIGP0RVALID = out Bool
    val SAXIGP0RREADY = in Bool
    val SAXIGP0AWQOS = in Bits(4 bits)
    val SAXIGP0ARQOS = in Bits(4 bits)
    val SAXIGP0ARESETN = out Bool
/*
    val SAXIGP1ACLK = in Bool
    val SAXIGP1AWID = in Bits(6 bits)
    val SAXIGP1AWADDR = in Bits(32 bits)
    val SAXIGP1AWLEN = in Bits(4 bits)
    val SAXIGP1AWSIZE = in Bits(2 bits)
    val SAXIGP1AWBURST = in Bits(2 bits)
    val SAXIGP1AWLOCK = in Bits(2 bits)
    val SAXIGP1AWCACHE = in Bits(4 bits)
    val SAXIGP1AWPROT = in Bits(3 bits)
    val SAXIGP1AWVALID = in Bool
    val SAXIGP1AWREADY = out Bool
    val SAXIGP1WID = out Bits(6 bits)
    val SAXIGP1WDATA = in Bits(32 bits)
    val SAXIGP1WSTRB = in Bits(4 bits)
    val SAXIGP1WLAST = in Bool
    val SAXIGP1WVALID = in Bool 
    val SAXIGP1WREADY = out Bool
    val SAXIGP1BID = out Bits(6 bits)
    val SAXIGP1BRESP = out Bits(2 bits)
    val SAXIGP1BVALID = out Bool
    val SAXIGP1BREADY = in Bool
    val SAXIGP1ARID = in Bits(6 bits)
    val SAXIGP1ARADDR = in Bits(32 bits)
    val SAXIGP1ARLEN = in Bits(4 bits)
    val SAXIGP1ARSIZE = in Bits(2 bits)
    val SAXIGP1ARBURST = in Bits(2 bits)
    val SAXIGP1ARLOCK = in Bits(2 bits)
    val SAXIGP1ARCACHE = in Bits(4 bits)
    val SAXIGP1ARPROT = in Bits(3 bits)
    val SAXIGP1ARVALID = in Bool
    val SAXIGP1ARREADY = out Bool   
    val SAXIGP1RID = out Bits(6 bits)
    val SAXIGP1RDATA = out Bits(32 bits)
    val SAXIGP1RRESP = out Bits(2 bits)
    val SAXIGP1RLAST = out Bool
    val SAXIGP1RVALID = out Bool
    val SAXIGP1RREADY = in Bool
    val SAXIGP1AWQOS = in Bits(4 bits)
    val SAXIGP1ARQOS = in Bits(4 bits)
    val SAXIGP1ARESET = out Bool

    // 1x PS Slave PL Master ACP Axi3 port
    val SAXIACPACLK = in Bool
    val SAXIACPAWID = in Bits(3 bits)
    val SAXIACPAWADDR = in Bits(32 bits)
    val SAXIACPAWLEN = in Bits(4 bits)
    val SAXIACPAWSIZE = in Bits(2 bits)
    val SAXIACPAWBURST = in Bits(2 bits)
    val SAXIACPAWLOCK = in Bits(2 bits)
    val SAXIACPAWCACHE = in Bits(4 bits)
    val SAXIACPAWPROT = in Bits(3 bits)
    val SAXIACPAWVALID = in Bool
    val SAXIACPAWREADY = out Bool
    val SAXIACPWID = out Bits(3 bits)
    val SAXIACPWDATA = in Bits(64 bits)
    val SAXIACPWSTRB = in Bits(8 bits)
    val SAXIACPWLAST = in Bool
    val SAXIACPWVALID = in Bool 
    val SAXIACPWREADY = out Bool
    val SAXIACPBID = out Bits(3 bits)
    val SAXIACPBRESP = out Bits(2 bits)
    val SAXIACPBVALID = out Bool
    val SAXIACPBREADY = in Bool
    val SAXIACPARID = in Bits(3 bits)
    val SAXIACPARADDR = in Bits(32 bits)
    val SAXIACPARLEN = in Bits(4 bits)
    val SAXIACPARSIZE = in Bits(2 bits)
    val SAXIACPARBURST = in Bits(2 bits)
    val SAXIACPARLOCK = in Bits(2 bits)
    val SAXIACPARCACHE = in Bits(4 bits)
    val SAXIACPARPROT = in Bits(3 bits)
    val SAXIACPARVALID = in Bool
    val SAXIACPARREADY = out Bool   
    val SAXIACPRID = out Bits(3 bits)
    val SAXIACPRDATA = out Bits(64 bits)
    val SAXIACPRRESP = out Bits(2 bits)
    val SAXIACPRLAST = out Bool
    val SAXIACPRVALID = out Bool
    val SAXIACPRREADY = in Bool
    val SAXIACPAWQOS = in Bits(4 bits)
    val SAXIACPARQOS = in Bits(4 bits)
    val SAXIACPAWUSER = in Bits(5 bits)
    val SAXIACPARUSER = in Bits(5 bits)    
    val SAXIACPARESETN = out Bool

    // 4x PS Slave PL Master High Performance Axi3 port
    val SAXIHP0ACLK = in Bool
    val SAXIHP0AWID = in Bits(6 bits)
    val SAXIHP0AWADDR = in Bits(32 bits)
    val SAXIHP0AWLEN = in Bits(4 bits)
    val SAXIHP0AWSIZE = in Bits(2 bits)
    val SAXIHP0AWBURST = in Bits(2 bits)
    val SAXIHP0AWLOCK = in Bits(2 bits)
    val SAXIHP0AWCACHE = in Bits(4 bits)
    val SAXIHP0AWPROT = in Bits(3 bits)
    val SAXIHP0AWVALID = in Bool
    val SAXIHP0AWREADY = out Bool
    val SAXIHP0WID = out Bits(6 bits)
    val SAXIHP0WDATA = in Bits(64 bits)
    val SAXIHP0WSTRB = in Bits(8 bits)
    val SAXIHP0WLAST = in Bool
    val SAXIHP0WVALID = in Bool 
    val SAXIHP0WREADY = out Bool
    val SAXIHP0BID = out Bits(6 bits)
    val SAXIHP0BRESP = out Bits(2 bits)
    val SAXIHP0BVALID = out Bool
    val SAXIHP0BREADY = in Bool
    val SAXIHP0ARID = in Bits(6 bits)
    val SAXIHP0ARADDR = in Bits(32 bits)
    val SAXIHP0ARLEN = in Bits(4 bits)
    val SAXIHP0ARSIZE = in Bits(2 bits)
    val SAXIHP0ARBURST = in Bits(2 bits)
    val SAXIHP0ARLOCK = in Bits(2 bits)
    val SAXIHP0ARCACHE = in Bits(4 bits)
    val SAXIHP0ARPROT = in Bits(3 bits)
    val SAXIHP0ARVALID = in Bool
    val SAXIHP0ARREADY = out Bool   
    val SAXIHP0RID = out Bits(6 bits)
    val SAXIHP0RDATA = out Bits(64 bits)
    val SAXIHP0RRESP = out Bits(2 bits)
    val SAXIHP0RLAST = out Bool
    val SAXIHP0RVALID = out Bool
    val SAXIHP0RREADY = in Bool
    val SAXIHP0AWQOS = in Bits(4 bits)
    val SAXIHP0ARQOS = in Bits(4 bits)
    val SAXIHP0WCOUNT = out Bits(8 bits)
    val SAXIHP0WACOUNT = out Bits(8 bits)
    val SAXIHP0WRISSUEcaplen = in Bool
    val SAXIHP0RCOUNT = out Bits(8 bits)
    val SAXIHP0RACOUNT = out Bits(8 bits)
    val SAXIHP0RDISSUECAPLEN = in Bool

    val SAXIHP1ACLK = in Bool
    val SAXIHP1AWID = in Bits(6 bits)
    val SAXIHP1AWADDR = in Bits(32 bits)
    val SAXIHP1AWLEN = in Bits(4 bits)
    val SAXIHP1AWSIZE = in Bits(2 bits)
    val SAXIHP1AWBURST = in Bits(2 bits)
    val SAXIHP1AWLOCK = in Bits(2 bits)
    val SAXIHP1AWCACHE = in Bits(4 bits)
    val SAXIHP1AWPROT = in Bits(3 bits)
    val SAXIHP1AWVALID = in Bool
    val SAXIHP1AWREADY = out Bool
    val SAXIHP1WID = out Bits(6 bits)
    val SAXIHP1WDATA = in Bits(64 bits)
    val SAXIHP1WSTRB = in Bits(8 bits)
    val SAXIHP1WLAST = in Bool
    val SAXIHP1WVALID = in Bool 
    val SAXIHP1WREADY = out Bool
    val SAXIHP1BID = out Bits(6 bits)
    val SAXIHP1BRESP = out Bits(2 bits)
    val SAXIHP1BVALID = out Bool
    val SAXIHP1BREADY = in Bool
    val SAXIHP1ARID = in Bits(6 bits)
    val SAXIHP1ARADDR = in Bits(32 bits)
    val SAXIHP1ARLEN = in Bits(4 bits)
    val SAXIHP1ARSIZE = in Bits(2 bits)
    val SAXIHP1ARBURST = in Bits(2 bits)
    val SAXIHP1ARLOCK = in Bits(2 bits)
    val SAXIHP1ARCACHE = in Bits(4 bits)
    val SAXIHP1ARPROT = in Bits(3 bits)
    val SAXIHP1ARVALID = in Bool
    val SAXIHP1ARREADY = out Bool   
    val SAXIHP1RID = out Bits(6 bits)
    val SAXIHP1RDATA = out Bits(64 bits)
    val SAXIHP1RRESP = out Bits(2 bits)
    val SAXIHP1RLAST = out Bool
    val SAXIHP1RVALID = out Bool
    val SAXIHP1RREADY = in Bool
    val SAXIHP1AWQOS = in Bits(4 bits)
    val SAXIHP1ARQOS = in Bits(4 bits)
    val SAXIHP1WCOUNT = out Bits(8 bits)
    val SAXIHP1WACOUNT = out Bits(8 bits)
    val SAXIHP1WRISSUEcaplen = in Bool
    val SAXIHP1RCOUNT = out Bits(8 bits)
    val SAXIHP1RACOUNT = out Bits(8 bits)
    val SAXIHP1RDISSUECAPLEN = in Bool

    val SAXIHP2ACLK = in Bool
    val SAXIHP2AWID = in Bits(6 bits)
    val SAXIHP2AWADDR = in Bits(32 bits)
    val SAXIHP2AWLEN = in Bits(4 bits)
    val SAXIHP2AWSIZE = in Bits(2 bits)
    val SAXIHP2AWBURST = in Bits(2 bits)
    val SAXIHP2AWLOCK = in Bits(2 bits)
    val SAXIHP2AWCACHE = in Bits(4 bits)
    val SAXIHP2AWPROT = in Bits(3 bits)
    val SAXIHP2AWVALID = in Bool
    val SAXIHP2AWREADY = out Bool
    val SAXIHP2WID = out Bits(6 bits)
    val SAXIHP2WDATA = in Bits(64 bits)
    val SAXIHP2WSTRB = in Bits(8 bits)
    val SAXIHP2WLAST = in Bool
    val SAXIHP2WVALID = in Bool 
    val SAXIHP2WREADY = out Bool
    val SAXIHP2BID = out Bits(6 bits)
    val SAXIHP2BRESP = out Bits(2 bits)
    val SAXIHP2BVALID = out Bool
    val SAXIHP2BREADY = in Bool
    val SAXIHP2ARID = in Bits(6 bits)
    val SAXIHP2ARADDR = in Bits(32 bits)
    val SAXIHP2ARLEN = in Bits(4 bits)
    val SAXIHP2ARSIZE = in Bits(2 bits)
    val SAXIHP2ARBURST = in Bits(2 bits)
    val SAXIHP2ARLOCK = in Bits(2 bits)
    val SAXIHP2ARCACHE = in Bits(4 bits)
    val SAXIHP2ARPROT = in Bits(3 bits)
    val SAXIHP2ARVALID = in Bool
    val SAXIHP2ARREADY = out Bool   
    val SAXIHP2RID = out Bits(6 bits)
    val SAXIHP2RDATA = out Bits(64 bits)
    val SAXIHP2RRESP = out Bits(2 bits)
    val SAXIHP2RLAST = out Bool
    val SAXIHP2RVALID = out Bool
    val SAXIHP2RREADY = in Bool
    val SAXIHP2AWQOS = in Bits(4 bits)
    val SAXIHP2ARQOS = in Bits(4 bits)
    val SAXIHP2WCOUNT = out Bits(8 bits)
    val SAXIHP2WACOUNT = out Bits(8 bits)
    val SAXIHP2WRISSUEcaplen = in Bool
    val SAXIHP2RCOUNT = out Bits(8 bits)
    val SAXIHP2RACOUNT = out Bits(8 bits)
    val SAXIHP2RDISSUECAPLEN = in Bool

    val SAXIHP3ACLK = in Bool
    val SAXIHP3AWID = in Bits(6 bits)
    val SAXIHP3AWADDR = in Bits(32 bits)
    val SAXIHP3AWLEN = in Bits(4 bits)
    val SAXIHP3AWSIZE = in Bits(2 bits)
    val SAXIHP3AWBURST = in Bits(2 bits)
    val SAXIHP3AWLOCK = in Bits(2 bits)
    val SAXIHP3AWCACHE = in Bits(4 bits)
    val SAXIHP3AWPROT = in Bits(3 bits)
    val SAXIHP3AWVALID = in Bool
    val SAXIHP3AWREADY = out Bool
    val SAXIHP3WID = out Bits(6 bits)
    val SAXIHP3WDATA = in Bits(64 bits)
    val SAXIHP3WSTRB = in Bits(8 bits)
    val SAXIHP3WLAST = in Bool
    val SAXIHP3WVALID = in Bool 
    val SAXIHP3WREADY = out Bool
    val SAXIHP3BID = out Bits(6 bits)
    val SAXIHP3BRESP = out Bits(2 bits)
    val SAXIHP3BVALID = out Bool
    val SAXIHP3BREADY = in Bool
    val SAXIHP3ARID = in Bits(6 bits)
    val SAXIHP3ARADDR = in Bits(32 bits)
    val SAXIHP3ARLEN = in Bits(4 bits)
    val SAXIHP3ARSIZE = in Bits(2 bits)
    val SAXIHP3ARBURST = in Bits(2 bits)
    val SAXIHP3ARLOCK = in Bits(2 bits)
    val SAXIHP3ARCACHE = in Bits(4 bits)
    val SAXIHP3ARPROT = in Bits(3 bits)
    val SAXIHP3ARVALID = in Bool
    val SAXIHP3ARREADY = out Bool   
    val SAXIHP3RID = out Bits(6 bits)
    val SAXIHP3RDATA = out Bits(64 bits)
    val SAXIHP3RRESP = out Bits(2 bits)
    val SAXIHP3RLAST = out Bool
    val SAXIHP3RVALID = out Bool
    val SAXIHP3RREADY = in Bool
    val SAXIHP3AWQOS = in Bits(4 bits)
    val SAXIHP3ARQOS = in Bits(4 bits)
    val SAXIHP3WCOUNT = out Bits(8 bits)
    val SAXIHP3WACOUNT = out Bits(8 bits)
    val SAXIHP3WRISSUECAPLEN = in Bool
    val SAXIHP3RCOUNT = out Bits(8 bits)
    val SAXIHP3RACOUNT = out Bits(8 bits)
    val SAXIHP3RDISSUECAPLEN = in Bool*/
  }
}