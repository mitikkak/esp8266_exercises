project(nokia_5110_lcd_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/12e.cmake)
set(EXT_SRC_DIR ${PCD8544_SRC}
                ${GFX_SRC}
                ${SPI_ESP8266_DIR})
set(ext_sources ${adafruit_sources}
                ${spi_sources}
)
set(all_sources ${sources} ${ext_sources})
build_targets_esp8266_12e("${all_sources}" "${EXT_SRC_DIR}")