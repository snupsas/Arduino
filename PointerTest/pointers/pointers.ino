int *pointer;
int value = 100;

void setup() {
  Serial.begin(9600);
}

void loop() 
{  
  pointer = &value;
  MemAddressPrint(pointer);
  delay(1000);
}

void MemAddressPrint(int *value)
{
  Serial.println("value:");
  Serial.print(*(value-1));
  Serial.print('\n');
  Serial.println("address:");
  Serial.print((int)value);
  Serial.print('\n');
}

