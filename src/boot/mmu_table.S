/******************************************************************************
* Copyright (c) 2009 - 2020 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/
/*****************************************************************************/
/**
* @file translation_table.s
*
* @addtogroup a9_boot_code
* @{
* <h2> translation_table.S </h2>
* translation_table.S contains a static page table required by MMU for
* cortex-A9. This translation table is flat mapped (input address = output
* address) with default memory attributes defined for zynq architecture. It
* utilizes short descriptor translation table format with each section defining
* 1MB of memory.
*
* The overview of translation table memory attributes is described below.
*
*|                       | Memory Range            | Definition in Translation Table   |
*|-----------------------|-------------------------|-----------------------------------|
*| Reserved              | 0x00000000 - 0x000FFFFF | Unassigned                        |
*| DDR                   | 0x00100000 - 0x3FFFFFFF | Normal write-back Cacheable       |
*| PL                    | 0x40000000 - 0xBFFFFFFF | Strongly Ordered                  |
*| Reserved              | 0xC0000000 - 0xDFFFFFFF | Unassigned                        |
*| Memory mapped devices | 0xE0000000 - 0xE02FFFFF | Device Memory                     |
*| Reserved              | 0xE0300000 - 0xE0FFFFFF | Unassigned                        |
*| NAND, NOR             | 0xE1000000 - 0xE3FFFFFF | Device memory                     |
*| SRAM                  | 0xE4000000 - 0xE5FFFFFF | Normal write-back Cacheable       |
*| Reserved              | 0xE6000000 - 0xF7FFFFFF | Unassigned                        |
*| AMBA APB Peripherals  | 0xF8000000 - 0xF8FFFFFF | Device Memory                     |
*| Reserved              | 0xF9000000 - 0xFBFFFFFF | Unassigned                        |
*| Linear QSPI - XIP     | 0xFC000000 - 0xFDFFFFFF | Normal write-through cacheable    |
*| Reserved              | 0xFE000000 - 0xFFEFFFFF | Unassigned                        |
*| OCM                   | 0xFFF00000 - 0xFFFFFFFF | Normal inner write-back cacheable |
*
* @note
*
* For region 0x00100000 - 0x3FFFFFFF, a system where DDR is less than 1GB,
* region after DDR and before PL is marked as undefined/reserved in translation
* table. In 0xF8000000 - 0xF8FFFFFF, 0xF8000C00 - 0xF8000FFF, 0xF8010000 -
* 0xF88FFFFF and 0xF8F03000 to 0xF8FFFFFF are reserved  but due to granual size
* of 1MB, it is not possible to define separate regions for them. For region
* 0xFFF00000 - 0xFFFFFFFF, 0xFFF00000 to 0xFFFB0000 is reserved but due to 1MB
* granual size, it is not possible to define separate region for it
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- ---------------------------------------------------
* 1.00a ecm  10/20/09 Initial version
* 3.04a sdm  01/13/12 Updated MMU table to mark DDR memory as Shareable
* 3.07a sgd  07/05/2012 Configuring device address spaces as shareable device
*		       instead of strongly-ordered.
* 3.07a asa  07/17/2012 Changed the property of the ".mmu_tbl" section.
* 4.2	pkp  09/02/2014 added entries for 0xfe000000 to 0xffefffff as reserved
*			and  0xe0000000 - 0xe1ffffff is broken down into
*			0xe0000000 - 0xe02fffff (memory mapped divides)
*			0xe0300000 - 0xe0ffffff (reserved) and
*			0xe1000000 - 0xe1ffffff (NAND)
* 5.2	pkp  06/08/2015 put a check for XPAR_PS7_DDR_0_S_AXI_BASEADDR to confirm
*			if DDR is present or not and accordingly generate the
*			translation table
* 6.1	pkp  07/11/2016 Corrected comments for memory attributes
* 6.8   mus  07/12/2018 Mark DDR memory as inner cacheable, if BSP is built
*			with the USE_AMP flag.
* </pre>
*
*
******************************************************************************/
//#include "board_parameters.h"

	.globl  MMUTable

	.section .mmu_tbl,"a"

MMUTable:
	/* Each table entry occupies one 32-bit word and there are
	 * 4096 entries, so the entire table takes up 16KB.
	 * Each entry covers a 1MB section.
	 */
.set SECT, 0

.set DDR_START, (1 * 1024 * 1024) 
.set DDR_END, DDR_START +  (512 * 1024 * 1024)
.set DDR_SIZE, (512 * 1024 * 1024)
.set DDR_REG, DDR_SIZE/0x100000

.set UNDEF_REG, 0x3FF - DDR_REG

#define SHAREABLE (1 << 16)
#define NON_CACHED (0)
#define WB_WA_CACHE (1) /* write back, write allocate */
#define WT_CACHE (2) /* write thru */
#define WB_CACHE (3) /* write back */
#define INNER_SHIFT (2)
#define OUTER_SHIFT (12)
#define TEX_MSB (1 << 14)
#define AP_FAULT (0) /* no access, a fault */
#define AP_FULL (3 << 10) /* full access */
#define DOMAIN(x) (x << 5)
#define INNER_NON_CACHED (NON_CACHED << INNER_SHIFT)
#define INNER_WB_WA (WB_WA_CACHE << INNER_SHIFT)
#define INNER_WT (WT_CACHE << INNER_SHIFT)
#define INNER_WB (WB_CACHE << INNER_SHIFT)
#define OUTER_NON_CACHED (TEX_MSB | (NON_CACHED << OUTER_SHIFT))
#define OUTER_WB_WA (TEX_MSB | (WB_WA_CACHE << OUTER_SHIFT))
#define OUTER_WT (TEX_MSB | (WT_CACHE << OUTER_SHIFT))
#define OUTER_WB (TEX_MSB | (WB_CACHE << OUTER_SHIFT))
#define SECTION(attributes) ((attributes) | 0x2)
#define SUPER_SECTION(attributes) ((attributes) | 0x4002)

#define FaultAttributes AP_FAULT
#define OcmAttributes SECTION(SHAREABLE | OUTER_NON_CACHED | AP_FULL | INNER_NON_CACHED)
#define DdrAttributes SECTION(SHAREABLE | OUTER_WB_WA | AP_FULL | INNER_WB_WA | DOMAIN(0xF))

//                            /* 1st MB  */
//.word	SECT + 0x0			/* S=b0 TEX=b000 AP=b00, Domain=b0, C=b0, B=b0 */
                                /*0x00000000 - 0x00100000 (inner and outer cacheable )*/
.word   SECT + FaultAttributes
.set	SECT, SECT+0x100000

.rept	DDR_REG				/* 512 MB (DDR Cacheable) */
.word	SECT + DdrAttributes
.set	SECT, SECT+0x100000
.endr

.rept	UNDEF_REG			// Generates a translation fault if accessed 
.word	SECT + FaultAttributes
.set	SECT, SECT+0x100000
.endr

.rept	0x0400				// 0x40000000 - 0x7fffffff (FPGA slave0)
.word	SECT + 0xc02		// S=b0 TEX=b000 AP=b11, Domain=b0, C=b0, B=b0
.set	SECT, SECT+0x100000
.endr

.rept	0x0400			// 0x80000000 - 0xbfffffff (FPGA slave1)
.word	SECT + 0xc02	// S=b0 TEX=b000 AP=b11, Domain=b0, C=b0, B=b0
.set	SECT, SECT+0x100000
.endr

.rept	0x0200			// 0xc0000000 - 0xdfffffff Fault
.word	SECT + FaultAttributes
.set	SECT, SECT+0x100000
.endr

.rept	0x003			// 0xe0000000 - 0xe02fffff UART/USB/IIC/SPI/CAN/GEM/GPIO/QSPI/SD/NAND
.word	SECT + 0xc06	// S=b0 TEX=b000 AP=b11, Domain=b0, C=b0, B=b1
.set	SECT, SECT+0x100000
.endr

.rept	0x0D			// 0xe0300000 - 0xe0ffffff Generates a translation fault if accessed
.word	SECT + 0x0		// S=b0 TEX=b000 AP=b00, Domain=b0, C=b0, B=b0
.set	SECT, SECT+0x100000
.endr

.rept	0x0010			// 0xe1000000 - 0xe1ffffff (NAND)
.word	SECT + 0xc06	// S=b0 TEX=b000 AP=b11, Domain=b0, C=b0, B=b1 
.set	SECT, SECT+0x100000
.endr

.rept	0x0020			// 0xe2000000 - 0xe3ffffff (NOR)
.word	SECT + 0xc06	// S=b0 TEX=b000 AP=b11, Domain=b0, C=b0, B=b1
.set	SECT, SECT+0x100000
.endr

.rept	0x0020			// 0xe4000000 - 0xe5ffffff (SRAM) */
.word	SECT + 0xc0e	/* S=b0 TEX=b000 AP=b11, Domain=b0, C=b1, B=b1 */
.set	SECT, SECT+0x100000
.endr

.rept	0x0120			// 0xe6000000 - 0xf7ffffff  Fault
.word	SECT + FaultAttributes
.set	SECT, SECT+0x100000
.endr

.rept	0x0010			// 0xf/8000000 - 0xf8ffffff (AMBA APB Peripherals)
.word	SECT + 0xc06	// S=b0 TEX=b000 AP=b11, Domain=b0, C=b0, B=b1
.set	SECT, SECT+0x100000
.endr

.rept	0x0030			// 0xf9000000 - 0xfbffffff Fault
.word	SECT + FaultAttributes
.set	SECT, SECT+0x100000
.endr

.rept	0x0020			// 0xfc000000 - 0xfdffffff (Linear QSPI - XIP) */
.word	SECT + 0xc0a	// S=b0 TEX=b000 AP=b11, Domain=b0, C=b1, B=b0 
.set	SECT, SECT+0x100000
.endr

.rept	0x001F			// 0xfe000000 - 0xffefffff (unassigned/reserved).
.word	SECT + FaultAttributes
.set	SECT, SECT+0x100000
.endr

// 	0xfff00000 - 0xffffffff 256K OCM when mapped to high address space
.word	SECT + OcmAttributes
.set	SECT, SECT+0x100000

.end
