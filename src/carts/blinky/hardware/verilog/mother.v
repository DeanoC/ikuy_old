`timescale 1ns / 1ps

module main(
  input wire sys_clock,
  output wire [3:0] leds,
  input wire [1:0] switches,
  output wire [2:0] led4,
  output wire [2:0] led5,

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
  
  inout wire [53:0]FIXED_IO_mio,
  inout wire FIXED_IO_ps_clk,
  inout wire FIXED_IO_ps_porb,
  inout wire FIXED_IO_ps_srstb

);
  wire PSM_AXI_GP0_ACLK;
  wire PSM_AXI_GP0_ARESETN;
  wire PSM_AXI_GP0_ARVALID;
  wire PSM_AXI_GP0_AWVALID;
  wire PSM_AXI_GP0_BREADY;
  wire PSM_AXI_GP0_RREADY;
  wire PSM_AXI_GP0_WLAST;
  wire PSM_AXI_GP0_WVALID;
  wire [11 : 0] PSM_AXI_GP0_ARID;
  wire [11 : 0] PSM_AXI_GP0_AWID;
  wire [11 : 0] PSM_AXI_GP0_WID;
  wire [1 : 0] PSM_AXI_GP0_ARBURST;
  wire [1 : 0] PSM_AXI_GP0_ARLOCK;
  wire [2 : 0] PSM_AXI_GP0_ARSIZE;
  wire [1 : 0] PSM_AXI_GP0_AWBURST;
  wire [1 : 0] PSM_AXI_GP0_AWLOCK;
  wire [2 : 0] PSM_AXI_GP0_AWSIZE;
  wire [2 : 0] PSM_AXI_GP0_ARPROT;
  wire [2 : 0] PSM_AXI_GP0_AWPROT;
  wire [31 : 0] PSM_AXI_GP0_ARADDR;
  wire [31 : 0] PSM_AXI_GP0_AWADDR;
  wire [31 : 0] PSM_AXI_GP0_WDATA;
  wire [3 : 0] PSM_AXI_GP0_ARCACHE;
  wire [3 : 0] PSM_AXI_GP0_ARLEN;
  wire [3 : 0] PSM_AXI_GP0_ARQOS;
  wire [3 : 0] PSM_AXI_GP0_AWCACHE;
  wire [3 : 0] PSM_AXI_GP0_AWLEN;
  wire [3 : 0] PSM_AXI_GP0_AWQOS;
  wire [3 : 0] PSM_AXI_GP0_WSTRB;
  wire PSM_AXI_GP0_ARREADY;
  wire PSM_AXI_GP0_AWREADY;
  wire PSM_AXI_GP0_BVALID;
  wire PSM_AXI_GP0_RLAST;
  wire PSM_AXI_GP0_RVALID;
  wire PSM_AXI_GP0_WREADY;
  wire [11 : 0] PSM_AXI_GP0_BID;
  wire [11 : 0] PSM_AXI_GP0_RID;
  wire [1 : 0] PSM_AXI_GP0_BRESP;
  wire [1 : 0] PSM_AXI_GP0_RRESP;
  wire [31 : 0] PSM_AXI_GP0_RDATA;


  Ps7BlackBox ps7(
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

    .FIXED_IO_mio(FIXED_IO_mio[53:0]),

    .FIXED_IO_ps_clk(FIXED_IO_ps_clk),
    .FIXED_IO_ps_porb(FIXED_IO_ps_porb),
    .FIXED_IO_ps_srstb(FIXED_IO_ps_srstb),

    .PSM_AXI_GP0_ACLK(PSM_AXI_GP0_ACLK),
    .PSM_AXI_GP0_ARESETN(PSM_AXI_GP0_ARESETN),
    .PSM_AXI_GP0_AWID(PSM_AXI_GP0_AWID),
    .PSM_AXI_GP0_AWVALID(PSM_AXI_GP0_AWVALID),
    .PSM_AXI_GP0_AWREADY(PSM_AXI_GP0_AWREADY),
    .PSM_AXI_GP0_AWBURST(PSM_AXI_GP0_AWBURST),
    .PSM_AXI_GP0_AWLOCK(PSM_AXI_GP0_AWLOCK),
    .PSM_AXI_GP0_AWSIZE(PSM_AXI_GP0_AWSIZE),
    .PSM_AXI_GP0_AWPROT(PSM_AXI_GP0_AWPROT),
    .PSM_AXI_GP0_AWADDR(PSM_AXI_GP0_AWADDR),
    .PSM_AXI_GP0_AWCACHE(PSM_AXI_GP0_AWCACHE),
    .PSM_AXI_GP0_AWLEN(PSM_AXI_GP0_AWLEN),
    .PSM_AXI_GP0_AWQOS(PSM_AXI_GP0_AWQOS),

    .PSM_AXI_GP0_ARID(PSM_AXI_GP0_ARID),
    .PSM_AXI_GP0_ARVALID(PSM_AXI_GP0_ARVALID),
    .PSM_AXI_GP0_ARBURST(PSM_AXI_GP0_ARBURST),
    .PSM_AXI_GP0_ARLOCK(PSM_AXI_GP0_ARLOCK),
    .PSM_AXI_GP0_ARSIZE(PSM_AXI_GP0_ARSIZE),
    .PSM_AXI_GP0_ARPROT(PSM_AXI_GP0_ARPROT),
    .PSM_AXI_GP0_ARADDR(PSM_AXI_GP0_ARADDR),
    .PSM_AXI_GP0_ARCACHE(PSM_AXI_GP0_ARCACHE),
    .PSM_AXI_GP0_ARLEN(PSM_AXI_GP0_ARLEN),
    .PSM_AXI_GP0_ARQOS(PSM_AXI_GP0_ARQOS),
    .PSM_AXI_GP0_ARREADY(PSM_AXI_GP0_ARREADY),

    .PSM_AXI_GP0_WID(PSM_AXI_GP0_WID),
    .PSM_AXI_GP0_WVALID(PSM_AXI_GP0_WVALID),
    .PSM_AXI_GP0_WREADY(PSM_AXI_GP0_WREADY),
    .PSM_AXI_GP0_WLAST(PSM_AXI_GP0_WLAST),
    .PSM_AXI_GP0_WSTRB(PSM_AXI_GP0_WSTRB),
    .PSM_AXI_GP0_WDATA(PSM_AXI_GP0_WDATA),

    .PSM_AXI_GP0_RID(PSM_AXI_GP0_RID),
    .PSM_AXI_GP0_RVALID(PSM_AXI_GP0_RVALID),
    .PSM_AXI_GP0_RREADY(PSM_AXI_GP0_RREADY),
    .PSM_AXI_GP0_RLAST(PSM_AXI_GP0_RLAST),
    .PSM_AXI_GP0_RRESP(PSM_AXI_GP0_RRESP),
    .PSM_AXI_GP0_RDATA(PSM_AXI_GP0_RDATA),

    .PSM_AXI_GP0_BID(PSM_AXI_GP0_BID),
    .PSM_AXI_GP0_BVALID(PSM_AXI_GP0_BVALID),
    .PSM_AXI_GP0_BREADY(PSM_AXI_GP0_BREADY),
    .PSM_AXI_GP0_BRESP(PSM_AXI_GP0_BRESP)
  );

  // zynq AXI are axi3 whereas everybody includign spinalHDL use
  // axi4 these days.

  // this converts PS master AXI3 to PL slave AXI4 for Zynq's AXI3
  wire [7:0] PSM_AXI_GP0_AWLEN_extended;
  wire [7:0] PSM_AXI_GP0_ARLEN_extended;
  reg [3:0] PSM_AXI_GP0_AWCACHE_converted;
  reg [3:0] PSM_AXI_GP0_ARCACHE_converted;

  assign PSM_AXI_GP0_AWLEN_extended = { 4'b0, PSM_AXI_GP0_AWLEN};
  assign PSM_AXI_GP0_ARLEN_extended = { 4'b0, PSM_AXI_GP0_ARLEN};
  assign PSM_AXI_GP0_ARLEN_extended = { 4'b0, PSM_AXI_GP0_ARLEN};

	always @(*)
	case(PSM_AXI_GP0_AWCACHE)
    4'b1010: PSM_AXI_GP0_AWCACHE_converted = 4'b1110;
    4'b1011: PSM_AXI_GP0_AWCACHE_converted = 4'b1111;
    default: PSM_AXI_GP0_AWCACHE_converted = PSM_AXI_GP0_AWCACHE;
	endcase

	always @(*)
	case(PSM_AXI_GP0_ARCACHE)
    4'b1010: PSM_AXI_GP0_ARCACHE_converted = 4'b1110;
    4'b1011: PSM_AXI_GP0_ARCACHE_converted = 4'b1111;
    default: PSM_AXI_GP0_ARCACHE_converted = PSM_AXI_GP0_ARCACHE;
	endcase

  Blinky blinky(
      .leds(leds[3:0]),
      .rgb_led0(led4),
      .rgb_led1(led5)
  );

endmodule

module BuildDummy();
endmodule
