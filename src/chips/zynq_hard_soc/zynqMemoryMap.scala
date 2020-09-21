package zynq_hard_soc

import bus_and_chips._

object ZynqMemoryMap
{
  def addToChip(chip : Chip) = {
    chip.addCHeaderFile(cheader)
  }

  private val cheader = ("memory_map.h", """
  #pragma once

/*
 This is the memory map post boot. Before boot has
 finished OCM + DDR will be different. 

 +---------------------------------------------+  0xFFFF_FFFF  4GB
 |                OCM (SRAM)                   |                ^
 |                  256KB                      |                |
 +---------------------------------------------+  0xFFFC_0000  4GB - 256 KB
 |           Empty (but mapped)                |                ^
 |                                             |                |
 +---------------------------------------------+  0xFFF0_0000  4095 MB
 |                  Empty                      |                ^
 |                                             |                |
 +---------------------------------------------+  0xFD00_0000   4048 MB
 |                 Quad-SPI                    |                ^
 |                  16MB                       |                |
 +---------------------------------------------+  0xFC00_0000  4032 MB
 |                   Empty                     |                ^
 |                                             |                |
 +---------------------------------------------+  0xF900_0000   3984 MB
 |                   MPCore                    |                ^
 |                                             |                |
 +---------------------------------------------+  0xF8F0_0000  3983 MB
 |                   Empty                     |                ^
 |                                             |                |
 +---------------------------------------------+  0xF8A0_0000 3979 MB
 |                   QOS                       |                ^
 |                                             |                |
 +---------------------------------------------+  0xF890_0000 3978 MB
 |                   Debug                     |                ^
 |                                             |                |
 +---------------------------------------------+  0xF880_0000 3977 MB
 |                   Empty                     |                ^
 |                                             |                |
 +---------------------------------------------+  0xF810_0000 3967 MB
 |                   Misc                      |                ^
 |                                             |                |
 +---------------------------------------------+  0xF800_0000 3968 MB   
 |                   Empty                     |                ^
 |                                             |                |
 +---------------------------------------------+  0xE020_0000 3586 MB
 |                   SDIO                      |                ^
 |                                             |                |
 +---------------------------------------------+  0xE010_0000 3585 MB
 |                   I/O                       |                ^
 |                                             |                |
 +---------------------------------------------+  0xE000_0000 3584 MB
 |                  Empty                      |                ^
 |                                             |                |
 +---------------------------------------------+  0xC000_0000  3 GB
 |                M_AXI_GP1                    |                ^
 |                                             |                |
 +---------------------------------------------+  0x8000_0000  2 GB
 |                M_AXI_GP0                    |                ^
 |                                             |                |
 +---------------------------------------------+  0x4000_0000  1 GB
 |                  Empty                      |                ^
 |                                             |                |
 +---------------------------------------------+  0x2010_0000 513 MB
 |                   DDR                       |                ^
 |                  512MB                      |                |
 +---------------------------------------------+  0x0010_0000  1 MB
 |                  Empty                      |                ^
 |            Data Error on access!            |                |
 |---------------------------------------------+  0x0000_0000   0

 */

#define MEM_MAP_DDR_START (0x00100000)
#define MEM_MAP_DDR_END (0x20100000)

#define MEM_MAP_M_AXI_GP0_START (0x40000000)
#define MEM_MAP_M_AXI_GP0_END (0x80000000)

#define MEM_MAP_M_AXI_GP1_START (0x80000000)
#define MEM_MAP_M_AXI_GP1_END (0xC0000000)

#define MEM_MAP_IO_START (0xE0000000)
#define MEM_MAP_IO_END (0xE0100000)

#define MEM_MAP_SDIO_START (0xE0100000)
#define MEM_MAP_SDIO_END (0xE0200000)

#define MEM_MAP_MISC_START (0xF8000000)
#define MEM_MAP_MISC_END (0xF8100000)

#define MEM_MAP_DEBUG_START (0xF8800000)
#define MEM_MAP_DEBUG_END (0xF8900000)

#define MEM_MAP_QOS_START (0xF8900000)
#define MEM_MAP_QOS_END (0xF8A00000)

#define MEM_MAP_MPCORE_START (0xF8F00000)
#define MEM_MAP_MPCORE_END (0xF9000000)

#define MEM_MAP_QUADSPI_START (0xFC000000)
#define MEM_MAP_QUADSPI_END (0xFD000000)

#define MEM_MAP_OCM_START (0xFFFC0000)
#define MEM_MAP_OCM_END (0xFFFFFFFF)
""")
}