
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(sources ${PROJECT_ROOT}/Loop.cpp
            ${PROJECT_ROOT}/Setup.cpp
)

add_subdirectory(targets/esp8266)
add_subdirectory(targets/esp8266_12e)
