#include <stdint.h>

#if !defined(DEBUG_WRITES)
#define DEBUG_WRITES 0
#endif

#define PSIC_INSTRUCTION_SHIFT (0) 
#define PSIC_INSTRUCTION_MASK (0xF << PSIC_INSTRUCTION_SHIFT)
#define PSIC_LOOP_SHIFT (4)
#define PSIC_LOOP_MASK (0xFF << PSIC_LOOP_SHIFT)
#define PSIC_REGISTER_SHIFT (16)
#define PSIC_REGISTER_MASK (0x1FFF << PSIC_REGISTER_SHIFT)

typedef enum PSI_CONTROL
{
    PSIC_END_PROGRAM = 0 << PSIC_INSTRUCTION_SHIFT,
    PSIC_SET_BANK = 1 << PSIC_INSTRUCTION_SHIFT,
    PSIC_WRITE_32BIT = 2 << PSIC_INSTRUCTION_SHIFT,
    PSIC_WRITE_MASKED_32BIT = 3 << PSIC_INSTRUCTION_SHIFT,
    PSIC_POLL_MASKED_32BIT = 4 << PSIC_INSTRUCTION_SHIFT,

    PSIC_MULTI_WRITE_32BIT = 5 << PSIC_INSTRUCTION_SHIFT,
    PSIC_MULTI_WRITE_MASKED_32BIT = 6 << PSIC_INSTRUCTION_SHIFT,
    PSIC_MULTI_WRITE_MULTI_MASKED_32BIT = 7 << PSIC_INSTRUCTION_SHIFT,

    PSIC_MULTI_WRITE_MASKED_16BIT = 8 << PSIC_INSTRUCTION_SHIFT,

    PSIC_POLL_GLOBAL_MASKED_32BIT = 9 << PSIC_INSTRUCTION_SHIFT,

} PSI_CONTROL;

typedef uint32_t PSI_IWord;

#define PSI_END_PROGRAM PSIC_END_PROGRAM
#define PSI_SET_REGISTER_BANK(bank) PSIC_SET_BANK, (bank)
#define PSI_WRITE_32(reg, value) (PSIC_WRITE_32BIT | (1 << PSIC_LOOP_SHIFT) | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), (value)
#define PSI_WRITE_MASKED32(reg, mask, value) (PSIC_WRITE_MASKED_32BIT | (1 << PSIC_LOOP_SHIFT)  | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), (mask), (value)
#define PSI_POLL_MASKED32(reg, mask) (PSIC_POLL_MASKED_32BIT | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), (mask)

// allow a constant set to continous registers (no more than 255 register per loop)
#define PSI_WRITE_N_32(reg, n, value) (PSIC_WRITE_32BIT | ((n) << PSIC_LOOP_SHIFT) | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), (value)
#define PSI_WRITE_N_MASKED32(reg, n, mask, value) (PSIC_WRITE_MASKED_32BIT | ((n) << PSIC_LOOP_SHIFT)  | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), (mask), (value) 
// write multiple values to continous register with a shared mask (if masked)
#define PSI_MULTI_WRITE_32(reg, n, ...) (PSIC_MULTI_WRITE_32BIT | ((n) << PSIC_LOOP_SHIFT) | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), __VA_ARGS__
#define PSI_MULTI_WRITE_MASKED32(reg, n, mask, ...) (PSIC_MULTI_WRITE_MASKED_32BIT | ((n) << PSIC_LOOP_SHIFT)  | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), (mask), __VA_ARGS__
// write multiple values to continous register each with its own mask
#define PSI_MULTI_WRITE_MULTI_MASKED32(reg, n, ...) (PSIC_MULTI_WRITE_MULTI_MASKED_32BIT | ((n) << PSIC_LOOP_SHIFT)  | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), __VA_ARGS__

// TODO generilise 16 bit, this was implemented for MIO specificaly
// odd number of transfer must be padded to 32 bit boundraryu
// for odd tranfers set n = odd number and add a dummy low
#define PSI_MULTI_WRITE_MASKED16(reg, n, mask, ...) (PSIC_MULTI_WRITE_MASKED_16BIT | ((n) << PSIC_LOOP_SHIFT)  | (((uint32_t)(reg)) << PSIC_REGISTER_SHIFT)), (mask), __VA_ARGS__
#define PSI_PACK_16(a, b) ((uint32_t)(a) << 16U) | ((uint32_t)(b))

#define PSI_POLL_GLOBAL_MASKED32(reg, mask) (PSIC_POLL_GLOBAL_MASKED_32BIT), (reg), (mask)

// check = 64K * 32bit block produced via EMIT_WRITExxx in DEBUG_TRACE mode
// ignore if null or nut DEBUG_TRCE mode
void psi_RunProgram( PSI_IWord const * program, uint32_t const * check );

