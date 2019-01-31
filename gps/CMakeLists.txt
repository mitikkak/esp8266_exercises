
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(IIC_LCD_SRC ${PROJECT_ROOT}/LiquidCrystal_I2C)
set(GPS_SRC ${PROJECT_ROOT}/TinyGPS)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
)
set(ext_sources
            ${IIC_LCD_SRC}/LiquidCrystal_I2C.cpp
            ${WIRE_ESP8266_DIR}/Wire.cpp
            ${GPS_SRC}/TinyGPS.cpp
)
set(EXT_SRC_DIR ${GPS_SRC}
                ${IIC_LCD_SRC}
                ${WIRE_ESP8266_DIR}
)

add_subdirectory(targets/generic)
add_subdirectory(targets/12e)