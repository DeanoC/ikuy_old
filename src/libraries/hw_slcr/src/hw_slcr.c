#include <assert.h>
#include "hw_slcr/slcr.h"
#include "hw/slcr.h"
#include "hw/reg.h"

void hw_slcr_unlock(void)
{
  *HW_REG(slcr, SLCR_UNLOCK) = 0xDF0FU;
}

void hw_slcr_lock(void)
{
  *HW_REG(slcr, SLCR_LOCK) = 0x767BU;
}

uint32_t hw_slcr_get_clock(HWSLCR_CLOCKS clock)
{
#define MHZ (1000*1000)
  uint32_t const refClk = 50 * MHZ; // TODO stop hard coding this

  switch(clock)
  {
    case HWSLC_REF_CLOCK: return refClk;

    case HWSLC_CPU_CLOCK:
    case HWSLC_ARM_3X_CLOCK:
    case HWSLC_DMAC_CLOCK:
    case HWSLC_APB_CLOCK:
    {
      uint32_t const armPllDiv = HW_REG_GET_FIELD(slcr, ARM_PLL_CTRL, PLL_FDIV);
      uint32_t const armPll = refClk * armPllDiv;
      uint32_t const armClockDiv = HW_REG_GET_FIELD(slcr, ARM_CLK_CTRL, DIVISOR);
      uint32_t const armClk = armClockDiv ? (armPll / armClockDiv) : armPll;
      switch (clock)
      {
        case HWSLC_CPU_CLOCK: return armClk;
        case HWSLC_ARM_3X_CLOCK: return armClk / 2;
        case HWSLC_DMAC_CLOCK: return armClk / 3;
        case HWSLC_APB_CLOCK: return armClk / 6;
        default: return 0; // can never get here
        }
      break;
    }
    case HWSLC_FPGA_SYSTEM_CLOCK: return 125 * MHZ; // TODO stop hard coding this
    case HWSLC_AXI_HP_CLOCK:
    {
      uint32_t const ddrPllDiv = HW_REG_GET_FIELD(slcr, DDR_PLL_CTRL, PLL_FDIV);
      uint32_t const ddrPll = refClk * ddrPllDiv;
      uint32_t const ddr2xClockDiv = HW_REG_GET_FIELD(slcr, DDR_CLK_CTRL, DDR_2XCLK_DIVISOR);
      uint32_t const ddr2xClk = ddr2xClockDiv ? (ddrPll / ddr2xClockDiv) : ddrPll;
      return ddr2xClk;
    }
    case HWSLC_DDR_RAM_CLOCK:
    {
      uint32_t const ddrPllDiv = HW_REG_GET_FIELD(slcr, DDR_PLL_CTRL, PLL_FDIV);
      uint32_t const ddrPll = refClk * ddrPllDiv;
      uint32_t const ddr3xClockDiv = HW_REG_GET_FIELD(slcr, DDR_CLK_CTRL, DDR_3XCLK_DIVISOR);
      uint32_t const ddr3xClk = ddr3xClockDiv ? (ddrPll / ddr3xClockDiv) : ddrPll;
      return ddr3xClk;
    }
  }
  return 0; // can never get here
#undef MHZ
}
