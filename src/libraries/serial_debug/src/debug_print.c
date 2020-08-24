#include <stdint.h>
#include <hw/uart.h>
#include <hw/reg.h>
#include "snprintf.h"
#include "serial_debug/debug_print.h"
#define IsTransmitFull() (HW_REG_MB_GET_BIT(uart, 0, SR, TXFULL))

extern void own_uart(void);
extern void release_uart(void);

uint32_t debug_uart_lock;

void debug_print(char const *const text)
{
    own_uart();

    debug_unsafe_print(text);

    release_uart();
}

void debug_unsafe_print(char const *const text)
{
    char const * cur = text;
    while(*cur != nullptr)
    {
        while (IsTransmitFull())
        {
            // stall
        }

        *HW_REG_MB(uart, 0, FIFO) = *cur;

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

void debug_unsafe_printf(const char *format, ...)
{
    char buffer[256]; // 1K max string (on stack)
    va_list va;
    va_start(va, format);
    vsnprintf(buffer, 1024, format, va);
    va_end(va);
    buffer[1023] = 0;
    debug_unsafe_print(buffer);
}
