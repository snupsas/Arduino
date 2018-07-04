/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#define rowSize 6
#define colSize 14

typedef struct
{
  char symbol;
  int ofset;
} matrixElement;
  
void setup()   {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  matrixTest();
}


void loop() {
  
}

void PopulateMatrix(matrixElement matrixToPopulate[rowSize][colSize])
{
    for(int row = 0; row < rowSize; row++)
    {
      for(int col = 0; col < colSize; col++)
      {
          matrixToPopulate[row][col].symbol = (char)random(33,126);
          matrixToPopulate[row][col].ofset = random(row*10, row*20);
      }
    }
}

void matrixTest()
{

  display.setTextSize(1);
  display.setTextColor(WHITE);

  matrixElement record[rowSize][colSize];

  PopulateMatrix(record);

  while(1)
  {
    display.clearDisplay();
    for(int col = 0; col < colSize; col++)
    {
      for(int row = 0; row < rowSize; row++)
      {            
        if(record[row][col].ofset > display.height())
        {
          record[row][col].ofset = random(0, 128);
          record[row][col].symbol = (char)random(33,126);
        }
        display.setCursor(col * 10, record[row][col].ofset);
        display.print(record[row][col].symbol);
        record[row][col].ofset++;
      }
    }
    display.display();
    delay(50);
  }
}


