int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  float mV = sensorValue * 5000L / 1024L;
  float celc = mV / 10;
  
  Serial.print(celc);
  Serial.print('C');
  Serial.print("\n");
  delay(1000); 
}
