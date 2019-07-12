#pragma once

#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
extern Adafruit_PCD8544 lcd;

void lcdDbg(const char* const msg);
void initLcd();

