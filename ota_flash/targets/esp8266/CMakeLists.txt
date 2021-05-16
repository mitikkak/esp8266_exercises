
include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(EXT_SRC_DIR
    ${WIFI_ESP8266_DIR}
    ${MDNS_ESP8266_DIR}
    ${OTA_ESP8266_DIR}
)

set(ext_sources
    ${esp8266_ota_sources}
    ${esp8266_wifi_sources}
    ${esp8266_mdns_sources}
)

#add_subdirectory(generic)
add_subdirectory(12e)