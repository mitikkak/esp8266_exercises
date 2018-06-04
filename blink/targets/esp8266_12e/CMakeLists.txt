
project(blink_esp8266_12e)

include(${ARDUINO_CMAKE_DIR}/esp8266/paths.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/tools.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/defs.cmake)
include(${ARDUINO_CMAKE_DIR}/esp8266/deploy.cmake)

set(sources ${PROJECT_ROOT}/Loop.cpp
            ${PROJECT_ROOT}/Setup.cpp
   )
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} PRIVATE ${esp8266_12e_linker_options})
add_dependencies(${PROJECT_NAME} ${esp8266_12e_core_libs})
target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${compiler_set_cpp}
    ${esp8266_12e_defs}
)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
	${esp8266_12e_path}
)

elf_to_bin(${PROJECT_NAME})
upload(${PROJECT_NAME} elf_to_bin_${PROJECT_NAME})
