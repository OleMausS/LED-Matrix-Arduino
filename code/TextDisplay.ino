//Unter Verwendung der Adafuit GFX und Adafruit LEDBackpack Library 
//https://github.com/adafruit/Adafruit-GFX-Library/archive/master.zip
//https://github.com/adafruit/Adafruit_LED_Backpack/archive/master.zip

#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"
int count = 1; //start eines Couters         
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix(); //definiert den Code für die Bicolor Matrix

void setup() {
  Serial.begin(9600); //Starten des seriellen Monitors
  Serial.println("Start TextDisplay"); //zeigen das das Programm beginnt
  
  matrix.begin(0x70); //Die 7-Bit-Adresse der Matrix ist 0x70, hätte man mehrere Matrizen so wären die 0x71,0x72... 
}

void loop() {
    ausrufezeichen();
    ausrufezeichen();
    ausrufezeichen();
    Serial.println("!!! WRITTEN");
    matrix.setTextWrap(false); 
    matrix.setTextColor(LED_GREEN);
 for (int8_t x=7; x>=-47; x--){ //x-- folglich von rechts nach links
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("vorwaerts");
    matrix.writeDisplay();
    delay(75);
    Serial.println(x); //zeige den aktuellen x-Wert im Seriellen Monitor
    }
    Serial.println("VORWÄRTS WRITTEN");
    matrix.setTextWrap(false); 
    matrix.setTextColor(LED_RED);
 for (int8_t x=-61; x<=8; x++){ //x++ folglich von links nach rechts 
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("rueckwaerts");
    matrix.writeDisplay();
    delay(75);
    Serial.println(x); //zeige den aktuellen x-Wert im Seriellen Monitor
    }
    Serial.println("RÜCKWÄRTS WRITTEN");
    delay(200);
    matrix.setTextWrap(false); 
    matrix.setTextColor(LED_YELLOW);
 for (int8_t x=7; x>=-77; x--){
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("HALLELUJAH!!!");
    matrix.writeDisplay();
    delay(20);
    Serial.println(x); //zeige den aktuellen x-Wert im Seriellen Monitor
    }
    Serial.println("HALLELUJAH WRITTEN");
    count=count+1;//erhöht den Counter um 1
    Serial.println("Starte Durchgang");  Serial.println(count); //Anzeigen der Durchläufe
}
void ausrufezeichen()
{
matrix.setTextColor(LED_RED); //blinkendes Ausrufezeichen 
    matrix.setCursor(1,0);
    matrix.print("!");
    matrix.writeDisplay();
    delay(200);
    matrix.clear();
    matrix.writeDisplay();
    delay(200);
}


