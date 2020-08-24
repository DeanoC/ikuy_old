#include <stdint.h>
#include <stdbool.h>

void hw_fpga_pcap_log_registers();
// currently only full bitstreams are supported (TODO Partial bitstreams)
bool hw_fpga_pcap_upload_bitstream(uintptr_t addr);
bool hw_fpga_is_devcfg_dma_busy();