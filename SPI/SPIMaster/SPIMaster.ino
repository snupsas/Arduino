#include <SPI.h>
#define SLAVE_SELECT 10
void setup()
{
	Serial.begin(9600);
  cli();
	SPCR |= 0b00010000; // turn on SPI
	DDRB |= 0b00101100;
  DDRB &= 0b11101111;
	PORTB &= 0b11111011;
	
	//SPI.begin();
	
	//SPI.setClockDivider(SPI_CLOCK_DIV4);
}

void loop()
{
	byte dataIn;
	byte dataOut = 'B';
	spiWriteAndRead(dataOut);
	delay(2000);
}

byte spiWriteAndRead(byte dout) {	
	byte din;
	digitalWrite(SLAVE_SELECT, LOW);
	delay(1);
	din = SPI.transfer(dout);
	delay(1);
	digitalWrite(SLAVE_SELECT, HIGH);
	Serial.println("data sent");
	return din;
}

