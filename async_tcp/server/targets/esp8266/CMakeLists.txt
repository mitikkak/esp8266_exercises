
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(EXT_SRC_DIR ${WIFI_ESP8266_DIR}
                ${DNS_SERVER_ESP8266_DIR}
                ${ESP_ASYNC_TCP_DIR}
                ${COMMON_DIR}
)
set(ext_sources
    ${wifi_sources}
    ${esp8266_dns_server_sources}
    ${async_tcp_sources}
)

add_subdirectory(12e)
add_subdirectory(generic)