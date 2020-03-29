
project(sd_cleaner_wroom32)

include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)

set(EXT_SRC_DIR
    ${ESP32_SPI_SRC_DIR}
    ${ESP32_SD_SRC_DIR}
    ${ESP32_FS_SRC_DIR}
)
set(ext_sources
    ${esp32_sd_sources}
    ${esp32_spi_sources}
    ${esp32_fs_sources}
)
set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")