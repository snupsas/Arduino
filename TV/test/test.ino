#include <SoftwareSerial.h>
SoftwareSerial TV(10, 11);
// creates a "virtual" serial port/UART
// connect BT module TX to A4
// connect BT module RX to A5
// connect BT Vcc to 5V, GND to GND
int pin = 2;
int *p = &pin;
void setup()  
{
  // set the data rate for the SoftwareSerial port
	TV.begin(9600);
}
void loop() 
{
	DDRB |= B11111111;
	delay(1000);
	DDRB |= B00000000;
	delay(1000);
}

