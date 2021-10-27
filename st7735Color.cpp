#include <Arduino.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include "st7735Color.h"

void drawPixel(Adafruit_ST7735 *tft, uint8_t x, uint8_t y, uint16_t color)
{
    tft->startWrite();
    tft->writePixel(x, y, color);
    tft->endWrite();
}

void drawGradientVLine(Adafruit_ST7735 *tft, uint8_t pointX, uint8_t pointY, uint8_t pointXMin, uint8_t pointXMax, uint16_t colorStart, uint16_t colorEnd)
{
    uint8_t redStart = (colorStart & REDMASK) >> 11;
    uint8_t greenStart = (colorStart & GREENMASK) >> 5;
    uint8_t blueStart = (colorStart & BLUEMASK);

    uint8_t redEnd = (colorEnd & REDMASK) >> 11;
    uint8_t greenEnd = (colorEnd & GREENMASK) >> 5;
    uint8_t blueEnd = (colorEnd & BLUEMASK);

    for(uint8_t x = pointXMin; x < pointX; x++)
    {
        uint8_t red = map(x, pointXMin, pointXMax, redStart, redEnd);       
        uint8_t green = map(x, pointXMin, pointXMax, greenStart, greenEnd);       
        uint8_t blue = map(x, pointXMin, pointXMax, blueStart, blueEnd);

        uint16_t colorResult = (red << 11) | (green << 5) | (blue);

        drawPixel(tft, x, pointY, colorResult);       
    }
}