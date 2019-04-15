project(ble_gatt_server_wroom32)

set(sources ${gatt_server_src_dir}/gatt_server.cpp
)
include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)
set(all_sources ${sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")