
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(ext_sources
            ${gps_sources}
            ${esp8266_sw_serial_sources}
)

set(EXT_SRC_DIR ${GPS_SRC}
                ${SW_SERIAL_ESP8266_SRC}
)

add_subdirectory(12e)
