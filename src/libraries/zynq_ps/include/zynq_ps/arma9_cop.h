#pragma once

#include <stdint.h>

#define arma9_cop_get_CP(cp, op1, Rt, CRn, CRm, op2) __asm__ volatile("MRC p" # cp ", " # op1 ", %0, c" # CRn ", c" # CRm ", " # op2 : "=r" (Rt) : : "memory" )
#define arma9_cop_set_CP(cp, op1, Rt, CRn, CRm, op2) __asm__ volatile("MCR p" # cp ", " # op1 ", %0, c" # CRn ", c" # CRm ", " # op2 : : "r" (Rt) : "memory" )

// Aux Control Register Get
static inline __attribute__((always_inline)) uint32_t arma9_cop_get_ACTLR(void) 
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 1, 0, 1);
  return(result);
}

// Aux Control Register set
static inline __attribute__((always_inline))  void arma9_cop_set_ACTLR(uint32_t actlr)
{
  arma9_cop_set_CP(15, 0, actlr, 1, 0, 1);
}

// Coprocessor Access Control get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_CPACR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 1, 0, 2);
  return result;
}

// Coprocessor Access Control set
static inline __attribute__((always_inline))  void arma9_cop_set_CPACR(uint32_t cpacr)
{
  arma9_cop_set_CP(15, 0, cpacr, 1, 0, 2);
}

// Data Fault Status Register get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_DFSR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 5, 0, 0);
  return result;
}

// Data Fault Status value set
static inline __attribute__((always_inline))  void arma9_cop_set_DFSR(uint32_t dfsr)
{
  arma9_cop_set_CP(15, 0, dfsr, 5, 0, 0);
}

// Instruction Fault Status get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_IFSR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 5, 0, 1);
  return result;
}

// Instruction Fault Status set
static inline __attribute__((always_inline))  void arma9_cop_set_IFSR(uint32_t ifsr)
{
  arma9_cop_set_CP(15, 0, ifsr, 5, 0, 1);
}

// Interrupt Status Register get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_ISR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 12, 1, 0);
  return result;
}

// Configuration Base Address get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_CBAR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 4, result, 15, 0, 0);
  return result;
}
// Translation Table Base get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_TTBR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 2, 0, 0);
  return result;
}

// Translation Table Base set
static inline __attribute__((always_inline))  void arma9_cop_set_TTBR(uint32_t ttbr0)
{
  arma9_cop_set_CP(15, 0, ttbr0, 2, 0, 0);
}

// Domain Access Control get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_DACR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 3, 0, 0);
  return result;
}

// Domain Access Control set
static inline __attribute__((always_inline))  void arma9_cop_set_DACR(uint32_t dacr)
{
  arma9_cop_set_CP(15, 0, dacr, 3, 0, 0);
}

#define arma9_cop_SCTLR_DSSBD (1 << 31)
#define arma9_cop_SCTLR_TE (1 << 30)
#define arma9_cop_SCTLR_AFR (1 << 29)
#define arma9_cop_SCTLR_TFE (1 << 28)
#define arma9_cop_SCTLR_EE (1 << 25)
#define arma9_cop_SCTLR_SPAN (1 << 23)
#define arma9_cop_SCTLR_UWXN (1 << 20)
#define arma9_cop_SCTLR_WXN (1 << 19)
#define arma9_cop_SCTLR_mTWE (1 << 18)
#define arma9_cop_SCTLR_nTWI (1 << 16)
#define arma9_cop_SCTLR_V (1 << 13)
#define arma9_cop_SCTLR_ICACHE (1 << 12)
#define arma9_cop_SCTLR_EnRCTX (1 << 10)
#define arma9_cop_SCTLR_SED (1 << 8)
#define arma9_cop_SCTLR_ITD (1 << 7)
#define arma9_cop_SCTLR_CP16BEN (1 << 5)
#define arma9_cop_SCTLR_LSMAOE (1 << 4)
#define arma9_cop_SCTLR_nTLSMD (1 << 3)
#define arma9_cop_SCTLR_DCACHE (1 << 2)
#define arma9_cop_SCTLR_ALIGN_CHK (1 << 1)
#define arma9_cop_SCTLR_MMU (1 << 0)

// System Control Register set
static inline __attribute__((always_inline))  void arma9_cop_set_SCTLR(uint32_t sctlr)
{
  arma9_cop_set_CP(15, 0, sctlr, 1, 0, 0);
}

// System Control Register get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_SCTLR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 1, 0, 0);
  return result;
}

// Auxiliary Control Register set
static inline __attribute__((always_inline))  void arma9_cop_set_ACTRL(uint32_t actrl)
{
  arma9_cop_set_CP(15, 0, actrl, 1, 0, 1);
}

// Auxiliary Control Register get
static inline __attribute__((always_inline)) uint32_t arma9_cop_get_ACTRL(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 1, 0, 1);
  return result;
}

// Multiprocessor Affinity get
static inline __attribute__((always_inline)) uint32_t arma9_cop_get_MPIDR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 0, 0, 5);
  return result;
}

// Vector Base Address get
static inline __attribute__((always_inline))  uint32_t arma9_cop_get_VBAR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 12, 0, 0);
  return result;
}

// Vector Base Address Register value to set
static inline __attribute__((always_inline)) void arma9_cop_set_VBAR(uint32_t vbar)
{
  arma9_cop_set_CP(15, 0, vbar, 12, 0, 0);
}

// Monitor Vector Base Address get
static inline __attribute__((always_inline)) uint32_t arma9_cop_get_MVBAR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 0, result, 12, 0, 1);
  return result;
}

// Monitor Vector Base Address set
static inline __attribute__((always_inline)) void arma9_cop_set_MVBAR(uint32_t mvbar)
{
  arma9_cop_set_CP(15, 0, mvbar, 12, 0, 1);
}

//  TLB Invalidate All
static inline __attribute__((always_inline)) void arma9_cop_set_TLBIALL()
{
  arma9_cop_set_CP(15, 0, 0, 8, 7, 0);
}

// Branch Predictor Invalidate All
static inline __attribute__((always_inline)) void arma9_cop_set_BPIALL()
{
  arma9_cop_set_CP(15, 0, 0, 7, 5, 6);
}

// Instruction Cache Invalidate All
static inline __attribute__((always_inline)) void arma9_cop_set_ICIALLU()
{
  arma9_cop_set_CP(15, 0, 0, 7, 5, 0);
}

// Data cache clean
static inline __attribute__((always_inline)) void arma9_cop_set_DCCMVAC(uint32_t value)
{
  arma9_cop_set_CP(15, 0, value, 7, 10, 1);
}

// Data cache invalidate
static inline __attribute__((always_inline)) void arma9_cop_set_DCIMVAC(uint32_t value)
{
  arma9_cop_set_CP(15, 0, value, 7, 6, 1);
}

//  Data cache clean and invalidate
static inline __attribute__((always_inline)) void arma9_cop_set_DCCIMVAC(uint32_t value)
{
  arma9_cop_set_CP(15, 0, value, 7, 14, 1);
}

#define arma9_cop_CSSELR_DATA (0x0)
#define arma9_cop_CSSELR_INSTRUCTION (0x1)
#define arma9_cop_CSSELR_L1 (0x0 << 1)
#define arma9_cop_CSSELR_L2 (0x1 << 2)

// Cache Size Selection set
static inline __attribute__((always_inline)) void arma9_cop_set_CSSELR(uint32_t value)
{
  arma9_cop_set_CP(15, 2, value, 0, 0, 0);
}

// Cache Size Selection get
static inline __attribute__((always_inline)) uint32_t arma9_cop_get_CSSELR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 2, result, 0, 0, 0);
  return result;
}
// Current Cache Size ID get
static inline __attribute__((always_inline)) uint32_t arma9_cop_get_CCSIDR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 1, result, 0, 0, 0);
  return result;
}

// Cache Level ID get
static inline __attribute__((always_inline)) uint32_t arma9_cop_get_CLIDR(void)
{
  uint32_t result;
  arma9_cop_get_CP(15, 1, result, 0, 0, 1);
  return result;
}

// Data Cache line Invalidate by Set/Way set
static inline __attribute__((always_inline)) void arma9_cop_set_DCISW(uint32_t value)
{
  arma9_cop_set_CP(15, 0, value, 7, 6, 2);
}

// Data Cache line Clean by Set/Way set
static inline __attribute__((always_inline)) void arma9_cop_set_DCCSW(uint32_t value)
{
  arma9_cop_set_CP(15, 0, value, 7, 10, 2);
}

// Data Cache line Clean and Invalidate by Set/Way set
static inline __attribute__((always_inline)) void arma9_cop_set_DCCISW(uint32_t value)
{
  arma9_cop_set_CP(15, 0, value, 7, 14, 2);
}
