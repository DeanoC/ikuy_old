#include <stdint.h>
#include <uart.h>
#include <hw_regs.h>
#include "snprintf.h"

#define IsTransmitFull() ((*HW_MB_REG(uart, 0, SR) & uart_SR_TXFULL_MASK) == uart_SR_TXFULL_MASK)

void debug_print(char const *const text)
{
    char const * cur = text;
    while(*cur != nullptr)
    {
        while (IsTransmitFull())
        {
            // stall
        }

        *HW_MB_REG(uart, 0, FIFO) = *cur;

        cur++;
    }
}

void debug_printf(const char *format, ...)
{
    char buffer[1024]; // 1K max string (on stack)
    va_list va;
    va_start(va, format);
    vsnprintf(buffer, 1024, format, va);
    va_end(va);
    buffer[1023] = 0;
    debug_print(buffer);
}
