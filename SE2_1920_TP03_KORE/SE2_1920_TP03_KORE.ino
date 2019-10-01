#define LED 13
#define LED_ON digitalWrite(LED, LOW)
#define LED_OFF digitalWrite(LED, HIGH)
#define BUTTON analogRead(A1)

void setup() 
{
  pinMode(LED, OUTPUT);
  LED_OFF;
}

void loop() 
{
  if(!BUTTON)
  {
    temps = millis();
  }

  do
  {
    LED_ON;
    delay(200);
    LED_OFF;
    delay(200);
  }while(temps < );
  
}
