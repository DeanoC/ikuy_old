#pragma once

void debug_print(char const * const text);
void debug_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

