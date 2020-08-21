#pragma once

#include <stdint.h>
typedef enum debug_uart_freq
{
    DUF_BAUD_9600,
    DUF_BAUD_115200,
    DUF_BAUD_921600,
} debug_uart_freq;

void debug_set_uart_freq(debug_uart_freq freq);

void debug_set_uart_fifo_size(uint32_t size);

void debug_uart_stall_till_transmit_fifo_is_empty();