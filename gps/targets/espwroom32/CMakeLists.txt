
project(gps_wroom32)
include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)

set(ESP32_PCD8544_SRC ${PROJECT_ROOT}/Adafruit-PCD8544-ShiftOut)
set(GFX_SRC ${PROJECT_ROOT}/Adafruit-GFX)
set(esp32_adafruit_sources ${ESP32_PCD8544_SRC}/Adafruit_PCD8544.cpp
                     ${GFX_SRC}/Adafruit_GFX.cpp
)

set(EXT_SRC_DIR
    ${ESP32_PCD8544_SRC}
    ${GFX_SRC}
    ${GPS_SRC}
    ${ESP32_SD_SRC_DIR}
    ${ESP32_FS_SRC_DIR}
    ${ESP32_SPI_SRC_DIR}
    ${ESP32_BLE_SRC_DIR}
    ${ESP32_WIFI_SRC_DIR}
)

set(ext_sources
    ${gps_sources}
    ${esp32_adafruit_sources}
    ${esp32_fs_sources}
    ${esp32_sd_sources}
    ${esp32_spi_sources}
    ${esp32_wifi_sources}
)

set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")