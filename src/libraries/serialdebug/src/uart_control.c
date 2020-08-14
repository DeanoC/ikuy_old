#include <stdint.h>
#include "uart_control.h"
#include "uart.h"
#include "hw_regs.h"

void debug_set_uart_freq(debug_uart_freq freq)
{
    HW_MB_MERGE_REG(uart, 0, CR, uart_CR_MASK,
                    HW_REG_FIELD(uart, CR, TX_DIS) |
                    HW_REG_FIELD(uart, CR, RX_DIS));

    switch(freq)
    {
        case DUF_BAUD_9600:
            *HW_MB_REG(uart, 0, BAUD_RATE_GENERATOR) = 1302;
            *HW_MB_REG(uart, 0, BAUD_RATE_DIVIDER) = 7;
            break;
        default:
        case DUF_BAUD_115200:
            *HW_MB_REG(uart, 0, BAUD_RATE_GENERATOR) = 124;
            *HW_MB_REG(uart, 0, BAUD_RATE_DIVIDER) = 6;
            break;
        case DUF_BAUD_921600:
            *HW_MB_REG(uart, 0, BAUD_RATE_GENERATOR) = 18;
            *HW_MB_REG(uart, 0, BAUD_RATE_DIVIDER) = 5;
            break;
        }

    HW_MB_MERGE_REG(uart, 0, CR, uart_CR_MASK,
                        HW_REG_FIELD(uart, CR, TX_EN) |
                        HW_REG_FIELD(uart, CR, RX_EN) |
                        HW_REG_FIELD(uart, CR, TXRST) |
                        HW_REG_FIELD(uart, CR, RXRST) );
}

void debug_set_uart_fifo_size(uint32_t size)
{
    if(size > 0x2F)
    {
        return;
    } else 
    {
        *HW_MB_REG(uart, 0, RX_FIFO_TRIGGER_LEVEL) = size;
        *HW_MB_REG(uart, 0, TX_FIFO_TRIGGER_LEVEL) = size;
    }
}