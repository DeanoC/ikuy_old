#pragma once
#include <stdint.h>

// the global timer (GTC) is a 64 bit timer running 1/2 CPU clock speed

void hw_timers_global_reset();

uint64_t hw_timers_global_get();

float hw_timers_global_get_elapsed(uint64_t start, uint64_t end);