#include "serial_debug/debug_print.h"
#include "hw/l1cache.h"
#include "hw_fpga/pcap.h"

extern uintptr_t get_bitstream_start_address(void);
extern uintptr_t get_bitstream_end_address(void);

#define assert(test, fmt, ...) \
    if( !(test) ) { debug_printf(fmt)}
int cpu0_main()
{
//    l1cache_instruction_enable(true);
//    l1cache_data_enable(true);

debug_print(DEBUG_WHITE_PEN "\nBlinky cpu0 starting\n");
//debug_printf("bitstream start address = 0x%.8x\n", get_bitstream_start_address());
//debug_printf("bitstream end address = 0x%.8x\n", get_bitstream_end_address());

hw_fpga_pcap_upload_bitstream(get_bitstream_start_address());

debug_print(DEBUG_WHITE_PEN "AXI GP0 PS Master test ");
assertf(*(uint32_t *)0x40000000 == 0xDCDCDCDC, DEBUG_RED_PEN "\nFailed 0x%x == 0x%x\n", 0x40000000, 0xDCDCDCDC);
assertf(*(uint32_t *)0x40000004 == 0x40000004, DEBUG_RED_PEN "\nFailed 0x%x == 0x%x\n", 0x40000004, 0x40000004);

// write to the test register (its a simple 32 bit register)
*(uint32_t *)0x40000000 = 0x0A0B0C0D;
assertf(*(uint32_t *)0x40000000 == 0x0A0B0C0D, DEBUG_RED_PEN "\nFailed readback of register write\n");
debug_print(DEBUG_GREEN_PEN "PASS\n");

while (1)
{
    }
}

int cpu1_main()
{
//    l1cache_instruction_enable(true);
//    l1cache_data_enable(true);

//    debug_print("Blinky cpu1 starting\n");

    while(1)
    {
    }
}