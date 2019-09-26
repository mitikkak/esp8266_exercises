
include(${ARDUINO_CMAKE_DIR}/esp8266/env/wifi.cmake)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/libs.cmake)

set(WEB_SOCKETS_DIR ${PROJECT_ROOT}/arduinoWebSockets/src)
set(web_sockets_sources ${WEB_SOCKETS_DIR}/WebSocketsServer.cpp
                        ${WEB_SOCKETS_DIR}/WebSocketsClient.cpp
                        ${WEB_SOCKETS_DIR}/WebSockets.cpp
)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
)
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
add_subdirectory(targets/12e)