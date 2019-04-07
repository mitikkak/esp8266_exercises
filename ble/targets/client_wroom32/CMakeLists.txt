project(ble_client_wroom32)

set(sources ${client_src_dir}/client.cpp
)
include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)
set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")