project(data_logger)

include(${ARDUINO_CMAKE_DIR}/esp8266/tools.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/defs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/deploy.cmake)

add_executable(${PROJECT_NAME} ${sources} ${sd_sources} ${spi_sources} ${wire_sources} ${lcd_i2c_sources})
target_link_libraries(${PROJECT_NAME} PRIVATE ${esp8266_linker_options})
add_dependencies(${PROJECT_NAME} ${esp8266_core_libs})
target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${compiler_set_cpp}
    ${esp8266_generic_defs}
)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${PCD8544_SRC}
    ${GFX_SRC}
    ${esp8266_generic_path}
)

elf_to_bin(${PROJECT_NAME})
upload(${PROJECT_NAME} elf_to_bin_${PROJECT_NAME})