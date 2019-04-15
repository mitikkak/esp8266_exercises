project(ble_gatt_client_wroom32)

set(sources ${gatt_client_src_dir}/gatt_client.cpp
)
include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)
set(all_sources ${sources} )
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")