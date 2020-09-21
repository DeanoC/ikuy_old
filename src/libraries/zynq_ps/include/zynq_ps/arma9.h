
#pragma once

#include <stdint.h>

#define arma9_CPSR_N (1 << 31)
#define arma9_CPSR_Z (1 << 30)
#define arma9_CPSR_C (1 << 29)
#define arma9_CPSR_V (1 << 28)
#define arma9_CPSR_Q (1 << 27)
#define arma9_CPSR_SSBS (1 << 23)
#define arma9_CPSR_PAN (1 << 22)
#define arma9_CPSR_DIT (1 << 21)
#define arma9_CPSR_GE_LSHIFT (1 << 16)
#define arma9_CPSR_GE_MASK (0xF << arma9_CPSR_GE_LSHIFT)
#define arma9_CPSR_ENDIANNESS (1 << 9)
#define arma9_CPSR_SERROR_MASKED (1 << 8)
#define arma9_CPSR_IRQ_MASKED (1 << 7)
#define arma9_CPSR_FIQ_MASKED (1 << 6)
#define arma9_CPSR_FAST_MODE_LSHIFT (0)
#define arma9_CPSR_FAST_MODE_MASK (0xF << arma9_CPSR_FAST_MODE_LSHIFT)

static inline __attribute__((always_inline)) uint32_t arma9_get_CPSR(void)
{
  uint32_t result;
  __asm__ __volatile__("mrs	%0, cpsr": "=r" (result));
  return(result);
}
static inline __attribute__((always_inline)) void arma9_set_CPSR(uint32_t cpsr)
{
  __asm__ __volatile__("msr	cpsr,%0": : "r" (cpsr) : "cc");			
}

static inline __attribute__((always_inline)) void arma9_dsb()
{
  __asm__ __volatile__("dsb" : : :);
}

static inline __attribute__((always_inline)) void arma9_isb()
{
  __asm__ __volatile__("isb"
                       :
                       :
                       :);
}
