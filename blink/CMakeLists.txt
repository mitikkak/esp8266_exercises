
project(blink)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/tools.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/defs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/core.cmake)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
   )
add_executable(${PROJECT_NAME} ${sources})
#add_executable(${PROJECT_NAME} ${sources} esp8266_core)
#target_link_libraries(${PROJECT_NAME} esp8266_core esp8266_core_asm)
target_link_libraries(${PROJECT_NAME} esp8266_core)
target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${compiler_set_2}
)
#add_dependencies(${PROJECT_NAME} esp8266_core)
