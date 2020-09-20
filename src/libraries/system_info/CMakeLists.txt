set(project system_info)

project(${project} C ASM)

file(GLOB_RECURSE SRCLIST CONFIGURE_DEPENDS src/*.c )
file(GLOB_RECURSE HEADERLIST CONFIGURE_DEPENDS include/*.h )


add_library(${project} ${SRCLIST} ${HEADERLIST})
target_include_directories(${project} PUBLIC include)
target_link_libraries(${project} PRIVATE zynq_ps)
target_link_libraries(${project} PRIVATE core)
target_link_libraries(${project} PRIVATE hw_slcr)
target_link_libraries(${project} PRIVATE serial_debug)
