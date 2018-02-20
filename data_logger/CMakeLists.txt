project(data_logger)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/tools.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/defs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/core.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/deploy.cmake)

include_directories(${SDFAT_ESP8266_DIR} ${SPI_ESP8266_DIR})

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${SDFAT_ESP8266_DIR}/SD.cpp
            ${SDFAT_ESP8266_DIR}/File.cpp
            ${SDFAT_ESP8266_DIR}/utility/SdVolume.cpp
            ${SDFAT_ESP8266_DIR}/utility/SdFile.cpp
            ${SDFAT_ESP8266_DIR}/utility/Sd2Card.cpp
            ${SPI_ESP8266_DIR}/SPI.cpp
   )
add_executable(${PROJECT_NAME} ${sources})
#target_link_libraries(${PROJECT_NAME} ${esp8266_linker_options})
target_link_libraries(${PROJECT_NAME} PUBLIC esp8266_core PRIVATE ${esp8266_linker_options})
target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${compiler_set_2}
)

elf_to_bin(${PROJECT_NAME})
upload(${PROJECT_NAME} elf_to_bin_${PROJECT_NAME})