set(project blinky_hw)

file(GLOB SRC_SCALA_FILES CONFIGURE_DEPENDS 
    *.scala
    ../chip/dissy/*.scala
    ../chip/*.scala
    project/plugins.sbt
    project/ikuy.scala
    build.sbt

)

set( GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/workspace )
set( BIN_PATH ${GEN_DIR}/${project}.bin)
set( FINAL_PATH ${CMAKE_CURRENT_BINARY_DIR}/${project}.bin)

project(${project} NONE)

add_custom_command( 
      OUTPUT ${BIN_PATH}
      COMMAND sbt "runMain blinky.Build"
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      DEPENDS ${SRC_SCALA_FILES} 
)

add_custom_command(
    OUTPUT ${FINAL_PATH}
    COMMAND ${CMAKE_OBJCOPY} 
                -I binary -O binary 
                --reverse-bytes=4 
                ${BIN_PATH} 
                ${FINAL_PATH}
    DEPENDS ${BIN_PATH}
)

add_custom_target( ${project} DEPENDS ${FINAL_PATH} )
