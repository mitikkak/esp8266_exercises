cmake_minimum_required(VERSION 3.1)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(ARDUINO_CMAKE_DIR ${PROJECT_ROOT}/arduino_cmake)

set(ESP32_PCD8544_SRC ${PROJECT_ROOT}/esp32-snippets/hardware/displays/Adafruit-PCD8544-Nokia-5110-LCD-library)
set(ESP32_GFX_SRC ${PROJECT_ROOT}/esp32-snippets/hardware/displays/Adafruit-GFX-Library)
set(esp32_adafruit_sources 
    ${ESP32_PCD8544_SRC}/Adafruit_PCD8544.cpp
    ${ESP32_GFX_SRC}/Adafruit_GFX.cpp
)

add_subdirectory(${ARDUINO_CMAKE_DIR}/esp8266/core)
add_subdirectory(${ARDUINO_CMAKE_DIR}/esp32/core)
add_subdirectory(${PROJECT_ROOT}/ble)
add_subdirectory(${PROJECT_ROOT}/blink)
add_subdirectory(${PROJECT_ROOT}/buttons)
add_subdirectory(${PROJECT_ROOT}/data_logger)
add_subdirectory(${PROJECT_ROOT}/lcd_i2c)
add_subdirectory(${PROJECT_ROOT}/gps)
add_subdirectory(${PROJECT_ROOT}/web_server)
add_subdirectory(${PROJECT_ROOT}/web_ap)
add_subdirectory(${PROJECT_ROOT}/web_sockets)
add_subdirectory(${PROJECT_ROOT}/i2c_scanner)
add_subdirectory(${PROJECT_ROOT}/nokia_5110_lcd)
add_subdirectory(${PROJECT_ROOT}/wire)
add_subdirectory(${PROJECT_ROOT}/esp32_nokia_5110)

