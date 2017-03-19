#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"
#include "Keypad.h"
const byte ROWS = 4; //das Keypad hat vier Reihen
const byte COLS = 4; //das Keypad hat vier Spalten
//definieren der Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix(); //definiert den Code für die Bicolor Matrix

void setup() {
  Serial.begin(9600); //Starten des seriellen Monitors
  Serial.println("Programmstart"); //zeigen das das Programm beginnt
  matrix.begin(0x70); //Die 7-Bit-Adresse der Matrix ist 0x70, hätte man mehrere Matrizen so wären die 0x71,0x72... 

}

void loop() {

char key = keypad.getKey(); //definiert die Variable key als den Key, der gerdückt wird

  if (key != NO_KEY) //wenn nicht kein Key gedrückt wird, wird ausgeführt 
    {
      Serial.println(key);
      matrix.setRotation(3); //drehen der Matrix um 270°, kann kommentiert werden 
      matrix.setTextColor(LED_GREEN);  
      matrix.clear();
      matrix.setCursor(1,0);
      matrix.print(key); //darstellen des Keys, der gedrückt wird 
      matrix.writeDisplay();
     }
}      
