#include <stdint.h>
#include <assert.h>
#include <hwreg.h>
#include "serial_debug/uart_control.h"
#include "zynq_ps/uart.h"

void debug_set_uart_freq(debug_uart_freq freq)
{
    HW_REG_MB_MERGE(uart, 0, CR, uart_CR_MASK,
                    HW_REG_FIELD(uart, CR, TX_DIS) |
                    HW_REG_FIELD(uart, CR, RX_DIS));

    switch(freq)
    {
        case DUF_BAUD_9600:
            *HW_REG_MB(uart, 0, BAUD_RATE_GENERATOR) = 1302;
            *HW_REG_MB(uart, 0, BAUD_RATE_DIVIDER) = 7;
            break;
        default:
        case DUF_BAUD_115200:
            *HW_REG_MB(uart, 0, BAUD_RATE_GENERATOR) = 124;
            *HW_REG_MB(uart, 0, BAUD_RATE_DIVIDER) = 6;
            break;
        case DUF_BAUD_921600:
            *HW_REG_MB(uart, 0, BAUD_RATE_GENERATOR) = 18;
            *HW_REG_MB(uart, 0, BAUD_RATE_DIVIDER) = 5;
            break;
        }

    HW_REG_MB_MERGE(uart, 0, CR, uart_CR_MASK,
                        HW_REG_FIELD(uart, CR, TX_EN) |
                        HW_REG_FIELD(uart, CR, RX_EN) |
                        HW_REG_FIELD(uart, CR, TXRST) |
                        HW_REG_FIELD(uart, CR, RXRST) );
}

void debug_set_uart_fifo_size(uint32_t size)
{
    uint32_t cappedSize = (size > 0x2F) ? 0x2F : size;
    *HW_REG_MB(uart, 0, RX_FIFO_TRIGGER_LEVEL) = cappedSize;
    *HW_REG_MB(uart, 0, TX_FIFO_TRIGGER_LEVEL) = cappedSize;

    assert(size <= 0x2F);
}

#define IsTransmitEmpty() ((*HW_REG_MB(uart, 0, SR) & uart_SR_TXEMPTY_MASK) == uart_SR_TXEMPTY_MASK)

void debug_uart_stall_till_transmit_fifo_is_empty()
{
    while (!IsTransmitEmpty())
    {
        // do nothing
    }
    
}