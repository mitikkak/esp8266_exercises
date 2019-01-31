
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(LCD_I2C_DIR ${PROJECT_ROOT}/LiquidCrystal_I2C)
set(lcd_i2c_sources
      ${LCD_I2C_DIR}/LiquidCrystal_I2C.cpp
)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            
)
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
            ${lcd_i2c_sources}
            ${wire_sources}
)
set(EXT_SRC_DIR
    ${SDFAT_ESP8266_DIR}
    ${SPI_ESP8266_DIR}
    ${LCD_I2C_DIR}
    ${WIRE_ESP8266_DIR}
)

add_subdirectory(targets/generic)
add_subdirectory(targets/12e)
