#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 
// creates a "virtual" serial port/UART
// connect BT module TX to D11
// connect BT module RX to D10
// connect BT Vcc to 5V, GND to GND
void setup()  
{
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  Serial.begin(9600);
}
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
      Serial.print((char)BT.read());
      Serial.print("\n");
  }
}
