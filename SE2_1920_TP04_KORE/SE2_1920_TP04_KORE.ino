void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  while(Serial.available())
  {
    char c = Serial.read();
    Serial.print(c);
    Serial.print('\t');
    Serial.println(int(c));
    delay(10);
  }
}
