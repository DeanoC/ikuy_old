#include "serial_debug/debug_print.h"

#define assert(test)                                                                           \
  if (!(test))                                                                                 \
  {                                                                                            \
    debug_unsafe_printf(DEBUG_RED_PEN "%s:%u: ERROR %s\n" DEBUG_WHITE_PEN, __FILE__, __LINE__, #test); \
  }
