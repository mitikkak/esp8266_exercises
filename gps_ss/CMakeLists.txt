
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Components.cpp
)
set(GPS_SRC ${PROJECT_ROOT}/TinyGPS)

set(gps_sources ${GPS_SRC}/TinyGPS.cpp)

add_subdirectory(targets/esp8266)