
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(slave_sources ${SRC_DIR}/Loop.cpp
            ${SRC_DIR}/Setup.cpp
            ${SRC_DIR}/Components.cpp
)

add_subdirectory(targets/atmega328)