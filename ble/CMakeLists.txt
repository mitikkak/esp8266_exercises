
include(${ARDUINO_CMAKE_DIR}/esp32/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp32/libs.cmake)
set(client_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/client)
set(server_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/server)
set(gatt_client_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/gatt_client)
set(gatt_server_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/gatt_server)
set(EXT_SRC_DIR ${ESP32_BLE_SRC_DIR}
)
set(ext_sources ${esp32_ble_sources}
)
add_subdirectory(targets/client_wroom32)
add_subdirectory(targets/server_wroom32)
#add_subdirectory(targets/gatt_client_wroom32)
#add_subdirectory(targets/gatt_server_wroom32)