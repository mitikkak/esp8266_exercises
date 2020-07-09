
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(sources ${PROJECT_ROOT}/sd_cleaner.cpp)
add_subdirectory(targets/espwroom32)
add_subdirectory(targets/12e)