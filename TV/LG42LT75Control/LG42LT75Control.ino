#include <SoftwareSerial.h>
SoftwareSerial BT(A4, A5);
SoftwareSerial TV(10, 11);
// creates a "virtual" serial port/UART
// connect BT module TX to A4
// connect BT module RX to A5
// connect BT Vcc to 5V, GND to GND
String incomingStringBT;
String incomingStringTV;
void setup()  
{
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  TV.begin(9600);
}
void loop() 
{
  BT.listen();
  incomingStringTV.trim();
  if(incomingStringTV != "")
  {
      BT.println(incomingStringTV);
  }
  
  while (BT.available())
  {
      incomingStringBT = BT.readString();
  }
  incomingStringBT.trim();
  if(incomingStringBT == "on")
  {
      BT.println("TV on");
      turnTvOn();
  }
  else if(incomingStringBT == "off")
  {
      BT.println("TV off");
      turnTvOff(); 
  }

  resetReceivedBTCommand();  
  delay(500);
}

void resetReceivedBTCommand()
{
  if(incomingStringBT != "")
  {
    incomingStringBT = "";  
  }
}

void turnTvOn()
{
  TV.listen();
  byte command[] = {'k', 'a', 0x20, 1, 0x20, 1, 0x0D};
  TV.write(command, sizeof(command));
  delay(500);

  while (TV.available())
  {
    incomingStringTV = TV.readString();
  }
}

void turnTvOff()
{
  TV.listen();
  byte command[] = {'k', 'a', 0x20, 1, 0x20, 0, 0x0D};
  TV.write(command, sizeof(command));
  delay(500);

  while (TV.available())
  {
    incomingStringTV = TV.readString();
  }
}
