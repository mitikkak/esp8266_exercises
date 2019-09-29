
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/arduino_version.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/${ARDUINO_VERSION}/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/${ARDUINO_VERSION}/libs.cmake)

set(ext_sources
            ${esp8266_spi_sources}
            ${esp8266_sd_all_sources}
            ${adafruit_sources}
)
set(EXT_SRC_DIR
    ${SD_ALL_ESP8266_DIR}
    ${SPI_ESP8266_DIR}
    ${PCD8544_SRC}
    ${GFX_SRC}
)

#add_subdirectory(generic)
add_subdirectory(12e)
