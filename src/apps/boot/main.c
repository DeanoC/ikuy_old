#include <devcfg.h>
#include <uart.h>
#include <hw_regs.h>

#include "debug_print.h"

extern void sclrRunInitProgram();
extern void ddrcRunInitProgram();
extern void uartRunInitProgram();

int ps7_init();
int ps7_debug();

int main(int argc, char const * argv[])
{
    //ret = ps7_config (ps7_mio_init_data);  
    //ret = ps7_config (ps7_pll_init_data); 
    //ret = ps7_config (ps7_clock_init_data);
    //ret = ps7_config (ps7_ddr_init_data);
    //ret = ps7_config (ps7_peripherals_init_data);
    //ret = ps7_config (ps7_post_config_3_0);
    //ps7_debug_3_0
    
    // lets get the uart running as early as possible for debug messages during boot
    uartRunInitProgram();
    
    // System Level Control Registers need setting up
    sclrRunInitProgram();

   //   ddrcRunInitProgram();

    int counter = 0;
    while (1)
    {
        debug_printf("hello %i\n", counter++);
        // infinite loop
    }
}