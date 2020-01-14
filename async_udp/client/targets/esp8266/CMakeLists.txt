
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(EXT_SRC_DIR ${WIFI_ESP8266_DIR}
                ${ESP_ASYNC_UDP_DIR}
)
set(ext_sources
    ${wifi_sources}
    ${ESP_ASYNC_UDP_DIR}/AsyncUDP.cpp
)

add_subdirectory(12e)
add_subdirectory(generic)