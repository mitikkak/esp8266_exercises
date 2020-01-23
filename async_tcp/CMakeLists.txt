
set(ESP_ASYNC_TCP_DIR ${PROJECT_ROOT}/ESPAsyncTCP/src)
set(async_tcp_sources ${ESP_ASYNC_TCP_DIR}/ESPAsyncTCP.cpp
)
set(ESP32_ASYNC_TCP_SRC_DIR ${PROJECT_ROOT}/AsyncTCP/src)
set(esp32_async_tcp_sources ${ESP32_ASYNC_TCP_SRC_DIR}/AsyncTCP.cpp
)
set(COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(server)
add_subdirectory(client)