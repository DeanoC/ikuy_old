set(project serialdebug)

project(${project} C ASM)

set(SRCLIST 
        src/debug_print.c
)
set(HEADERLIST 
        include/debug_print.h
)


add_library(${project} ${SRCLIST} ${HEADERLIST})
target_include_directories(${project} PUBLIC include)
target_link_libraries(${project} PUBLIC core)
