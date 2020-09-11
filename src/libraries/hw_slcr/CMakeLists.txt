set(project hw_slcr)

project(${project} C ASM)

file(GLOB_RECURSE SRCLIST CONFIGURE_DEPENDS src/*.c )
file(GLOB_RECURSE HEADERLIST CONFIGURE_DEPENDS include/*.h )

add_library(${project} ${SRCLIST} ${HEADERLIST})
target_include_directories(${project} PUBLIC include)
target_link_libraries(${project} PUBLIC core serial_debug)
