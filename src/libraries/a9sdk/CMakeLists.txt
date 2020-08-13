set(project a9sdk)

project(${project} C ASM)

add_library(${project} INTERFACE)
target_include_directories(${project} INTERFACE .)
