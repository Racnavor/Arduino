//Bibliothèque à télécharger
//http://www.hamptonsailer.com/Fubar/Examples/
#include <TimerOne.h>
#include <MultiFuncShield.h>

// Définition des LEDs et du bouton
#define LED 13
#define LED_ON digitalWrite(LED, LOW)
#define LED_OFF digitalWrite(LED, HIGH)
#define BUTTON analogRead(A1)

unsigned long temps;
unsigned long tempo;
float affichTemps;

void setup() 
{
  Timer1.initialize();
  MFS.initialize(&Timer1); // Initialisation de la bibliothèque multi-function shield
  
  // Buzzer
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  delay(50);
  digitalWrite(3, HIGH);
  
  pinMode(LED, OUTPUT);
  LED_OFF;
}

void loop() 
{
  if(!BUTTON)
  {
    temps = millis();
    while(!BUTTON){}
    tempo = millis() - temps; // Initialisation de la tempo
    temps = millis();
    affichTemps = (tempo / 1000.0);
    MFS.write(affichTemps); // Affichage du temps de clignotement sur l'afficheur 7 segments
    do
    {
      LED_ON;
      delay(200);
      LED_OFF;
      delay(200);
    }while(millis() <= temps + tempo);
    LED_OFF;
  }
}
