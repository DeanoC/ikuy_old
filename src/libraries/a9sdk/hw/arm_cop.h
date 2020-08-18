#pragma once

#include <stdint.h>

static inline void arm_cop_wait_for_interupt(void)
{
    __asm__ __volatile__("MCR p15,0,%0,c7,c0,4" ::"r"(0));
}

extern uint32_t arm_cop_main_id(void);