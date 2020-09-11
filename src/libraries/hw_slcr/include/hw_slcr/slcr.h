#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum HWSLCR_CLOCKS
{
  HWSLC_REF_CLOCK = 0,     // PS PLL Reference clock 50Mhz for pynq-z2
  HWSLC_FPGA_SYSTEM_CLOCK, // FPGA System lock 125 Mhz for pynq-z2
  HWSLC_CPU_CLOCK,         // CPU_6x
  HWSLC_ARM_3X_CLOCK,      // CPU_3x
  HWSLC_DMAC_CLOCK,        // CPU_2x
  HWSLC_APB_CLOCK,         // CPU_1x
  HWSLC_AXI_HP_CLOCK,      // DDR_2x
  HWSLC_DDR_RAM_CLOCK,     // DDR_3x
} HWSLCR_CLOCKS;

void hw_slcr_unlock(void);
void hw_slcr_lock(void);

uint32_t hw_slcr_get_clock(HWSLCR_CLOCKS clock);
