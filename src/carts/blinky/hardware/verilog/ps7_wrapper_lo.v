module ps7_lo_wrapper (
  output wire [1 : 0] USB0_PORT_INDCTL,
  output wire USB0_VBUS_PWRSELECT,
  input wire USB0_VBUS_PWRFAULT,

  input wire M_AXI_GP0_ACLK,
  output wire M_AXI_GP0_ARESETN,
  output wire M_AXI_GP0_ARVALID,
  output wire M_AXI_GP0_AWVALID,
  output wire M_AXI_GP0_BREADY,
  output wire M_AXI_GP0_RREADY,
  output wire M_AXI_GP0_WLAST,
  output wire M_AXI_GP0_WVALID,
  output wire [11 : 0] M_AXI_GP0_ARID,
  output wire [11 : 0] M_AXI_GP0_AWID,
  output wire [11 : 0] M_AXI_GP0_WID,
  output wire [1 : 0] M_AXI_GP0_ARBURST,
  output wire [1 : 0] M_AXI_GP0_ARLOCK,
  output wire [2 : 0] M_AXI_GP0_ARSIZE,
  output wire [1 : 0] M_AXI_GP0_AWBURST,
  output wire [1 : 0] M_AXI_GP0_AWLOCK,
  output wire [2 : 0] M_AXI_GP0_AWSIZE,
  output wire [2 : 0] M_AXI_GP0_ARPROT,
  output wire [2 : 0] M_AXI_GP0_AWPROT,
  output wire [31 : 0] M_AXI_GP0_ARADDR,
  output wire [31 : 0] M_AXI_GP0_AWADDR,
  output wire [31 : 0] M_AXI_GP0_WDATA,
  output wire [3 : 0] M_AXI_GP0_ARCACHE,
  output wire [3 : 0] M_AXI_GP0_ARLEN,
  output wire [3 : 0] M_AXI_GP0_ARQOS,
  output wire [3 : 0] M_AXI_GP0_AWCACHE,
  output wire [3 : 0] M_AXI_GP0_AWLEN,
  output wire [3 : 0] M_AXI_GP0_AWQOS,
  output wire [3 : 0] M_AXI_GP0_WSTRB,
  input wire M_AXI_GP0_ARREADY,
  input wire M_AXI_GP0_AWREADY,
  input wire M_AXI_GP0_BVALID,
  input wire M_AXI_GP0_RLAST,
  input wire M_AXI_GP0_RVALID,
  input wire M_AXI_GP0_WREADY,
  input wire [11 : 0] M_AXI_GP0_BID,
  input wire [11 : 0] M_AXI_GP0_RID,
  input wire [1 : 0] M_AXI_GP0_BRESP,
  input wire [1 : 0] M_AXI_GP0_RRESP,
  input wire [31 : 0] M_AXI_GP0_RDATA,
  
  output wire FCLK_CLK0,
  output wire FCLK_RESET0_N,
  
  inout wire [53 : 0] MIO,
  
  inout wire DDR_CAS_n,
  inout wire DDR_CKE,
  inout wire DDR_Clk_n,
  inout wire DDR_Clk,
  inout wire DDR_CS_n,
  inout wire DDR_DRSTB,
  inout wire DDR_ODT,
  inout wire DDR_RAS_n,
  inout wire DDR_WEB,
  inout wire [2 : 0] DDR_BankAddr,
  inout wire [14 : 0] DDR_Addr,
  inout wire DDR_VRN,
  inout wire DDR_VRP,
  inout wire [3 : 0] DDR_DM,
  inout wire [31 : 0] DDR_DQ,
  inout wire [3 : 0] DDR_DQS_n,
  inout wire [3 : 0] DDR_DQS,

  output M_AXI_GP1_ARESETN,
  output S_AXI_GP0_ARESETN,
  output S_AXI_GP1_ARESETN,
  output S_AXI_ACP_ARESETN,
  output S_AXI_HP0_ARESETN,
  output S_AXI_HP1_ARESETN,
  output S_AXI_HP2_ARESETN,
  output S_AXI_HP3_ARESETN,
  output DMA0_RSTN,
  output DMA1_RSTN,
  output DMA2_RSTN,
  output DMA3_RSTN,

  inout wire PS_SRSTB,
  inout wire PS_CLK,
  inout wire PS_PORB
);
  processing_system7_v5_5_processing_system7 #(
    .C_EN_EMIO_PJTAG(0),
    .C_EN_EMIO_ENET0(0),
    .C_EN_EMIO_ENET1(0),
    .C_EN_EMIO_TRACE(0),
    .C_INCLUDE_TRACE_BUFFER(0),
    .C_TRACE_BUFFER_FIFO_SIZE(128),
    .USE_TRACE_DATA_EDGE_DETECTOR(0),
    .C_TRACE_PIPELINE_WIDTH(8),
    .C_TRACE_BUFFER_CLOCK_DELAY(12),
    .C_EMIO_GPIO_WIDTH(64),
    .C_INCLUDE_ACP_TRANS_CHECK(0),
    .C_USE_DEFAULT_ACP_USER_VAL(0),
    .C_S_AXI_ACP_ARUSER_VAL(31),
    .C_S_AXI_ACP_AWUSER_VAL(31),
    .C_M_AXI_GP0_ID_WIDTH(12),
    .C_M_AXI_GP0_ENABLE_STATIC_REMAP(0),
    .C_M_AXI_GP1_ID_WIDTH(12),
    .C_M_AXI_GP1_ENABLE_STATIC_REMAP(0),
    .C_S_AXI_GP0_ID_WIDTH(6),
    .C_S_AXI_GP1_ID_WIDTH(6),
    .C_S_AXI_ACP_ID_WIDTH(3),
    .C_S_AXI_HP0_ID_WIDTH(6),
    .C_S_AXI_HP0_DATA_WIDTH(64),
    .C_S_AXI_HP1_ID_WIDTH(6),
    .C_S_AXI_HP1_DATA_WIDTH(64),
    .C_S_AXI_HP2_ID_WIDTH(6),
    .C_S_AXI_HP2_DATA_WIDTH(64),
    .C_S_AXI_HP3_ID_WIDTH(6),
    .C_S_AXI_HP3_DATA_WIDTH(64),
    .C_M_AXI_GP0_THREAD_ID_WIDTH(12),
    .C_M_AXI_GP1_THREAD_ID_WIDTH(12),
    .C_NUM_F2P_INTR_INPUTS(1),
    .C_IRQ_F2P_MODE("DIRECT"),
    .C_DQ_WIDTH(32),
    .C_DQS_WIDTH(4),
    .C_DM_WIDTH(4),
    .C_MIO_PRIMITIVE(54),
    .C_TRACE_INTERNAL_WIDTH(2),
    .C_USE_AXI_NONSECURE(0),
    .C_USE_M_AXI_GP0(1),
    .C_USE_M_AXI_GP1(0),
    .C_USE_S_AXI_GP0(0),
    .C_USE_S_AXI_GP1(0),
    .C_USE_S_AXI_HP0(0),
    .C_USE_S_AXI_HP1(0),
    .C_USE_S_AXI_HP2(0),
    .C_USE_S_AXI_HP3(0),
    .C_USE_S_AXI_ACP(0),
    .C_PS7_SI_REV("PRODUCTION"),
    .C_FCLK_CLK0_BUF("TRUE"),
    .C_FCLK_CLK1_BUF("FALSE"),
    .C_FCLK_CLK2_BUF("FALSE"),
    .C_FCLK_CLK3_BUF("FALSE"),
    .C_PACKAGE_NAME("clg400"),
    .C_GP0_EN_MODIFIABLE_TXN(1),
    .C_GP1_EN_MODIFIABLE_TXN(1)
  ) inst (
    .CAN0_PHY_TX(),
    .CAN0_PHY_RX(1'B0),
    .CAN1_PHY_TX(),
    .CAN1_PHY_RX(1'B0),
    .ENET0_GMII_TX_EN(),
    .ENET0_GMII_TX_ER(),
    .ENET0_MDIO_MDC(),
    .ENET0_MDIO_O(),
    .ENET0_MDIO_T(),
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
    .ENET0_GMII_TXD(),
    .ENET0_GMII_COL(1'B0),
    .ENET0_GMII_CRS(1'B0),
    .ENET0_GMII_RX_CLK(1'B0),
    .ENET0_GMII_RX_DV(1'B0),
    .ENET0_GMII_RX_ER(1'B0),
    .ENET0_GMII_TX_CLK(1'B0),
    .ENET0_MDIO_I(1'B0),
    .ENET0_EXT_INTIN(1'B0),
    .ENET0_GMII_RXD(8'B0),
    .ENET1_GMII_TX_EN(),
    .ENET1_GMII_TX_ER(),
    .ENET1_MDIO_MDC(),
    .ENET1_MDIO_O(),
    .ENET1_MDIO_T(),
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
    .ENET1_GMII_TXD(),
    .ENET1_GMII_COL(1'B0),
    .ENET1_GMII_CRS(1'B0),
    .ENET1_GMII_RX_CLK(1'B0),
    .ENET1_GMII_RX_DV(1'B0),
    .ENET1_GMII_RX_ER(1'B0),
    .ENET1_GMII_TX_CLK(1'B0),
    .ENET1_MDIO_I(1'B0),
    .ENET1_EXT_INTIN(1'B0),
    .ENET1_GMII_RXD(8'B0),
    .GPIO_I(64'B0),
    .GPIO_O(),
    .GPIO_T(),
    .I2C0_SDA_I(1'B0),
    .I2C0_SDA_O(),
    .I2C0_SDA_T(),
    .I2C0_SCL_I(1'B0),
    .I2C0_SCL_O(),
    .I2C0_SCL_T(),
    .I2C1_SDA_I(1'B0),
    .I2C1_SDA_O(),
    .I2C1_SDA_T(),
    .I2C1_SCL_I(1'B0),
    .I2C1_SCL_O(),
    .I2C1_SCL_T(),
    .PJTAG_TCK(1'B0),
    .PJTAG_TMS(1'B0),
    .PJTAG_TDI(1'B0),
    .PJTAG_TDO(),
    .SDIO0_CLK(),
    .SDIO0_CLK_FB(1'B0),
    .SDIO0_CMD_O(),
    .SDIO0_CMD_I(1'B0),
    .SDIO0_CMD_T(),
    .SDIO0_DATA_I(4'B0),
    .SDIO0_DATA_O(),
    .SDIO0_DATA_T(),
    .SDIO0_LED(),
    .SDIO0_CDN(1'B0),
    .SDIO0_WP(1'B0),
    .SDIO0_BUSPOW(),
    .SDIO0_BUSVOLT(),
    .SDIO1_CLK(),
    .SDIO1_CLK_FB(1'B0),
    .SDIO1_CMD_O(),
    .SDIO1_CMD_I(1'B0),
    .SDIO1_CMD_T(),
    .SDIO1_DATA_I(4'B0),
    .SDIO1_DATA_O(),
    .SDIO1_DATA_T(),
    .SDIO1_LED(),
    .SDIO1_CDN(1'B0),
    .SDIO1_WP(1'B0),
    .SDIO1_BUSPOW(),
    .SDIO1_BUSVOLT(),
    .SPI0_SCLK_I(1'B0),
    .SPI0_SCLK_O(),
    .SPI0_SCLK_T(),
    .SPI0_MOSI_I(1'B0),
    .SPI0_MOSI_O(),
    .SPI0_MOSI_T(),
    .SPI0_MISO_I(1'B0),
    .SPI0_MISO_O(),
    .SPI0_MISO_T(),
    .SPI0_SS_I(1'B0),
    .SPI0_SS_O(),
    .SPI0_SS1_O(),
    .SPI0_SS2_O(),
    .SPI0_SS_T(),
    .SPI1_SCLK_I(1'B0),
    .SPI1_SCLK_O(),
    .SPI1_SCLK_T(),
    .SPI1_MOSI_I(1'B0),
    .SPI1_MOSI_O(),
    .SPI1_MOSI_T(),
    .SPI1_MISO_I(1'B0),
    .SPI1_MISO_O(),
    .SPI1_MISO_T(),
    .SPI1_SS_I(1'B0),
    .SPI1_SS_O(),
    .SPI1_SS1_O(),
    .SPI1_SS2_O(),
    .SPI1_SS_T(),
    .UART0_DTRN(),
    .UART0_RTSN(),
    .UART0_TX(),
    .UART0_CTSN(1'B0),
    .UART0_DCDN(1'B0),
    .UART0_DSRN(1'B0),
    .UART0_RIN(1'B0),
    .UART0_RX(1'B1),
    .UART1_DTRN(),
    .UART1_RTSN(),
    .UART1_TX(),
    .UART1_CTSN(1'B0),
    .UART1_DCDN(1'B0),
    .UART1_DSRN(1'B0),
    .UART1_RIN(1'B0),
    .UART1_RX(1'B1),
    .TTC0_WAVE0_OUT(),
    .TTC0_WAVE1_OUT(),
    .TTC0_WAVE2_OUT(),
    .TTC0_CLK0_IN(1'B0),
    .TTC0_CLK1_IN(1'B0),
    .TTC0_CLK2_IN(1'B0),
    .TTC1_WAVE0_OUT(),
    .TTC1_WAVE1_OUT(),
    .TTC1_WAVE2_OUT(),
    .TTC1_CLK0_IN(1'B0),
    .TTC1_CLK1_IN(1'B0),
    .TTC1_CLK2_IN(1'B0),
    .WDT_CLK_IN(1'B0),
    .WDT_RST_OUT(),
    .TRACE_CLK(1'B0),
    .TRACE_CLK_OUT(),
    .TRACE_CTL(),
    .TRACE_DATA(),
    .USB0_PORT_INDCTL(USB0_PORT_INDCTL),
    .USB0_VBUS_PWRSELECT(USB0_VBUS_PWRSELECT),
    .USB0_VBUS_PWRFAULT(USB0_VBUS_PWRFAULT),
    .USB1_PORT_INDCTL(),
    .USB1_VBUS_PWRSELECT(),
    .USB1_VBUS_PWRFAULT(1'B0),
    .SRAM_INTIN(1'B0),

    .M_AXI_GP0_ACLK(M_AXI_GP0_ACLK),
    .M_AXI_GP0_ARESETN(M_AXI_GP0_ARESETN),
    .M_AXI_GP0_ARVALID(M_AXI_GP0_ARVALID),
    .M_AXI_GP0_AWVALID(M_AXI_GP0_AWVALID),
    .M_AXI_GP0_BREADY(M_AXI_GP0_BREADY),
    .M_AXI_GP0_RREADY(M_AXI_GP0_RREADY),
    .M_AXI_GP0_WLAST(M_AXI_GP0_WLAST),
    .M_AXI_GP0_WVALID(M_AXI_GP0_WVALID),
    .M_AXI_GP0_ARID(M_AXI_GP0_ARID),
    .M_AXI_GP0_AWID(M_AXI_GP0_AWID),
    .M_AXI_GP0_WID(M_AXI_GP0_WID),
    .M_AXI_GP0_ARBURST(M_AXI_GP0_ARBURST),
    .M_AXI_GP0_ARLOCK(M_AXI_GP0_ARLOCK),
    .M_AXI_GP0_ARSIZE(M_AXI_GP0_ARSIZE),
    .M_AXI_GP0_AWBURST(M_AXI_GP0_AWBURST),
    .M_AXI_GP0_AWLOCK(M_AXI_GP0_AWLOCK),
    .M_AXI_GP0_AWSIZE(M_AXI_GP0_AWSIZE),
    .M_AXI_GP0_ARPROT(M_AXI_GP0_ARPROT),
    .M_AXI_GP0_AWPROT(M_AXI_GP0_AWPROT),
    .M_AXI_GP0_ARADDR(M_AXI_GP0_ARADDR),
    .M_AXI_GP0_AWADDR(M_AXI_GP0_AWADDR),
    .M_AXI_GP0_WDATA(M_AXI_GP0_WDATA),
    .M_AXI_GP0_ARCACHE(M_AXI_GP0_ARCACHE),
    .M_AXI_GP0_ARLEN(M_AXI_GP0_ARLEN),
    .M_AXI_GP0_ARQOS(M_AXI_GP0_ARQOS),
    .M_AXI_GP0_AWCACHE(M_AXI_GP0_AWCACHE),
    .M_AXI_GP0_AWLEN(M_AXI_GP0_AWLEN),
    .M_AXI_GP0_AWQOS(M_AXI_GP0_AWQOS),
    .M_AXI_GP0_WSTRB(M_AXI_GP0_WSTRB),
    .M_AXI_GP0_ARREADY(M_AXI_GP0_ARREADY),
    .M_AXI_GP0_AWREADY(M_AXI_GP0_AWREADY),
    .M_AXI_GP0_BVALID(M_AXI_GP0_BVALID),
    .M_AXI_GP0_RLAST(M_AXI_GP0_RLAST),
    .M_AXI_GP0_RVALID(M_AXI_GP0_RVALID),
    .M_AXI_GP0_WREADY(M_AXI_GP0_WREADY),
    .M_AXI_GP0_BID(M_AXI_GP0_BID),
    .M_AXI_GP0_RID(M_AXI_GP0_RID),
    .M_AXI_GP0_BRESP(M_AXI_GP0_BRESP),
    .M_AXI_GP0_RRESP(M_AXI_GP0_RRESP),
    .M_AXI_GP0_RDATA(M_AXI_GP0_RDATA),

    .M_AXI_GP1_ARVALID(),
    .M_AXI_GP1_AWVALID(),
    .M_AXI_GP1_BREADY(),
    .M_AXI_GP1_RREADY(),
    .M_AXI_GP1_WLAST(),
    .M_AXI_GP1_WVALID(),
    .M_AXI_GP1_ARID(),
    .M_AXI_GP1_AWID(),
    .M_AXI_GP1_WID(),
    .M_AXI_GP1_ARBURST(),
    .M_AXI_GP1_ARLOCK(),
    .M_AXI_GP1_ARSIZE(),
    .M_AXI_GP1_AWBURST(),
    .M_AXI_GP1_AWLOCK(),
    .M_AXI_GP1_AWSIZE(),
    .M_AXI_GP1_ARPROT(),
    .M_AXI_GP1_AWPROT(),
    .M_AXI_GP1_ARADDR(),
    .M_AXI_GP1_AWADDR(),
    .M_AXI_GP1_WDATA(),
    .M_AXI_GP1_ARCACHE(),
    .M_AXI_GP1_ARLEN(),
    .M_AXI_GP1_ARQOS(),
    .M_AXI_GP1_AWCACHE(),
    .M_AXI_GP1_AWLEN(),
    .M_AXI_GP1_AWQOS(),
    .M_AXI_GP1_WSTRB(),
    .M_AXI_GP1_ACLK(1'B0),
    .M_AXI_GP1_ARREADY(1'B0),
    .M_AXI_GP1_AWREADY(1'B0),
    .M_AXI_GP1_BVALID(1'B0),
    .M_AXI_GP1_RLAST(1'B0),
    .M_AXI_GP1_RVALID(1'B0),
    .M_AXI_GP1_WREADY(1'B0),
    .M_AXI_GP1_BID(12'B0),
    .M_AXI_GP1_RID(12'B0),
    .M_AXI_GP1_BRESP(2'B0),
    .M_AXI_GP1_RRESP(2'B0),
    .M_AXI_GP1_RDATA(32'B0),
    .S_AXI_GP0_ARREADY(),
    .S_AXI_GP0_AWREADY(),
    .S_AXI_GP0_BVALID(),
    .S_AXI_GP0_RLAST(),
    .S_AXI_GP0_RVALID(),
    .S_AXI_GP0_WREADY(),
    .S_AXI_GP0_BRESP(),
    .S_AXI_GP0_RRESP(),
    .S_AXI_GP0_RDATA(),
    .S_AXI_GP0_BID(),
    .S_AXI_GP0_RID(),
    .S_AXI_GP0_ACLK(1'B0),
    .S_AXI_GP0_ARVALID(1'B0),
    .S_AXI_GP0_AWVALID(1'B0),
    .S_AXI_GP0_BREADY(1'B0),
    .S_AXI_GP0_RREADY(1'B0),
    .S_AXI_GP0_WLAST(1'B0),
    .S_AXI_GP0_WVALID(1'B0),
    .S_AXI_GP0_ARBURST(2'B0),
    .S_AXI_GP0_ARLOCK(2'B0),
    .S_AXI_GP0_ARSIZE(3'B0),
    .S_AXI_GP0_AWBURST(2'B0),
    .S_AXI_GP0_AWLOCK(2'B0),
    .S_AXI_GP0_AWSIZE(3'B0),
    .S_AXI_GP0_ARPROT(3'B0),
    .S_AXI_GP0_AWPROT(3'B0),
    .S_AXI_GP0_ARADDR(32'B0),
    .S_AXI_GP0_AWADDR(32'B0),
    .S_AXI_GP0_WDATA(32'B0),
    .S_AXI_GP0_ARCACHE(4'B0),
    .S_AXI_GP0_ARLEN(4'B0),
    .S_AXI_GP0_ARQOS(4'B0),
    .S_AXI_GP0_AWCACHE(4'B0),
    .S_AXI_GP0_AWLEN(4'B0),
    .S_AXI_GP0_AWQOS(4'B0),
    .S_AXI_GP0_WSTRB(4'B0),
    .S_AXI_GP0_ARID(6'B0),
    .S_AXI_GP0_AWID(6'B0),
    .S_AXI_GP0_WID(6'B0),
    .S_AXI_GP1_ARREADY(),
    .S_AXI_GP1_AWREADY(),
    .S_AXI_GP1_BVALID(),
    .S_AXI_GP1_RLAST(),
    .S_AXI_GP1_RVALID(),
    .S_AXI_GP1_WREADY(),
    .S_AXI_GP1_BRESP(),
    .S_AXI_GP1_RRESP(),
    .S_AXI_GP1_RDATA(),
    .S_AXI_GP1_BID(),
    .S_AXI_GP1_RID(),
    .S_AXI_GP1_ACLK(1'B0),
    .S_AXI_GP1_ARVALID(1'B0),
    .S_AXI_GP1_AWVALID(1'B0),
    .S_AXI_GP1_BREADY(1'B0),
    .S_AXI_GP1_RREADY(1'B0),
    .S_AXI_GP1_WLAST(1'B0),
    .S_AXI_GP1_WVALID(1'B0),
    .S_AXI_GP1_ARBURST(2'B0),
    .S_AXI_GP1_ARLOCK(2'B0),
    .S_AXI_GP1_ARSIZE(3'B0),
    .S_AXI_GP1_AWBURST(2'B0),
    .S_AXI_GP1_AWLOCK(2'B0),
    .S_AXI_GP1_AWSIZE(3'B0),
    .S_AXI_GP1_ARPROT(3'B0),
    .S_AXI_GP1_AWPROT(3'B0),
    .S_AXI_GP1_ARADDR(32'B0),
    .S_AXI_GP1_AWADDR(32'B0),
    .S_AXI_GP1_WDATA(32'B0),
    .S_AXI_GP1_ARCACHE(4'B0),
    .S_AXI_GP1_ARLEN(4'B0),
    .S_AXI_GP1_ARQOS(4'B0),
    .S_AXI_GP1_AWCACHE(4'B0),
    .S_AXI_GP1_AWLEN(4'B0),
    .S_AXI_GP1_AWQOS(4'B0),
    .S_AXI_GP1_WSTRB(4'B0),
    .S_AXI_GP1_ARID(6'B0),
    .S_AXI_GP1_AWID(6'B0),
    .S_AXI_GP1_WID(6'B0),
    .S_AXI_ACP_ARREADY(),
    .S_AXI_ACP_AWREADY(),
    .S_AXI_ACP_BVALID(),
    .S_AXI_ACP_RLAST(),
    .S_AXI_ACP_RVALID(),
    .S_AXI_ACP_WREADY(),
    .S_AXI_ACP_BRESP(),
    .S_AXI_ACP_RRESP(),
    .S_AXI_ACP_BID(),
    .S_AXI_ACP_RID(),
    .S_AXI_ACP_RDATA(),
    .S_AXI_ACP_ACLK(1'B0),
    .S_AXI_ACP_ARVALID(1'B0),
    .S_AXI_ACP_AWVALID(1'B0),
    .S_AXI_ACP_BREADY(1'B0),
    .S_AXI_ACP_RREADY(1'B0),
    .S_AXI_ACP_WLAST(1'B0),
    .S_AXI_ACP_WVALID(1'B0),
    .S_AXI_ACP_ARID(3'B0),
    .S_AXI_ACP_ARPROT(3'B0),
    .S_AXI_ACP_AWID(3'B0),
    .S_AXI_ACP_AWPROT(3'B0),
    .S_AXI_ACP_WID(3'B0),
    .S_AXI_ACP_ARADDR(32'B0),
    .S_AXI_ACP_AWADDR(32'B0),
    .S_AXI_ACP_ARCACHE(4'B0),
    .S_AXI_ACP_ARLEN(4'B0),
    .S_AXI_ACP_ARQOS(4'B0),
    .S_AXI_ACP_AWCACHE(4'B0),
    .S_AXI_ACP_AWLEN(4'B0),
    .S_AXI_ACP_AWQOS(4'B0),
    .S_AXI_ACP_ARBURST(2'B0),
    .S_AXI_ACP_ARLOCK(2'B0),
    .S_AXI_ACP_ARSIZE(3'B0),
    .S_AXI_ACP_AWBURST(2'B0),
    .S_AXI_ACP_AWLOCK(2'B0),
    .S_AXI_ACP_AWSIZE(3'B0),
    .S_AXI_ACP_ARUSER(5'B0),
    .S_AXI_ACP_AWUSER(5'B0),
    .S_AXI_ACP_WDATA(64'B0),
    .S_AXI_ACP_WSTRB(8'B0),
    .S_AXI_HP0_ARREADY(),
    .S_AXI_HP0_AWREADY(),
    .S_AXI_HP0_BVALID(),
    .S_AXI_HP0_RLAST(),
    .S_AXI_HP0_RVALID(),
    .S_AXI_HP0_WREADY(),
    .S_AXI_HP0_BRESP(),
    .S_AXI_HP0_RRESP(),
    .S_AXI_HP0_BID(),
    .S_AXI_HP0_RID(),
    .S_AXI_HP0_RDATA(),
    .S_AXI_HP0_RCOUNT(),
    .S_AXI_HP0_WCOUNT(),
    .S_AXI_HP0_RACOUNT(),
    .S_AXI_HP0_WACOUNT(),
    .S_AXI_HP0_ACLK(1'B0),
    .S_AXI_HP0_ARVALID(1'B0),
    .S_AXI_HP0_AWVALID(1'B0),
    .S_AXI_HP0_BREADY(1'B0),
    .S_AXI_HP0_RDISSUECAP1_EN(1'B0),
    .S_AXI_HP0_RREADY(1'B0),
    .S_AXI_HP0_WLAST(1'B0),
    .S_AXI_HP0_WRISSUECAP1_EN(1'B0),
    .S_AXI_HP0_WVALID(1'B0),
    .S_AXI_HP0_ARBURST(2'B0),
    .S_AXI_HP0_ARLOCK(2'B0),
    .S_AXI_HP0_ARSIZE(3'B0),
    .S_AXI_HP0_AWBURST(2'B0),
    .S_AXI_HP0_AWLOCK(2'B0),
    .S_AXI_HP0_AWSIZE(3'B0),
    .S_AXI_HP0_ARPROT(3'B0),
    .S_AXI_HP0_AWPROT(3'B0),
    .S_AXI_HP0_ARADDR(32'B0),
    .S_AXI_HP0_AWADDR(32'B0),
    .S_AXI_HP0_ARCACHE(4'B0),
    .S_AXI_HP0_ARLEN(4'B0),
    .S_AXI_HP0_ARQOS(4'B0),
    .S_AXI_HP0_AWCACHE(4'B0),
    .S_AXI_HP0_AWLEN(4'B0),
    .S_AXI_HP0_AWQOS(4'B0),
    .S_AXI_HP0_ARID(6'B0),
    .S_AXI_HP0_AWID(6'B0),
    .S_AXI_HP0_WID(6'B0),
    .S_AXI_HP0_WDATA(64'B0),
    .S_AXI_HP0_WSTRB(8'B0),
    .S_AXI_HP1_ARREADY(),
    .S_AXI_HP1_AWREADY(),
    .S_AXI_HP1_BVALID(),
    .S_AXI_HP1_RLAST(),
    .S_AXI_HP1_RVALID(),
    .S_AXI_HP1_WREADY(),
    .S_AXI_HP1_BRESP(),
    .S_AXI_HP1_RRESP(),
    .S_AXI_HP1_BID(),
    .S_AXI_HP1_RID(),
    .S_AXI_HP1_RDATA(),
    .S_AXI_HP1_RCOUNT(),
    .S_AXI_HP1_WCOUNT(),
    .S_AXI_HP1_RACOUNT(),
    .S_AXI_HP1_WACOUNT(),
    .S_AXI_HP1_ACLK(1'B0),
    .S_AXI_HP1_ARVALID(1'B0),
    .S_AXI_HP1_AWVALID(1'B0),
    .S_AXI_HP1_BREADY(1'B0),
    .S_AXI_HP1_RDISSUECAP1_EN(1'B0),
    .S_AXI_HP1_RREADY(1'B0),
    .S_AXI_HP1_WLAST(1'B0),
    .S_AXI_HP1_WRISSUECAP1_EN(1'B0),
    .S_AXI_HP1_WVALID(1'B0),
    .S_AXI_HP1_ARBURST(2'B0),
    .S_AXI_HP1_ARLOCK(2'B0),
    .S_AXI_HP1_ARSIZE(3'B0),
    .S_AXI_HP1_AWBURST(2'B0),
    .S_AXI_HP1_AWLOCK(2'B0),
    .S_AXI_HP1_AWSIZE(3'B0),
    .S_AXI_HP1_ARPROT(3'B0),
    .S_AXI_HP1_AWPROT(3'B0),
    .S_AXI_HP1_ARADDR(32'B0),
    .S_AXI_HP1_AWADDR(32'B0),
    .S_AXI_HP1_ARCACHE(4'B0),
    .S_AXI_HP1_ARLEN(4'B0),
    .S_AXI_HP1_ARQOS(4'B0),
    .S_AXI_HP1_AWCACHE(4'B0),
    .S_AXI_HP1_AWLEN(4'B0),
    .S_AXI_HP1_AWQOS(4'B0),
    .S_AXI_HP1_ARID(6'B0),
    .S_AXI_HP1_AWID(6'B0),
    .S_AXI_HP1_WID(6'B0),
    .S_AXI_HP1_WDATA(64'B0),
    .S_AXI_HP1_WSTRB(8'B0),
    .S_AXI_HP2_ARREADY(),
    .S_AXI_HP2_AWREADY(),
    .S_AXI_HP2_BVALID(),
    .S_AXI_HP2_RLAST(),
    .S_AXI_HP2_RVALID(),
    .S_AXI_HP2_WREADY(),
    .S_AXI_HP2_BRESP(),
    .S_AXI_HP2_RRESP(),
    .S_AXI_HP2_BID(),
    .S_AXI_HP2_RID(),
    .S_AXI_HP2_RDATA(),
    .S_AXI_HP2_RCOUNT(),
    .S_AXI_HP2_WCOUNT(),
    .S_AXI_HP2_RACOUNT(),
    .S_AXI_HP2_WACOUNT(),
    .S_AXI_HP2_ACLK(1'B0),
    .S_AXI_HP2_ARVALID(1'B0),
    .S_AXI_HP2_AWVALID(1'B0),
    .S_AXI_HP2_BREADY(1'B0),
    .S_AXI_HP2_RDISSUECAP1_EN(1'B0),
    .S_AXI_HP2_RREADY(1'B0),
    .S_AXI_HP2_WLAST(1'B0),
    .S_AXI_HP2_WRISSUECAP1_EN(1'B0),
    .S_AXI_HP2_WVALID(1'B0),
    .S_AXI_HP2_ARBURST(2'B0),
    .S_AXI_HP2_ARLOCK(2'B0),
    .S_AXI_HP2_ARSIZE(3'B0),
    .S_AXI_HP2_AWBURST(2'B0),
    .S_AXI_HP2_AWLOCK(2'B0),
    .S_AXI_HP2_AWSIZE(3'B0),
    .S_AXI_HP2_ARPROT(3'B0),
    .S_AXI_HP2_AWPROT(3'B0),
    .S_AXI_HP2_ARADDR(32'B0),
    .S_AXI_HP2_AWADDR(32'B0),
    .S_AXI_HP2_ARCACHE(4'B0),
    .S_AXI_HP2_ARLEN(4'B0),
    .S_AXI_HP2_ARQOS(4'B0),
    .S_AXI_HP2_AWCACHE(4'B0),
    .S_AXI_HP2_AWLEN(4'B0),
    .S_AXI_HP2_AWQOS(4'B0),
    .S_AXI_HP2_ARID(6'B0),
    .S_AXI_HP2_AWID(6'B0),
    .S_AXI_HP2_WID(6'B0),
    .S_AXI_HP2_WDATA(64'B0),
    .S_AXI_HP2_WSTRB(8'B0),
    .S_AXI_HP3_ARREADY(),
    .S_AXI_HP3_AWREADY(),
    .S_AXI_HP3_BVALID(),
    .S_AXI_HP3_RLAST(),
    .S_AXI_HP3_RVALID(),
    .S_AXI_HP3_WREADY(),
    .S_AXI_HP3_BRESP(),
    .S_AXI_HP3_RRESP(),
    .S_AXI_HP3_BID(),
    .S_AXI_HP3_RID(),
    .S_AXI_HP3_RDATA(),
    .S_AXI_HP3_RCOUNT(),
    .S_AXI_HP3_WCOUNT(),
    .S_AXI_HP3_RACOUNT(),
    .S_AXI_HP3_WACOUNT(),
    .S_AXI_HP3_ACLK(1'B0),
    .S_AXI_HP3_ARVALID(1'B0),
    .S_AXI_HP3_AWVALID(1'B0),
    .S_AXI_HP3_BREADY(1'B0),
    .S_AXI_HP3_RDISSUECAP1_EN(1'B0),
    .S_AXI_HP3_RREADY(1'B0),
    .S_AXI_HP3_WLAST(1'B0),
    .S_AXI_HP3_WRISSUECAP1_EN(1'B0),
    .S_AXI_HP3_WVALID(1'B0),
    .S_AXI_HP3_ARBURST(2'B0),
    .S_AXI_HP3_ARLOCK(2'B0),
    .S_AXI_HP3_ARSIZE(3'B0),
    .S_AXI_HP3_AWBURST(2'B0),
    .S_AXI_HP3_AWLOCK(2'B0),
    .S_AXI_HP3_AWSIZE(3'B0),
    .S_AXI_HP3_ARPROT(3'B0),
    .S_AXI_HP3_AWPROT(3'B0),
    .S_AXI_HP3_ARADDR(32'B0),
    .S_AXI_HP3_AWADDR(32'B0),
    .S_AXI_HP3_ARCACHE(4'B0),
    .S_AXI_HP3_ARLEN(4'B0),
    .S_AXI_HP3_ARQOS(4'B0),
    .S_AXI_HP3_AWCACHE(4'B0),
    .S_AXI_HP3_AWLEN(4'B0),
    .S_AXI_HP3_AWQOS(4'B0),
    .S_AXI_HP3_ARID(6'B0),
    .S_AXI_HP3_AWID(6'B0),
    .S_AXI_HP3_WID(6'B0),
    .S_AXI_HP3_WDATA(64'B0),
    .S_AXI_HP3_WSTRB(8'B0),
    .IRQ_P2F_DMAC_ABORT(),
    .IRQ_P2F_DMAC0(),
    .IRQ_P2F_DMAC1(),
    .IRQ_P2F_DMAC2(),
    .IRQ_P2F_DMAC3(),
    .IRQ_P2F_DMAC4(),
    .IRQ_P2F_DMAC5(),
    .IRQ_P2F_DMAC6(),
    .IRQ_P2F_DMAC7(),
    .IRQ_P2F_SMC(),
    .IRQ_P2F_QSPI(),
    .IRQ_P2F_CTI(),
    .IRQ_P2F_GPIO(),
    .IRQ_P2F_USB0(),
    .IRQ_P2F_ENET0(),
    .IRQ_P2F_ENET_WAKE0(),
    .IRQ_P2F_SDIO0(),
    .IRQ_P2F_I2C0(),
    .IRQ_P2F_SPI0(),
    .IRQ_P2F_UART0(),
    .IRQ_P2F_CAN0(),
    .IRQ_P2F_USB1(),
    .IRQ_P2F_ENET1(),
    .IRQ_P2F_ENET_WAKE1(),
    .IRQ_P2F_SDIO1(),
    .IRQ_P2F_I2C1(),
    .IRQ_P2F_SPI1(),
    .IRQ_P2F_UART1(),
    .IRQ_P2F_CAN1(),
    .IRQ_F2P(1'B0),
    .Core0_nFIQ(1'B0),
    .Core0_nIRQ(1'B0),
    .Core1_nFIQ(1'B0),
    .Core1_nIRQ(1'B0),
    .DMA0_DATYPE(),
    .DMA0_DAVALID(),
    .DMA0_DRREADY(),
    .DMA1_DATYPE(),
    .DMA1_DAVALID(),
    .DMA1_DRREADY(),
    .DMA2_DATYPE(),
    .DMA2_DAVALID(),
    .DMA2_DRREADY(),
    .DMA3_DATYPE(),
    .DMA3_DAVALID(),
    .DMA3_DRREADY(),
    .DMA0_ACLK(1'B0),
    .DMA0_DAREADY(1'B0),
    .DMA0_DRLAST(1'B0),
    .DMA0_DRVALID(1'B0),
    .DMA1_ACLK(1'B0),
    .DMA1_DAREADY(1'B0),
    .DMA1_DRLAST(1'B0),
    .DMA1_DRVALID(1'B0),
    .DMA2_ACLK(1'B0),
    .DMA2_DAREADY(1'B0),
    .DMA2_DRLAST(1'B0),
    .DMA2_DRVALID(1'B0),
    .DMA3_ACLK(1'B0),
    .DMA3_DAREADY(1'B0),
    .DMA3_DRLAST(1'B0),
    .DMA3_DRVALID(1'B0),
    .DMA0_DRTYPE(2'B0),
    .DMA1_DRTYPE(2'B0),
    .DMA2_DRTYPE(2'B0),
    .DMA3_DRTYPE(2'B0),
    .FCLK_CLK0(FCLK_CLK0),
    .FCLK_CLK1(),
    .FCLK_CLK2(),
    .FCLK_CLK3(),
    .FCLK_CLKTRIG0_N(1'B0),
    .FCLK_CLKTRIG1_N(1'B0),
    .FCLK_CLKTRIG2_N(1'B0),
    .FCLK_CLKTRIG3_N(1'B0),
    .FCLK_RESET0_N(FCLK_RESET0_N),
    .FCLK_RESET1_N(),
    .FCLK_RESET2_N(),
    .FCLK_RESET3_N(),
    .FTMD_TRACEIN_DATA(32'B0),
    .FTMD_TRACEIN_VALID(1'B0),
    .FTMD_TRACEIN_CLK(1'B0),
    .FTMD_TRACEIN_ATID(4'B0),
    .FTMT_F2P_TRIG_0(1'B0),
    .FTMT_F2P_TRIGACK_0(),
    .FTMT_F2P_TRIG_1(1'B0),
    .FTMT_F2P_TRIGACK_1(),
    .FTMT_F2P_TRIG_2(1'B0),
    .FTMT_F2P_TRIGACK_2(),
    .FTMT_F2P_TRIG_3(1'B0),
    .FTMT_F2P_TRIGACK_3(),
    .FTMT_F2P_DEBUG(32'B0),
    .FTMT_P2F_TRIGACK_0(1'B0),
    .FTMT_P2F_TRIG_0(),
    .FTMT_P2F_TRIGACK_1(1'B0),
    .FTMT_P2F_TRIG_1(),
    .FTMT_P2F_TRIGACK_2(1'B0),
    .FTMT_P2F_TRIG_2(),
    .FTMT_P2F_TRIGACK_3(1'B0),
    .FTMT_P2F_TRIG_3(),
    .FTMT_P2F_DEBUG(),
    .FPGA_IDLE_N(1'B0),
    .EVENT_EVENTO(),
    .EVENT_STANDBYWFE(),
    .EVENT_STANDBYWFI(),
    .EVENT_EVENTI(1'B0),
    .DDR_ARB(4'B0),

    .MIO(MIO),

    .DDR_CAS_n(DDR_CAS_n),
    .DDR_CKE(DDR_CKE),
    .DDR_Clk_n(DDR_Clk_n),
    .DDR_Clk(DDR_Clk),
    .DDR_CS_n(DDR_CS_n),
    .DDR_DRSTB(DDR_DRSTB),
    .DDR_ODT(DDR_ODT),
    .DDR_RAS_n(DDR_RAS_n),
    .DDR_WEB(DDR_WEB),
    .DDR_BankAddr(DDR_BankAddr),
    .DDR_Addr(DDR_Addr),
    .DDR_VRN(DDR_VRN),
    .DDR_VRP(DDR_VRP),
    .DDR_DM(DDR_DM),
    .DDR_DQ(DDR_DQ),
    .DDR_DQS_n(DDR_DQS_n),
    .DDR_DQS(DDR_DQS),

    .M_AXI_GP1_ARESETN(M_AXI_GP1_ARESETN),
    .S_AXI_GP0_ARESETN(S_AXI_GP0_ARESETN),
    .S_AXI_GP1_ARESETN(S_AXI_GP1_ARESETN),
    .S_AXI_ACP_ARESETN(S_AXI_ACP_ARESETN),
    .S_AXI_HP0_ARESETN(S_AXI_HP0_ARESETN),
    .S_AXI_HP1_ARESETN(S_AXI_HP1_ARESETN),
    .S_AXI_HP2_ARESETN(S_AXI_HP2_ARESETN),
    .S_AXI_HP3_ARESETN(S_AXI_HP3_ARESETN),
    .DMA0_RSTN(DMA0_RSTN),
    .DMA1_RSTN(DMA1_RSTN),
    .DMA2_RSTN(DMA2_RSTN),
    .DMA3_RSTN(DMA3_RSTN),

    .PS_SRSTB(PS_SRSTB),
    .PS_CLK(PS_CLK),
    .PS_PORB(PS_PORB)
  );
endmodule
