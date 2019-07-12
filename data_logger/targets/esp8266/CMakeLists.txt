
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

include_directories(${SDFAT_ESP8266_DIR} ${SPI_ESP8266_DIR})

set(spi_sources
 ${SPI_ESP8266_DIR}/SPI.cpp
)
set(sd_sources
            ${SDFAT_ESP8266_DIR}/SD.cpp
            ${SDFAT_ESP8266_DIR}/File.cpp
            ${SDFAT_ESP8266_DIR}/utility/SdVolume.cpp
            ${SDFAT_ESP8266_DIR}/utility/SdFile.cpp
            ${SDFAT_ESP8266_DIR}/utility/Sd2Card.cpp
)
set(ext_sources
            ${spi_sources}
            ${sd_sources}
            ${adafruit_sources}
)
set(EXT_SRC_DIR
    ${SDFAT_ESP8266_DIR}
    ${SPI_ESP8266_DIR}
    ${PCD8544_SRC}
    ${GFX_SRC}
)

#add_subdirectory(generic)
add_subdirectory(12e)
