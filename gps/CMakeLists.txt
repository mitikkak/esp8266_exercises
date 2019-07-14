
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(GPS_SRC ${PROJECT_ROOT}/TinyGPS)

set(PCD8544_SRC ${PROJECT_ROOT}/Adafruit-PCD8544)
set(GFX_SRC ${PROJECT_ROOT}/Adafruit-GFX)
set(adafruit_sources ${PCD8544_SRC}/Adafruit_PCD8544.cpp
                     ${GFX_SRC}/Adafruit_GFX.cpp
)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
)
set(ext_sources
            ${GPS_SRC}/TinyGPS.cpp
            ${adafruit_sources}
            ${spi_sources}
)
set(EXT_SRC_DIR ${GPS_SRC}
                ${PCD8544_SRC}
                ${GFX_SRC}
                ${SPI_ESP8266_DIR}
)

add_subdirectory(targets/generic)
add_subdirectory(targets/12e)