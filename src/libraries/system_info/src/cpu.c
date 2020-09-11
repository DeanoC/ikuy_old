#include "system_info/cpu.h"
#include "serial_debug/debug_print.h"

#include "hw/reg.h"
#include "hw/slcr.h"
#include "hw_slcr/slcr.h"

void system_info_log_clocks()
{
    debug_print(DEBUG_WHITE_PEN "Clocks\n------\n");
    uint32_t const refClock = 50;
    uint32_t const armPllDiv = HW_REG_GET_FIELD(slcr, ARM_PLL_CTRL, PLL_FDIV);
    uint32_t const ddrPllDiv = HW_REG_GET_FIELD(slcr,DDR_PLL_CTRL, PLL_FDIV);
    uint32_t const ioPllDiv = HW_REG_GET_FIELD(slcr,IO_PLL_CTRL, PLL_FDIV);
    uint32_t const armPll = refClock * armPllDiv;
    uint32_t const ddrPll = refClock * ddrPllDiv;
    uint32_t const ioPll = refClock * ioPllDiv;

    debug_printf(DEBUG_WHITE_PEN "ARM PLL: " DEBUG_GREEN_PEN "Mult 0x%.02x == %i Mhz\n", armPllDiv, armPll);
    debug_printf(DEBUG_WHITE_PEN "DDR PLL: " DEBUG_YELLOW_PEN "Mult 0x%.02x == %i Mhz\n", ddrPllDiv, ddrPll);
    debug_printf(DEBUG_WHITE_PEN "IO PLL: " DEBUG_CYAN_PEN "Mult 0x%.02x == %i Mhz\n", ioPllDiv, ioPll);
    debug_printf("\n");

#define MHZ (1000*1000)
    debug_printf(DEBUG_WHITE_PEN "Reference Clock  : " DEBUG_GREEN_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_REF_CLOCK) / MHZ);
    debug_printf(DEBUG_WHITE_PEN "FPGA System Clock: " DEBUG_GREEN_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_FPGA_SYSTEM_CLOCK) / MHZ);
    debug_printf("\n");
    debug_printf(DEBUG_WHITE_PEN "CPU Clock     : " DEBUG_GREEN_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_CPU_CLOCK) / MHZ);
    debug_printf(DEBUG_WHITE_PEN "CPU_3x: Clock : " DEBUG_GREEN_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_ARM_3X_CLOCK) / MHZ);
    debug_printf(DEBUG_WHITE_PEN "DMAC Clock    : " DEBUG_GREEN_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_DMAC_CLOCK) / MHZ);
    debug_printf(DEBUG_WHITE_PEN "APB Clock     : " DEBUG_GREEN_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_APB_CLOCK) / MHZ);
    debug_printf(DEBUG_WHITE_PEN "AXI HP Clock  : " DEBUG_YELLOW_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_AXI_HP_CLOCK) / MHZ);
    debug_printf(DEBUG_WHITE_PEN "DDR RAM Clock : " DEBUG_YELLOW_PEN "%i MHz\n", hw_slcr_get_clock(HWSLC_DDR_RAM_CLOCK) / MHZ);
#undef MHZ

    debug_print(DEBUG_WHITE_PEN "------\n");
}

void system_info_log_cpu0()
{

}

void system_info_log_cpu1()
{

}