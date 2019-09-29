
project(web_sockets_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/12e.cmake)

set(ext_sources ${wifi_sources} 
                ${WEB_SERVER_ESP8266_DIR}/ESP8266WebServer.cpp
                ${WEB_SERVER_ESP8266_DIR}/Parsing.cpp
                ${web_sockets_sources}
                ${ARDUINO_OTA_DIR}/ArduinoOTA.cpp
                ${esp8266_mdns_sources}
                ${HASH_ESP8266_DIR}/Hash.cpp
)
set(EXT_SRC_DIR ${WIFI_ESP8266_DIR}
                ${ARDUINO_OTA_DIR}
                ${WEB_SERVER_ESP8266_DIR}
                ${MDNS_ESP8266_DIR}
                ${WEB_SOCKETS_DIR}
                ${HASH_ESP8266_DIR}
)

set(all_sources ${sources} ${ext_sources})
build_targets_esp8266_12e("${all_sources}" "${EXT_SRC_DIR}")