#pragma once
#include <_global_vars.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SCREEN_ADDRESS 0x3C // 0x3D for 128x64, 0x3C for 128x32

extern Adafruit_SSD1306 display;

void initializeLcd();
void loopLcd();