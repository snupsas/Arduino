#include <SoftwareSerial.h>
SoftwareSerial BT(A4, A5); 
// creates a "virtual" serial port/UART
// connect BT module TX to A4
// connect BT module RX to A5
// connect BT Vcc to 5V, GND to GND
String incomingString;
void setup()  
{
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  Serial.begin(9600);
}
void loop() 
{
  while (BT.available())
  // if text arrived in from BT serial...
  {
      incomingString = BT.readString();
  }
  if(incomingString != "")
  {
    Serial.println(incomingString);
    incomingString = "";  
  }
}
