//Unter Verwendung der Adafuit GFX und Adafruit LEDBackpack Library 
//https://github.com/adafruit/Adafruit-GFX-Library/archive/master.zip
//https://github.com/adafruit/Adafruit_LED_Backpack/archive/master.zip

#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix(); //definiert den Code für die Bicolor Matrix

void setup() {
  Serial.begin(9600); //Starten des seriellen Monitors
  Serial.println("Programmstart"); //zeigen das das Programm beginnt
  
  matrix.begin(0x70); //Die 7-Bit-Adresse der Matrix ist 0x70, hätte man mehrere Matrizen so wären die 0x71,0x72... 

}

void loop() {

}
