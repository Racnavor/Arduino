#include<Keypad.h>

boolean prog = false;
unsigned long temps;
int tempo = 2000;
int cpt = 0;

const byte numRows = 3; //nombre de lignes
const byte numCols = 3; //nombre de colonnes

//keymap définit la touche sur laquelle on appuie. C'est par rapport aux lignes et colonnes
char keymap[numRows][numCols] =
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};
//Initialisation du keypad en 3X3

//Définition des pins
byte rowPins[numRows] = {48, 49, 50}; //Lignes 0 à 2
byte colPins[numCols] = {51, 52, 53}; //Colonnes 0 à 2

//Initialisation d'une instance pour la classe Keypad
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//Création de la variable Keypad et importation des paramètres des touches

void setup()
{
  //Initialisation des différentes pins
  pinMode(18, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(18), raz, CHANGE);
  Serial.begin(9600);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
}

void loop()
{
  //Mise dans une variable de la touche pressée
  char keypressed = myKeypad.getKey();
  delay(250);
  if (keypressed)
  {
    Serial.println(keypressed);
    //Serial.print("Bouton 2 : ");
    //Serial.println(BUTTON2);
  }


  if (keypressed == '1')
  {
    prog = !prog;
    delay(250);
  }

  if (prog == true)
  {
    switch (keypressed)
    {
      case '3':
        {
          cpt = 0;
          delay(250);
          while (keypressed != '2')
          {
            keypressed = myKeypad.getKey();
            delay(250);
          }
          temps = millis();
          cpt++;
          do
          {
            if (myKeypad.getKey() == '2')
            {
              cpt++;
              delay(250);
            }
            if(cpt >= 4)
            {
              cpt = 0;
            }
          } while (millis() <= temps + tempo && cpt < 4);
          switch (cpt)
          {
            case 1:
              digitalWrite(22, HIGH);
              break;

            case 2:
              digitalWrite(22, LOW);
              break;

            case 3:
              digitalWrite(22, LOW);
              delay(500);
              digitalWrite(22, HIGH);
              delay(500);
              break;

            default:
              break;
          }
          break;
        }
      case '4':
        {
          cpt = 0;
          delay(250);
          while (keypressed != '2')
          {
            keypressed = myKeypad.getKey();
            delay(250);
          }
          temps = millis();
          cpt++;
          do
          {
            if (myKeypad.getKey() == '2')
            {
              cpt++;
              delay(250);
            }
            if(cpt >= 4)
            {
              cpt = 0;
            }
          } while (millis() <= temps + tempo && cpt < 4);
          switch (cpt)
          {
            case 1:
              digitalWrite(23, HIGH);
              break;

            case 2:
              digitalWrite(23, LOW);
              break;

            case 3:
              digitalWrite(23, LOW);
              delay(500);
              digitalWrite(23, HIGH);
              delay(500);
              break;

            default:
              break;
          }
          break;
        }
      case '5':
        {
          cpt = 0;
          delay(250);
          while (keypressed != '2')
          {
            keypressed = myKeypad.getKey();
            delay(250);
          }
          temps = millis();
          cpt++;
          do
          {
            if (myKeypad.getKey() == '2')
            {
              cpt++;
              delay(250);
            }
            if(cpt >= 4)
            {
              cpt = 0;
            }
          } while (millis() <= temps + tempo && cpt < 4);
          switch (cpt)
          {
            case 1:
              digitalWrite(24, HIGH);
              break;

            case 2:
              digitalWrite(24, LOW);
              break;

            case 3:
              digitalWrite(24, LOW);
              delay(500);
              digitalWrite(24, HIGH);
              delay(500);
              break;

            default:
              break;
          }
          break;
        }
      case '6':
        {
          cpt = 0;
          delay(250);
          while (keypressed != '2')
          {
            keypressed = myKeypad.getKey();
            delay(250);
          }
          temps = millis();
          cpt++;
          do
          {
            if (myKeypad.getKey() == '2')
            {
              cpt++;
              delay(250);
            }
            if(cpt >= 4)
            {
              cpt = 0;
            }
          } while (millis() <= temps + tempo && cpt < 4);
          switch (cpt)
          {
            case 1:
              digitalWrite(25, HIGH);
              break;

            case 2:
              digitalWrite(25, LOW);
              break;

            case 3:
              digitalWrite(25, LOW);
              delay(500);
              digitalWrite(25, HIGH);
              delay(500);
              break;

            default:
              break;
          }
          break;
        }
      default:
        {
          if (keypressed)
          {
            Serial.println("ERREUR");
          }
          break;
        }
    }
  }
}

void raz()
{
  prog = false;
  cpt = 0;
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
}
