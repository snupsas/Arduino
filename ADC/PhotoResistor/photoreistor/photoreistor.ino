#include <Servo.h>
#include <stdlib.h>

Servo myservo;
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int valueBuffer = 100;
int oldValue = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(PORTB7);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  float mV = sensorValue * 5000L / 1024L;

  if(abs(oldValue - mV) > valueBuffer)
  {
      Serial.print(mV);
      Serial.print('\n');
      myservo.write(GetServoValueFromADC(mV));
      oldValue = mV;
      delay(100);
  }
}

int GetServoValue(int value)
{
  return map(value, 1, 180, 5, 180);  
}

int GetServoValueFromADC(int adcValue)
{
  return map(adcValue, 0, 4500, 10, 180);
}

