set(project core)

project(${project} C ASM)

set(SRCLIST 
        src/snprintf.c
)
set(HEADERLIST 
        include/snprintf.h
)


add_library(${project} ${SRCLIST} ${HEADERLIST})
target_include_directories(${project} PUBLIC include)
target_link_libraries(${project} PUBLIC -lgcc)
