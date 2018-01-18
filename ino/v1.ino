#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'H','G','F','E'},
  {'D','C','B','A'},
  {'P','O','N','M'},
  {'L','K','J','I'}
};


byte colPins[COLS] = {9, 8, 7, 6};
byte rowPins[ROWS] = {5, 4, 3, 2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int verrou = 11; //Pin connected to latch pin (ST_CP) of 74HC595 pin 12
const int donnee = 10; //Pin connected to clock pin (SH_CP) of 74HC595 pin 11
const int horloge = 12; //Pin connected to Data in (DS) of 74HC595 pin 14

int ListPourUneLed[] = {1,2,4,8,16,32,64,128};
  
int quelJoueur;
int quelLed;
int numeroLed;
int trouve = 0;
byte loading = 0;

void setup() {
    pinMode(verrou, OUTPUT);
    pinMode(donnee, OUTPUT);
    pinMode(horloge, OUTPUT);
    randomSeed(analogRead(0));
}

void loop(){
  char key = keypad.getKey();
  if (key){
    if (trouve != 0) {
      int mykey = key;
      numeroLed = quelLed + ((quelJoueur - 1) * 8);
      
      if ( (mykey - 65) == numeroLed){        
        trouve = 0;
      }
    }
  }
  
  // vérifier que le bouton à été trouvé
  if (trouve == 0) {
    if (loading == 0){
      chargement();
      loading = 1;
    }
    quelJoueur = random(1,3);
    quelLed = random(8);
    digitalWrite(verrou, LOW);
    if ( quelJoueur == 1){
      shiftOut(donnee, horloge, LSBFIRST,0);
      shiftOut(donnee, horloge, LSBFIRST, ListPourUneLed[quelLed]);
    }else{
      shiftOut(donnee, horloge, LSBFIRST, ListPourUneLed[quelLed]);
      shiftOut(donnee, horloge, LSBFIRST,0);
    }
    digitalWrite(verrou, HIGH);
    trouve = 1;
  }
}

# code from https://www.arduino.cc/en/Tutorial/ShiftOut
void chargement(){
  for (int j = 0; j < 8; j++) {
    digitalWrite(verrou, 0);
    lightShiftPinA(7-j);
    lightShiftPinA(j);
    digitalWrite(verrou, 1);
    delay(100);
  }
  for (int j = 0; j < 8; j++) {
    digitalWrite(verrou, 0);
    lightShiftPinB(j);
    lightShiftPinB(7-j);
    digitalWrite(verrou, 1);
    delay(100);
  } 
}

void lightShiftPinA(int p) {
  int pin;
  shiftOut(donnee, horloge, pin);   
}

void lightShiftPinB(int p) {
  int pin;
  pin = 1;
  for (int x = 0; x < p; x++) {
    pin = pin * 2; 
  }
  shiftOut(donnee, horloge, pin);   
}

// the heart of the program
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }
    digitalWrite(myDataPin, pinState);
    digitalWrite(myClockPin, 1);
    digitalWrite(myDataPin, 0);
  }
  digitalWrite(myClockPin, 0);
}
