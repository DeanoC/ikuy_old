#include <hw/devcfg.h>
#include <hw/uart.h>
#include <hw/regs.h>

#include "uart_control.h"
#include "debug_print.h"

extern void slcrRunInitProgram();
extern void slcrRunPostDDRInitProgram();
extern void ddrcRunInitProgram();
extern void uartRunInitProgram();

#include <stdbool.h>
bool ddrEarlyMemTest();

void WaitForInterupt(void)
{
    __asm__ __volatile__("MCR p15,0,%0,c7,c0,4" ::"r"(0));
}

int main(int argc, char const *argv[])
{
    //ret = ps7_config (ps7_mio_init_data);  
    //ret = ps7_config (ps7_pll_init_data); 
    //ret = ps7_config (ps7_clock_init_data);
    //ret = ps7_config (ps7_ddr_init_data);
    //ret = ps7_config (ps7_peripherals_init_data);
    //ret = ps7_config (ps7_post_config_3_0);
    //ps7_debug_3_0

    // init uart early for debugging
    uartRunInitProgram();

    // step our debug uart baud to 921600!
    // make the uart fifo as big as allowed
    debug_set_uart_freq(DUF_BAUD_921600);
    debug_set_uart_fifo_size(0x2F);

    debug_print(DEBUG_CLR_SCREEN);
    debug_print(DEBUG_WHITE_PEN "** ikuy booting **\n");

    debug_print(DEBUG_WHITE_PEN "System Level Configuration Init ");
    // slcr requires the uart tx fifo is empty
    debug_uart_stall_till_transmit_fifo_is_empty();

    // System Level Control Registers
    slcrRunInitProgram();
    debug_print(DEBUG_GREEN_PEN "OK\n");

    // ddr
    debug_print(DEBUG_WHITE_PEN "DDR Init ");
    ddrcRunInitProgram();
    slcrRunPostDDRInitProgram();
    debug_print(DEBUG_GREEN_PEN "OK\n");
    debug_print(DEBUG_WHITE_PEN "DDR Early MemTest ");
    if (ddrEarlyMemTest() == true)
    {
        debug_print(DEBUG_GREEN_PEN "OK\n");
    } else 
    {
        debug_print(DEBUG_RED_PEN "FAIL\n");
    }
   
    while (1)
    {
        // infinite loop
    }
}