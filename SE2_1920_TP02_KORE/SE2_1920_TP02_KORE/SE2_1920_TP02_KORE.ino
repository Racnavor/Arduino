//Bibliothèque à télécharger
//http://www.hamptonsailer.com/Fubar/Examples/
#include <TimerOne.h>
#include <MultiFuncShield.h>

int pot_pour;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1); // Initialisation de la bibliothèque multi-function shield
   
  MFS.write("Debu"); // Affichage de "Debu" sur l'afficheur 7 segments
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pot_pour = map(analogRead(A0), 0, 1023, 0, 100); // Redéfinition de la plage de valeur
  Serial.println(pot_pour); // Affichage de la valeur du potentiomètre en pourcent sur l'écran
  MFS.write(pot_pour); // Affichage de la valeur du potentiomètre en pourcent sur l'afficheur 7 segments
  delay(100);
}
