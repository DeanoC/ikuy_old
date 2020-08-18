#pragma once

inline void invalidate_l1_dcache(void)
{
    __asm__ __volatile__("MCR p15,0,%0,c7,c14,2" ::"r"(0));
}

inline void invalidate_l1_icache(void)
{
    __asm__ __volatile__("MCR p15,0,%0,c7,c5,0" ::"r"(0));
}

inline void invalidate_l1_branch_predictor(void)
{
    __asm__ __volatile__("MCR p15,0,%0,c7,c5,6" ::"r"(0));
}
