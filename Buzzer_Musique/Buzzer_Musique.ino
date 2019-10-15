#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698




//Pin du piezo Buzzer
int MusiquePin = 3;

//durée en milliseconde pour chaque note (dans l'ordre)
int PrincesseDesNeigesRytm[] = {
  250,250,1500,250,250, 750,
  250,250,750,250,750,
  250, 750,
  250,250,1500,250,250,250, 250, 750,
  250,250,750,750,500,500,750,0
};

//Note à jouer (dans l'ordre)
int PrincesseDesNeigesNote[] = {
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_G4, NOTE_G4, NOTE_D5,
  NOTE_A4,  NOTE_A4, NOTE_A4,  NOTE_A4, NOTE_A4,
  NOTE_B4, NOTE_C5,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_G4, NOTE_G4, NOTE_E5,NOTE_E5,NOTE_D5,
  NOTE_C5,NOTE_D5,NOTE_E5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_C5
  ,0
};


void setup() {
 }

void loop() {
  int i = 0;
      // Lecture du tableau de note ... lorsque nous lisons un 0  c'est que c'est la fin
  while (PrincesseDesNeigesNote[i] != 0){
      //On joue la note
    tone(MusiquePin, PrincesseDesNeigesNote[i],PrincesseDesNeigesRytm[i]);
          //On attend X millisecondes (durée de la note) avant de passer à la suivante
    delay(PrincesseDesNeigesRytm[i]);
      //On arrête la lecture de la note
    noTone(MusiquePin);
      //On marque une courte pose (entre chaque note, pour les différencer)
    delay(50);
      //On passe à la note suivante
    ++i;
  }
}
