set(project serial_debug)

project(${project} C ASM)

set(SRCLIST 
        src/debug_print.c
        src/uart_control.c
)
set(HEADERLIST 
        include/${project}/debug_print.h
        include/${project}/uart_control.h
)


add_library(${project} ${SRCLIST} ${HEADERLIST})
target_include_directories(${project} PUBLIC include)
target_link_libraries(${project} PUBLIC core)
