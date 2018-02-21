// for SSD1306 128x64 screen
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define rowSize 6
#define colSize 14
#define columnStep 10
#define fromCharacter 33
#define toCharacter 126

typedef struct
{
  char symbol;
  int ofset;
} MatrixElement;
  
void setup()   {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  MatrixTest();
}

void loop() {
  
}

void PopulateMatrix(MatrixElement matrixToPopulate[rowSize][colSize])
{
  for(int row = 0; row < rowSize; row++)
  {
    for(int col = 0; col < colSize; col++)
    {
        matrixToPopulate[row][col].symbol = (char)random(fromCharacter,toCharacter); //random character from ascii table (from '!' to '~')
        matrixToPopulate[row][col].ofset = random(row*10, row*20); //random offset between characters
    }
  }
}

void MatrixTest()
{
  display.setTextSize(1);
  display.setTextColor(WHITE);

  MatrixElement record[rowSize][colSize];
  PopulateMatrix(record);

  while(1)
  {
    display.clearDisplay();
    for(int col = 0; col < colSize; col++)
    {
      for(int row = 0; row < rowSize; row++)
      {            
        if(record[row][col].ofset > random(30, 128))
        {
          record[row][col].ofset = random(-15, 0); // reset element position when screen bottom is reached
          record[row][col].symbol = (char)random(fromCharacter,toCharacter); // generate random character
        }
        
        display.setCursor(col * columnStep, record[row][col].ofset);
        display.print(record[row][col].symbol);

        // different column speeds
        if(col % random(1,3) == 0)
        {
          record[row][col].ofset++;
        }
        else
        {
          record[row][col].ofset = record[row][col].ofset + random(1,5);
        }
      }
    }
    display.display();
    delay(50);
  }
}


