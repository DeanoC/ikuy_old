set(project hw_timers)

project(${project} C ASM)

set(SRCLIST 
        src/global.c
        src/private.c
)
set(HEADERLIST 
        include/${project}/global.h
        include/${project}/private.h
)


add_library(${project} ${SRCLIST} ${HEADERLIST})
target_include_directories(${project} PUBLIC include)
target_link_libraries(${project} PUBLIC core)
