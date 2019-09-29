project(i2c_scanner_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/12e.cmake)
set(ext_sources 
            ${WIRE_ESP8266_DIR}/Wire.cpp
)
set(EXT_SRC_DIR
    ${WIRE_ESP8266_DIR}
)
set(all_sources ${sources} ${ext_sources})
build_targets_esp8266_12e("${all_sources}" "${EXT_SRC_DIR}")