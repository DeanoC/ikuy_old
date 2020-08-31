module ps7_wrapper
(
  `ifdef USE_CAN0
    output wire CAN0_PHY_TX,
    input wire CAN0_PHY_RX,
  `endif

  `ifdef USE_CAN1
    output wire CAN1_PHY_TX,  
    input wire CAN1_PHY_RX,
  `endif

  // Ethernet wires
  `ifdef USE_ENET0
    output wire ENET0_GMII_TX_EN,
    output wire ENET0_GMII_TX_ER,
    output wire ENET0_MDIO_MDC,
    output wire ENET0_MDIO_O,
    output wire ENET0_MDIO_T,
    output wire ENET0_PTP_DELAY_REQ_RX,
    output wire ENET0_PTP_DELAY_REQ_TX,
    output wire ENET0_PTP_PDELAY_REQ_RX,
    output wire ENET0_PTP_PDELAY_REQ_TX,
    output wire ENET0_PTP_PDELAY_RESP_RX,
    output wire ENET0_PTP_PDELAY_RESP_TX,
    output wire ENET0_PTP_SYNC_FRAME_RX,
    output wire ENET0_PTP_SYNC_FRAME_TX,
    output wire ENET0_SOF_RX,
    output wire ENET0_SOF_TX,
    output wire [7:0] ENET0_GMII_TXD,  
    input wire ENET0_GMII_COL,
    input wire ENET0_GMII_CRS,
    input wire ENET0_GMII_RX_CLK,
    input wire ENET0_GMII_RX_DV,
    input wire ENET0_GMII_RX_ER,
    input wire ENET0_GMII_TX_CLK,
    input wire ENET0_MDIO_I,
    input wire ENET0_EXT_INTIN,
    input wire [7:0] ENET0_GMII_RXD,  
  `endif
  `ifdef USE_ENET1
    output wire ENET1_GMII_TX_EN,
    output wire ENET1_GMII_TX_ER,
    output wire ENET1_MDIO_MDC,
    output wire ENET1_MDIO_O,
    output wire ENET1_MDIO_T,
    output wire ENET1_PTP_DELAY_REQ_RX,
    output wire ENET1_PTP_DELAY_REQ_TX,
    output wire ENET1_PTP_PDELAY_REQ_RX,
    output wire ENET1_PTP_PDELAY_REQ_TX,
    output wire ENET1_PTP_PDELAY_RESP_RX,
    output wire ENET1_PTP_PDELAY_RESP_TX,
    output wire ENET1_PTP_SYNC_FRAME_RX,
    output wire ENET1_PTP_SYNC_FRAME_TX,
    output wire ENET1_SOF_RX,
    output wire ENET1_SOF_TX,
    output wire [7:0] ENET1_GMII_TXD,  
    input wire ENET1_GMII_COL,
    input wire ENET1_GMII_CRS,
    input wire ENET1_GMII_RX_CLK,
    input wire ENET1_GMII_RX_DV,
    input wire ENET1_GMII_RX_ER,
    input wire ENET1_GMII_TX_CLK,
    input wire ENET1_MDIO_I,
    input wire ENET1_EXT_INTIN,
    input wire [7:0] ENET1_GMII_RXD,  
  `endif

  // 4 DMA ports
  `ifdef USE_DMA0
    input wire DMA0_ACLK,
    output wire DMA0_RESET,
    output wire [1:0] DMA0_DATYPE,  
    input wire [1:0] DMA0_DRTYPE,
    output wire DMA0_DAVALID,
    output wire DMA0_DRREADY,
    input wire DMA0_DAREADY,
    input wire DMA0_DRLAST,
    input wire DMA0_DRVALID,
  `endif
  `ifdef USE_DMA1
    input wire DMA1_ACLK,
    output wire DMA1_RESET,
    output wire [1:0] DMA1_DATYPE,  
    input wire [1:0] DMA1_DRTYPE,
    output wire DMA1_DAVALID,
    output wire DMA1_DRREADY,
    input wire DMA1_DAREADY,
    input wire DMA1_DRLAST,
    input wire DMA1_DRVALID,
  `endif
  `ifdef USE_DMA2
    input wire DMA2_ACLK,
    output wire DMA2_RESET,  
    output wire [1:0] DMA2_DATYPE,  
    input wire [1:0] DMA2_DRTYPE,
    output wire DMA2_DAVALID,
    output wire DMA2_DRREADY,
    input wire DMA2_DAREADY,
    input wire DMA2_DRLAST,
    input wire DMA2_DRVALID,
  `endif
  `ifdef USE_DMA3
    input wire DMA3_ACLK,
    output wire DMA3_RESET,  
    output wire [1:0] DMA3_DATYPE,    
    input wire [1:0] DMA3_DRTYPE,
    output wire DMA3_DRREADY,
    input wire DMA3_DAREADY,
    input wire DMA3_DRLAST,
    input wire DMA3_DRVALID,  
    output wire DMA3_DAVALID,
  `endif

  // tristate GPIO wires + 54 MIO
  `ifdef USE_GPIO
    input wire [63:0] GPIO_I,
    output wire [63:0] GPIO_O,
    output wire [63:0] GPIO_T,
  `endif
  `ifdef USE_MIO
    inout wire [53:0] MIO,
  `endif

  // 2x I2C buses
  `ifdef USE_I2C0
    input wire I2C0_SDA_I,
    output wire I2C0_SDA_O,
    output wire I2C0_SDA_T,
    input wire I2C0_SCL_I,
    output wire I2C0_SCL_O,
    output wire I2C0_SCL_T,
  `endif
  `ifdef USE_I2C1
    input wire I2C1_SDA_I,
    output wire I2C1_SDA_O,
    output wire I2C1_SDA_T,
    input wire I2C1_SCL_I,
    output wire I2C1_SCL_O,
    output wire I2C1_SCL_T,
  `endif

  // 2x SDIO 
  `ifdef USE_SDIO0
    output wire SDIO0_CLK,
    input wire SDIO0_CLK_FB,
    output wire SDIO0_CMD_O,
    input wire SDIO0_CMD_I,
    output wire SDIO0_CMD_T,
    input wire [3:0] SDIO0_DATA_I,
    output wire [3:0] SDIO0_DATA_O,
    output wire [3:0] SDIO0_DATA_T,
    output wire SDIO0_LED,
    input wire SDIO0_CDN,
    input wire SDIO0_WP,  
    output wire SDIO0_BUSPOW,
    output wire [2:0] SDIO0_BUSVOLT,
  `endif
  `ifdef USE_SDIO1
    output wire SDIO1_CLK,
    input wire SDIO1_CLK_FB,
    output wire SDIO1_CMD_O,
    input wire SDIO1_CMD_I,
    output wire SDIO1_CMD_T,
    input wire [3:0] SDIO1_DATA_I,
    output wire [3:0] SDIO1_DATA_O,
    output wire [3:0] SDIO1_DATA_T,
    output wire SDIO1_LED,
    input wire SDIO1_CDN,
    input wire SDIO1_WP,
    output wire SDIO1_BUSPOW,
    output wire [2:0] SDIO1_BUSVOLT,
  `endif

  // 2x SPI
  `ifdef USE_SPI0
    input wire SPI0_SCLK_I,
    output  wire SPI0_SCLK_O,
    output wire SPI0_SCLK_T,
    input wire SPI0_MOSI_I,
    output wire SPI0_MOSI_O,
    output wire SPI0_MOSI_T,
    input wire SPI0_MISO_I,
    output wire SPI0_MISO_O,
    output wire SPI0_MISO_T,
    input wire SPI0_SS_I,
    output wire SPI0_SS_O,
    output wire SPI0_SS1_O,
    output wire SPI0_SS2_O,
    output wire SPI0_SS_T,
  `endif
  `ifdef USE_SPI1
    input wire SPI1_SCLK_I,
    output wire SPI1_SCLK_O,
    output wire SPI1_SCLK_T,
    input wire SPI1_MOSI_I,
    output wire SPI1_MOSI_O,
    output wire SPI1_MOSI_T,
    input wire SPI1_MISO_I,
    output wire SPI1_MISO_O,
    output wire SPI1_MISO_T,
    input wire SPI1_SS_I,
    output wire SPI1_SS_O,
    output wire SPI1_SS1_O,
    output wire SPI1_SS2_O,
    output wire SPI1_SS_T,
  `endif
  // 2 x UART
  `ifdef USE_UART0
    output wire UART0_DTRN,
    output wire UART0_RTSN, 
    output wire UART0_TX,
    input wire UART0_CTSN,
    input wire UART0_DCDN,
    input wire UART0_DSRN,
    input wire UART0_RIN,
    input wire UART0_RX,
  `endif
  `ifdef USE_UART1
    output wire UART1_DTRN,
    output wire UART1_RTSN,  
    output wire UART1_TX,
    input wire UART1_CTSN,
    input wire UART1_DCDN,
    input wire UART1_DSRN,
    input wire UART1_RIN,
    input wire UART1_RX,
  `endif

  // trace, debug and jtag
  `ifdef USE_JTAG
    input wire PJTAG_TCK,
    input wire PJTAG_TMS,
    input wire PJTAG_TDI,
    output wire PJTAG_TDO,
  `endif
  `ifdef USE_TTC0
    output wire TTC0_WAVE0_OUT,
    output wire TTC0_WAVE1_OUT,
    output wire TTC0_WAVE2_OUT,
    input wire TTC0_CLK0_IN,
    input wire TTC0_CLK1_IN,
    input wire TTC0_CLK2_IN,
  `endif
  `ifdef USE_TTC1
  output wire TTC1_WAVE0_OUT,
  output wire TTC1_WAVE1_OUT,
  output wire TTC1_WAVE2_OUT,
  input wire TTC1_CLK0_IN,
  input wire TTC1_CLK1_IN,
  input wire TTC1_CLK2_IN,
  `endif
  `ifdef USE_TRACE
    input wire TRACE_CLK,
    output wire TRACE_CTL,
    output wire [31:0] TRACE_DATA,
    output wire TRACE_CLK_OUT,

    input wire [31:0] FTMD_TRACEIN_DATA,
    input wire FTMD_TRACEIN_VALID,
    input wire FTMD_TRACEIN_CLK,
    input wire [3:0]  FTMD_TRACEIN_ATID,
    input wire FTMT_F2P_TRIG_0,
    output wire FTMT_F2P_TRIGACK_0,
    input wire FTMT_F2P_TRIG_1,
    output wire FTMT_F2P_TRIGACK_1,
    input wire FTMT_F2P_TRIG_2,
    output wire FTMT_F2P_TRIGACK_2,
    input wire FTMT_F2P_TRIG_3,
    output wire FTMT_F2P_TRIGACK_3,
    input wire [31:0] FTMT_F2P_DEBUG,
    input wire FTMT_P2F_TRIGACK_0,
    output wire FTMT_P2F_TRIG_0,
    input wire FTMT_P2F_TRIGACK_1,
    output wire FTMT_P2F_TRIG_1,
    input wire FTMT_P2F_TRIGACK_2,
    output wire FTMT_P2F_TRIG_2,
    input wire FTMT_P2F_TRIGACK_3,
    output wire FTMT_P2F_TRIG_3,
    output wire [31:0] FTMT_P2F_DEBUG,
  `endif
  `ifdef USE_WATCHDOG
    input wire WDT_CLK_IN,
    output wire WDT_RST_OUT,
  `endif
  `ifdef USE_USB0
    output wire [1:0] USB0_PORT_INDCTL,
    output wire USB0_VBUS_PWRSELECT,
    input wire USB0_VBUS_PWRFAULT,
  `endif
  `ifdef USE_USB1
    output wire [1:0]  USB1_PORT_INDCTL,
    output wire USB1_VBUS_PWRSELECT,
    input wire USB1_VBUS_PWRFAULT,
  `endif

  `ifdef USE_INTERRUPTS
    // events and interrupts
    output wire IRQ_P2F_DMAC_ABORT,
    output wire IRQ_P2F_DMAC0,
    output wire IRQ_P2F_DMAC1,
    output wire IRQ_P2F_DMAC2,
    output wire IRQ_P2F_DMAC3,
    output wire IRQ_P2F_DMAC4,
    output wire IRQ_P2F_DMAC5,
    output wire IRQ_P2F_DMAC6,
    output wire IRQ_P2F_DMAC7,
    output wire IRQ_P2F_SMC,
    output wire IRQ_P2F_QSPI,
    output wire IRQ_P2F_CTI,
    output wire IRQ_P2F_GPIO,
    output wire IRQ_P2F_USB0,
    output wire IRQ_P2F_ENET0,
    output wire IRQ_P2F_ENET_WAKE0,
    output wire IRQ_P2F_SDIO0,
    output wire IRQ_P2F_I2C0,
    output wire IRQ_P2F_SPI0,
    output wire IRQ_P2F_UART0,
    output wire IRQ_P2F_CAN0,
    output wire IRQ_P2F_USB1,
    output wire IRQ_P2F_ENET1,
    output wire IRQ_P2F_ENET_WAKE1,
    output wire IRQ_P2F_SDIO1,
    output wire IRQ_P2F_I2C1,
    output wire IRQ_P2F_SPI1,
    output wire IRQ_P2F_UART1,
    output wire IRQ_P2F_CAN1,
    input  wire Core0_nFIQ,
    input  wire Core0_nIRQ,
    input  wire Core1_nFIQ,
    input  wire Core1_nIRQ,
    input  wire [15:0] IRQ_F2P,
    input wire SRAM_INTIN,
  `endif
  `ifdef USE_PS_EVENTS
    output wire EVENT_EVENTO,
    input wire EVENT_EVENTI,   
    output wire [1:0] EVENT_STANDBYWFE,
    output wire [1:0] EVENT_STANDBYWFI,
  `endif
  `ifdef USE_FPGA_IDLE
    input wire FPGA_IDLE,
  `endif

  // 4 frabric clks
  `ifdef USE_FCLK0
    output wire FCLK0_CLK,
    output wire FCLK0_RESET,
  `endif
  `ifdef USE_FCLK1
    output wire FCLK1_CLK,
    output wire FCLK1_RESET,
  `endif
  `ifdef USE_FCLK2
    output wire FCLK2_CLK,
    output wire FCLK2_RESET,
  `endif
  `ifdef USE_FCLK3
    output wire FCLK3_CLK,
    output wire FCLK3_RESET,
  `endif

  // AXI3+ (3 with some optional Axi4 wires)
  // direction is from PS point of view
  // 2 PS Master General Purpose ports
  // 2 PS Slave General Purpose ports
  // 1 PS Slave ACP port
  // 4 PS Slave High Performance ports

  `ifdef PS_MASTER_AXI_GP0
    //M_AXI_GP0  
    output wire M_AXI_GP0_ARESET,
    output wire M_AXI_GP0_ARVALID,
    output wire M_AXI_GP0_AWVALID,
    output wire M_AXI_GP0_BREADY,
    output wire M_AXI_GP0_RREADY,
    output wire M_AXI_GP0_WLAST,
    output wire M_AXI_GP0_WVALID,
    output wire [11:0] M_AXI_GP0_ARID,
    output wire [11:0] M_AXI_GP0_AWID,
    output wire [11:0] M_AXI_GP0_WID,
    output wire [1:0] M_AXI_GP0_ARBURST,
    output wire [1:0] M_AXI_GP0_ARLOCK,
    output wire [1:0] M_AXI_GP0_ARSIZE,
    output wire [1:0] M_AXI_GP0_AWBURST,
    output wire [1:0] M_AXI_GP0_AWLOCK,
    output wire [1:0] M_AXI_GP0_AWSIZE,
    output wire [2:0] M_AXI_GP0_ARPROT,
    output wire [2:0] M_AXI_GP0_AWPROT,
    output wire [31:0] M_AXI_GP0_ARADDR,
    output wire [31:0] M_AXI_GP0_AWADDR,
    output wire [31:0] M_AXI_GP0_WDATA,
    output wire [3:0] M_AXI_GP0_ARCACHE,
    output wire [3:0] M_AXI_GP0_ARLEN,
    output wire [3:0] M_AXI_GP0_ARQOS,
    output wire [3:0] M_AXI_GP0_AWCACHE,
    output wire [3:0] M_AXI_GP0_AWLEN,
    output wire [3:0] M_AXI_GP0_AWQOS,
    output wire [3:0] M_AXI_GP0_WSTRB,
    input wire M_AXI_GP0_ACLK,
    input wire M_AXI_GP0_ARREADY,
    input wire M_AXI_GP0_AWREADY,
    input wire M_AXI_GP0_BVALID,
    input wire M_AXI_GP0_RLAST,
    input wire M_AXI_GP0_RVALID,
    input wire M_AXI_GP0_WREADY,
    input wire [11:0] M_AXI_GP0_BID,
    input wire [11:0] M_AXI_GP0_RID,
    input wire [1:0] M_AXI_GP0_BRESP,
    input wire [1:0] M_AXI_GP0_RRESP,
    input wire [31:0] M_AXI_GP0_RDATA,  
  `endif
  `ifdef PS_MASTER_AXI_GP1
    //M_AXI_GP1
    output wire M_AXI_GP1_ARESET,
    output wire M_AXI_GP1_ARVALID,
    output wire M_AXI_GP1_AWVALID,
    output wire M_AXI_GP1_BREADY,
    output wire M_AXI_GP1_RREADY,
    output wire M_AXI_GP1_WLAST,
    output wire M_AXI_GP1_WVALID,
    output wire [11:0] M_AXI_GP1_ARID,
    output wire [11:0] M_AXI_GP1_AWID,
    output wire [11:0] M_AXI_GP1_WID,
    output wire [1:0] M_AXI_GP1_ARBURST,
    output wire [1:0] M_AXI_GP1_ARLOCK,
    output wire [1:0] M_AXI_GP1_ARSIZE,
    output wire [1:0] M_AXI_GP1_AWBURST,
    output wire [1:0] M_AXI_GP1_AWLOCK,
    output wire [1:0] M_AXI_GP1_AWSIZE,
    output wire [2:0] M_AXI_GP1_ARPROT,
    output wire [2:0] M_AXI_GP1_AWPROT,
    output wire [31:0] M_AXI_GP1_ARADDR,
    output wire [31:0] M_AXI_GP1_AWADDR,
    output wire [31:0] M_AXI_GP1_WDATA,
    output wire [3:0] M_AXI_GP1_ARCACHE,
    output wire [3:0] M_AXI_GP1_ARLEN,
    output wire [3:0] M_AXI_GP1_ARQOS,
    output wire [3:0] M_AXI_GP1_AWCACHE,
    output wire [3:0] M_AXI_GP1_AWLEN,
    output wire [3:0] M_AXI_GP1_AWQOS,
    output wire [3:0] M_AXI_GP1_WSTRB,
    input wire M_AXI_GP1_ACLK,
    input wire M_AXI_GP1_ARREADY,
    input wire M_AXI_GP1_AWREADY,
    input wire M_AXI_GP1_BVALID,
    input wire M_AXI_GP1_RLAST,
    input wire M_AXI_GP1_RVALID,
    input wire M_AXI_GP1_WREADY,  
    input wire [11:0] M_AXI_GP1_BID,
    input wire [11:0] M_AXI_GP1_RID,
    input wire [1:0] M_AXI_GP1_BRESP,
    input wire [1:0] M_AXI_GP1_RRESP,
    input wire [31:0] M_AXI_GP1_RDATA,
  `endif
  `ifdef PS_SLAVE_AXI_GP0
    // S_AXI_GP0
    output wire S_AXI_GP0_ARESET,
    output wire S_AXI_GP0_ARREADY,
    output wire S_AXI_GP0_AWREADY,
    output wire S_AXI_GP0_BVALID,
    output wire S_AXI_GP0_RLAST,
    output wire S_AXI_GP0_RVALID,
    output wire S_AXI_GP0_WREADY,  
    output wire [1:0] S_AXI_GP0_BRESP,
    output wire [1:0] S_AXI_GP0_RRESP,
    output wire [31:0] S_AXI_GP0_RDATA,
    output wire [5:0] S_AXI_GP0_BID,
    output wire [5:0] S_AXI_GP0_RID,
    input wire S_AXI_GP0_ACLK,
    input wire S_AXI_GP0_ARVALID,
    input wire S_AXI_GP0_AWVALID,
    input wire S_AXI_GP0_BREADY,
    input wire S_AXI_GP0_RREADY,
    input wire S_AXI_GP0_WLAST,
    input wire S_AXI_GP0_WVALID,
    input wire [1:0] S_AXI_GP0_ARBURST,
    input wire [1:0] S_AXI_GP0_ARLOCK,
    input wire [1:0] S_AXI_GP0_ARSIZE,
    input wire [1:0] S_AXI_GP0_AWBURST,
    input wire [1:0] S_AXI_GP0_AWLOCK,
    input wire [1:0] S_AXI_GP0_AWSIZE,
    input wire [2:0] S_AXI_GP0_ARPROT,
    input wire [2:0] S_AXI_GP0_AWPROT,
    input wire [31:0] S_AXI_GP0_ARADDR,
    input wire [31:0] S_AXI_GP0_AWADDR,
    input wire [31:0] S_AXI_GP0_WDATA,
    input wire [3:0] S_AXI_GP0_ARCACHE,
    input wire [3:0] S_AXI_GP0_ARLEN,
    input wire [3:0] S_AXI_GP0_ARQOS,
    input wire [3:0] S_AXI_GP0_AWCACHE,
    input wire [3:0] S_AXI_GP0_AWLEN,
    input wire [3:0] S_AXI_GP0_AWQOS,
    input wire [3:0] S_AXI_GP0_WSTRB,
    input wire [5:0] S_AXI_GP0_ARID,
    input wire [5:0] S_AXI_GP0_AWID,
    input wire [5:0] S_AXI_GP0_WID,  
  `endif
  `ifdef PS_SLAVE_AXI_GP1
    // S_AXI_GP1
    output wire S_AXI_GP1_ARESET,
    output wire S_AXI_GP1_ARREADY,
    output wire S_AXI_GP1_AWREADY,
    output wire S_AXI_GP1_BVALID,
    output wire S_AXI_GP1_RLAST,
    output wire S_AXI_GP1_RVALID,
    output wire S_AXI_GP1_WREADY,  
    output wire [1:0] S_AXI_GP1_BRESP,
    output wire [1:0] S_AXI_GP1_RRESP,
    output wire [31:0] S_AXI_GP1_RDATA,
    output wire [5:0] S_AXI_GP1_BID,
    output wire [5:0] S_AXI_GP1_RID,
    input wire S_AXI_GP1_ACLK,
    input wire S_AXI_GP1_ARVALID,
    input wire S_AXI_GP1_AWVALID,
    input wire S_AXI_GP1_BREADY,
    input wire S_AXI_GP1_RREADY,
    input wire S_AXI_GP1_WLAST,
    input wire S_AXI_GP1_WVALID,
    input wire [1:0] S_AXI_GP1_ARBURST,
    input wire [1:0] S_AXI_GP1_ARLOCK,
    input wire [1:0] S_AXI_GP1_ARSIZE,
    input wire [1:0] S_AXI_GP1_AWBURST,
    input wire [1:0] S_AXI_GP1_AWLOCK,
    input wire [1:0] S_AXI_GP1_AWSIZE,
    input wire [2:0] S_AXI_GP1_ARPROT,
    input wire [2:0] S_AXI_GP1_AWPROT,
    input wire [31:0] S_AXI_GP1_ARADDR,
    input wire [31:0] S_AXI_GP1_AWADDR,
    input wire [31:0] S_AXI_GP1_WDATA,
    input wire [3:0] S_AXI_GP1_ARCACHE,
    input wire [3:0] S_AXI_GP1_ARLEN,
    input wire [3:0] S_AXI_GP1_ARQOS,
    input wire [3:0] S_AXI_GP1_AWCACHE,
    input wire [3:0] S_AXI_GP1_AWLEN,
    input wire [3:0] S_AXI_GP1_AWQOS,
    input wire [3:0] S_AXI_GP1_WSTRB,
    input wire [5:0] S_AXI_GP1_ARID,
    input wire [5:0] S_AXI_GP1_AWID,
    input wire [5:0] S_AXI_GP1_WID, 
  `endif
  `ifdef PS_SLAVE_AXI_ACP
    //S_AXI_ACP
    output wire S_AXI_ACP_ARESET,
    output wire S_AXI_ACP_ARREADY,
    output wire S_AXI_ACP_AWREADY,
    output wire S_AXI_ACP_BVALID,
    output wire S_AXI_ACP_RLAST,
    output wire S_AXI_ACP_RVALID,
    output wire S_AXI_ACP_WREADY,  
    output wire [1:0] S_AXI_ACP_BRESP,
    output wire [1:0] S_AXI_ACP_RRESP,
    output wire [2 : 0] S_AXI_ACP_BID,
    output wire [2 : 0] S_AXI_ACP_RID,
    output wire [63:0] S_AXI_ACP_RDATA,
    input wire S_AXI_ACP_ACLK,
    input wire S_AXI_ACP_ARVALID,
    input wire S_AXI_ACP_AWVALID,
    input wire S_AXI_ACP_BREADY,
    input wire S_AXI_ACP_RREADY,
    input wire S_AXI_ACP_WLAST,
    input wire S_AXI_ACP_WVALID,
    input wire [2:0] S_AXI_ACP_ARID,
    input wire [2:0] S_AXI_ACP_ARPROT,
    input wire [2:0] S_AXI_ACP_AWID,
    input wire [2:0] S_AXI_ACP_AWPROT,
    input wire [2:0] S_AXI_ACP_WID,
    input wire [31:0] S_AXI_ACP_ARADDR,
    input wire [31:0] S_AXI_ACP_AWADDR,
    input wire [3:0] S_AXI_ACP_ARCACHE,
    input wire [3:0] S_AXI_ACP_ARLEN,
    input wire [3:0] S_AXI_ACP_ARQOS,
    input wire [3:0] S_AXI_ACP_AWCACHE,
    input wire [3:0] S_AXI_ACP_AWLEN,
    input wire [3:0] S_AXI_ACP_AWQOS,
    input wire [1:0] S_AXI_ACP_ARBURST,
    input wire [1:0] S_AXI_ACP_ARLOCK,
    input wire [1:0] S_AXI_ACP_ARSIZE,
    input wire [1:0] S_AXI_ACP_AWBURST,
    input wire [1:0] S_AXI_ACP_AWLOCK,
    input wire [1:0] S_AXI_ACP_AWSIZE,
    input wire [4:0] S_AXI_ACP_ARUSER,
    input wire [4:0] S_AXI_ACP_AWUSER,
    input wire [63:0] S_AXI_ACP_WDATA,
    input wire [7:0] S_AXI_ACP_WSTRB, 
  `endif
  `ifdef PS_SLAVE_AXI_HP0
    // AXI HP0
    output wire S_AXI_HP0_ARESET,
    output wire S_AXI_HP0_ARREADY,
    output wire S_AXI_HP0_AWREADY,
    output wire S_AXI_HP0_BVALID,
    output wire S_AXI_HP0_RLAST,
    output wire S_AXI_HP0_RVALID,
    output wire S_AXI_HP0_WREADY,  
    output wire [1:0] S_AXI_HP0_BRESP,
    output wire [1:0] S_AXI_HP0_RRESP,
    output wire [5:0] S_AXI_HP0_BID,
    output wire [5:0] S_AXI_HP0_RID,
    output wire [63:0] S_AXI_HP0_RDATA,
    output wire [7:0] S_AXI_HP0_RCOUNT,
    output wire [7:0] S_AXI_HP0_WCOUNT,
    output wire [2:0] S_AXI_HP0_RACOUNT,
    output wire [5:0] S_AXI_HP0_WACOUNT,
    input wire S_AXI_HP0_ACLK,
    input wire S_AXI_HP0_ARVALID,
    input wire S_AXI_HP0_AWVALID,
    input wire S_AXI_HP0_BREADY,
    input wire S_AXI_HP0_RDISSUECAP1_EN,
    input wire S_AXI_HP0_RREADY,
    input wire S_AXI_HP0_WLAST,
    input wire S_AXI_HP0_WRISSUECAP1_EN,
    input wire S_AXI_HP0_WVALID,
    input wire [1:0] S_AXI_HP0_ARBURST,
    input wire [1:0] S_AXI_HP0_ARLOCK,
    input wire [1:0] S_AXI_HP0_ARSIZE,
    input wire [1:0] S_AXI_HP0_AWBURST,
    input wire [1:0] S_AXI_HP0_AWLOCK,
    input wire [1:0] S_AXI_HP0_AWSIZE,
    input wire [2:0] S_AXI_HP0_ARPROT,
    input wire [2:0] S_AXI_HP0_AWPROT,
    input wire [31:0] S_AXI_HP0_ARADDR,
    input wire [31:0] S_AXI_HP0_AWADDR,
    input wire [3:0] S_AXI_HP0_ARCACHE,
    input wire [3:0] S_AXI_HP0_ARLEN,
    input wire [3:0] S_AXI_HP0_ARQOS,
    input wire [3:0] S_AXI_HP0_AWCACHE,
    input wire [3:0] S_AXI_HP0_AWLEN,
    input wire [3:0] S_AXI_HP0_AWQOS,
    input wire [5:0] S_AXI_HP0_ARID,
    input wire [5:0] S_AXI_HP0_AWID,
    input wire [5:0] S_AXI_HP0_WID,
    input wire [63:0] S_AXI_HP0_WDATA,
    input wire [7:0] S_AXI_HP0_WSTRB,
  `endif
  `ifdef PS_SLAVE_AXI_HP1
    // AXI HP1
    output wire S_AXI_HP1_ARESET,
    output wire S_AXI_HP1_ARREADY,
    output wire S_AXI_HP1_AWREADY,
    output wire S_AXI_HP1_BVALID,
    output wire S_AXI_HP1_RLAST,
    output wire S_AXI_HP1_RVALID,
    output wire S_AXI_HP1_WREADY,  
    output wire [1:0] S_AXI_HP1_BRESP,
    output wire [1:0] S_AXI_HP1_RRESP,
    output wire [5:0] S_AXI_HP1_BID,
    output wire [5:0] S_AXI_HP1_RID,
    output wire [63:0] S_AXI_HP1_RDATA,
    output wire [7:0] S_AXI_HP1_RCOUNT,
    output wire [7:0] S_AXI_HP1_WCOUNT,
    output wire [2:0] S_AXI_HP1_RACOUNT,
    output wire [5:0] S_AXI_HP1_WACOUNT,
    input wire S_AXI_HP1_ACLK,
    input wire S_AXI_HP1_ARVALID,
    input wire S_AXI_HP1_AWVALID,
    input wire S_AXI_HP1_BREADY,
    input wire S_AXI_HP1_RDISSUECAP1_EN,
    input wire S_AXI_HP1_RREADY,
    input wire S_AXI_HP1_WLAST,
    input wire S_AXI_HP1_WRISSUECAP1_EN,
    input wire S_AXI_HP1_WVALID,
    input wire [1:0] S_AXI_HP1_ARBURST,
    input wire [1:0] S_AXI_HP1_ARLOCK,
    input wire [1:0] S_AXI_HP1_ARSIZE,
    input wire [1:0] S_AXI_HP1_AWBURST,
    input wire [1:0] S_AXI_HP1_AWLOCK,
    input wire [1:0] S_AXI_HP1_AWSIZE,
    input wire [2:0] S_AXI_HP1_ARPROT,
    input wire [2:0] S_AXI_HP1_AWPROT,
    input wire [31:0] S_AXI_HP1_ARADDR,
    input wire [31:0] S_AXI_HP1_AWADDR,
    input wire [3:0] S_AXI_HP1_ARCACHE,
    input wire [3:0] S_AXI_HP1_ARLEN,
    input wire [3:0] S_AXI_HP1_ARQOS,
    input wire [3:0] S_AXI_HP1_AWCACHE,
    input wire [3:0] S_AXI_HP1_AWLEN,
    input wire [3:0] S_AXI_HP1_AWQOS,
    input wire [5:0] S_AXI_HP1_ARID,
    input wire [5:0] S_AXI_HP1_AWID,
    input wire [5:0] S_AXI_HP1_WID,
    input wire [63:0] S_AXI_HP1_WDATA,
    input wire [7:0] S_AXI_HP1_WSTRB,
  `endif
  `ifdef PS_SLAVE_AXI_HP2
    // S_AXI_HP2
    output wire S_AXI_HP2_ARESET,
    output wire S_AXI_HP2_ARREADY,
    output wire S_AXI_HP2_AWREADY,
    output wire S_AXI_HP2_BVALID,
    output wire S_AXI_HP2_RLAST,
    output wire S_AXI_HP2_RVALID,
    output wire S_AXI_HP2_WREADY,  
    output wire [1:0] S_AXI_HP2_BRESP,
    output wire [1:0] S_AXI_HP2_RRESP,
    output wire [5:0] S_AXI_HP2_BID,
    output wire [5:0] S_AXI_HP2_RID,
    output wire [63:0] S_AXI_HP2_RDATA,
    output wire [7:0] S_AXI_HP2_RCOUNT,
    output wire [7:0] S_AXI_HP2_WCOUNT,
    output wire [2:0] S_AXI_HP2_RACOUNT,
    output wire [5:0] S_AXI_HP2_WACOUNT,
    input wire S_AXI_HP2_ACLK,
    input wire S_AXI_HP2_ARVALID,
    input wire S_AXI_HP2_AWVALID,
    input wire S_AXI_HP2_BREADY,
    input wire S_AXI_HP2_RDISSUECAP1_EN,
    input wire S_AXI_HP2_RREADY,
    input wire S_AXI_HP2_WLAST,
    input wire S_AXI_HP2_WRISSUECAP1_EN,
    input wire S_AXI_HP2_WVALID,
    input wire [1:0] S_AXI_HP2_ARBURST,
    input wire [1:0] S_AXI_HP2_ARLOCK,
    input wire [1:0] S_AXI_HP2_ARSIZE,
    input wire [1:0] S_AXI_HP2_AWBURST,
    input wire [1:0] S_AXI_HP2_AWLOCK,
    input wire [1:0] S_AXI_HP2_AWSIZE,
    input wire [2:0] S_AXI_HP2_ARPROT,
    input wire [2:0] S_AXI_HP2_AWPROT,
    input wire [31:0] S_AXI_HP2_ARADDR,
    input wire [31:0] S_AXI_HP2_AWADDR,
    input wire [3:0] S_AXI_HP2_ARCACHE,
    input wire [3:0] S_AXI_HP2_ARLEN,
    input wire [3:0] S_AXI_HP2_ARQOS,
    input wire [3:0] S_AXI_HP2_AWCACHE,
    input wire [3:0] S_AXI_HP2_AWLEN,
    input wire [3:0] S_AXI_HP2_AWQOS,
    input wire [5:0] S_AXI_HP2_ARID,
    input wire [5:0] S_AXI_HP2_AWID,
    input wire [5:0] S_AXI_HP2_WID,
    input wire [63:0] S_AXI_HP2_WDATA,
    input wire [7:0] S_AXI_HP2_WSTRB,
  `endif
  `ifdef PS_SLAVE_AXI_HP3
    // S_AXI_HP_3
    output wire S_AXI_HP3_ARESET,
    output wire S_AXI_HP3_ARREADY,
    output wire S_AXI_HP3_AWREADY,
    output wire S_AXI_HP3_BVALID,
    output wire S_AXI_HP3_RLAST,
    output wire S_AXI_HP3_RVALID,
    output wire S_AXI_HP3_WREADY,  
    output wire [1:0] S_AXI_HP3_BRESP,
    output wire [1:0] S_AXI_HP3_RRESP,
    output wire [5:0] S_AXI_HP3_BID,
    output wire [5:0] S_AXI_HP3_RID,
    output wire [63:0] S_AXI_HP3_RDATA,
    output wire [7:0] S_AXI_HP3_RCOUNT,
    output wire [7:0] S_AXI_HP3_WCOUNT,
    output wire [2:0] S_AXI_HP3_RACOUNT,
    output wire [5:0] S_AXI_HP3_WACOUNT,
    input wire S_AXI_HP3_ACLK,
    input wire S_AXI_HP3_ARVALID,
    input wire S_AXI_HP3_AWVALID,
    input wire S_AXI_HP3_BREADY,
    input wire S_AXI_HP3_RDISSUECAP1_EN,
    input wire S_AXI_HP3_RREADY,
    input wire S_AXI_HP3_WLAST,
    input wire S_AXI_HP3_WRISSUECAP1_EN,
    input wire S_AXI_HP3_WVALID,
    input wire [1:0] S_AXI_HP3_ARBURST,
    input wire [1:0] S_AXI_HP3_ARLOCK,
    input wire [1:0] S_AXI_HP3_ARSIZE,
    input wire [1:0] S_AXI_HP3_AWBURST,
    input wire [1:0] S_AXI_HP3_AWLOCK,
    input wire [1:0] S_AXI_HP3_AWSIZE,
    input wire [2:0] S_AXI_HP3_ARPROT,
    input wire [2:0] S_AXI_HP3_AWPROT,
    input wire [31:0] S_AXI_HP3_ARADDR,
    input wire [31:0] S_AXI_HP3_AWADDR,
    input wire [3:0] S_AXI_HP3_ARCACHE,
    input wire [3:0] S_AXI_HP3_ARLEN,
    input wire [3:0] S_AXI_HP3_ARQOS,
    input wire [3:0] S_AXI_HP3_AWCACHE,
    input wire [3:0] S_AXI_HP3_AWLEN,
    input wire [3:0] S_AXI_HP3_AWQOS,
    input wire [5:0] S_AXI_HP3_ARID,
    input wire [5:0] S_AXI_HP3_AWID,
    input wire [5:0] S_AXI_HP3_WID,
    input wire [63:0] S_AXI_HP3_WDATA,
    input wire [7:0] S_AXI_HP3_WSTRB,
  `endif
  // DDR
  input [3:0] DDR_ARB,
  inout wire DDR_CAS_n,
  inout wire DDR_CKE,
  inout wire DDR_Clk_n,
  inout wire DDR_Clk,
  inout wire DDR_CS_n,
  inout wire DDR_DRSTB,
  inout wire DDR_ODT,
  inout wire DDR_RAS_n,
  inout wire DDR_WEB,
  inout wire [2:0]  DDR_BankAddr,
  inout wire [14:0] DDR_Addr,
  inout wire DDR_VRN,
  inout wire DDR_VRP,
  inout wire [3:0]  DDR_DM,
  inout wire [31:0] DDR_DQ,
  inout wire [3:0]  DDR_DQS_n,
  inout wire [3:0]  DDR_DQS,

  // PS Clock and Reset wires
  inout wire PS_SOFT_RESET,
  inout wire PS_CLK,         
  inout wire PS_POWER_ON_RESET
  
);
  genvar i;

  `ifdef USE_MIO
    // ---------- MIO buffering
    wire [53:0] MIO_buffered;
    generate
      for (i=0; i < 54; i=i+1) begin
        BIBUF MIO_BIBUF (.PAD(MIO[i]), .IO(MIO_buffered[i]));
      end
    endgenerate
  `endif

  // ---------- jtag out buffer
  `ifdef USE_JTAG
    wire PJTAG_TDO_O;
    wire PJTAG_TDO_T;
    OBUFT PJTAG_TDO_BUFFER (.O(PJTAG_TDO), .I(PJTAG_TDO_O), .T(PJTAG_TDO_T) );
  `endif
  // ---------- FCLK buffers
  `ifdef USE_FCLK0
    wire FCLK0_CLK_buffered;
    BUFG FCLK0_CLK_BUFG (.I(FCLK0_CLK), .O(FCLK0_CLK_buffered));
  `endif
  `ifdef USE_FCLK1
    wire FCLK1_CLK_buffered;
    BUFG FCLK1_CLK_BUFG (.I(FCLK1_CLK), .O(FCLK1_CLK_buffered));
  `endif
  `ifdef USE_FCLK2
    wire FCLK2_CLK_buffered;
    BUFG FCLK2_CLK_BUFG (.I(FCLK2_CLK), .O(FCLK2_CLK_buffered));
  `endif
  `ifdef USE_FCLK3
    wire FCLK3_CLK_buffered;
    BUFG FCLK3_CLK_BUFG (.I(FCLK3_CLK), .O(FCLK3_CLK_buffered));
  `endif

  // ---------- misc PS signal buffers
  wire PS_SOFT_RESET_buffered;
  wire PS_CLK_buffered;
  wire PS_POWER_ON_RESET_buffered;
  BIBUF PS_SRSTB_BIBUF (.PAD(PS_SOFT_RESET), .IO(PS_SOFT_RESET_buffered));
  BIBUF PS_CLK_BIBUF (.PAD(PS_CLK), .IO(PS_CLK_buffered));
  BIBUF PS_PORB_BIBUF (.PAD(PS_POWER_ON_RESET), .IO(PS_POWER_ON_RESET_buffered));

  // ---------- DDR Buffering
  wire DDR_CAS_n_buffered;
  wire DDR_CKE_buffered;
  wire DDR_Clk_n_buffered;
  wire DDR_Clk_buffered;
  wire DDR_CS_n_buffered;
  wire DDR_DRSTB_buffered;
  wire DDR_ODT_buffered;
  wire DDR_RAS_n_buffered;
  wire DDR_WEB_buffered;
  wire [2 : 0] DDR_BankAddr_buffered;
  wire [14 : 0] DDR_Addr_buffered;
  wire DDR_VRN_buffered;
  wire DDR_VRP_buffered;
  wire [3 : 0] DDR_DM_buffered;
  wire [31 : 0] DDR_DQ_buffered;
  wire [3 : 0] DDR_DQS_n_buffered;
  wire [3 : 0] DDR_DQS_buffered;
  BIBUF DDR_CAS_n_BIBUF (.PAD(DDR_CAS_n), .IO(DDR_CAS_n_buffered));
  BIBUF DDR_CKE_BIBUF (.PAD(DDR_CKE), .IO(DDR_CKE_buffered));
  BIBUF DDR_Clk_n_BIBUF (.PAD(DDR_Clk_n), .IO(DDR_Clk_n_buffered));
  BIBUF DDR_Clk_BIBUF (.PAD(DDR_Clk), .IO(DDR_Clk_buffered));
  BIBUF DDR_CS_n_BIBUF (.PAD(DDR_CS_n), .IO(DDR_CS_n_buffered));
  BIBUF DDR_DRSTB_BIBUF (.PAD(DDR_DRSTB), .IO(DDR_DRSTB_buffered));
  BIBUF DDR_ODT_BIBUF (.PAD(DDR_ODT), .IO(DDR_ODT_buffered));
  BIBUF DDR_RAS_n_BIBUF (.PAD(DDR_RAS_n), .IO(DDR_RAS_n_buffered));
  BIBUF DDR_WEB_BIBUF (.PAD(DDR_WEB), .IO(DDR_WEB_buffered));
  BIBUF DDR_VRN_BIBUF (.PAD(DDR_VRN), .IO(DDR_VRN_buffered));
  BIBUF DDR_VRP_BIBUF (.PAD(DDR_VRP), .IO(DDR_VRP_buffered));
  generate
    for (i=0; i < 3; i=i+1) begin
      BIBUF DDR_BankAddr_BIBUF (.PAD(DDR_BankAddr[i]), .IO(DDR_BankAddr_buffered[i]));
    end
  endgenerate

  generate
    for (i=0; i < 15; i=i+1) begin
      BIBUF DDR_Addr_BIBUF (.PAD(DDR_Addr[i]), .IO(DDR_Addr_buffered[i]));
    end
  endgenerate

  generate
    for (i=0; i < 32; i=i+1) begin
      BIBUF DDR_DQ_BIBUF (.PAD(DDR_DQ[i]), .IO(DDR_DQ_buffered[i]));
    end
  endgenerate

  generate
    for (i=0; i < 4; i=i+1) begin
      BIBUF DDR_DQS_BIBUF (.PAD(DDR_DQS[i]), .IO(DDR_DQS_buffered[i]));
      BIBUF DDR_DQS_n_BIBUF (.PAD(DDR_DQS_n[i]), .IO(DDR_DQS_n_buffered[i]));
      BIBUF DDR_DM_BIBUF (.PAD(DDR_DM[i]), .IO(DDR_DM_buffered[i]));
    end
  endgenerate
  // ----------

  //  ---------- Tristate Inversion logic 
  `ifdef USE_ENET0
    wire ENET0_MDIO_T_n;
  `endif
  `ifdef USE_ENT0
    wire ENET1_MDIO_T_n;
  `endif
  `ifdef USE_DMA0
    wire DMA0_RESET_n;
  `endif
  `ifdef USE_DMA1
    wire DMA1_RESET_n;
  `endif
  `ifdef USE_DMA2
    wire DMA2_RESET_n;
  `endif
  `ifdef USE_DMA3
    wire DMA3_RESET_n;
  `endif

  `ifdef USE_GPIO
    wire [63:0] GPIO_T_n;
  `endif
  `ifdef USE_I2C0
    wire I2C0_SDA_T_n;
    wire I2C0_SCL_T_n;
  `endif
  `ifdef USE_I2C1
    wire I2C1_SDA_T_n;
    wire I2C1_SCL_T_n;
  `endif
  `ifdef USE_SDIO0
    wire SDIO0_CMD_T_n;
    wire [3:0] SDIO0_DATA_T_n;
  `endif
  `ifdef USE_SDIO1
    wire SDIO1_CMD_T_n;
    wire [3:0]SDIO1_DATA_T_n;
  `endif
  `ifdef USE_SPI0
    wire SPI0_SCLK_T_n;
    wire SPI0_MOSI_T_n;
    wire SPI0_MISO_T_n;
    wire SPI0_SS_T_n;
  `endif
  `ifdef USE_SPI1
    wire SPI1_SCLK_T_n;
    wire SPI1_MOSI_T_n;
    wire SPI1_MISO_T_n;
    wire SPI1_SS_T_n;
  `endif
  `ifdef USE_JTAG
    wire PJTAG_TDO_T_n;
  `endif
  `ifdef USE_FPGA_IDLE
    wire FPGA_IDLE_n;
  `endif
  `ifdef USE_FCLK0
    wire FCLK0_RESET_n;
  `endif
  `ifdef USE_FCLK1
    wire FCLK1_RESET_n;
  `endif
  `ifdef USE_FCLK2
    wire FCLK2_RESET_n;
  `endif
  `ifdef USE_FCLK3
    wire FCLK3_RESET_n;
  `endif

  `ifdef USE_ENET0
    assign ENET0_MDIO_T = ~ENET0_MDIO_T_n;
  `endif
  `ifdef USE_ENET1
    assign ENET1_MDIO_T = ~ENET1_MDIO_T_n;
  `endif
  `ifdef USE_DMA0
    assign DMA0_RESET = ~DMA0_RESET_n;
  `endif
  `ifdef USE_DMA1
    assign DMA1_RESET = ~DMA1_RESET_n;
  `endif
  `ifdef USE_DMA2
    assign DMA2_RESET = ~DMA2_RESET_n;
  `endif
  `ifdef USE_DMA3
    assign DMA3_RESET = ~DMA3_RESET_n;
  `endif

  `ifdef USE_GPIO
    assign GPIO_T = ~GPIO_T_n;
  `endif
  `ifdef USE_I2C0
    assign I2C0_SDA_T  = ~I2C0_SDA_T_n;
    assign I2C0_SCL_T  = ~I2C0_SCL_T_n;
  `endif
  `ifdef USE_I2C1
    assign I2C1_SDA_T  = ~I2C1_SDA_T_n;
    assign I2C1_SCL_T  = ~I2C1_SCL_T_n;
  `endif
  `ifdef USE_SDIO0
    assign SDIO0_CMD_T = ~SDIO0_CMD_T_n;
    assign SDIO0_DATA_T = ~SDIO0_DATA_T_n;
  `endif
  `ifdef USE_SDIO1
    assign SDIO1_CMD_T = ~SDIO1_CMD_T_n;
    assign SDIO1_DATA_T = ~SDIO1_DATA_T_n;
  `endif
  `ifdef USE_SPI0
    assign SPI0_SCLK_T = ~SPI0_SCLK_T_n;
    assign SPI0_MOSI_T = ~SPI0_MOSI_T_n;
    assign SPI0_MISO_T = ~SPI0_MISO_T_n;
    assign SPI0_SS_T   = ~SPI0_SS_T_n;
  `endif
  `ifdef USE_SPI1
    assign SPI1_SCLK_T = ~SPI1_SCLK_T_n;
    assign SPI1_MOSI_T = ~SPI1_MOSI_T_n;
    assign SPI1_MISO_T = ~SPI1_MISO_T_n;
    assign SPI1_SS_T   = ~SPI1_SS_T_n;
  `endif
  `ifdef USE_JTAG
    assign PJTAG_TDO_T = ~PJTAG_TDO_T_n;
  `endif
  `ifdef USE_FPGA_IDLE
    assign FPGA_IDLE_n = ~FPGA_IDLE;
  `endif
  `ifdef USE_FCLK0
    assign FCLK0_RESET = ~FCLK0_RESET_n;
  `endif
  `ifdef USE_FCLK1
    assign FCLK1_RESET = ~FCLK1_RESET_n;
  `endif
  `ifdef USE_FCLK2
    assign FCLK2_RESET = ~FCLK2_RESET_n;
  `endif
  `ifdef USE_FCLK3
    assign FCLK3_RESET = ~FCLK3_RESET_n;
  `endif

  // ----- Ethernet registers
  `ifdef USE_ENET0
    reg ENET0_GMII_TX_EN_reg = 'b0;
    reg ENET0_GMII_TX_ER_reg = 'b0;
    reg ENET0_GMII_COL_reg;
    reg ENET0_GMII_CRS_reg;
    reg ENET0_GMII_RX_DV_reg;
    reg ENET0_GMII_RX_ER_reg;
    reg [7:0] ENET0_GMII_RXD_reg;
    reg [7:0] ENET0_GMII_TXD_reg;

    wire ENET0_GMII_TX_EN_i;
    wire ENET0_GMII_TX_ER_i;
    wire ENET0_GMII_COL_i;
    wire ENET0_GMII_CRS_i;
    wire ENET0_GMII_RX_DV_i;
    wire ENET0_GMII_RX_ER_i;
    wire [7:0] ENET0_GMII_RXD_i;
    wire [7:0] ENET0_GMII_TXD_i;

    assign ENET0_GMII_TX_EN = ENET0_GMII_TX_EN_reg;
    assign ENET0_GMII_TX_ER = ENET0_GMII_TX_ER_reg;
    assign ENET0_GMII_TXD = ENET0_GMII_TXD_reg;
    assign ENET0_GMII_COL_o = ENET0_GMII_COL_reg;
    assign ENET0_GMII_CRS_o = ENET0_GMII_CRS_reg;
    assign ENET0_GMII_RX_DV_o = ENET0_GMII_RX_DV_reg;
    assign ENET0_GMII_RX_ER_o = ENET0_GMII_RX_ER_reg;
    assign ENET0_GMII_RXD_o = ENET0_GMII_RXD_reg;

    always @(posedge ENET0_GMII_TX_CLK ) begin
      ENET0_GMII_TX_EN_reg <= ENET0_GMII_TX_EN_i;
      ENET0_GMII_TX_ER_reg <= ENET0_GMII_TX_ER_i;
      ENET0_GMII_TXD_reg <= ENET0_GMII_TXD;
      ENET0_GMII_COL_reg <= ENET0_GMII_COL;
      ENET0_GMII_CRS_reg <= ENET0_GMII_CRS;
      ENET0_GMII_RX_DV_reg <= ENET0_GMII_RX_DV;
      ENET0_GMII_RX_ER_reg <= ENET0_GMII_RX_ER;
      ENET0_GMII_RXD_reg <= ENET0_GMII_RXD;
    end
  `endif
  `ifdef USE_ENET1
    reg ENET1_GMII_TX_EN_reg = 'b0;
    reg ENET1_GMII_TX_ER_reg = 'b0;
    reg ENET1_GMII_COL_reg;
    reg ENET1_GMII_CRS_reg;
    reg ENET1_GMII_RX_DV_reg;
    reg ENET1_GMII_RX_ER_reg;
    reg [7:0] ENET1_GMII_RXD_reg;
    reg [7:0] ENET1_GMII_TXD_reg;

    wire ENET1_GMII_TX_EN_i;
    wire ENET1_GMII_TX_ER_i;
    wire [7:0] ENET1_GMII_TXD_i;
    wire ENET1_GMII_COL_o;
    wire ENET1_GMII_CRS_o;
    wire ENET1_GMII_RX_DV_o;
    wire ENET1_GMII_RX_ER_o;
    wire [7:0] ENET1_GMII_RXD_o;

    assign ENET1_GMII_TX_EN = ENET1_GMII_TX_EN_reg;
    assign ENET1_GMII_TX_ER = ENET1_GMII_TX_ER_reg;
    assign ENET1_GMII_TXD = ENET1_GMII_TXD_reg;
    assign ENET1_GMII_COL_o = ENET1_GMII_COL_reg;
    assign ENET1_GMII_CRS_o = ENET1_GMII_CRS_reg;
    assign ENET1_GMII_RX_DV_o = ENET1_GMII_RX_DV_reg;
    assign ENET1_GMII_RX_ER_o = ENET1_GMII_RX_ER_reg;
    assign ENET1_GMII_RXD_o = ENET1_GMII_RXD_reg;

    always @(posedge ENET1_GMII_TX_CLK ) begin
      ENET1_GMII_TX_EN_reg <= ENET1_GMII_TX_EN_i;
      ENET1_GMII_TX_ER_reg <= ENET1_GMII_TX_ER_i;
      ENET1_GMII_TXD_reg <= ENET1_GMII_TXD_i;
      ENET1_GMII_COL_reg = ENET1_GMII_COL;
      ENET1_GMII_CRS_reg = ENET1_GMII_CRS;
      ENET1_GMII_RX_DV_reg = ENET1_GMII_RX_DV;
      ENET1_GMII_RX_ER_reg = ENET1_GMII_RX_ER;
      ENET1_GMII_RXD_reg = ENET1_GMII_RXD;
    end
  `endif
  // ----- Instaniate the raw PS7 core
  ps7_port_rename ps7_port_rename_i (
  `ifdef USE_CAN0
    .CAN0_PHY_TX(CAN0_PHY_TX),
    .CAN0_PHY_RX(CAN0_PHY_RX),
  `else
    .CAN0_PHY_RX(1'b0),
    .CAN0_PHY_TX(),
  `endif

  `ifdef USE_CAN1
    .CAN1_PHY_TX(CAN1_PHY_TX),
    .CAN1_PHY_RX(CAN1_PHY_RX),
  `else
    .CAN1_PHY_RX(1'b0),
    .CAN1_PHY_TX(),
  `endif

  `ifdef USE_ENET0
    .ENET0_GMII_TX_EN(ENET0_GMII_TX_EN_i),
    .ENET0_GMII_TX_ER(ENET0_GMII_TX_ER_i),
    .ENET0_GMII_RX_CLK(ENET0_GMII_RX_CLK),
    .ENET0_GMII_TX_CLK(ENET0_GMII_TX_CLK),
    .ENET0_GMII_TXD(ENET0_GMII_TXD_i),
    .ENET0_GMII_COL(ENET0_GMII_COL_o),
    .ENET0_GMII_CRS(ENET0_GMII_CRS_o),
    .ENET0_GMII_RX_DV(ENET0_GMII_RX_DV_o),
    .ENET0_GMII_RX_ER(ENET0_GMII_RX_ER_o),
    .ENET0_GMII_RXD(ENET0_GMII_RXD_o),
    .ENET0_MDIO_MDC(ENET0_MDIO_MDC),
    .ENET0_MDIO_O(ENET0_MDIO_O),
    .ENET0_MDIO_T_n(ENET0_MDIO_T_n),
    .ENET0_PTP_DELAY_REQ_RX(ENET0_PTP_DELAY_REQ_RX),
    .ENET0_PTP_DELAY_REQ_TX(ENET0_PTP_DELAY_REQ_TX),
    .ENET0_PTP_PDELAY_REQ_RX(ENET0_PTP_PDELAY_REQ_RX),
    .ENET0_PTP_PDELAY_REQ_TX(ENET0_PTP_PDELAY_REQ_TX),
    .ENET0_PTP_PDELAY_RESP_RX(ENET0_PTP_PDELAY_RESP_RX),
    .ENET0_PTP_PDELAY_RESP_TX(ENET0_PTP_PDELAY_RESP_TX),
    .ENET0_PTP_SYNC_FRAME_RX(ENET0_PTP_SYNC_FRAME_RX),
    .ENET0_PTP_SYNC_FRAME_TX(ENET0_PTP_SYNC_FRAME_TX),
    .ENET0_SOF_RX(ENET0_SOF_RX),
    .ENET0_SOF_TX(ENET0_SOF_TX),
    .ENET0_MDIO_I(ENET0_MDIO_I),
    .ENET0_EXT_INTIN(ENET0_EXT_INTIN),
  `else
    .ENET0_GMII_RX_CLK(1'b0),
    .ENET0_GMII_TX_CLK(1'b0),
    .ENET0_GMII_COL(1'b0),
    .ENET0_GMII_CRS(1'b0),
    .ENET0_GMII_RX_DV(1'b0),
    .ENET0_GMII_RX_ER(1'b0),
    .ENET0_GMII_RXD(8'b0),
    .ENET0_MDIO_I(1'b0),
    .ENET0_EXT_INTIN(1'b0),
    .ENET0_GMII_TX_EN(),
    .ENET0_GMII_TX_ER(),
    .ENET0_GMII_TXD(),
    .ENET0_MDIO_MDC(),
    .ENET0_MDIO_O(),
    .ENET0_MDIO_T_n(),
    .ENET0_PTP_DELAY_REQ_RX(),
    .ENET0_PTP_DELAY_REQ_TX(),
    .ENET0_PTP_PDELAY_REQ_RX(),
    .ENET0_PTP_PDELAY_REQ_TX(),
    .ENET0_PTP_PDELAY_RESP_RX(),
    .ENET0_PTP_PDELAY_RESP_TX(),
    .ENET0_PTP_SYNC_FRAME_RX(),
    .ENET0_PTP_SYNC_FRAME_TX(),
    .ENET0_SOF_RX(),
    .ENET0_SOF_TX(),
  `endif
  `ifdef USE_ENET1
    .ENET1_GMII_TX_EN(ENET1_GMII_TX_EN_i),
    .ENET1_GMII_TX_ER(ENET1_GMII_TX_ER_i),
    .ENET1_GMII_RX_CLK(ENET1_GMII_RX_CLK),
    .ENET1_GMII_TX_CLK(ENET1_GMII_TX_CLK),
    .ENET1_GMII_TXD(ENET1_GMII_TXD_i),
    .ENET1_GMII_COL(ENET1_GMII_COL_o),
    .ENET1_GMII_CRS(ENET1_GMII_CRS_o),
    .ENET1_GMII_RX_DV(ENET1_GMII_RX_DV_o),
    .ENET1_GMII_RX_ER(ENET1_GMII_RX_ER_o),
    .ENET1_GMII_RXD(ENET1_GMII_RXD_o),
    .ENET1_MDIO_MDC(ENET1_MDIO_MDC),
    .ENET1_MDIO_O(ENET1_MDIO_O),
    .ENET1_MDIO_T_n(ENET1_MDIO_T_n),
    .ENET1_PTP_DELAY_REQ_RX(ENET1_PTP_DELAY_REQ_RX),
    .ENET1_PTP_DELAY_REQ_TX(ENET1_PTP_DELAY_REQ_TX),
    .ENET1_PTP_PDELAY_REQ_RX(ENET1_PTP_PDELAY_REQ_RX),
    .ENET1_PTP_PDELAY_REQ_TX(ENET1_PTP_PDELAY_REQ_TX),
    .ENET1_PTP_PDELAY_RESP_RX(ENET1_PTP_PDELAY_RESP_RX),
    .ENET1_PTP_PDELAY_RESP_TX(ENET1_PTP_PDELAY_RESP_TX),
    .ENET1_PTP_SYNC_FRAME_RX(ENET1_PTP_SYNC_FRAME_RX),
    .ENET1_PTP_SYNC_FRAME_TX(ENET1_PTP_SYNC_FRAME_TX),
    .ENET1_SOF_RX(ENET1_SOF_RX),
    .ENET1_SOF_TX(ENET1_SOF_TX),
    .ENET1_MDIO_I(ENET1_MDIO_I),
    .ENET1_EXT_INTIN(ENET1_EXT_INTIN),
  `else
    .ENET1_GMII_RX_CLK(1'b0),
    .ENET1_GMII_TX_CLK(1'b0),
    .ENET1_GMII_COL(1'b0),
    .ENET1_GMII_CRS(1'b0),
    .ENET1_GMII_RX_DV(1'b0),
    .ENET1_GMII_RX_ER(1'b0),
    .ENET1_GMII_RXD(8'b0),
    .ENET1_MDIO_I(1'b0),
    .ENET1_EXT_INTIN(1'b0),
    .ENET1_GMII_TX_EN(),
    .ENET1_GMII_TX_ER(),
    .ENET1_GMII_TXD(),
    .ENET1_MDIO_MDC(),
    .ENET1_MDIO_O(),
    .ENET1_MDIO_T_n(),
    .ENET1_PTP_DELAY_REQ_RX(),
    .ENET1_PTP_DELAY_REQ_TX(),
    .ENET1_PTP_PDELAY_REQ_RX(),
    .ENET1_PTP_PDELAY_REQ_TX(),
    .ENET1_PTP_PDELAY_RESP_RX(),
    .ENET1_PTP_PDELAY_RESP_TX(),
    .ENET1_PTP_SYNC_FRAME_RX(),
    .ENET1_PTP_SYNC_FRAME_TX(),
    .ENET1_SOF_RX(),
    .ENET1_SOF_TX(),
  `endif
  `ifdef USE_DMA0
	  .DMA0_ACLK		            (DMA0_ACLK),
	  .DMA0_RESET_n		          (DMA0_RESET_n),  
	  .DMA0_DATYPE		          (DMA0_DATYPE),
	  .DMA0_DAVALID		          (DMA0_DAVALID),
	  .DMA0_DRREADY		          (DMA0_DRREADY),  
	  .DMA0_DAREADY		          (DMA0_DAREADY),
	  .DMA0_DRLAST		          (DMA0_DRLAST),
	  .DMA0_DRTYPE              (DMA0_DRTYPE),
	  .DMA0_DRVALID		          (DMA0_DRVALID),
  `else
	  .DMA0_ACLK		            (1'b0),
	  .DMA0_DAREADY		          (1'b0),
	  .DMA0_DRLAST		          (1'b0),
	  .DMA0_DRVALID		          (1'b0),
	  .DMA0_RESET_n		          (),  
	  .DMA0_DATYPE		          (),
	  .DMA0_DAVALID		          (),
	  .DMA0_DRREADY		          (),  
	  .DMA0_DRTYPE              (),
  `endif
  `ifdef USE_DMA1
	  .DMA1_ACLK		            (DMA1_ACLK),
	  .DMA1_RESET_n		          (DMA1_RESET_n),
	  .DMA1_DATYPE		          (DMA1_DATYPE),
	  .DMA1_DAVALID		          (DMA1_DAVALID),
	  .DMA1_DRREADY		          (DMA1_DRREADY),
	  .DMA1_DAREADY		          (DMA1_DAREADY),
	  .DMA1_DRLAST		          (DMA1_DRLAST),
	  .DMA1_DRTYPE              (DMA1_DRTYPE),  
	  .DMA1_DRVALID		          (DMA1_DRVALID),
  `else
	  .DMA1_ACLK		            (1'b0),
	  .DMA1_DAREADY		          (1'b0),
	  .DMA1_DRLAST		          (1'b0),
	  .DMA1_DRVALID		          (1'b0),
	  .DMA1_RESET_n		          (),  
	  .DMA1_DATYPE		          (),
	  .DMA1_DAVALID		          (),
	  .DMA1_DRREADY		          (),  
	  .DMA1_DRTYPE              (),
  `endif
  `ifdef USE_DMA2
	  .DMA2_ACLK		            (DMA2_ACLK),
	  .DMA2_RESET_n		          (DMA2_RESET_n),
	  .DMA2_DATYPE		          (DMA2_DATYPE),
	  .DMA2_DAVALID		          (DMA2_DAVALID),
	  .DMA2_DRREADY		          (DMA2_DRREADY),
	  .DMA2_DAREADY		          (DMA2_DAREADY),
	  .DMA2_DRLAST		          (DMA2_DRLAST),
	  .DMA2_DRTYPE              (DMA2_DRTYPE),    
	  .DMA2_DRVALID		          (DMA2_DRVALID),
  `else
	  .DMA2_ACLK		            (1'b0),
	  .DMA2_DAREADY		          (1'b0),
	  .DMA2_DRLAST		          (1'b0),
	  .DMA2_DRVALID		          (1'b0),
	  .DMA2_RESET_n		          (),  
	  .DMA2_DATYPE		          (),
	  .DMA2_DAVALID		          (),
	  .DMA2_DRREADY		          (),  
	  .DMA2_DRTYPE              (),
  `endif
  `ifdef USE_DMA3
	  .DMA3_ACLK		            (DMA3_ACLK),
	  .DMA3_RESET_n		          (DMA3_RESET_n),
	  .DMA3_DAREADY		          (DMA3_DAREADY),
	  .DMA3_DRLAST		          (DMA3_DRLAST),
	  .DMA3_DRTYPE              (DMA3_DRTYPE),
	  .DMA3_DRVALID		          (DMA3_DRVALID),
	  .DMA3_DATYPE		          (DMA3_DATYPE),
	  .DMA3_DAVALID		          (DMA3_DAVALID),
	  .DMA3_DRREADY		          (DMA3_DRREADY),
  `else
	  .DMA3_ACLK		            (1'b0),
	  .DMA3_DAREADY		          (1'b0),
	  .DMA3_DRLAST		          (1'b0),
	  .DMA3_DRVALID		          (1'b0),
	  .DMA3_RESET_n		          (),  
	  .DMA3_DATYPE		          (),
	  .DMA3_DAVALID		          (),
	  .DMA3_DRREADY		          (),  
	  .DMA3_DRTYPE              (),
  `endif
  `ifdef USE_GPIO
    .GPIO_I                   (GPIO_I),
    .GPIO_O                   (GPIO_O),
    .GPIO_T_n                 (GPIO_T_n),
  `else
    .GPIO_I                   (64'b0),
    .GPIO_O                   (),
    .GPIO_T_n                 (),
  `endif
  `ifdef USE_MIO
    .MIO                      (MIO_buffered),
  `else
    .MIO                      (),
  `endif

  `ifdef USE_I2C0
    .I2C0_SDA_I               (I2C0_SDA_I),
    .I2C0_SDA_O               (I2C0_SDA_O),
    .I2C0_SDA_T_n             (I2C0_SDA_T_n),
    .I2C0_SCL_I               (I2C0_SCL_I),
    .I2C0_SCL_O               (I2C0_SCL_O),
    .I2C0_SCL_T_n             (I2C0_SCL_T_n),
  `else
    .I2C0_SDA_I               (1'b0),
    .I2C0_SCL_I               (1'b0),
    .I2C0_SDA_O               (),
    .I2C0_SDA_T_n             (),
    .I2C0_SCL_O               (),
    .I2C0_SCL_T_n             (),
  `endif    
  `ifdef USE_I2C1
    .I2C1_SDA_I               (I2C1_SDA_I),
    .I2C1_SDA_O               (I2C1_SDA_O),
    .I2C1_SDA_T_n             (I2C1_SDA_T_n),
    .I2C1_SCL_I               (I2C1_SCL_I),
    .I2C1_SCL_O               (I2C1_SCL_O),
    .I2C1_SCL_T_n             (I2C1_SCL_T_n),
  `else
    .I2C1_SDA_I               (1'b0),
    .I2C1_SCL_I               (1'b0),
    .I2C1_SDA_O               (),
    .I2C1_SDA_T_n             (),
    .I2C1_SCL_O               (),
    .I2C1_SCL_T_n             (),
  `endif
  `ifdef USE_SDIO0
    .SDIO0_CLK                (SDIO0_CLK),
    .SDIO0_CLK_FB             (SDIO0_CLK_FB),
    .SDIO0_CMD_O              (SDIO0_CMD_O),
    .SDIO0_CMD_I              (SDIO0_CMD_I),
    .SDIO0_CMD_T_n            (SDIO0_CMD_T_n),
    .SDIO0_DATA_I             (SDIO0_DATA_I),
    .SDIO0_DATA_O             (SDIO0_DATA_O),
    .SDIO0_DATA_T_n           (SDIO0_DATA_T_n),
    .SDIO0_LED                (SDIO0_LED),
    .SDIO0_CDN                (SDIO0_CDN),
    .SDIO0_WP                 (SDIO0_WP),  
    .SDIO0_BUSPOW             (SDIO0_BUSPOW),
    .SDIO0_BUSVOLT            (SDIO0_BUSVOLT),
  `else
    .SDIO0_CLK_FB             (1'b0),
    .SDIO0_CMD_I              (1'b0),
    .SDIO0_DATA_I             (4'b0),
    .SDIO0_CDN                (1'b0),
    .SDIO0_WP                 (1'b0),
    .SDIO0_CLK                (),
    .SDIO0_CMD_O              (),
    .SDIO0_CMD_T_n            (),
    .SDIO0_DATA_O             (),
    .SDIO0_DATA_T_n           (),
    .SDIO0_LED                (),
    .SDIO0_BUSPOW             (),
    .SDIO0_BUSVOLT            (),
  `endif
  `ifdef USE_SDIO1
    .SDIO1_CLK                (SDIO1_CLK),
    .SDIO1_CLK_FB             (SDIO1_CLK_FB),
    .SDIO1_CMD_O              (SDIO1_CMD_O),
    .SDIO1_CMD_I              (SDIO1_CMD_I),
    .SDIO1_CMD_T_n            (SDIO1_CMD_T_n),
    .SDIO1_DATA_I             (SDIO1_DATA_I),
    .SDIO1_DATA_O             (SDIO1_DATA_O),
    .SDIO1_DATA_T_n           (SDIO1_DATA_T_n),
    .SDIO1_LED                (SDIO1_LED),
    .SDIO1_CDN                (SDIO1_CDN),
    .SDIO1_WP                 (SDIO1_WP),
    .SDIO1_BUSPOW             (SDIO1_BUSPOW),
    .SDIO1_BUSVOLT            (SDIO1_BUSVOLT),
  `else
    .SDIO1_CLK_FB             (1'b0),
    .SDIO1_CMD_I              (1'b0),
    .SDIO1_DATA_I             (4'b0),
    .SDIO1_CDN                (1'b0),
    .SDIO1_WP                 (1'b0),
    .SDIO1_CLK                (),
    .SDIO1_CMD_O              (),
    .SDIO1_CMD_T_n            (),
    .SDIO1_DATA_O             (),
    .SDIO1_DATA_T_n           (),
    .SDIO1_LED                (),
    .SDIO1_BUSPOW             (),
    .SDIO1_BUSVOLT            (),
  `endif
  `ifdef USE_SPI0
      // SPI wires
    .SPI0_SCLK_I              (SPI0_SCLK_I),
    .SPI0_SCLK_O              (SPI0_SCLK_O),
    .SPI0_SCLK_T_n            (SPI0_SCLK_T_n),
    .SPI0_MOSI_I              (SPI0_MOSI_I),
    .SPI0_MOSI_O              (SPI0_MOSI_O),
    .SPI0_MOSI_T_n            (SPI0_MOSI_T_n),
    .SPI0_MISO_I              (SPI0_MISO_I),
    .SPI0_MISO_O              (SPI0_MISO_O),
    .SPI0_MISO_T_n            (SPI0_MISO_T_n),
    .SPI0_SS_I                (SPI0_SS_I),
    .SPI0_SS_O                (SPI0_SS_O),
    .SPI0_SS1_O               (SPI0_SS1_O),
    .SPI0_SS2_O               (SPI0_SS2_O),
    .SPI0_SS_T_n              (SPI0_SS_T_n),
  `else
    .SPI0_SCLK_I              (1'b0),
    .SPI0_MOSI_I              (1'b0),
    .SPI0_MISO_I              (1'b0),
    .SPI0_SS_I                (1'b0),
    .SPI0_SCLK_O              (),
    .SPI0_SCLK_T_n            (),
    .SPI0_MOSI_O              (),
    .SPI0_MOSI_T_n            (),
    .SPI0_MISO_O              (),
    .SPI0_MISO_T_n            (),
    .SPI0_SS_O                (),
    .SPI0_SS1_O               (),
    .SPI0_SS2_O               (),
    .SPI0_SS_T_n              (),
  `endif
  `ifdef USE_SPI1
    .SPI1_SCLK_I              (SPI1_SCLK_I),
    .SPI1_SCLK_O              (SPI1_SCLK_O),
    .SPI1_SCLK_T_n            (SPI1_SCLK_T_n),
    .SPI1_MOSI_I              (SPI1_MOSI_I),
    .SPI1_MOSI_O              (SPI1_MOSI_O),
    .SPI1_MOSI_T_n            (SPI1_MOSI_T_n),
    .SPI1_MISO_I              (SPI1_MISO_I),
    .SPI1_MISO_O              (SPI1_MISO_O),
    .SPI1_MISO_T_n            (SPI1_MISO_T_n),
    .SPI1_SS_I                (SPI1_SS_I),
    .SPI1_SS_O                (SPI1_SS_O),
    .SPI1_SS1_O               (SPI1_SS1_O),
    .SPI1_SS2_O               (SPI1_SS2_O),
    .SPI1_SS_T_n              (SPI1_SS_T_n),
  `else
    .SPI1_SCLK_I              (1'b0),
    .SPI1_MOSI_I              (1'b0),
    .SPI1_MISO_I              (1'b0),
    .SPI1_SS_I                (1'b0),
    .SPI1_SCLK_O              (),
    .SPI1_SCLK_T_n            (),
    .SPI1_MOSI_O              (),
    .SPI1_MOSI_T_n            (),
    .SPI1_MISO_O              (),
    .SPI1_MISO_T_n            (),
    .SPI1_SS_O                (),
    .SPI1_SS1_O               (),
    .SPI1_SS2_O               (),
    .SPI1_SS_T_n              (),
  `endif
  `ifdef USE_UART0
    .UART0_DTRN               (UART0_DTRN),
    .UART0_RTSN               (UART0_RTSN), 
    .UART0_TX                 (UART0_TX),
    .UART0_CTSN               (UART0_CTSN),
    .UART0_DCDN               (UART0_DCDN),
    .UART0_DSRN               (UART0_DSRN),
    .UART0_RIN                (UART0_RIN),
    .UART0_RX                 (UART0_RX),
  `else
    .UART0_CTSN               (1'b0),
    .UART0_DCDN               (1'b0),
    .UART0_DSRN               (1'b0),
    .UART0_RIN                (1'b0),
    .UART0_RX                 (1'b1),
    .UART0_DTRN               (),
    .UART0_RTSN               (),
    .UART0_TX                 (),
  `endif
  `ifdef USE_UART1
    .UART1_DTRN               (UART1_DTRN),
    .UART1_RX                 (UART1_RX),
    .UART1_RTSN               (UART1_RTSN),  
    .UART1_TX                 (UART1_TX),
    .UART1_CTSN               (UART1_CTSN),
    .UART1_DCDN               (UART1_DCDN),
    .UART1_DSRN               (UART1_DSRN),
    .UART1_RIN                (UART1_RIN),
  `else
    .UART1_CTSN               (1'b0),
    .UART1_DCDN               (1'b0),
    .UART1_DSRN               (1'b0),
    .UART1_RIN                (1'b0),
    .UART1_RX                 (1'b1),
    .UART1_DTRN               (),
    .UART1_RTSN               (),
    .UART1_TX                 (),
  `endif
  `ifdef USE_JTAG
    .PJTAG_TCK                (PJTAG_TCK),
    .PJTAG_TMS                (PJTAG_TMS),
    .PJTAG_TDI                (PJTAG_TDI),
    .PJTAG_TDO_O              (PJTAG_TDO_O),
    .PJTAG_TDO_T_n            (PJTAG_TDO_T_n),
  `else
    .PJTAG_TCK                (1'b0),
    .PJTAG_TMS                (1'b0),
    .PJTAG_TDI                (1'b0),
    .PJTAG_TDO_O              (),
    .PJTAG_TDO_T_n            (),
  `endif
  `ifdef USE_TTC0
    .TTC0_WAVE0_OUT           (TTC0_WAVE0_OUT),
    .TTC0_WAVE1_OUT           (TTC0_WAVE1_OUT),
    .TTC0_WAVE2_OUT           (TTC0_WAVE2_OUT),
    .TTC0_CLK0_IN             (TTC0_CLK0_IN),
    .TTC0_CLK1_IN             (TTC0_CLK1_IN),
    .TTC0_CLK2_IN             (TTC0_CLK2_IN),
  `else
    .TTC0_CLK0_IN             (1'b0),
    .TTC0_CLK1_IN             (1'b0),
    .TTC0_CLK2_IN             (1'b0),
    .TTC0_WAVE0_OUT           (),
    .TTC0_WAVE1_OUT           (),
    .TTC0_WAVE2_OUT           (),
  `endif
  `ifdef USE_TTC1
    .TTC1_WAVE0_OUT           (TTC1_WAVE0_OUT),
    .TTC1_WAVE1_OUT           (TTC1_WAVE1_OUT),
    .TTC1_WAVE2_OUT           (TTC1_WAVE2_OUT),
    .TTC1_CLK0_IN             (TTC1_CLK0_IN),
    .TTC1_CLK1_IN             (TTC1_CLK1_IN),
    .TTC1_CLK2_IN             (TTC1_CLK2_IN),
  `else
    .TTC1_CLK0_IN             (1'b0),
    .TTC1_CLK1_IN             (1'b0),
    .TTC1_CLK2_IN             (1'b0),
    .TTC1_WAVE0_OUT           (),
    .TTC1_WAVE1_OUT           (),
    .TTC1_WAVE2_OUT           (),
  `endif
  `ifdef USE_TRACE
    .TRACE_CLK                (TRACE_CLK),
    .TRACE_CTL                (TRACE_CTL),
    .TRACE_DATA               (TRACE_DATA),
    .TRACE_CLK_OUT            (TRACE_CLK_OUT),
    .FTMD_TRACEIN_DATA        (FTMD_TRACEIN_DATA),
    .FTMD_TRACEIN_VALID       (FTMD_TRACEIN_VALID),
    .FTMD_TRACEIN_CLK         (FTMD_TRACEIN_CLK),
    .FTMD_TRACEIN_ATID        (FTMD_TRACEIN_ATID),
    .FTMT_F2P_TRIG_0          (FTMT_F2P_TRIG_0),
    .FTMT_F2P_TRIGACK_0       (FTMT_F2P_TRIGACK_0),
    .FTMT_F2P_TRIG_1          (FTMT_F2P_TRIG_1),
    .FTMT_F2P_TRIGACK_1       (FTMT_F2P_TRIGACK_1),
    .FTMT_F2P_TRIG_2          (FTMT_F2P_TRIG_2),
    .FTMT_F2P_TRIGACK_2       (FTMT_F2P_TRIGACK_2),
    .FTMT_F2P_TRIG_3          (FTMT_F2P_TRIG_3),
    .FTMT_F2P_TRIGACK_3       (FTMT_F2P_TRIGACK_3),
    .FTMT_F2P_DEBUG           (FTMT_F2P_DEBUG),
    .FTMT_P2F_TRIGACK_0       (FTMT_P2F_TRIGACK_0),
    .FTMT_P2F_TRIG_0          (FTMT_P2F_TRIG_0),
    .FTMT_P2F_TRIGACK_1       (FTMT_P2F_TRIGACK_1),
    .FTMT_P2F_TRIG_1          (FTMT_P2F_TRIG_1),
    .FTMT_P2F_TRIGACK_2       (FTMT_P2F_TRIGACK_2),
    .FTMT_P2F_TRIG_2          (FTMT_P2F_TRIG_2),
    .FTMT_P2F_TRIGACK_3       (FTMT_P2F_TRIGACK_3),
    .FTMT_P2F_TRIG_3          (FTMT_P2F_TRIG_3),
    .FTMT_P2F_DEBUG           (FTMT_P2F_DEBUG),
  `else
    .TRACE_CLK                (1'b0),
    .TRACE_CLK_OUT            (),
    .TRACE_CTL                (),
    .TRACE_DATA               (),
    .FTMD_TRACEIN_DATA        (32'b0),
    .FTMD_TRACEIN_VALID       (1'b0),
    .FTMD_TRACEIN_CLK         (1'b0),
    .FTMD_TRACEIN_ATID        (4'b0),
    .FTMT_F2P_TRIG_0          (1'b0),
    .FTMT_F2P_TRIGACK_0       (),
    .FTMT_F2P_TRIG_1          (1'b0),
    .FTMT_F2P_TRIGACK_1       (),
    .FTMT_F2P_TRIG_2          (1'b0),
    .FTMT_F2P_TRIGACK_2       (),
    .FTMT_F2P_TRIG_3          (1'b0),
    .FTMT_F2P_TRIGACK_3       (),
    .FTMT_F2P_DEBUG           (32'b0),
    .FTMT_P2F_TRIGACK_0       (1'b0),
    .FTMT_P2F_TRIG_0          (),
    .FTMT_P2F_TRIGACK_1       (1'b0),
    .FTMT_P2F_TRIG_1          (),
    .FTMT_P2F_TRIGACK_2       (1'b0),
    .FTMT_P2F_TRIG_2          (),
    .FTMT_P2F_TRIGACK_3       (1'b0),
    .FTMT_P2F_TRIG_3          (),
    .FTMT_P2F_DEBUG           (),
  `endif

  `ifdef USE_WATCHDOG
    .WDT_CLK_IN               (WDT_CLK_IN),
    .WDT_RST_OUT              (WDT_RST_OUT),
  `else
    .WDT_CLK_IN               (0'b0),
    .WDT_RST_OUT              (),
  `endif
  `ifdef USE_USB0
    .USB0_PORT_INDCTL         (USB0_PORT_INDCTL),
    .USB0_VBUS_PWRSELECT      (USB0_VBUS_PWRSELECT),
    .USB0_VBUS_PWRFAULT       (USB0_VBUS_PWRFAULT),
  `else
    .USB0_VBUS_PWRFAULT       (0'b0),
    .USB0_PORT_INDCTL         (),
    .USB0_VBUS_PWRSELECT      (),
  `endif
  `ifdef USE_USB1
    .USB1_PORT_INDCTL         (USB1_PORT_INDCTL),
    .USB1_VBUS_PWRSELECT      (USB1_VBUS_PWRSELECT),
    .USB1_VBUS_PWRFAULT       (USB1_VBUS_PWRFAULT),
  `else
    .USB1_VBUS_PWRFAULT       (0'b0),
    .USB1_PORT_INDCTL         (),
    .USB1_VBUS_PWRSELECT      (),
  `endif
  `ifdef USE_INTERRUPTS
    .IRQ_P2F_DMAC_ABORT       (IRQ_P2F_DMAC_ABORT),
    .IRQ_P2F_DMAC0            (IRQ_P2F_DMAC0),
    .IRQ_P2F_DMAC1            (IRQ_P2F_DMAC1),
    .IRQ_P2F_DMAC2            (IRQ_P2F_DMAC2),
    .IRQ_P2F_DMAC3            (IRQ_P2F_DMAC3),
    .IRQ_P2F_DMAC4            (IRQ_P2F_DMAC4),
    .IRQ_P2F_DMAC5            (IRQ_P2F_DMAC5),
    .IRQ_P2F_DMAC6            (IRQ_P2F_DMAC6),
    .IRQ_P2F_DMAC7            (IRQ_P2F_DMAC7),
    .IRQ_P2F_SMC              (IRQ_P2F_SMC),
    .IRQ_P2F_QSPI             (IRQ_P2F_QSPI),
    .IRQ_P2F_CTI              (IRQ_P2F_CTI),
    .IRQ_P2F_GPIO             (IRQ_P2F_GPIO),
    .IRQ_P2F_USB0             (IRQ_P2F_USB0),
    .IRQ_P2F_ENET0            (IRQ_P2F_ENET0),
    .IRQ_P2F_ENET_WAKE0       (IRQ_P2F_ENET_WAKE0),
    .IRQ_P2F_SDIO0            (IRQ_P2F_SDIO0),
    .IRQ_P2F_I2C0             (IRQ_P2F_I2C0),
    .IRQ_P2F_SPI0             (IRQ_P2F_SPI0),
    .IRQ_P2F_UART0            (IRQ_P2F_UART0),
    .IRQ_P2F_CAN0             (IRQ_P2F_CAN0),
    .IRQ_P2F_USB1             (IRQ_P2F_USB1),
    .IRQ_P2F_ENET1            (IRQ_P2F_ENET1),
    .IRQ_P2F_ENET_WAKE1       (IRQ_P2F_ENET_WAKE1),
    .IRQ_P2F_SDIO1            (IRQ_P2F_SDIO1),
    .IRQ_P2F_I2C1             (IRQ_P2F_I2C1),
    .IRQ_P2F_SPI1             (IRQ_P2F_SPI1),
    .IRQ_P2F_UART1            (IRQ_P2F_UART1),
    .IRQ_P2F_CAN1             (IRQ_P2F_CAN1),
    .Core0_nFIQ               (Core0_nFIQ),
    .Core0_nIRQ               (Core0_nIRQ),
    .Core1_nFIQ               (Core1_nFIQ),
    .Core1_nIRQ               (Core1_nIRQ),
    .IRQ_F2P                  (IRQ_F2P),
    .SRAM_INTIN               (SRAM_INTIN),
  `else
    .Core0_nFIQ               (0'b0),
    .Core0_nIRQ               (0'b0),
    .Core1_nFIQ               (0'b0),
    .Core1_nIRQ               (0'b0),
    .IRQ_F2P                  (0'b0),
    .SRAM_INTIN               (0'b0),
    .IRQ_P2F_DMAC_ABORT       (),
    .IRQ_P2F_DMAC0            (),
    .IRQ_P2F_DMAC1            (),
    .IRQ_P2F_DMAC2            (),
    .IRQ_P2F_DMAC3            (),
    .IRQ_P2F_DMAC4            (),
    .IRQ_P2F_DMAC5            (),
    .IRQ_P2F_DMAC6            (),
    .IRQ_P2F_DMAC7            (),
    .IRQ_P2F_SMC              (),
    .IRQ_P2F_QSPI             (),
    .IRQ_P2F_CTI              (),
    .IRQ_P2F_GPIO             (),
    .IRQ_P2F_USB0             (),
    .IRQ_P2F_ENET0            (),
    .IRQ_P2F_ENET_WAKE0       (),
    .IRQ_P2F_SDIO0            (),
    .IRQ_P2F_I2C0             (),
    .IRQ_P2F_SPI0             (),
    .IRQ_P2F_UART0            (),
    .IRQ_P2F_CAN0             (),
    .IRQ_P2F_USB1             (),
    .IRQ_P2F_ENET1            (),
    .IRQ_P2F_ENET_WAKE1       (),
    .IRQ_P2F_SDIO1            (),
    .IRQ_P2F_I2C1             (),
    .IRQ_P2F_SPI1             (),
    .IRQ_P2F_UART1            (),
    .IRQ_P2F_CAN1             (),
  `endif
  `ifdef USE_PS_EVENTS
    .EVENT_EVENTO             (EVENT_EVENTO),
    .EVENT_EVENTI             (EVENT_EVENTI),   
    .EVENT_STANDBYWFE         (EVENT_STANDBYWFE),
    .EVENT_STANDBYWFI         (EVENT_STANDBYWFI),
  `else
    .EVENT_EVENTI             (1'b0),   
    .EVENT_EVENTO             (),
    .EVENT_STANDBYWFE         (),
    .EVENT_STANDBYWFI         (),
  `endif
  `ifdef USE_FPGA_IDLE
    .FPGA_IDLE_n              (FPGA_IDLE_n),
  `else
    .FPGA_IDLE_n              (1'b1),
  `endif    
  `ifdef USE_FCLK0
    .FCLK0_CLK                (FCLK0_CLK),
    .FCLK0_RESET_n            (FCLK0_RESET_n),
  `else
    .FCLK0_CLK                (),
    .FCLK0_RESET_n            (),
  `endif
  `ifdef USE_FCLK1
    .FCLK1_CLK                (FCLK1_CLK),
    .FCLK1_RESET_n            (FCLK1_RESET_n),
  `else
    .FCLK1_CLK                (),
    .FCLK1_RESET_n            (),
  `endif
  `ifdef USE_FCLK2
    .FCLK2_CLK                (FCLK2_CLK),
    .FCLK2_RESET_n            (FCLK2_RESET_n),
  `else
    .FCLK2_CLK                (),
    .FCLK2_RESET_n            (),
  `endif
  `ifdef USE_FCLK3
    .FCLK3_CLK                (FCLK3_CLK),
    .FCLK3_RESET_n            (FCLK3_RESET_n),
  `else
    .FCLK3_CLK                (),
    .FCLK3_RESET_n            (),
  `endif
  `ifdef PS_MASTER_AXI_GP0
    .M_AXI_GP0_ACLK           (M_AXI_GP0_ACLK),
    .M_AXI_GP0_ARESET_n       (M_AXI_GP0_ARESET_n),
    .M_AXI_GP0_ARVALID        (M_AXI_GP0_ARVALID),
    .M_AXI_GP0_AWVALID        (M_AXI_GP0_AWVALID),
    .M_AXI_GP0_BREADY         (M_AXI_GP0_BREADY),
    .M_AXI_GP0_RREADY         (M_AXI_GP0_RREADY),
    .M_AXI_GP0_WLAST          (M_AXI_GP0_WLAST),
    .M_AXI_GP0_WVALID         (M_AXI_GP0_WVALID),
    .M_AXI_GP0_ARID           (M_AXI_GP0_ARID),
    .M_AXI_GP0_AWID           (M_AXI_GP0_AWID),
    .M_AXI_GP0_WID            (M_AXI_GP0_WID),
    .M_AXI_GP0_ARBURST        (M_AXI_GP0_ARBURST),
    .M_AXI_GP0_ARLOCK         (M_AXI_GP0_ARLOCK),
    .M_AXI_GP0_ARSIZE         (M_AXI_GP0_ARSIZE),
    .M_AXI_GP0_AWBURST        (M_AXI_GP0_AWBURST),
    .M_AXI_GP0_AWLOCK         (M_AXI_GP0_AWLOCK),
    .M_AXI_GP0_AWSIZE         (M_AXI_GP0_AWSIZE),
    .M_AXI_GP0_ARPROT         (M_AXI_GP0_ARPROT),
    .M_AXI_GP0_AWPROT         (M_AXI_GP0_AWPROT),
    .M_AXI_GP0_ARADDR         (M_AXI_GP0_ARADDR),
    .M_AXI_GP0_AWADDR         (M_AXI_GP0_AWADDR),
    .M_AXI_GP0_WDATA          (M_AXI_GP0_WDATA),
    .M_AXI_GP0_ARCACHE        (M_AXI_GP0_ARCACHE),
    .M_AXI_GP0_ARLEN          (M_AXI_GP0_ARLEN),
    .M_AXI_GP0_ARQOS          (M_AXI_GP0_ARQOS),
    .M_AXI_GP0_AWCACHE        (M_AXI_GP0_AWCACHE),
    .M_AXI_GP0_AWLEN          (M_AXI_GP0_AWLEN),
    .M_AXI_GP0_AWQOS          (M_AXI_GP0_AWQOS),
    .M_AXI_GP0_WSTRB          (M_AXI_GP0_WSTRB),
    .M_AXI_GP0_ARREADY        (M_AXI_GP0_ARREADY),
    .M_AXI_GP0_AWREADY        (M_AXI_GP0_AWREADY),
    .M_AXI_GP0_BVALID         (M_AXI_GP0_BVALID),
    .M_AXI_GP0_RLAST          (M_AXI_GP0_RLAST),
    .M_AXI_GP0_RVALID         (M_AXI_GP0_RVALID),
    .M_AXI_GP0_WREADY         (M_AXI_GP0_WREADY),
    .M_AXI_GP0_BID            (M_AXI_GP0_BID),
    .M_AXI_GP0_RID            (M_AXI_GP0_RID),
    .M_AXI_GP0_BRESP          (M_AXI_GP0_BRESP),
    .M_AXI_GP0_RRESP          (M_AXI_GP0_RRESP),
    .M_AXI_GP0_RDATA          (M_AXI_GP0_RDATA),  
  `else
    .M_AXI_GP0_ACLK           (1'b0),
    .M_AXI_GP0_ARREADY        (1'b0),
    .M_AXI_GP0_AWREADY        (1'b0),
    .M_AXI_GP0_BVALID         (1'b0),
    .M_AXI_GP0_RLAST          (1'b0),
    .M_AXI_GP0_RVALID         (1'b0),
    .M_AXI_GP0_WREADY         (1'b0),
    .M_AXI_GP0_BID            (12'b0),
    .M_AXI_GP0_RID            (12'b0),
    .M_AXI_GP0_BRESP          (2'b0),
    .M_AXI_GP0_RRESP          (2'b0),
    .M_AXI_GP0_RDATA          (32'b0),
    .M_AXI_GP0_ARESET_n       (),
    .M_AXI_GP0_ARVALID        (),
    .M_AXI_GP0_AWVALID        (),
    .M_AXI_GP0_BREADY         (),
    .M_AXI_GP0_RREADY         (),
    .M_AXI_GP0_WLAST          (),
    .M_AXI_GP0_WVALID         (),
    .M_AXI_GP0_ARID           (),
    .M_AXI_GP0_AWID           (),
    .M_AXI_GP0_WID            (),
    .M_AXI_GP0_ARBURST        (),
    .M_AXI_GP0_ARLOCK         (),
    .M_AXI_GP0_ARSIZE         (),
    .M_AXI_GP0_AWBURST        (),
    .M_AXI_GP0_AWLOCK         (),
    .M_AXI_GP0_AWSIZE         (),
    .M_AXI_GP0_ARPROT         (),
    .M_AXI_GP0_AWPROT         (),
    .M_AXI_GP0_ARADDR         (),
    .M_AXI_GP0_AWADDR         (),
    .M_AXI_GP0_WDATA          (),
    .M_AXI_GP0_ARCACHE        (),
    .M_AXI_GP0_ARLEN          (),
    .M_AXI_GP0_ARQOS          (),
    .M_AXI_GP0_AWCACHE        (),
    .M_AXI_GP0_AWLEN          (),
    .M_AXI_GP0_AWQOS          (),
    .M_AXI_GP0_WSTRB          (),
  `endif
  `ifdef PS_MASTER_AXI_GP1
    .M_AXI_GP1_ACLK           (M_AXI_GP1_ACLK),
    .M_AXI_GP1_ARESET_n       (M_AXI_GP1_ARESET_n),
    .M_AXI_GP1_ARVALID        (M_AXI_GP1_ARVALID),
    .M_AXI_GP1_AWVALID        (M_AXI_GP1_AWVALID),
    .M_AXI_GP1_BREADY         (M_AXI_GP1_BREADY),
    .M_AXI_GP1_RREADY         (M_AXI_GP1_RREADY),
    .M_AXI_GP1_WLAST          (M_AXI_GP1_WLAST),
    .M_AXI_GP1_WVALID         (M_AXI_GP1_WVALID),
    .M_AXI_GP1_ARID           (M_AXI_GP1_ARID),
    .M_AXI_GP1_AWID           (M_AXI_GP1_AWID),
    .M_AXI_GP1_WID            (M_AXI_GP1_WID),
    .M_AXI_GP1_ARBURST        (M_AXI_GP1_ARBURST),
    .M_AXI_GP1_ARLOCK         (M_AXI_GP1_ARLOCK),
    .M_AXI_GP1_ARSIZE         (M_AXI_GP1_ARSIZE),
    .M_AXI_GP1_AWBURST        (M_AXI_GP1_AWBURST),
    .M_AXI_GP1_AWLOCK         (M_AXI_GP1_AWLOCK),
    .M_AXI_GP1_AWSIZE         (M_AXI_GP1_AWSIZE),
    .M_AXI_GP1_ARPROT         (M_AXI_GP1_ARPROT),
    .M_AXI_GP1_AWPROT         (M_AXI_GP1_AWPROT),
    .M_AXI_GP1_ARADDR         (M_AXI_GP1_ARADDR),
    .M_AXI_GP1_AWADDR         (M_AXI_GP1_AWADDR),
    .M_AXI_GP1_WDATA          (M_AXI_GP1_WDATA),
    .M_AXI_GP1_ARCACHE        (M_AXI_GP1_ARCACHE),
    .M_AXI_GP1_ARLEN          (M_AXI_GP1_ARLEN),
    .M_AXI_GP1_ARQOS          (M_AXI_GP1_ARQOS),
    .M_AXI_GP1_AWCACHE        (M_AXI_GP1_AWCACHE),
    .M_AXI_GP1_AWLEN          (M_AXI_GP1_AWLEN),
    .M_AXI_GP1_AWQOS          (M_AXI_GP1_AWQOS),
    .M_AXI_GP1_WSTRB          (M_AXI_GP1_WSTRB),
    .M_AXI_GP1_ARREADY        (M_AXI_GP1_ARREADY),
    .M_AXI_GP1_AWREADY        (M_AXI_GP1_AWREADY),
    .M_AXI_GP1_BVALID         (M_AXI_GP1_BVALID),
    .M_AXI_GP1_RLAST          (M_AXI_GP1_RLAST),
    .M_AXI_GP1_RVALID         (M_AXI_GP1_RVALID),
    .M_AXI_GP1_WREADY         (M_AXI_GP1_WREADY),  
    .M_AXI_GP1_BID            (M_AXI_GP1_BID),
    .M_AXI_GP1_RID            (M_AXI_GP1_RID),
    .M_AXI_GP1_BRESP          (M_AXI_GP1_BRESP),
    .M_AXI_GP1_RRESP          (M_AXI_GP1_RRESP),
    .M_AXI_GP1_RDATA          (M_AXI_GP1_RDATA),
  `else
    .M_AXI_GP1_ACLK           (1'b0),
    .M_AXI_GP1_ARREADY        (1'b0),
    .M_AXI_GP1_AWREADY        (1'b0),
    .M_AXI_GP1_BVALID         (1'b0),
    .M_AXI_GP1_RLAST          (1'b0),
    .M_AXI_GP1_RVALID         (1'b0),
    .M_AXI_GP1_WREADY         (1'b0),
    .M_AXI_GP1_BID            (12'b0),
    .M_AXI_GP1_RID            (12'b0),
    .M_AXI_GP1_BRESP          (2'b0),
    .M_AXI_GP1_RRESP          (2'b0),
    .M_AXI_GP1_RDATA          (32'b0),
    .M_AXI_GP1_ARESET_n       (),
    .M_AXI_GP1_ARVALID        (),
    .M_AXI_GP1_AWVALID        (),
    .M_AXI_GP1_BREADY         (),
    .M_AXI_GP1_RREADY         (),
    .M_AXI_GP1_WLAST          (),
    .M_AXI_GP1_WVALID         (),
    .M_AXI_GP1_ARID           (),
    .M_AXI_GP1_AWID           (),
    .M_AXI_GP1_WID            (),
    .M_AXI_GP1_ARBURST        (),
    .M_AXI_GP1_ARLOCK         (),
    .M_AXI_GP1_ARSIZE         (),
    .M_AXI_GP1_AWBURST        (),
    .M_AXI_GP1_AWLOCK         (),
    .M_AXI_GP1_AWSIZE         (),
    .M_AXI_GP1_ARPROT         (),
    .M_AXI_GP1_AWPROT         (),
    .M_AXI_GP1_ARADDR         (),
    .M_AXI_GP1_AWADDR         (),
    .M_AXI_GP1_WDATA          (),
    .M_AXI_GP1_ARCACHE        (),
    .M_AXI_GP1_ARLEN          (),
    .M_AXI_GP1_ARQOS          (),
    .M_AXI_GP1_AWCACHE        (),
    .M_AXI_GP1_AWLEN          (),
    .M_AXI_GP1_AWQOS          (),
    .M_AXI_GP1_WSTRB          (),
  `endif
  `ifdef PS_SLAVE_AXI_GP0
    .S_AXI_GP0_ACLK           (S_AXI_GP0_ACLK),
    .S_AXI_GP0_ARESET_n       (S_AXI_GP0_ARESET_n),
    .S_AXI_GP0_ARREADY        (S_AXI_GP0_ARREADY),
    .S_AXI_GP0_AWREADY        (S_AXI_GP0_AWREADY),
    .S_AXI_GP0_BVALID         (S_AXI_GP0_BVALID),
    .S_AXI_GP0_RLAST          (S_AXI_GP0_RLAST),
    .S_AXI_GP0_RVALID         (S_AXI_GP0_RVALID),
    .S_AXI_GP0_WREADY         (S_AXI_GP0_WREADY),  
    .S_AXI_GP0_BRESP          (S_AXI_GP0_BRESP),
    .S_AXI_GP0_RRESP          (S_AXI_GP0_RRESP),
    .S_AXI_GP0_RDATA          (S_AXI_GP0_RDATA),
    .S_AXI_GP0_BID            (S_AXI_GP0_BID),
    .S_AXI_GP0_RID            (S_AXI_GP0_RID),
    .S_AXI_GP0_ARVALID        (S_AXI_GP0_ARVALID),
    .S_AXI_GP0_AWVALID        (S_AXI_GP0_AWVALID),
    .S_AXI_GP0_BREADY         (S_AXI_GP0_BREADY),
    .S_AXI_GP0_RREADY         (S_AXI_GP0_RREADY),
    .S_AXI_GP0_WLAST          (S_AXI_GP0_WLAST),
    .S_AXI_GP0_WVALID         (S_AXI_GP0_WVALID),
    .S_AXI_GP0_ARBURST        (S_AXI_GP0_ARBURST),
    .S_AXI_GP0_ARLOCK         (S_AXI_GP0_ARLOCK),
    .S_AXI_GP0_ARSIZE         (S_AXI_GP0_ARSIZE),
    .S_AXI_GP0_AWBURST        (S_AXI_GP0_AWBURST),
    .S_AXI_GP0_AWLOCK         (S_AXI_GP0_AWLOCK),
    .S_AXI_GP0_AWSIZE         (S_AXI_GP0_AWSIZE),
    .S_AXI_GP0_ARPROT         (S_AXI_GP0_ARPROT),
    .S_AXI_GP0_AWPROT         (S_AXI_GP0_AWPROT),
    .S_AXI_GP0_ARADDR         (S_AXI_GP0_ARADDR),
    .S_AXI_GP0_AWADDR         (S_AXI_GP0_AWADDR),
    .S_AXI_GP0_WDATA          (S_AXI_GP0_WDATA),
    .S_AXI_GP0_ARCACHE        (S_AXI_GP0_ARCACHE),
    .S_AXI_GP0_ARLEN          (S_AXI_GP0_ARLEN),
    .S_AXI_GP0_ARQOS          (S_AXI_GP0_ARQOS),
    .S_AXI_GP0_AWCACHE        (S_AXI_GP0_AWCACHE),
    .S_AXI_GP0_AWLEN          (S_AXI_GP0_AWLEN),
    .S_AXI_GP0_AWQOS          (S_AXI_GP0_AWQOS),
    .S_AXI_GP0_WSTRB          (S_AXI_GP0_WSTRB),
    .S_AXI_GP0_ARID           (S_AXI_GP0_ARID),
    .S_AXI_GP0_AWID           (S_AXI_GP0_AWID),
    .S_AXI_GP0_WID            (S_AXI_GP0_WID), 
  `else
    .S_AXI_GP0_ACLK           (1'b0),
    .S_AXI_GP0_ARVALID        (1'b0),
    .S_AXI_GP0_AWVALID        (1'b0),
    .S_AXI_GP0_BREADY         (1'b0),
    .S_AXI_GP0_RREADY         (1'b0),
    .S_AXI_GP0_WLAST          (1'b0),
    .S_AXI_GP0_WVALID         (1'b0),
    .S_AXI_GP0_ARBURST        (2'b0),
    .S_AXI_GP0_ARLOCK         (2'b0),
    .S_AXI_GP0_ARSIZE         (3'b0),
    .S_AXI_GP0_AWBURST        (2'b0),
    .S_AXI_GP0_AWLOCK         (2'b0),
    .S_AXI_GP0_AWSIZE         (3'b0),
    .S_AXI_GP0_ARPROT         (3'b0),
    .S_AXI_GP0_AWPROT         (3'b0),
    .S_AXI_GP0_ARADDR         (32'b0),
    .S_AXI_GP0_AWADDR         (32'b0),
    .S_AXI_GP0_WDATA          (32'b0),
    .S_AXI_GP0_ARCACHE        (4'b0),
    .S_AXI_GP0_ARLEN          (4'b0),
    .S_AXI_GP0_ARQOS          (4'b0),
    .S_AXI_GP0_AWCACHE        (4'b0),
    .S_AXI_GP0_AWLEN          (4'b0),
    .S_AXI_GP0_AWQOS          (4'b0),
    .S_AXI_GP0_WSTRB          (4'b0),
    .S_AXI_GP0_ARID           (6'b0),
    .S_AXI_GP0_AWID           (6'b0),
    .S_AXI_GP0_WID            (6'b0),
    .S_AXI_GP0_ARESET_n       (),
    .S_AXI_GP0_ARREADY        (),
    .S_AXI_GP0_AWREADY        (),
    .S_AXI_GP0_BVALID         (),
    .S_AXI_GP0_RLAST          (),
    .S_AXI_GP0_RVALID         (),
    .S_AXI_GP0_WREADY         (),
    .S_AXI_GP0_BRESP          (),
    .S_AXI_GP0_RRESP          (),
    .S_AXI_GP0_RDATA          (),
    .S_AXI_GP0_BID            (),
    .S_AXI_GP0_RID            (),
  `endif
  `ifdef PS_SLAVE_AXI_GP1
    .S_AXI_GP1_ACLK           (S_AXI_GP1_ACLK),
    .S_AXI_GP1_ARESET_n       (S_AXI_GP1_ARESET_n),
    .S_AXI_GP1_ARREADY        (S_AXI_GP1_ARREADY),
    .S_AXI_GP1_AWREADY        (S_AXI_GP1_AWREADY),
    .S_AXI_GP1_BVALID         (S_AXI_GP1_BVALID),
    .S_AXI_GP1_RLAST          (S_AXI_GP1_RLAST),
    .S_AXI_GP1_RVALID         (S_AXI_GP1_RVALID),
    .S_AXI_GP1_WREADY         (S_AXI_GP1_WREADY),  
    .S_AXI_GP1_BRESP          (S_AXI_GP1_BRESP),
    .S_AXI_GP1_RRESP          (S_AXI_GP1_RRESP),
    .S_AXI_GP1_RDATA          (S_AXI_GP1_RDATA),
    .S_AXI_GP1_BID            (S_AXI_GP1_BID),
    .S_AXI_GP1_RID            (S_AXI_GP1_RID),
    .S_AXI_GP1_ARVALID        (S_AXI_GP1_ARVALID),
    .S_AXI_GP1_AWVALID        (S_AXI_GP1_AWVALID),
    .S_AXI_GP1_BREADY         (S_AXI_GP1_BREADY),
    .S_AXI_GP1_RREADY         (S_AXI_GP1_RREADY),
    .S_AXI_GP1_WLAST          (S_AXI_GP1_WLAST),
    .S_AXI_GP1_WVALID         (S_AXI_GP1_WVALID),
    .S_AXI_GP1_ARBURST        (S_AXI_GP1_ARBURST),
    .S_AXI_GP1_ARLOCK         (S_AXI_GP1_ARLOCK),
    .S_AXI_GP1_ARSIZE         (S_AXI_GP1_ARSIZE),
    .S_AXI_GP1_AWBURST        (S_AXI_GP1_AWBURST),
    .S_AXI_GP1_AWLOCK         (S_AXI_GP1_AWLOCK),
    .S_AXI_GP1_AWSIZE         (S_AXI_GP1_AWSIZE),
    .S_AXI_GP1_ARPROT         (S_AXI_GP1_ARPROT),
    .S_AXI_GP1_AWPROT         (S_AXI_GP1_AWPROT),
    .S_AXI_GP1_ARADDR         (S_AXI_GP1_ARADDR),
    .S_AXI_GP1_AWADDR         (S_AXI_GP1_AWADDR),
    .S_AXI_GP1_WDATA          (S_AXI_GP1_WDATA),
    .S_AXI_GP1_ARCACHE        (S_AXI_GP1_ARCACHE),
    .S_AXI_GP1_ARLEN          (S_AXI_GP1_ARLEN),
    .S_AXI_GP1_ARQOS          (S_AXI_GP1_ARQOS),
    .S_AXI_GP1_AWCACHE        (S_AXI_GP1_AWCACHE),
    .S_AXI_GP1_AWLEN          (S_AXI_GP1_AWLEN),
    .S_AXI_GP1_AWQOS          (S_AXI_GP1_AWQOS),
    .S_AXI_GP1_WSTRB          (S_AXI_GP1_WSTRB),
    .S_AXI_GP1_ARID           (S_AXI_GP1_ARID),
    .S_AXI_GP1_AWID           (S_AXI_GP1_AWID),
    .S_AXI_GP1_WID            (S_AXI_GP1_WID), 
  `else
    .S_AXI_GP1_ACLK           (1'b0),
    .S_AXI_GP1_ARVALID        (1'b0),
    .S_AXI_GP1_AWVALID        (1'b0),
    .S_AXI_GP1_BREADY         (1'b0),
    .S_AXI_GP1_RREADY         (1'b0),
    .S_AXI_GP1_WLAST          (1'b0),
    .S_AXI_GP1_WVALID         (1'b0),
    .S_AXI_GP1_ARBURST        (2'b0),
    .S_AXI_GP1_ARLOCK         (2'b0),
    .S_AXI_GP1_ARSIZE         (3'b0),
    .S_AXI_GP1_AWBURST        (2'b0),
    .S_AXI_GP1_AWLOCK         (2'b0),
    .S_AXI_GP1_AWSIZE         (3'b0),
    .S_AXI_GP1_ARPROT         (3'b0),
    .S_AXI_GP1_AWPROT         (3'b0),
    .S_AXI_GP1_ARADDR         (32'b0),
    .S_AXI_GP1_AWADDR         (32'b0),
    .S_AXI_GP1_WDATA          (32'b0),
    .S_AXI_GP1_ARCACHE        (4'b0),
    .S_AXI_GP1_ARLEN          (4'b0),
    .S_AXI_GP1_ARQOS          (4'b0),
    .S_AXI_GP1_AWCACHE        (4'b0),
    .S_AXI_GP1_AWLEN          (4'b0),
    .S_AXI_GP1_AWQOS          (4'b0),
    .S_AXI_GP1_WSTRB          (4'b0),
    .S_AXI_GP1_ARID           (6'b0),
    .S_AXI_GP1_AWID           (6'b0),
    .S_AXI_GP1_WID            (6'b0),
    .S_AXI_GP1_ARESET_n       (),
    .S_AXI_GP1_ARREADY        (),
    .S_AXI_GP1_AWREADY        (),
    .S_AXI_GP1_BVALID         (),
    .S_AXI_GP1_RLAST          (),
    .S_AXI_GP1_RVALID         (),
    .S_AXI_GP1_WREADY         (),
    .S_AXI_GP1_BRESP          (),
    .S_AXI_GP1_RRESP          (),
    .S_AXI_GP1_RDATA          (),
    .S_AXI_GP1_BID            (),
    .S_AXI_GP1_RID            (),
  `endif
  `ifdef PS_SLAVE_AXI_ACP
    .S_AXI_ACP_ACLK           (S_AXI_ACP_ACLK),
    .S_AXI_ACP_ARESET_n       (S_AXI_ACP_ARESET_n),
    .S_AXI_ACP_ARREADY        (S_AXI_ACP_ARREADY),
    .S_AXI_ACP_AWREADY        (S_AXI_ACP_AWREADY),
    .S_AXI_ACP_BVALID         (S_AXI_ACP_BVALID),
    .S_AXI_ACP_RLAST          (S_AXI_ACP_RLAST),
    .S_AXI_ACP_RVALID         (S_AXI_ACP_RVALID),
    .S_AXI_ACP_WREADY         (S_AXI_ACP_WREADY),  
    .S_AXI_ACP_BRESP          (S_AXI_ACP_BRESP),
    .S_AXI_ACP_RRESP          (S_AXI_ACP_RRESP),
    .S_AXI_ACP_BID            (S_AXI_ACP_BID),
    .S_AXI_ACP_RID            (S_AXI_ACP_RID),
    .S_AXI_ACP_RDATA          (S_AXI_ACP_RDATA),
    .S_AXI_ACP_ARVALID        (S_AXI_ACP_ARVALID),
    .S_AXI_ACP_AWVALID        (S_AXI_ACP_AWVALID),
    .S_AXI_ACP_BREADY         (S_AXI_ACP_BREADY),
    .S_AXI_ACP_RREADY         (S_AXI_ACP_RREADY),
    .S_AXI_ACP_WLAST          (S_AXI_ACP_WLAST),
    .S_AXI_ACP_WVALID         (S_AXI_ACP_WVALID),
    .S_AXI_ACP_ARID           (S_AXI_ACP_ARID),
    .S_AXI_ACP_ARPROT         (S_AXI_ACP_ARPROT),
    .S_AXI_ACP_AWID           (S_AXI_ACP_AWID),
    .S_AXI_ACP_AWPROT         (S_AXI_ACP_AWPROT),
    .S_AXI_ACP_WID            (S_AXI_ACP_WID),
    .S_AXI_ACP_ARADDR         (S_AXI_ACP_ARADDR),
    .S_AXI_ACP_AWADDR         (S_AXI_ACP_AWADDR),
    .S_AXI_ACP_ARCACHE        (S_AXI_ACP_ARCACHE),
    .S_AXI_ACP_ARLEN          (S_AXI_ACP_ARLEN),
    .S_AXI_ACP_ARQOS          (S_AXI_ACP_ARQOS),
    .S_AXI_ACP_AWCACHE        (S_AXI_ACP_AWCACHE),
    .S_AXI_ACP_AWLEN          (S_AXI_ACP_AWLEN),
    .S_AXI_ACP_AWQOS          (S_AXI_ACP_AWQOS),
    .S_AXI_ACP_ARBURST        (S_AXI_ACP_ARBURST),
    .S_AXI_ACP_ARLOCK         (S_AXI_ACP_ARLOCK),
    .S_AXI_ACP_ARSIZE         (S_AXI_ACP_ARSIZE),
    .S_AXI_ACP_AWBURST        (S_AXI_ACP_AWBURST),
    .S_AXI_ACP_AWLOCK         (S_AXI_ACP_AWLOCK),
    .S_AXI_ACP_AWSIZE         (S_AXI_ACP_AWSIZE),
    .S_AXI_ACP_ARUSER         (S_AXI_ACP_ARUSER),
    .S_AXI_ACP_AWUSER         (S_AXI_ACP_AWUSER),
    .S_AXI_ACP_WDATA          (S_AXI_ACP_WDATA),
    .S_AXI_ACP_WSTRB          (S_AXI_ACP_WSTRB), 
  `else
    .S_AXI_ACP_ACLK           (1'b0),
    .S_AXI_ACP_ARVALID        (1'b0),
    .S_AXI_ACP_AWVALID        (1'b0),
    .S_AXI_ACP_BREADY         (1'b0),
    .S_AXI_ACP_RREADY         (1'b0),
    .S_AXI_ACP_WLAST          (1'b0),
    .S_AXI_ACP_WVALID         (1'b0),
    .S_AXI_ACP_ARBURST        (2'b0),
    .S_AXI_ACP_ARLOCK         (2'b0),
    .S_AXI_ACP_ARSIZE         (3'b0),
    .S_AXI_ACP_AWBURST        (2'b0),
    .S_AXI_ACP_AWLOCK         (2'b0),
    .S_AXI_ACP_AWSIZE         (3'b0),
    .S_AXI_ACP_ARPROT         (3'b0),
    .S_AXI_ACP_AWPROT         (3'b0),
    .S_AXI_ACP_ARADDR         (32'b0),
    .S_AXI_ACP_AWADDR         (32'b0),
    .S_AXI_ACP_WDATA          (32'b0),
    .S_AXI_ACP_ARCACHE        (4'b0),
    .S_AXI_ACP_ARLEN          (4'b0),
    .S_AXI_ACP_ARQOS          (4'b0),
    .S_AXI_ACP_AWCACHE        (4'b0),
    .S_AXI_ACP_AWLEN          (4'b0),
    .S_AXI_ACP_AWQOS          (4'b0),
    .S_AXI_ACP_WSTRB          (4'b0),
    .S_AXI_ACP_ARID           (6'b0),
    .S_AXI_ACP_AWID           (6'b0),
    .S_AXI_ACP_WID            (6'b0),
    .S_AXI_ACP_ARUSER         (5'b0),
    .S_AXI_ACP_AWUSER         (5'b0),
    .S_AXI_ACP_ARESET_n       (),
    .S_AXI_ACP_ARREADY        (),
    .S_AXI_ACP_AWREADY        (),
    .S_AXI_ACP_BVALID         (),
    .S_AXI_ACP_RLAST          (),
    .S_AXI_ACP_RVALID         (),
    .S_AXI_ACP_WREADY         (),
    .S_AXI_ACP_BRESP          (),
    .S_AXI_ACP_RRESP          (),
    .S_AXI_ACP_RDATA          (),
    .S_AXI_ACP_BID            (),
    .S_AXI_ACP_RID            (),
  `endif
  `ifdef PS_SLAVE_AXI_HP0
    .S_AXI_HP0_ARESET_n       (S_AXI_HP0_ARESET_n),
    .S_AXI_HP0_ARREADY        (S_AXI_HP0_ARREADY),
    .S_AXI_HP0_AWREADY        (S_AXI_HP0_AWREADY),
    .S_AXI_HP0_BVALID         (S_AXI_HP0_BVALID),
    .S_AXI_HP0_RLAST          (S_AXI_HP0_RLAST),
    .S_AXI_HP0_RVALID         (S_AXI_HP0_RVALID),
    .S_AXI_HP0_WREADY         (S_AXI_HP0_WREADY),  
    .S_AXI_HP0_BRESP          (S_AXI_HP0_BRESP),
    .S_AXI_HP0_RRESP          (S_AXI_HP0_RRESP),
    .S_AXI_HP0_BID            (S_AXI_HP0_BID),
    .S_AXI_HP0_RID            (S_AXI_HP0_RID),
    .S_AXI_HP0_RDATA          (S_AXI_HP0_RDATA),
    .S_AXI_HP0_RCOUNT         (S_AXI_HP0_RCOUNT),
    .S_AXI_HP0_WCOUNT         (S_AXI_HP0_WCOUNT),
    .S_AXI_HP0_RACOUNT        (S_AXI_HP0_RACOUNT),
    .S_AXI_HP0_WACOUNT        (S_AXI_HP0_WACOUNT),
    .S_AXI_HP0_ACLK           (S_AXI_HP0_ACLK),
    .S_AXI_HP0_ARVALID        (S_AXI_HP0_ARVALID),
    .S_AXI_HP0_AWVALID        (S_AXI_HP0_AWVALID),
    .S_AXI_HP0_BREADY         (S_AXI_HP0_BREADY),
    .S_AXI_HP0_RDISSUECAP1_EN (S_AXI_HP0_RDISSUECAP1_EN),
    .S_AXI_HP0_RREADY         (S_AXI_HP0_RREADY),
    .S_AXI_HP0_WLAST          (S_AXI_HP0_WLAST),
    .S_AXI_HP0_WRISSUECAP1_EN (S_AXI_HP0_WRISSUECAP1_EN),
    .S_AXI_HP0_WVALID         (S_AXI_HP0_WVALID),
    .S_AXI_HP0_ARBURST        (S_AXI_HP0_ARBURST),
    .S_AXI_HP0_ARLOCK         (S_AXI_HP0_ARLOCK),
    .S_AXI_HP0_ARSIZE         (S_AXI_HP0_ARSIZE),
    .S_AXI_HP0_AWBURST        (S_AXI_HP0_AWBURST),
    .S_AXI_HP0_AWLOCK         (S_AXI_HP0_AWLOCK),
    .S_AXI_HP0_AWSIZE         (S_AXI_HP0_AWSIZE),
    .S_AXI_HP0_ARPROT         (S_AXI_HP0_ARPROT),
    .S_AXI_HP0_AWPROT         (S_AXI_HP0_AWPROT),
    .S_AXI_HP0_ARADDR         (S_AXI_HP0_ARADDR),
    .S_AXI_HP0_AWADDR         (S_AXI_HP0_AWADDR),
    .S_AXI_HP0_ARCACHE        (S_AXI_HP0_ARCACHE),
    .S_AXI_HP0_ARLEN          (S_AXI_HP0_ARLEN),
    .S_AXI_HP0_ARQOS          (S_AXI_HP0_ARQOS),
    .S_AXI_HP0_AWCACHE        (S_AXI_HP0_AWCACHE),
    .S_AXI_HP0_AWLEN          (S_AXI_HP0_AWLEN),
    .S_AXI_HP0_AWQOS          (S_AXI_HP0_AWQOS),
    .S_AXI_HP0_ARID           (S_AXI_HP0_ARID),
    .S_AXI_HP0_AWID           (S_AXI_HP0_AWID),
    .S_AXI_HP0_WID            (S_AXI_HP0_WID),
    .S_AXI_HP0_WDATA          (S_AXI_HP0_WDATA),
    .S_AXI_HP0_WSTRB          (S_AXI_HP0_WSTRB),
  `else
    .S_AXI_HP0_ACLK           (1'B0),
    .S_AXI_HP0_ARVALID        (1'B0),
    .S_AXI_HP0_AWVALID        (1'B0),
    .S_AXI_HP0_BREADY         (1'B0),
    .S_AXI_HP0_RDISSUECAP1_EN (1'B0),
    .S_AXI_HP0_RREADY         (1'B0),
    .S_AXI_HP0_WLAST          (1'B0),
    .S_AXI_HP0_WRISSUECAP1_EN (1'B0),
    .S_AXI_HP0_WVALID         (1'B0),
    .S_AXI_HP0_ARBURST        (2'B0),
    .S_AXI_HP0_ARLOCK         (2'B0),
    .S_AXI_HP0_ARSIZE         (3'B0),
    .S_AXI_HP0_AWBURST        (2'B0),
    .S_AXI_HP0_AWLOCK         (2'B0),
    .S_AXI_HP0_AWSIZE         (3'B0),
    .S_AXI_HP0_ARPROT         (3'B0),
    .S_AXI_HP0_AWPROT         (3'B0),
    .S_AXI_HP0_ARADDR         (32'B0),
    .S_AXI_HP0_AWADDR         (32'B0),
    .S_AXI_HP0_ARCACHE        (4'B0),
    .S_AXI_HP0_ARLEN          (4'B0),
    .S_AXI_HP0_ARQOS          (4'B0),
    .S_AXI_HP0_AWCACHE        (4'B0),
    .S_AXI_HP0_AWLEN          (4'B0),
    .S_AXI_HP0_AWQOS          (4'B0),
    .S_AXI_HP0_ARID           (6'B0),
    .S_AXI_HP0_AWID           (6'B0),
    .S_AXI_HP0_WID            (6'B0),
    .S_AXI_HP0_WDATA          (64'B0),
    .S_AXI_HP0_WSTRB          (8'B0),
    .S_AXI_HP0_ARESET_n       (),
    .S_AXI_HP0_ARREADY        (),
    .S_AXI_HP0_AWREADY        (),
    .S_AXI_HP0_BVALID         (),
    .S_AXI_HP0_RLAST          (),
    .S_AXI_HP0_RVALID         (),
    .S_AXI_HP0_WREADY         (),
    .S_AXI_HP0_BRESP          (),
    .S_AXI_HP0_RRESP          (),
    .S_AXI_HP0_BID            (),
    .S_AXI_HP0_RID            (),
    .S_AXI_HP0_RDATA          (),
    .S_AXI_HP0_RCOUNT         (),
    .S_AXI_HP0_WCOUNT         (),
    .S_AXI_HP0_RACOUNT        (),
    .S_AXI_HP0_WACOUNT        (),
  `endif
  `ifdef PS_SLAVE_AXI_HP1
    .S_AXI_HP1_ARESET_n       (S_AXI_HP1_ARESET_n),
    .S_AXI_HP1_ARREADY        (S_AXI_HP1_ARREADY),
    .S_AXI_HP1_AWREADY        (S_AXI_HP1_AWREADY),
    .S_AXI_HP1_BVALID         (S_AXI_HP1_BVALID),
    .S_AXI_HP1_RLAST          (S_AXI_HP1_RLAST),
    .S_AXI_HP1_RVALID         (S_AXI_HP1_RVALID),
    .S_AXI_HP1_WREADY         (S_AXI_HP1_WREADY),  
    .S_AXI_HP1_BRESP          (S_AXI_HP1_BRESP),
    .S_AXI_HP1_RRESP          (S_AXI_HP1_RRESP),
    .S_AXI_HP1_BID            (S_AXI_HP1_BID),
    .S_AXI_HP1_RID            (S_AXI_HP1_RID),
    .S_AXI_HP1_RDATA          (S_AXI_HP1_RDATA),
    .S_AXI_HP1_RCOUNT         (S_AXI_HP1_RCOUNT),
    .S_AXI_HP1_WCOUNT         (S_AXI_HP1_WCOUNT),
    .S_AXI_HP1_RACOUNT        (S_AXI_HP1_RACOUNT),
    .S_AXI_HP1_WACOUNT        (S_AXI_HP1_WACOUNT),
    .S_AXI_HP1_ACLK           (S_AXI_HP1_ACLK),
    .S_AXI_HP1_ARVALID        (S_AXI_HP1_ARVALID),
    .S_AXI_HP1_AWVALID        (S_AXI_HP1_AWVALID),
    .S_AXI_HP1_BREADY         (S_AXI_HP1_BREADY),
    .S_AXI_HP1_RDISSUECAP1_EN (S_AXI_HP1_RDISSUECAP1_EN),
    .S_AXI_HP1_RREADY         (S_AXI_HP1_RREADY),
    .S_AXI_HP1_WLAST          (S_AXI_HP1_WLAST),
    .S_AXI_HP1_WRISSUECAP1_EN (S_AXI_HP1_WRISSUECAP1_EN),
    .S_AXI_HP1_WVALID         (S_AXI_HP1_WVALID),
    .S_AXI_HP1_ARBURST        (S_AXI_HP1_ARBURST),
    .S_AXI_HP1_ARLOCK         (S_AXI_HP1_ARLOCK),
    .S_AXI_HP1_ARSIZE         (S_AXI_HP1_ARSIZE),
    .S_AXI_HP1_AWBURST        (S_AXI_HP1_AWBURST),
    .S_AXI_HP1_AWLOCK         (S_AXI_HP1_AWLOCK),
    .S_AXI_HP1_AWSIZE         (S_AXI_HP1_AWSIZE),
    .S_AXI_HP1_ARPROT         (S_AXI_HP1_ARPROT),
    .S_AXI_HP1_AWPROT         (S_AXI_HP1_AWPROT),
    .S_AXI_HP1_ARADDR         (S_AXI_HP1_ARADDR),
    .S_AXI_HP1_AWADDR         (S_AXI_HP1_AWADDR),
    .S_AXI_HP1_ARCACHE        (S_AXI_HP1_ARCACHE),
    .S_AXI_HP1_ARLEN          (S_AXI_HP1_ARLEN),
    .S_AXI_HP1_ARQOS          (S_AXI_HP1_ARQOS),
    .S_AXI_HP1_AWCACHE        (S_AXI_HP1_AWCACHE),
    .S_AXI_HP1_AWLEN          (S_AXI_HP1_AWLEN),
    .S_AXI_HP1_AWQOS          (S_AXI_HP1_AWQOS),
    .S_AXI_HP1_ARID           (S_AXI_HP1_ARID),
    .S_AXI_HP1_AWID           (S_AXI_HP1_AWID),
    .S_AXI_HP1_WID            (S_AXI_HP1_WID),
    .S_AXI_HP1_WDATA          (S_AXI_HP1_WDATA),
    .S_AXI_HP1_WSTRB          (S_AXI_HP1_WSTRB),
  `else
    .S_AXI_HP1_ACLK           (1'B0),
    .S_AXI_HP1_ARVALID        (1'B0),
    .S_AXI_HP1_AWVALID        (1'B0),
    .S_AXI_HP1_BREADY         (1'B0),
    .S_AXI_HP1_RDISSUECAP1_EN (1'B0),
    .S_AXI_HP1_RREADY         (1'B0),
    .S_AXI_HP1_WLAST          (1'B0),
    .S_AXI_HP1_WRISSUECAP1_EN (1'B0),
    .S_AXI_HP1_WVALID         (1'B0),
    .S_AXI_HP1_ARBURST        (2'B0),
    .S_AXI_HP1_ARLOCK         (2'B0),
    .S_AXI_HP1_ARSIZE         (3'B0),
    .S_AXI_HP1_AWBURST        (2'B0),
    .S_AXI_HP1_AWLOCK         (2'B0),
    .S_AXI_HP1_AWSIZE         (3'B0),
    .S_AXI_HP1_ARPROT         (3'B0),
    .S_AXI_HP1_AWPROT         (3'B0),
    .S_AXI_HP1_ARADDR         (32'B0),
    .S_AXI_HP1_AWADDR         (32'B0),
    .S_AXI_HP1_ARCACHE        (4'B0),
    .S_AXI_HP1_ARLEN          (4'B0),
    .S_AXI_HP1_ARQOS          (4'B0),
    .S_AXI_HP1_AWCACHE        (4'B0),
    .S_AXI_HP1_AWLEN          (4'B0),
    .S_AXI_HP1_AWQOS          (4'B0),
    .S_AXI_HP1_ARID           (6'B0),
    .S_AXI_HP1_AWID           (6'B0),
    .S_AXI_HP1_WID            (6'B0),
    .S_AXI_HP1_WDATA          (64'B0),
    .S_AXI_HP1_WSTRB          (8'B0),
    .S_AXI_HP1_ARESET_n       (),
    .S_AXI_HP1_ARREADY        (),
    .S_AXI_HP1_AWREADY        (),
    .S_AXI_HP1_BVALID         (),
    .S_AXI_HP1_RLAST          (),
    .S_AXI_HP1_RVALID         (),
    .S_AXI_HP1_WREADY         (),
    .S_AXI_HP1_BRESP          (),
    .S_AXI_HP1_RRESP          (),
    .S_AXI_HP1_BID            (),
    .S_AXI_HP1_RID            (),
    .S_AXI_HP1_RDATA          (),
    .S_AXI_HP1_RCOUNT         (),
    .S_AXI_HP1_WCOUNT         (),
    .S_AXI_HP1_RACOUNT        (),
    .S_AXI_HP1_WACOUNT        (),
  `endif
  `ifdef PS_SLAVE_AXI_HP2
    .S_AXI_HP2_ARESET_n       (S_AXI_HP2_ARESET_n),
    .S_AXI_HP2_ARREADY        (S_AXI_HP2_ARREADY),
    .S_AXI_HP2_AWREADY        (S_AXI_HP2_AWREADY),
    .S_AXI_HP2_BVALID         (S_AXI_HP2_BVALID),
    .S_AXI_HP2_RLAST          (S_AXI_HP2_RLAST),
    .S_AXI_HP2_RVALID         (S_AXI_HP2_RVALID),
    .S_AXI_HP2_WREADY         (S_AXI_HP2_WREADY),  
    .S_AXI_HP2_BRESP          (S_AXI_HP2_BRESP),
    .S_AXI_HP2_RRESP          (S_AXI_HP2_RRESP),
    .S_AXI_HP2_BID            (S_AXI_HP2_BID),
    .S_AXI_HP2_RID            (S_AXI_HP2_RID),
    .S_AXI_HP2_RDATA          (S_AXI_HP2_RDATA),
    .S_AXI_HP2_RCOUNT         (S_AXI_HP2_RCOUNT),
    .S_AXI_HP2_WCOUNT         (S_AXI_HP2_WCOUNT),
    .S_AXI_HP2_RACOUNT        (S_AXI_HP2_RACOUNT),
    .S_AXI_HP2_WACOUNT        (S_AXI_HP2_WACOUNT),
    .S_AXI_HP2_ACLK           (S_AXI_HP2_ACLK),
    .S_AXI_HP2_ARVALID        (S_AXI_HP2_ARVALID),
    .S_AXI_HP2_AWVALID        (S_AXI_HP2_AWVALID),
    .S_AXI_HP2_BREADY         (S_AXI_HP2_BREADY),
    .S_AXI_HP2_RDISSUECAP1_EN (S_AXI_HP2_RDISSUECAP1_EN),
    .S_AXI_HP2_RREADY         (S_AXI_HP2_RREADY),
    .S_AXI_HP2_WLAST          (S_AXI_HP2_WLAST),
    .S_AXI_HP2_WRISSUECAP1_EN (S_AXI_HP2_WRISSUECAP1_EN),
    .S_AXI_HP2_WVALID         (S_AXI_HP2_WVALID),
    .S_AXI_HP2_ARBURST        (S_AXI_HP2_ARBURST),
    .S_AXI_HP2_ARLOCK         (S_AXI_HP2_ARLOCK),
    .S_AXI_HP2_ARSIZE         (S_AXI_HP2_ARSIZE),
    .S_AXI_HP2_AWBURST        (S_AXI_HP2_AWBURST),
    .S_AXI_HP2_AWLOCK         (S_AXI_HP2_AWLOCK),
    .S_AXI_HP2_AWSIZE         (S_AXI_HP2_AWSIZE),
    .S_AXI_HP2_ARPROT         (S_AXI_HP2_ARPROT),
    .S_AXI_HP2_AWPROT         (S_AXI_HP2_AWPROT),
    .S_AXI_HP2_ARADDR         (S_AXI_HP2_ARADDR),
    .S_AXI_HP2_AWADDR         (S_AXI_HP2_AWADDR),
    .S_AXI_HP2_ARCACHE        (S_AXI_HP2_ARCACHE),
    .S_AXI_HP2_ARLEN          (S_AXI_HP2_ARLEN),
    .S_AXI_HP2_ARQOS          (S_AXI_HP2_ARQOS),
    .S_AXI_HP2_AWCACHE        (S_AXI_HP2_AWCACHE),
    .S_AXI_HP2_AWLEN          (S_AXI_HP2_AWLEN),
    .S_AXI_HP2_AWQOS          (S_AXI_HP2_AWQOS),
    .S_AXI_HP2_ARID           (S_AXI_HP2_ARID),
    .S_AXI_HP2_AWID           (S_AXI_HP2_AWID),
    .S_AXI_HP2_WID            (S_AXI_HP2_WID),
    .S_AXI_HP2_WDATA          (S_AXI_HP2_WDATA),
    .S_AXI_HP2_WSTRB          (S_AXI_HP2_WSTRB),
  `else
    .S_AXI_HP2_ACLK           (1'B0),
    .S_AXI_HP2_ARVALID        (1'B0),
    .S_AXI_HP2_AWVALID        (1'B0),
    .S_AXI_HP2_BREADY         (1'B0),
    .S_AXI_HP2_RDISSUECAP1_EN (1'B0),
    .S_AXI_HP2_RREADY         (1'B0),
    .S_AXI_HP2_WLAST          (1'B0),
    .S_AXI_HP2_WRISSUECAP1_EN (1'B0),
    .S_AXI_HP2_WVALID         (1'B0),
    .S_AXI_HP2_ARBURST        (2'B0),
    .S_AXI_HP2_ARLOCK         (2'B0),
    .S_AXI_HP2_ARSIZE         (3'B0),
    .S_AXI_HP2_AWBURST        (2'B0),
    .S_AXI_HP2_AWLOCK         (2'B0),
    .S_AXI_HP2_AWSIZE         (3'B0),
    .S_AXI_HP2_ARPROT         (3'B0),
    .S_AXI_HP2_AWPROT         (3'B0),
    .S_AXI_HP2_ARADDR         (32'B0),
    .S_AXI_HP2_AWADDR         (32'B0),
    .S_AXI_HP2_ARCACHE        (4'B0),
    .S_AXI_HP2_ARLEN          (4'B0),
    .S_AXI_HP2_ARQOS          (4'B0),
    .S_AXI_HP2_AWCACHE        (4'B0),
    .S_AXI_HP2_AWLEN          (4'B0),
    .S_AXI_HP2_AWQOS          (4'B0),
    .S_AXI_HP2_ARID           (6'B0),
    .S_AXI_HP2_AWID           (6'B0),
    .S_AXI_HP2_WID            (6'B0),
    .S_AXI_HP2_WDATA          (64'B0),
    .S_AXI_HP2_WSTRB          (8'B0),
    .S_AXI_HP2_ARESET_n       (),
    .S_AXI_HP2_ARREADY        (),
    .S_AXI_HP2_AWREADY        (),
    .S_AXI_HP2_BVALID         (),
    .S_AXI_HP2_RLAST          (),
    .S_AXI_HP2_RVALID         (),
    .S_AXI_HP2_WREADY         (),
    .S_AXI_HP2_BRESP          (),
    .S_AXI_HP2_RRESP          (),
    .S_AXI_HP2_BID            (),
    .S_AXI_HP2_RID            (),
    .S_AXI_HP2_RDATA          (),
    .S_AXI_HP2_RCOUNT         (),
    .S_AXI_HP2_WCOUNT         (),
    .S_AXI_HP2_RACOUNT        (),
    .S_AXI_HP2_WACOUNT        (),
  `endif
  `ifdef PS_SLAVE_AXI_HP3
    .S_AXI_HP3_ARESET_n       (S_AXI_HP3_ARESET_n),
    .S_AXI_HP3_ARREADY        (S_AXI_HP3_ARREADY),
    .S_AXI_HP3_AWREADY        (S_AXI_HP3_AWREADY),
    .S_AXI_HP3_BVALID         (S_AXI_HP3_BVALID),
    .S_AXI_HP3_RLAST          (S_AXI_HP3_RLAST),
    .S_AXI_HP3_RVALID         (S_AXI_HP3_RVALID),
    .S_AXI_HP3_WREADY         (S_AXI_HP3_WREADY),  
    .S_AXI_HP3_BRESP          (S_AXI_HP3_BRESP),
    .S_AXI_HP3_RRESP          (S_AXI_HP3_RRESP),
    .S_AXI_HP3_BID            (S_AXI_HP3_BID),
    .S_AXI_HP3_RID            (S_AXI_HP3_RID),
    .S_AXI_HP3_RDATA          (S_AXI_HP3_RDATA),
    .S_AXI_HP3_RCOUNT         (S_AXI_HP3_RCOUNT),
    .S_AXI_HP3_WCOUNT         (S_AXI_HP3_WCOUNT),
    .S_AXI_HP3_RACOUNT        (S_AXI_HP3_RACOUNT),
    .S_AXI_HP3_WACOUNT        (S_AXI_HP3_WACOUNT),
    .S_AXI_HP3_ACLK           (S_AXI_HP3_ACLK),
    .S_AXI_HP3_ARVALID        (S_AXI_HP3_ARVALID),
    .S_AXI_HP3_AWVALID        (S_AXI_HP3_AWVALID),
    .S_AXI_HP3_BREADY         (S_AXI_HP3_BREADY),
    .S_AXI_HP3_RDISSUECAP1_EN (S_AXI_HP3_RDISSUECAP1_EN),
    .S_AXI_HP3_RREADY         (S_AXI_HP3_RREADY),
    .S_AXI_HP3_WLAST          (S_AXI_HP3_WLAST),
    .S_AXI_HP3_WRISSUECAP1_EN (S_AXI_HP3_WRISSUECAP1_EN),
    .S_AXI_HP3_WVALID         (S_AXI_HP3_WVALID),
    .S_AXI_HP3_ARBURST        (S_AXI_HP3_ARBURST),
    .S_AXI_HP3_ARLOCK         (S_AXI_HP3_ARLOCK),
    .S_AXI_HP3_ARSIZE         (S_AXI_HP3_ARSIZE),
    .S_AXI_HP3_AWBURST        (S_AXI_HP3_AWBURST),
    .S_AXI_HP3_AWLOCK         (S_AXI_HP3_AWLOCK),
    .S_AXI_HP3_AWSIZE         (S_AXI_HP3_AWSIZE),
    .S_AXI_HP3_ARPROT         (S_AXI_HP3_ARPROT),
    .S_AXI_HP3_AWPROT         (S_AXI_HP3_AWPROT),
    .S_AXI_HP3_ARADDR         (S_AXI_HP3_ARADDR),
    .S_AXI_HP3_AWADDR         (S_AXI_HP3_AWADDR),
    .S_AXI_HP3_ARCACHE        (S_AXI_HP3_ARCACHE),
    .S_AXI_HP3_ARLEN          (S_AXI_HP3_ARLEN),
    .S_AXI_HP3_ARQOS          (S_AXI_HP3_ARQOS),
    .S_AXI_HP3_AWCACHE        (S_AXI_HP3_AWCACHE),
    .S_AXI_HP3_AWLEN          (S_AXI_HP3_AWLEN),
    .S_AXI_HP3_AWQOS          (S_AXI_HP3_AWQOS),
    .S_AXI_HP3_ARID           (S_AXI_HP3_ARID),
    .S_AXI_HP3_AWID           (S_AXI_HP3_AWID),
    .S_AXI_HP3_WID            (S_AXI_HP3_WID),
    .S_AXI_HP3_WDATA          (S_AXI_HP3_WDATA),
    .S_AXI_HP3_WSTRB          (S_AXI_HP3_WSTRB),
  `else
    .S_AXI_HP3_ACLK           (1'B0),
    .S_AXI_HP3_ARVALID        (1'B0),
    .S_AXI_HP3_AWVALID        (1'B0),
    .S_AXI_HP3_BREADY         (1'B0),
    .S_AXI_HP3_RDISSUECAP1_EN (1'B0),
    .S_AXI_HP3_RREADY         (1'B0),
    .S_AXI_HP3_WLAST          (1'B0),
    .S_AXI_HP3_WRISSUECAP1_EN (1'B0),
    .S_AXI_HP3_WVALID         (1'B0),
    .S_AXI_HP3_ARBURST        (2'B0),
    .S_AXI_HP3_ARLOCK         (2'B0),
    .S_AXI_HP3_ARSIZE         (3'B0),
    .S_AXI_HP3_AWBURST        (2'B0),
    .S_AXI_HP3_AWLOCK         (2'B0),
    .S_AXI_HP3_AWSIZE         (3'B0),
    .S_AXI_HP3_ARPROT         (3'B0),
    .S_AXI_HP3_AWPROT         (3'B0),
    .S_AXI_HP3_ARADDR         (32'B0),
    .S_AXI_HP3_AWADDR         (32'B0),
    .S_AXI_HP3_ARCACHE        (4'B0),
    .S_AXI_HP3_ARLEN          (4'B0),
    .S_AXI_HP3_ARQOS          (4'B0),
    .S_AXI_HP3_AWCACHE        (4'B0),
    .S_AXI_HP3_AWLEN          (4'B0),
    .S_AXI_HP3_AWQOS          (4'B0),
    .S_AXI_HP3_ARID           (6'B0),
    .S_AXI_HP3_AWID           (6'B0),
    .S_AXI_HP3_WID            (6'B0),
    .S_AXI_HP3_WDATA          (64'B0),
    .S_AXI_HP3_WSTRB          (8'B0),
    .S_AXI_HP3_ARESET_n       (),
    .S_AXI_HP3_ARREADY        (),
    .S_AXI_HP3_AWREADY        (),
    .S_AXI_HP3_BVALID         (),
    .S_AXI_HP3_RLAST          (),
    .S_AXI_HP3_RVALID         (),
    .S_AXI_HP3_WREADY         (),
    .S_AXI_HP3_BRESP          (),
    .S_AXI_HP3_RRESP          (),
    .S_AXI_HP3_BID            (),
    .S_AXI_HP3_RID            (),
    .S_AXI_HP3_RDATA          (),
    .S_AXI_HP3_RCOUNT         (),
    .S_AXI_HP3_WCOUNT         (),
    .S_AXI_HP3_RACOUNT        (),
    .S_AXI_HP3_WACOUNT        (),
  `endif
  // DDR
  .DDR_ARB                  (DDR_ARB),
  .DDR_CAS_n                (DDR_CAS_n_buffered),
  .DDR_CKE                  (DDR_CKE_buffered),
  .DDR_Clk_n                (DDR_Clk_n_buffered),
  .DDR_Clk                  (DDR_Clk_buffered),
  .DDR_CS_n                 (DDR_CS_n_buffered),
  .DDR_DRSTB                (DDR_DRSTB_buffered),
  .DDR_ODT                  (DDR_ODT_buffered),
  .DDR_RAS_n                (DDR_RAS_n_buffered),
  .DDR_WEB                  (DDR_WEB_buffered),
  .DDR_BankAddr             (DDR_BankAddr_buffered),
  .DDR_Addr                 (DDR_Addr_buffered),
  .DDR_VRN                  (DDR_VRN_buffered),
  .DDR_VRP                  (DDR_VRP_buffered),
  .DDR_DM                   (DDR_DM_buffered),
  .DDR_DQ                   (DDR_DQ_buffered),
  .DDR_DQS_n                (DDR_DQS_n_buffered),
  .DDR_DQS                  (DDR_DQS_buffered),
  // PS Clock and Reset wires
  .PS_CLK                   (PS_CLK_buffered),         
  .PS_SOFT_RESET            (PS_SOFT_RESET_buffered),
  .PS_POWER_ON_RESET        (PS_POWER_ON_RESET_buffered)

  );
endmodule
