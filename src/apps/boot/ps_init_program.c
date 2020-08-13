#define DEBUG_TRACE 0

#include "ps_init_program.h"

#if DEBUG_WRITES == 1
#include <stdio.h>
#endif
#include <stdbool.h>


#define PSI_INIT_TIMEOUT 100000000

typedef struct psi_InternalState
{
    PSI_IWord const * pc;

    uintptr_t curBankAddr;

#if DEBUG_WRITES == 1
    uint32_t dummyMemoryBank[ 0xFFFF ];
    bool written[ 0xFFFF ];
    uint32_t highestWrite;
#endif

} psi_InternalState;

#if DEBUG_WRITES == 1
static void dbgUpdateHightestWrite(psi_InternalState *state, uint32_t reg)
{
    if(reg > state->highestWrite)
    {
        state->highestWrite = reg;
    }
    state->written[reg/4] = true;
}

#define WRITE_REG(state, reg, value) dbgUpdateHightestWrite(&state, reg); *(state.dummyMemoryBank + (reg/4)) = value
#define READ_REG(state, reg) *(state.dummyMemoryBank + (reg/4))
#else
#define WRITE_REG(state, reg, value) *(((uintptr_t*)state.curBankAddr) + (reg/4)) = value
#define READ_REG(state, reg) *(((uintptr_t*)state.curBankAddr) + (reg/4))
#endif

#define EXTRACT_REG(wordA) ((wordA & PSIC_REGISTER_MASK) >> PSIC_REGISTER_SHIFT)
#define EXTRACT_LOOP(wordA) ((wordA & PSIC_LOOP_MASK) >> PSIC_LOOP_SHIFT)

void psi_RunProgram(PSI_IWord const * program, uint32_t const * check)
{
    psi_InternalState state = { 0 };
    state.pc = program;

    while((*state.pc & PSIC_INSTRUCTION_MASK) != PSIC_END_PROGRAM)
    {
        uint32_t pcincr = 0; // 2 words is normal pc increment
        uint32_t wordA = *(state.pc+pcincr); pcincr++;

#if DEBUG_WRITES == 1
        // for error reporting
        uint32_t const curOffset = (uint32_t)(state.pc -program);
#endif
        switch( (wordA & PSIC_INSTRUCTION_MASK))
        {
            case PSIC_SET_BANK: {
                #if DEBUG_TRACE
                    printf("PSIC_SET_BANK\n");
                #endif
                uint32_t wordB = *(state.pc+pcincr); pcincr++;
                state.curBankAddr = wordB;
                break;
            }
            case PSIC_WRITE_32BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_WRITE_32BIT\n");
                #endif
                uint32_t loopCount = EXTRACT_LOOP(wordA);
                uint32_t reg = EXTRACT_REG(wordA);
                uint32_t wordB = *(state.pc+pcincr); pcincr++;
                while(loopCount) {
                    WRITE_REG(state, reg , wordB );
                    reg += 4;
                    loopCount--;
                }
                break;
            }
            case PSIC_WRITE_MASKED_32BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_WRITE_MASKED_32BIT\n");
                #endif
                uint32_t mask = *(state.pc+pcincr); pcincr++;
                uint32_t wordB = *(state.pc+pcincr); pcincr++;
                uint32_t loopCount = EXTRACT_LOOP(wordA);
                uint32_t reg = EXTRACT_REG(wordA);
                while(loopCount) {
                    uint32_t v = (READ_REG(state, reg) & (~mask)) | (wordB & mask);
                    WRITE_REG(state,  reg, v);
                    reg += 4;
                    loopCount--;
                }
                break;
            }
            case PSIC_MULTI_WRITE_32BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_MULTI_WRITE_32BIT\n");
                #endif
                uint32_t loopCount = EXTRACT_LOOP(wordA);
                uint32_t reg = EXTRACT_REG(wordA);
                while(loopCount) {
                    uint32_t wordB = *(state.pc+pcincr); pcincr++;
                    WRITE_REG(state, reg, wordB );
                    reg += 4;
                    loopCount--;
                }
                break;
            }
            case PSIC_MULTI_WRITE_MASKED_32BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_MULTI_WRITE_MASKED_32BIT\n");
                #endif
                uint32_t mask = *(state.pc+pcincr); pcincr++;
                uint32_t loopCount = EXTRACT_LOOP(wordA);
                uint32_t reg = EXTRACT_REG(wordA);
                while(loopCount) {
                    uint32_t wordB = *(state.pc+pcincr); pcincr++;
                    uint32_t v = (READ_REG(state, reg) & (~mask)) | (wordB & mask);
                    WRITE_REG(state,  reg, v);
                    reg += 4;
                    loopCount--;
                }
                break;
            }
            case PSIC_MULTI_WRITE_MULTI_MASKED_32BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_MULTI_WRITE_MULTI_MASKED_32BIT\n");
                #endif
                uint32_t loopCount = EXTRACT_LOOP(wordA);
                uint32_t reg = EXTRACT_REG(wordA);

                while(loopCount) {
                    uint32_t mask = *(state.pc+pcincr); pcincr++;
                    uint32_t wordB = *(state.pc+pcincr); pcincr++;
                    uint32_t v = (READ_REG(state, reg) & (~mask)) | (wordB & mask);
                    WRITE_REG(state,  reg, v);
                    reg += 4;
                    loopCount--;
                }
                break;
            }

            case PSIC_MULTI_WRITE_MASKED_16BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_MULTI_WRITE_MASKED_16BIT\n");
                #endif
                uint32_t mask = *(state.pc+pcincr); pcincr++;
                uint32_t loopCount = EXTRACT_LOOP(wordA);
                uint32_t reg = EXTRACT_REG(wordA);
                bool oddCount = loopCount & 0x1;
                loopCount = loopCount / 2;
                while(loopCount) {
                    uint32_t wordB = *(state.pc+pcincr); pcincr++;
                    uint16_t bhi = (wordB >> 16) & 0xFFFF;
                    uint16_t blo = wordB & 0xFFFF;

                    uint32_t v0 = (READ_REG(state, reg) & (~mask)) | (bhi & mask);
                    WRITE_REG(state,  reg, v0);
                    reg += 4;
                    uint32_t v1 = (READ_REG(state, reg) & (~mask)) | (blo & mask);
                    WRITE_REG(state,  reg, v1);
                    reg += 4;

                    loopCount--;
                }
                if(oddCount) {
                    uint32_t wordB = *(state.pc+pcincr); pcincr++;
                    uint16_t bhi = (wordB >> 16) & 0xFFFF;
                    uint32_t v0 = (READ_REG(state, reg) & (~mask)) | (bhi & mask);
                    WRITE_REG(state,  reg, v0);
                    reg += 4;
                }
                break;
            }

            case PSIC_POLL_MASKED_32BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_POLL_MASKED_32BIT\n");
                #endif
                int timeout = 0;
                uint32_t mask = *(state.pc+pcincr); pcincr++;
                while(!(READ_REG(state, EXTRACT_REG(wordA)) & mask))
                {
                    #if DEBUG_WRITES == 1
                        WRITE_REG(state, EXTRACT_REG(wordA), 0x1);
                        break;
                    #endif

                    if(timeout > PSI_INIT_TIMEOUT)
                    {
  //                      printf("init program timeout! ERROR at 0x%.8x\n", curOffset);
                    }
                    timeout++;
                }
                #if DEBUG_WRITES == 1
                    WRITE_REG(state, EXTRACT_REG(wordA), 0x0);
                    break;
                #endif
                break;
            }
            case PSIC_POLL_GLOBAL_MASKED_32BIT: {
                #if DEBUG_TRACE
                    printf("PSIC_POLL_MASKED_32BIT\n");
                #endif
                #if DEBUG_WRITES == 1
                    // poll global can't be emulated
                    pcincr+=2;
                #else
                    int timeout = 0;
                    uint32_t* reg = (uint32_t*)*(state.pc+pcincr); pcincr++;
                    uint32_t mask = *(state.pc+pcincr); pcincr++;
                    while(!(*reg & mask))
                    {
                        if(timeout > PSI_INIT_TIMEOUT)
                        {
//                            printf("init program timeout! ERROR at 0x%.8x\n", curOffset);
                        }
                        timeout++;
                    }
                #endif
                break;
            }

            default:
#if DEBUG_WRITES == 1
                printf("init program instruction ERROR at 0x%.8x reg 0x%.4x)\n", curOffset, wordA);
#endif
                break;
        }
        state.pc+=pcincr;
    }   
#if DEBUG_WRITES == 1
    if(check != NULL)
    {
        printf("Bank Address : 0x%.8x\n", state.curBankAddr);
        for (uint32_t i = 0; i < 0x0FFF; i++)
        {
            if( check[i] != state.dummyMemoryBank[i] )
            {
                printf("0x%.4x is 0x%.8x should be 0x%.8x\n", i * 4, state.dummyMemoryBank[i], check[i]);
            }
        }        
    } else
    {
        printf("Bank Address : 0x%.8x\n", state.curBankAddr);
        printf("Highest Reg: 0x%.4x\n", state.highestWrite);
        for (uint32_t i = 0; i <= state.highestWrite/4; i++)
        {
            if(state.written[i]) {
                printf("0x%.4x : 0x%.8x\n", i * 4, state.dummyMemoryBank[i]);
            }
        }
    }
#else
    check = check; // ignore unused
#endif
}