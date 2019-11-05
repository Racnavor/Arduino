//Bibliothèque à télécharger
//http://www.hamptonsailer.com/Fubar/Examples/
#include <MultiFuncShield.h>
#include <TimerOne.h>
#include <Keypad.h>

#define BTN_ON analogRead(A1)
#define LED1 22
#define LED2 23
#define LED3 24
#define LED4 25
#define LED5 26
#define LED6 27
#define LED_INFO 28

int potar, etat_led, etat_avant;
long tempo = 0;
boolean ledInfo = true;

void setup()
{
  Serial.begin(9600);

  //Initialisation des différentes pins
  pinMode(18, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(18), au, CHANGE);
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
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
  Serial.println(potar / 10); // Affichage de la valeur du potentiomètre en pourcent sur l'écran
  MFS.write(potar / 10); // Affichage de la valeur du potentiomètre en pourcent sur l'afficheur 7 segments
  etat_led = map(analogRead(A0), 0, 1023, 0, 6);
  Serial.println(etat_led);

  if (!BTN_ON)
  {
    while (!BTN_ON) {}
    digitalWrite(LED_INFO, HIGH);
    ledInfo = false;
    switch (etat_led)
    {
      case 1:
        ledOff();
        delay(1000);
        digitalWrite(LED1, !digitalRead(LED1));
        ledInfo = true;
        etat_avant = 1;
        break;

      case 2:
        ledOff();
        delay(1000);
        digitalWrite(LED1, !digitalRead(LED1));
        delay(1000);
        digitalWrite(LED2, !digitalRead(LED2));
        ledInfo = true;
        etat_avant = 2;
        break;

      case 3:
        ledOff();
        delay(1000);
        digitalWrite(LED1, !digitalRead(LED1));
        delay(1000);
        digitalWrite(LED2, !digitalRead(LED2));
        delay(1000);
        digitalWrite(LED3, !digitalRead(LED3));
        ledInfo = true;
        etat_avant = 3;
        break;

      case 4:
        ledOff();
        delay(1000);
        digitalWrite(LED1, !digitalRead(LED1));
        delay(1000);
        digitalWrite(LED2, !digitalRead(LED2));
        delay(1000);
        digitalWrite(LED3, !digitalRead(LED3));
        delay(1000);
        digitalWrite(LED4, !digitalRead(LED4));
        ledInfo = true;
        etat_avant = 4;
        break;

      case 5:
        ledOff();
        delay(1000);
        digitalWrite(LED1, !digitalRead(LED1));
        delay(1000);
        digitalWrite(LED2, !digitalRead(LED2));
        delay(1000);
        digitalWrite(LED3, !digitalRead(LED3));
        delay(1000);
        digitalWrite(LED4, !digitalRead(LED4));
        delay(1000);
        digitalWrite(LED5, !digitalRead(LED5));
        ledInfo = true;
        etat_avant = 5;
        break;

      case 6:
        ledOff();
        delay(1000);
        digitalWrite(LED1, !digitalRead(LED1));
        delay(1000);
        digitalWrite(LED2, !digitalRead(LED2));
        delay(1000);
        digitalWrite(LED3, !digitalRead(LED3));
        delay(1000);
        digitalWrite(LED4, !digitalRead(LED4));
        delay(1000);
        digitalWrite(LED5, !digitalRead(LED5));
        delay(1000);
        digitalWrite(LED6, !digitalRead(LED6));
        ledInfo = true;
        etat_avant = 6;
        break;

      default:
        break;
    }
    if(etat_avant > etat_led)
    {
      
    }
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
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
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
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
}
