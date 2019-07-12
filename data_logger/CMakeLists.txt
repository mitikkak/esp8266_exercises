
set(PCD8544_SRC ${PROJECT_ROOT}/Adafruit-PCD8544)
set(GFX_SRC ${PROJECT_ROOT}/Adafruit-GFX)
set(adafruit_sources ${PCD8544_SRC}/Adafruit_PCD8544.cpp
                     ${GFX_SRC}/Adafruit_GFX.cpp
)

set(sources ${CMAKE_CURRENT_SOURCE_DIR}/Loop.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Lcd.cpp
            
)

add_subdirectory(targets/esp8266)
add_subdirectory(targets/espwroom32)
