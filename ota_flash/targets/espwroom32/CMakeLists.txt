
project(ota_flash_wroom32)

include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)

set(EXT_SRC_DIR
    ${ESP32_WIFI_SRC_DIR}
    ${ESP32_MDNS_SRC_DIR}
    ${ESP32_UPDATE_SRC_DIR}
    ${ESP32_OTA_SRC_DIR}
)
set(ext_sources
    ${esp32_ota_sources}
    ${esp32_wifi_sources}
    ${esp32_update_sources}
    ${esp32_mdns_sources}
)

set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")