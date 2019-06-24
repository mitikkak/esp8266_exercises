project(buttons)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/tools.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/defs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/deploy.cmake)

add_executable(${PROJECT_NAME} ${sources} ${lcd_i2c_sources} ${wire_sources})
target_link_libraries(${PROJECT_NAME} PRIVATE ${esp8266_linker_options})
add_dependencies(${PROJECT_NAME} ${esp8266_core_libs})
target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${compiler_set_cpp}
    ${esp8266_generic_defs}
)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${SRC_DIR}
    ${WIRE_ESP8266_DIR}
    ${LCD_I2C_DIR}
    ${esp8266_generic_path}
)

elf_to_bin(${PROJECT_NAME})
upload(${PROJECT_NAME} elf_to_bin_${PROJECT_NAME})
