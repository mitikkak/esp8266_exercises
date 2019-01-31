cmake_minimum_required(VERSION 3.1)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(ARDUINO_CMAKE_DIR ${PROJECT_ROOT}/arduino_cmake)

add_subdirectory(${ARDUINO_CMAKE_DIR}/esp8266/core)
add_subdirectory(${PROJECT_ROOT}/blink)
add_subdirectory(${PROJECT_ROOT}/data_logger)
add_subdirectory(${PROJECT_ROOT}/lcd_i2c)
add_subdirectory(${PROJECT_ROOT}/gps)
add_subdirectory(${PROJECT_ROOT}/web_server)
add_subdirectory(${PROJECT_ROOT}/web_sockets)
