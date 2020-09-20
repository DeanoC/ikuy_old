#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// AXI_HP Interface (AFI)
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 4 banks of axi_hp chips
#define axi_hp0_BASE_ADDR 0xf8008000
#define axi_hp1_BASE_ADDR 0xf8009000
#define axi_hp2_BASE_ADDR 0xf800a000
#define axi_hp3_BASE_ADDR 0xf800b000

// Read Channel Control Register
#define axi_hp_AFI_RDCHAN_CTRL_OFFSET 0x00000000

// Read Issuing Capability Register
#define axi_hp_AFI_RDCHAN_ISSUINGCAP_OFFSET 0x00000004

// QOS Read Channel Register
#define axi_hp_AFI_RDQOS_OFFSET 0x00000008

// Read Data FIFO Level Register
#define axi_hp_AFI_RDDATAFIFO_LEVEL_OFFSET 0x0000000c

// Read Channel Debug Register
#define axi_hp_AFI_RDDEBUG_OFFSET 0x00000010

// Write Channel Control Register
#define axi_hp_AFI_WRCHAN_CTRL_OFFSET 0x00000014

// Write Issuing Capability Register
#define axi_hp_AFI_WRCHAN_ISSUINGCAP_OFFSET 0x00000018

// QOS Write Channel Register
#define axi_hp_AFI_WRQOS_OFFSET 0x0000001c

// Write Data FIFO Level Register
#define axi_hp_AFI_WRDATAFIFO_LEVEL_OFFSET 0x00000020

// Write Channel Debug Register
#define axi_hp_AFI_WRDEBUG_OFFSET 0x00000024
