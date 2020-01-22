
project(async_udp_client_wroom32)

include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)

set(EXT_SRC_DIR ${ESP32_WIFI_SRC_DIR}
                ${ESP32_ASYNC_UDP_SRC_DIR}
                ${COMMON_DIR}
)
set(ext_sources ${esp32_wifi_sources}
                ${esp32_async_udp_sources}
)
set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")