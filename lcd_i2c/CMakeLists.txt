project(lcd_i2c)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/tools.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/defs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/deploy.cmake)

include_directories(${SPI_ESP8266_DIR})

set(IIC_LCD_SRC ${PROJECT_ROOT}/LiquidCrystal_I2C)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${IIC_LCD_SRC}/LiquidCrystal_I2C.cpp
            ${WIRE_ESP8266_DIR}/Wire.cpp
   )
add_executable(${PROJECT_NAME} ${sources})
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
    ${IIC_LCD_SRC}
	${esp8266_generic_path}
)

elf_to_bin(${PROJECT_NAME})
upload(${PROJECT_NAME} elf_to_bin_${PROJECT_NAME})
