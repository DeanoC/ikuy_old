#include <assert.h>
#include "serial_debug/debug_print.h"

void assert_printf(char const *file, int line, char const *txt)
{
  debug_unsafe_printf(DEBUG_RED_PEN "%s:%u: ERROR %s\n", file, __FILE__, line, txt);
}
