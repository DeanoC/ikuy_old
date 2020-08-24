#include "serial_debug/debug_print.h"
#include "hw/l1cache.h"
#include "hw_fpga/pcap.h"

extern uintptr_t get_bitstream_start_address(void);
extern uintptr_t get_bitstream_end_address(void);

int cpu0_main()
{
//    l1cache_instruction_enable(true);
//    l1cache_data_enable(true);

    debug_print("Blinky cpu0 starting\n");
    debug_printf("bitstream start address = 0x%.8x\n", get_bitstream_start_address());
    debug_printf("bitstream end address = 0x%.8x\n", get_bitstream_end_address());

    hw_fpga_pcap_upload_bitstream(get_bitstream_start_address());

    while(1)
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