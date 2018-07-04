//lm35 outputs only in range of 0V - 1V
//so we set analog reference to max 1.1V instead of default 5V
//step is 10mV/C

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  float a = 1.1L / 1024L;
  float b = a / 0.01;
  float celc = sensorValue * b;
  //float celc = sensorValue / 9.31;
  
  Serial.println(celc);
  //Serial.println(sensorValue);
  delay(1000); 
}

