#include "system_info/cpu.h"
#include "serial_debug/debug_print.h"

#include "hw/reg.h"
#include "hw/slcr.h"

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

    uint32_t const armClockDiv = HW_REG_GET_FIELD(slcr, ARM_CLK_CTRL, DIVISOR);
    uint32_t const armClk = armClockDiv ? (armPll / armClockDiv) : armPll;
    uint32_t const ddr2xClockDiv = HW_REG_GET_FIELD(slcr, DDR_CLK_CTRL, DDR_2XCLK_DIVISOR);
    uint32_t const ddr2xClk = ddr2xClockDiv ? (ddrPll / ddr2xClockDiv) : ddrPll;
    uint32_t const ddr3xClockDiv = HW_REG_GET_FIELD(slcr, DDR_CLK_CTRL, DDR_3XCLK_DIVISOR);
    uint32_t const ddr3xClk = ddr3xClockDiv ? (ddrPll / ddr3xClockDiv) : ddrPll;

    debug_printf(DEBUG_WHITE_PEN "Ref: " DEBUG_GREEN_PEN "%i Mhz\n", refClock);

    debug_printf(DEBUG_WHITE_PEN "ARM PLL: " DEBUG_GREEN_PEN "Mult 0x%.02x == %i Mhz\n", armPllDiv, armPll);
    debug_printf(DEBUG_WHITE_PEN "DDR PLL: " DEBUG_YELLOW_PEN "Mult 0x%.02x == %i Mhz\n", ddrPllDiv, ddrPll);
    debug_printf(DEBUG_WHITE_PEN "IO PLL: " DEBUG_CYAN_PEN "Mult 0x%.02x == %i Mhz\n", ioPllDiv, ioPll);

    debug_printf(DEBUG_WHITE_PEN "ARM Clk: " DEBUG_GREEN_PEN "Div 0x%.02x == %i Mhz\n", armClockDiv, armClk);
    debug_printf(DEBUG_WHITE_PEN "DDR 2x Clk: " DEBUG_YELLOW_PEN "Div 0x%.02x == %i Mhz\n", ddr2xClockDiv, ddr2xClk);
    debug_printf(DEBUG_WHITE_PEN "DDR 3x Clk: " DEBUG_YELLOW_PEN "Div 0x%.02x == %i Mhz\n", ddr3xClockDiv, ddr3xClk);

    debug_print(DEBUG_WHITE_PEN "------\n");
}

void system_info_log_cpu0()
{

}

void system_info_log_cpu1()
{

}