
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
   )

include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

add_subdirectory(targets/generic)
add_subdirectory(targets/12e)
