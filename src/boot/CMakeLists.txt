set(project boot)
project(${project} C ASM)

file(GLOB LINKSCRIPT CONFIGURE_DEPENDS boot.ld)
file(GLOB ASMFILES CONFIGURE_DEPENDS *.S)
file(GLOB SRCLIST CONFIGURE_DEPENDS *.c )

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -Wl,-M=${project}.map -T ${LINKSCRIPT}")

add_executable(${project} ${SRCLIST} ${ASMFILES} ${LINKSCRIPT})
set_target_properties(${project} PROPERTIES OUTPUT_NAME ${project}.elf)
target_link_libraries(${project} PUBLIC a9sdk)
target_link_libraries(${project} PUBLIC core)
target_link_libraries(${project} PUBLIC serial_debug)
target_link_libraries(${project} PUBLIC hw_fpga)
target_link_libraries(${project} PUBLIC hw_timers)
target_link_libraries(${project} PUBLIC system_info)

