project(esp32_nokia_5110)

include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)

#set(EXT_SRC_DIR ${ESP32_PCD8544_SRC}
#                ${ESP32_GFX_SRC}
#                ${ESP32_SPI_SRC_DIR})
            
#set(ext_sources ${esp32_adafruit_sources}
#                ${esp32_spi_sources}
#)

set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")