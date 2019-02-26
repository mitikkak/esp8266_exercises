
include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
)
set(ext_sources 
            ${WIRE_ESP8266_DIR}/Wire.cpp
)
set(EXT_SRC_DIR
    ${WIRE_ESP8266_DIR}
)

add_subdirectory(targets/12e)