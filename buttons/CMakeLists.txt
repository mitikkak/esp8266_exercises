
#set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(LCD_I2C_DIR ${PROJECT_ROOT}/LiquidCrystal_I2C)
set(lcd_i2c_sources
      ${LCD_I2C_DIR}/LiquidCrystal_I2C.cpp
)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
)
set(ext_sources ${lcd_i2c_sources}
                ${wire_sources})
set(EXT_SRC_DIR ${LCD_I2C_DIR}
                ${WIRE_ESP8266_DIR}
)

add_subdirectory(targets/generic)
add_subdirectory(targets/12e)
