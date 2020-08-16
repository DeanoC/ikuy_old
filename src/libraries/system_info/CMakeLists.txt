set(project system_info)

project(${project} C ASM)

set(SRCLIST 
        src/cpu.c
)
set(HEADERLIST 
        include/${project}/cpu.h
)


add_library(${project} ${SRCLIST} ${HEADERLIST})
target_include_directories(${project} PUBLIC include)
target_link_libraries(${project} PUBLIC core)
target_link_libraries(${project} PUBLIC serial_debug)
