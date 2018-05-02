project(web_server)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/tools.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/defs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/deploy.cmake)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
            ${WIFI_ESP8266_DIR}/ESP8266WiFiSTA.cpp
            ${WIFI_ESP8266_DIR}/WiFiServer.cpp
            ${WIFI_ESP8266_DIR}/ESP8266WiFiGeneric.cpp
            ${WIFI_ESP8266_DIR}/ESP8266WiFi.cpp
            ${WIFI_ESP8266_DIR}/WiFiClient.cpp
   )
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} PRIVATE ${esp8266_linker_options})
add_dependencies(${PROJECT_NAME} ${esp8266_core_libs})
target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${compiler_set_cpp}
)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${SRC_DIR}
    ${WIFI_ESP8266_DIR}
)

elf_to_bin(${PROJECT_NAME})
upload(${PROJECT_NAME} elf_to_bin_${PROJECT_NAME})
