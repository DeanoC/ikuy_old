
#pragma once

#include "stdbool.h"
#include "arma9_cop.h"

#define L1CACHE_LINE_SIZE (32)
#define L1CACHE_LINE_ADDR_MASK (~(0x1F))

// invalidate means the cache lines WON'T be written back
// flush means cache lines will be written back out 
// icache is read only so no flush provided

void l1cache_data_flush_all(void);
void l1cache_data_invalidate_all(void);

void l1cache_instruction_invalidate_all(void);
void l1cache_branch_predictor_invalidate_all(void);

void l1cache_data_enable(bool enable);
void l1cache_instruction_enable(bool enable);

void l1cache_data_flush_line(void* addr);
void l1cache_data_flush_range(void* addr, uint32_t byteCount);
