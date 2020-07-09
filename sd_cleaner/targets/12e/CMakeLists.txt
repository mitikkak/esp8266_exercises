project(sd_cleaner_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/12e.cmake)

set(ext_sources
    ${esp8266_sd_sources}
    ${spi_sources}
)
set(EXT_SRC_DIR
    ${SDFAT_ESP8266_DIR}
    ${SPI_ESP8266_DIR}
)
set(all_sources ${sources} ${ext_sources})
build_targets_esp8266_12e("${all_sources}" "${EXT_SRC_DIR}")