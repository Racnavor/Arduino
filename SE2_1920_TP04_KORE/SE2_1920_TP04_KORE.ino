//Bibliothèque à télécharger
//http://www.hamptonsailer.com/Fubar/Examples/
#include <TimerOne.h>
#include <MultiFuncShield.h>
#include <avr/sleep.h>

// Définition des LEDs et des boutons
#define LED 13
#define LED_ON digitalWrite(LED, LOW)
#define LED_OFF digitalWrite(LED, HIGH)
#define BTN_ON analogRead(A1)

// Définition des variables
String lire;
int nbre, goToSleep = 10000;
unsigned long temps;

void setup()
{
  Serial.begin(9600);

  Timer1.initialize();
  MFS.initialize(&Timer1); // Initialisation de la bibliothèque multi-function shield

  Serial.print("Entrez un code à 4 chiffres : ");
  MFS.write("");
  pinMode(LED, OUTPUT);
  LED_ON;

  attachInterrupt(digitalPinToInterrupt(18), awake, CHANGE);
}

void loop()
{
  while (Serial.available())
  {
    lire = Serial.readString(); // Lecture du clavier
    nbre = lire.toInt(); // Transformation de la valeur en entier
    Serial.println(nbre);
    //Test pour savoir si l'utilisateur à entré 4 chiffres
    if (lire.length() > 5) // Si plus grand
    {
      Serial.println("Trop de valeur!");
    }
    else if (lire.length() < 5) // Si plus petit
    {
      Serial.println("Pas assez de valeur!");
    }
    else // Si OK
    {
      MFS.write(nbre);
      delay(5000);
      MFS.write("");
    }
  }

  // Réaffichage du nombre
  if (!BTN_ON)
  {
    MFS.write(nbre);
    temps = millis();
  }

  // Sleep
  if (temps != 0)
  {
    if (millis() > temps + goToSleep)
    {
      sleep_enable();
      set_sleep_mode(SLEEP_MODE_PWR_DOWN);
      LED_OFF;
      MFS.write("");
      delay(500);
      sleep_cpu();
    }
  }
}


// AttachInterrupt de réveil
void awake()
{
  sleep_disable();
  LED_ON;
  MFS.write(nbre);
  temps = 0;
}
