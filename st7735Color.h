#include <Arduino.h>
#include <Adafruit_ST7735.h>

#define REDMASK    0xF800
#define GREENMASK  0x7E0
#define BLUEMASK   0x1F

void drawPixel(Adafruit_ST7735 *tft, uint8_t x, uint8_t y, uint16_t color);
void drawGradientVLine(Adafruit_ST7735 *tft, uint8_t pointX, uint8_t pointY, uint8_t pointXMin, uint8_t pointXMax, uint16_t colorStart, uint16_t colorEnd);