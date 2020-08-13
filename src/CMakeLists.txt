cmake_minimum_required(VERSION 3.12.4)


set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING TRUE)
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_ASM_COMPILER "arm-none-eabi-as")
set(CMAKE_OBJCOPY "arm-none-eabi-objcopy")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -ggdb")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles -nostdlib -nostdinc -Wall -ggdb -Wno-builtin-declaration-mismatch -lgcc")
include_directories(libraries/a9sdk SYSTEM)

project(ikuy C)

add_subdirectory(libraries)
add_subdirectory(apps)

