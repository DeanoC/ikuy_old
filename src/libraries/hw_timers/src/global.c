#include "hw_timers/global.h"
#include "zynq_ps/scu.h"
#include "zynq_ps/slcr.h"
#include "hwreg.h"

void hw_timers_global_reset(void)
{
    HW_REG_CLR_BIT(scu, GLOBAL_TIMER_CONTROL, TIMER_ENABLE);
    *HW_REG(scu, GLOBAL_TIMER_COUNTER0) = 0;
    *HW_REG(scu, GLOBAL_TIMER_COUNTER1) = 0;
    HW_REG_MERGE_FIELD(scu, GLOBAL_TIMER_CONTROL, PRESCALER, 0x0);
    HW_REG_SET_BIT(scu, GLOBAL_TIMER_CONTROL, TIMER_ENABLE);
}

uint64_t hw_timers_global_get(void)
{
    uint32_t hi, lo;
redo:
    hi = *HW_REG(scu, GLOBAL_TIMER_COUNTER1);
    lo = *HW_REG(scu, GLOBAL_TIMER_COUNTER0);
    if(hi != *HW_REG(scu, GLOBAL_TIMER_COUNTER1))
    {
        goto redo;
    }

    uint64_t counter = ((uint64_t)hi) << 32UL | ((uint64_t)lo);
    return counter;
}

float hw_timers_global_get_elapsed(uint64_t start, uint64_t end)
{
    uint32_t const refClock = 50 * 1024 * 1024;
    uint32_t const armPllMul = HW_REG_GET_FIELD(slcr,ARM_PLL_CTRL, PLL_FDIV);
    uint32_t const armClockDiv = HW_REG_GET_FIELD(slcr, ARM_CLK_CTRL, DIVISOR);

    // global clock works at half cpu clock speed
    float elapsed =(float)(end - start);
    float time = elapsed / ((float)((refClock * armPllMul) / (armClockDiv * 2)));
    return time;
}