project(nokia_5110_lcd_wroom32)

include(${ARDUINO_CMAKE_DIR}/esp32/wroom32.cmake)

set(ESP32_PCD8544_SRC ${PROJECT_ROOT}/Adafruit-PCD8544-ShiftOut)
set(esp32_adafruit_sources ${ESP32_PCD8544_SRC}/Adafruit_PCD8544.cpp
                     ${GFX_SRC}/Adafruit_GFX.cpp
)

set(EXT_SRC_DIR ${ESP32_PCD8544_SRC}
                ${GFX_SRC}
)
            
set(ext_sources ${esp32_adafruit_sources}
)

set(all_sources ${sources} ${ext_sources})
build_targets_espwroom32("${all_sources}" "${EXT_SRC_DIR}")