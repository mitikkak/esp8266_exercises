
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(ext_sources
            ${esp8266_spi_sources}
            ${esp8266_sdfs_sources}
            ${esp8266_sdfat_sources}
            ${adafruit_sources}
)
set(EXT_SRC_DIR
    ${SD_ESP8266_DIR}
    ${SDFS_ESP8266_DIR}
    ${SDFAT_ESP8266_DIR}
    ${SPI_ESP8266_DIR}
    ${PCD8544_SRC}
    ${GFX_SRC}
)

#add_subdirectory(generic)
add_subdirectory(12e)
