#include "ps_init_program.h"
#include "zynq_ps/uart.h"

#define REG(reg) (uart_##reg##_OFFSET)
#define MASK(field) (uart_##field##_MASK)
#define VAL(field, val) (val << uart_##field##_LSHIFT)
#define TRUEV(field) VAL(field, 0x1)

// these values are taking from a vitis project.
static PSI_IWord const uart0_init[] =
{
        PSI_SET_REGISTER_BANK(uart0_BASE_ADDR),

        PSI_WRITE_MASKED32(REG(BAUD_RATE_DIVIDER),
                           MASK(BAUD_RATE_DIVIDER_BDIV),
                           VAL(BAUD_RATE_DIVIDER_BDIV, 0x6U)),
        PSI_WRITE_MASKED32(REG(BAUD_RATE_GENERATOR),
                           MASK(BAUD_RATE_GENERATOR_CD),
                           VAL(BAUD_RATE_GENERATOR_CD, 0x7CU)),

        PSI_MULTI_WRITE_MULTI_MASKED32(REG(CR),
                            2,
                            uart_CR_MASK, TRUEV(CR_TX_EN) | TRUEV(CR_RX_EN) | TRUEV(CR_TXRST) | TRUEV(CR_RXRST),
                            uart_MR_MASK, VAL(MR_PAR, 0x4)),

        PSI_END_PROGRAM
};

#if DEBUG_WRITES == 1
static void GeneratePs7initComparator(uint32_t * array)
{
#define EMIT_MASKWRITE(addr, mask, val) array[(addr & 0x0FFF) / 4] = (val & mask) | (array[(addr & 0x0FFF) / 4] & (~mask))
        EMIT_MASKWRITE(0XE0000034, 0x000000FFU, 0x00000006U),
        EMIT_MASKWRITE(0XE0000018, 0x0000FFFFU, 0x0000007CU),
        EMIT_MASKWRITE(0XE0000000, 0x000001FFU, 0x00000017U),
        EMIT_MASKWRITE(0XE0000004, 0x000003FFU, 0x00000020U)
}

void uartRunInitProgram()
{
    uint32_t array[0xFFF] = {0};
    GeneratePs7initComparator(array);
    psi_RunProgram(uart0_init, array);
}

#else
void uartRunInitProgram()
{
    psi_RunProgram(uart0_init, 0);
}
#endif
