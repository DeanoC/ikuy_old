#include "serial_debug/debug_print.h"
#include "hw/l1cache.h"

uintptr_t bitstream_start;

int cpu0_main()
{
    l1cache_instruction_enable(true);
    l1cache_data_enable(true);

    debug_print("Blinky cpu0 starting\n");
    debug_printf("bitstream address = 0x%.8x\n", bitstream_start);

    while(1)
    {
    }
}

int cpu1_main()
{
    l1cache_instruction_enable(true);
    l1cache_data_enable(true);

    debug_print("Blinky cpu1 starting\n");

    while(1)
    {
    }
}