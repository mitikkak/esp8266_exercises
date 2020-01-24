
project(multi_core_wroom32)

include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)
set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")