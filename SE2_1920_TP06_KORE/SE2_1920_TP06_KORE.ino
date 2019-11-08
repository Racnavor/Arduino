//Bibliothèque à télécharger
//http://www.hamptonsailer.com/Fubar/Examples/
#include <MultiFuncShield.h>
#include <TimerOne.h>
#include <Keypad.h>

#define BTN_ON analogRead(A1)
#define LED_INFO 28

int LED[] = {22, 23, 24, 25, 26, 27};
int potar, but_led, etat_led = 0;
long tempo = 0;
boolean ledInfo = true;

void setup()
{
  Serial.begin(9600);

  //Initialisation des différentes pins
  pinMode(18, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(18), au, CHANGE);

  for (int i = 0; i < sizeof(LED); i++)
  {
    pinMode(LED[i], OUTPUT);
  }

  pinMode(LED_INFO, OUTPUT);
  ledOff();
  digitalWrite(LED_INFO, HIGH);

  Timer1.initialize();
  MFS.initialize(&Timer1); // Initialisation de la bibliothèque multi-function shield
  MFS.write("SALU");
  delay(1000);
  MFS.write("");
}

void loop()
{
  potar = map(analogRead(A0), 0, 1023, 0, 1000); // Redéfinition de la plage de valeur
  MFS.write(potar / 10); // Affichage de la valeur du potentiomètre en pourcent sur l'afficheur 7 segments
  etat_led = map(analogRead(A0), 0, 1023, 0, 6);

  if (!BTN_ON)
  {
    while (!BTN_ON) {}
    digitalWrite(LED_INFO, HIGH);
    ledInfo = false;

    if (etat_led < but_led)
    {
      for (int i = etat_led; i < but_led; i++)
      {
        delay(1000);
        Serial.print("Position : ");
        Serial.println(etat_led);
        digitalWrite(LED[i], LOW);
        etat_led++;
      }
    }
    else if (etat_led > but_led)
    {
      for (int i = etat_led; i > but_led - 1; i--)
      {
        delay(1000);
        Serial.print("Position : ");
        Serial.println(etat_led);
        digitalWrite(LED[i], HIGH);
        etat_led--;
      }
    }
    ledInfo = true;
  }

  if (ledInfo)
  {
    if (millis() > tempo + 500)
    {
      digitalWrite(LED_INFO, !digitalRead(LED_INFO));
      tempo = millis();
    }
  }
}

void ledOff()
{
  for (int i = 0; i < sizeof(LED); i++)
  {
    digitalWrite(LED[i], HIGH);
  }
}

void au()
{
  ledInfo = true;
  /*MFS.write("BPAU");
    while (true)
    {
    digitalWrite(LED1, !digitalRead(LED1));
    digitalWrite(LED2, !digitalRead(LED2));
    digitalWrite(LED3, !digitalRead(LED3));
    digitalWrite(LED4, !digitalRead(LED4));
    digitalWrite(LED5, !digitalRead(LED5));
    digitalWrite(LED6, !digitalRead(LED6));
    digitalWrite(LED_INFO, !digitalRead(LED_INFO));
    delay(500);
    }*/
  for (int i = 0; i < sizeof(LED); i++)
  {
    digitalWrite(LED[i], HIGH);
  }
  
//  digitalWrite(LED1, HIGH);
//  digitalWrite(LED2, HIGH);
//  digitalWrite(LED3, HIGH);
//  digitalWrite(LED4, HIGH);
//  digitalWrite(LED5, HIGH);
//  digitalWrite(LED6, HIGH);
}
