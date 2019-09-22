#include<Keypad.h>

char code[4];
int i = 0;

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
//Create the variable myKeypad and import key settings

void setup()
{
  // put your setup code here, to run once:

  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), raz, CHANGE);
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
  // put your main code here, to run repeatedly:

  char keypressed = myKeypad.getKey();

  if (keypressed != NO_KEY && i < 4) //This is where it hangs out waiting for a key press
  {
    delay(25); //25 ms key read pause
    code[i] = keypressed;
    Serial.println(code[i]);
    i = i + 1;
  }


  if (i == 4)
  {
    if (code[0] == '1' && code[1] == '2' && code[2] == '1' && code[3] == '2')
    {
      digitalWrite(22, LOW);
      digitalWrite(23, LOW);
      digitalWrite(24, LOW);
      digitalWrite(25, LOW);
      delay(500);
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      delay(500);
    }
    else if (code[0] == '1' && code[1] == '2' && code[2] == '3' && code[3] == '4')
    {
      digitalWrite(22, LOW);
      delay(250);
      digitalWrite(22, HIGH);
      delay(250);
      digitalWrite(23, LOW);
      delay(250);
      digitalWrite(23, HIGH);
      delay(250);
      digitalWrite(24, LOW);
      delay(250);
      digitalWrite(24, HIGH);
      delay(250);
      digitalWrite(25, LOW);
      delay(250);
      digitalWrite(25, HIGH);
      delay(250);
    }
    else if (code[0] == '9' && code[1] == '8' && code[2] == '7' && code[3] == '6')
    {
      digitalWrite(22, LOW);
      delay(250);
      digitalWrite(23, LOW);
      delay(250);
      digitalWrite(24, LOW);
      delay(250);
      digitalWrite(25, LOW);
      delay(250);
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      delay(250);
    }
    else
    {
      Serial.println("Erreur! Code invalide");
      i = 0;
    }
  }
}

void raz()
{
  i = 0;
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
}
