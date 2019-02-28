
set(sources ${CMAKE_CURRENT_SOURCE_DIR}/nokia_5110_lcd.cpp)
set(PCD8544_SRC ${PROJECT_ROOT}/Adafruit-PCD8544)
set(GFX_SRC ${PROJECT_ROOT}/Adafruit-GFX)
set(adafruit_sources ${PCD8544_SRC}/Adafruit_PCD8544.cpp
                     ${GFX_SRC}/Adafruit_GFX.cpp
)
add_subdirectory(targets/12e)