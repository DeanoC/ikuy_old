#include "hw_timers/global.h"
#include "hw/scu.h"
#include "hw/reg.h"

void hw_timers_global_reset()
{
    HW_REG_CLR_BIT(scu, GLOBAL_TIMER_CONTROL, TIMER_ENABLE);
    *HW_REG(scu, GLOBAL_TIMER_COUNTER0) = 0;
    *HW_REG(scu, GLOBAL_TIMER_COUNTER1) = 0;
    HW_REG_MERGE_FIELD(scu, GLOBAL_TIMER_CONTROL, PRESCALER, 0x0);
    HW_REG_SET_BIT(scu, GLOBAL_TIMER_CONTROL, TIMER_ENABLE);
}

uint64_t hw_timers_global_get()
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
