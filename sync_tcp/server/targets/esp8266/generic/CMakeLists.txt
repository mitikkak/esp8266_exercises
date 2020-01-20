
project(sync_tcp_server)

include(${ARDUINO_CMAKE_DIR}/esp8266/generic.cmake)
set(all_sources ${sources} ${ext_sources})
build_targets_esp8266_generic("${all_sources}" "${EXT_SRC_DIR}")
