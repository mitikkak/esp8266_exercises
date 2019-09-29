
project(gps_ss_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/12e.cmake)

set(ext_sources
            ${gps_sources}
            ${esp8266_sw_serial_sources}
)

set(EXT_SRC_DIR ${GPS_SRC}
                ${SW_SERIAL_ESP8266_SRC}
)

set(all_sources ${sources} ${ext_sources})
build_targets_esp8266_12e("${all_sources}" "${EXT_SRC_DIR}")

