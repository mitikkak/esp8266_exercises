
project(wire_master_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/12e.cmake)
set(ext_sources 
                ${wire_sources}
)
set(EXT_SRC_DIR 
                ${WIRE_ESP8266_DIR}
)


set(all_sources ${master_sources} ${ext_sources})
build_targets_esp8266_12e("${all_sources}" "${EXT_SRC_DIR}")