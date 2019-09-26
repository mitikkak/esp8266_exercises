
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(PCD8544_SRC ${PROJECT_ROOT}/Adafruit-PCD8544)
set(GFX_SRC ${PROJECT_ROOT}/Adafruit-GFX)
set(adafruit_sources ${PCD8544_SRC}/Adafruit_PCD8544.cpp
                     ${GFX_SRC}/Adafruit_GFX.cpp
)

set(ext_sources
            ${GPS_SRC}/TinyGPS.cpp
            ${adafruit_sources}
            ${esp8266_spi_sources}
            ${esp8266_sd_all_sources}
)
set(EXT_SRC_DIR ${GPS_SRC}
                ${PCD8544_SRC}
                ${GFX_SRC}
                ${SPI_ESP8266_DIR}
                ${SD_ALL_ESP8266_DIR}
)

add_subdirectory(generic)
add_subdirectory(12e)