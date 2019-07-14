

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
)
set(GPS_SRC ${PROJECT_ROOT}/TinyGPS)

add_subdirectory(targets/esp8266)
add_subdirectory(targets/espwroom32)