
project(sync_tcp_server_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/12e.cmake)
set(all_sources ${sources} ${ext_sources})
build_targets_esp8266_12e("${all_sources}" "${EXT_SRC_DIR}")
