void setup() {
  Serial.begin(9600);
}

void loop() 
{
  uint8_t bin = B00000001;
  Serial.println(bin);
  
  uint8_t shifted = bin << 2;
  Serial.println(shifted);

  uint8_t lastBitChanged = bin | B10000000;
  Serial.println(lastBitChanged);

  Serial.println(bin &= B11111110);
  
  delay(1000);
}
