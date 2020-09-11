#ifndef DO_ASSERT
# define DO_ASSERT 1
#endif

#if DO_ASSERT

#include "serial_debug/debug_print.h"
#define assert(test)                                                                         \
if (!(test))                                                                                 \
{                                                                                            \
  debug_unsafe_printf(DEBUG_RED_PEN "%s:%u: ERROR %s\n" DEBUG_WHITE_PEN, __FILE__, __LINE__, #test); \
}

#else

#define assert(test)

#endif