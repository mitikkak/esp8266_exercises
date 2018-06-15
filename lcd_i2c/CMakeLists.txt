
#set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})


set(LCD_I2C_DIR ${PROJECT_ROOT}/LiquidCrystal_I2C)
set(lcd_i2c_sources
      ${LCD_I2C_DIR}/LiquidCrystal_I2C.cpp
)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
)

add_subdirectory(targets/generic)
add_subdirectory(targets/12e)
