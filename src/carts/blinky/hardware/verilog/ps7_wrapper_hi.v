//Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.1 (lin64) Build 2902540 Wed May 27 19:54:35 MDT 2020
//Date        : Wed Aug 26 12:52:01 2020
//Host        : Ubuntu20 running 64-bit Ubuntu 20.04.1 LTS
//Command     : generate_target justps7_wrapper.bd
//Design      : justps7_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module Ps7BlackBox (
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

  input wire PSM_AXI_GP0_ACLK,
  output wire PSM_AXI_GP0_ARESETN,
  output wire PSM_AXI_GP0_ARVALID,
  output wire PSM_AXI_GP0_AWVALID,
  output wire PSM_AXI_GP0_BREADY,
  output wire PSM_AXI_GP0_RREADY,
  output wire PSM_AXI_GP0_WLAST,
  output wire PSM_AXI_GP0_WVALID,
  output wire [11 : 0] PSM_AXI_GP0_ARID,
  output wire [11 : 0] PSM_AXI_GP0_AWID,
  output wire [11 : 0] PSM_AXI_GP0_WID,
  output wire [1 : 0] PSM_AXI_GP0_ARBURST,
  output wire [1 : 0] PSM_AXI_GP0_ARLOCK,
  output wire [2 : 0] PSM_AXI_GP0_ARSIZE,
  output wire [1 : 0] PSM_AXI_GP0_AWBURST,
  output wire [1 : 0] PSM_AXI_GP0_AWLOCK,
  output wire [2 : 0] PSM_AXI_GP0_AWSIZE,
  output wire [2 : 0] PSM_AXI_GP0_ARPROT,
  output wire [2 : 0] PSM_AXI_GP0_AWPROT,
  output wire [31 : 0] PSM_AXI_GP0_ARADDR,
  output wire [31 : 0] PSM_AXI_GP0_AWADDR,
  output wire [31 : 0] PSM_AXI_GP0_WDATA,
  output wire [3 : 0] PSM_AXI_GP0_ARCACHE,
  output wire [3 : 0] PSM_AXI_GP0_ARLEN,
  output wire [3 : 0] PSM_AXI_GP0_ARQOS,
  output wire [3 : 0] PSM_AXI_GP0_AWCACHE,
  output wire [3 : 0] PSM_AXI_GP0_AWLEN,
  output wire [3 : 0] PSM_AXI_GP0_AWQOS,
  output wire [3 : 0] PSM_AXI_GP0_WSTRB,
  input wire PSM_AXI_GP0_ARREADY,
  input wire PSM_AXI_GP0_AWREADY,
  input wire PSM_AXI_GP0_BVALID,
  input wire PSM_AXI_GP0_RLAST,
  input wire PSM_AXI_GP0_RVALID,
  input wire PSM_AXI_GP0_WREADY,
  input wire [11 : 0] PSM_AXI_GP0_BID,
  input wire [11 : 0] PSM_AXI_GP0_RID,
  input wire [1 : 0] PSM_AXI_GP0_BRESP,
  input wire [1 : 0] PSM_AXI_GP0_RRESP,
  input wire [31 : 0] PSM_AXI_GP0_RDATA,

  inout wire [53:0]FIXED_IO_mio,
  inout wire FIXED_IO_ps_clk,
  inout wire FIXED_IO_ps_porb,
  inout wire FIXED_IO_ps_srstb
  );

  ps7_lo_wrapper ps7_lo_i(
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

    .MIO(FIXED_IO_mio),
    
    .PS_CLK(FIXED_IO_ps_clk),
    .PS_PORB(FIXED_IO_ps_porb),
    .PS_SRSTB(FIXED_IO_ps_srstb),
    
    .M_AXI_GP0_ACLK(PSM_AXI_GP0_ACLK),
    .M_AXI_GP0_ARESETN(PSM_AXI_GP0_ARESETN),
    .M_AXI_GP0_ARVALID(PSM_AXI_GP0_ARVALID),
    .M_AXI_GP0_AWVALID(PSM_AXI_GP0_AWVALID),
    .M_AXI_GP0_BREADY(PSM_AXI_GP0_BREADY),
    .M_AXI_GP0_RREADY(PSM_AXI_GP0_RREADY),
    .M_AXI_GP0_WLAST(PSM_AXI_GP0_WLAST),
    .M_AXI_GP0_WVALID(PSM_AXI_GP0_WVALID),
    .M_AXI_GP0_ARID(PSM_AXI_GP0_ARID),
    .M_AXI_GP0_AWID(PSM_AXI_GP0_AWID),
    .M_AXI_GP0_WID(PSM_AXI_GP0_WID),
    .M_AXI_GP0_ARBURST(PSM_AXI_GP0_ARBURST),
    .M_AXI_GP0_ARLOCK(PSM_AXI_GP0_ARLOCK),
    .M_AXI_GP0_ARSIZE(PSM_AXI_GP0_ARSIZE),
    .M_AXI_GP0_AWBURST(PSM_AXI_GP0_AWBURST),
    .M_AXI_GP0_AWLOCK(PSM_AXI_GP0_AWLOCK),
    .M_AXI_GP0_AWSIZE(PSM_AXI_GP0_AWSIZE),
    .M_AXI_GP0_ARPROT(PSM_AXI_GP0_ARPROT),
    .M_AXI_GP0_AWPROT(PSM_AXI_GP0_AWPROT),
    .M_AXI_GP0_ARADDR(PSM_AXI_GP0_ARADDR),
    .M_AXI_GP0_AWADDR(PSM_AXI_GP0_AWADDR),
    .M_AXI_GP0_WDATA(PSM_AXI_GP0_WDATA),
    .M_AXI_GP0_ARCACHE(PSM_AXI_GP0_ARCACHE),
    .M_AXI_GP0_ARLEN(PSM_AXI_GP0_ARLEN),
    .M_AXI_GP0_ARQOS(PSM_AXI_GP0_ARQOS),
    .M_AXI_GP0_AWCACHE(PSM_AXI_GP0_AWCACHE),
    .M_AXI_GP0_AWLEN(PSM_AXI_GP0_AWLEN),
    .M_AXI_GP0_AWQOS(PSM_AXI_GP0_AWQOS),
    .M_AXI_GP0_WSTRB(PSM_AXI_GP0_WSTRB),
    .M_AXI_GP0_ARREADY(PSM_AXI_GP0_ARREADY),
    .M_AXI_GP0_AWREADY(PSM_AXI_GP0_AWREADY),
    .M_AXI_GP0_BVALID(PSM_AXI_GP0_BVALID),
    .M_AXI_GP0_RLAST(PSM_AXI_GP0_RLAST),
    .M_AXI_GP0_RVALID(PSM_AXI_GP0_RVALID),
    .M_AXI_GP0_WREADY(PSM_AXI_GP0_WREADY),
    .M_AXI_GP0_BID(PSM_AXI_GP0_BID),
    .M_AXI_GP0_RID(PSM_AXI_GP0_RID),
    .M_AXI_GP0_BRESP(PSM_AXI_GP0_BRESP),
    .M_AXI_GP0_RRESP(PSM_AXI_GP0_RRESP),
    .M_AXI_GP0_RDATA(PSM_AXI_GP0_RDATA),

    .M_AXI_GP1_ARESETN(),
    .S_AXI_GP0_ARESETN(),
    .S_AXI_GP1_ARESETN(),
    .S_AXI_ACP_ARESETN(),
    .S_AXI_HP0_ARESETN(),
    .S_AXI_HP1_ARESETN(),
    .S_AXI_HP2_ARESETN(),
    .S_AXI_HP3_ARESETN(),
    .DMA0_RSTN(),
    .DMA1_RSTN(),
    .DMA2_RSTN(),
    .DMA3_RSTN(),

    .USB0_PORT_INDCTL(),
    .USB0_VBUS_PWRSELECT(),
    .USB0_VBUS_PWRFAULT(),
    .FCLK_CLK0(),
    .FCLK_RESET0_N()
  );
endmodule
