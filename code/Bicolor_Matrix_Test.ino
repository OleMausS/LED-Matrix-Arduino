//Unter Verwendung der Adafuit GFX und Adafruit LEDBackpack Library 
//https://github.com/adafruit/Adafruit-GFX-Library/archive/master.zip
//https://github.com/adafruit/Adafruit_LED_Backpack/archive/master.zip

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 BiColor LED Matrix Test");
  matrix.setRotation(0);
  matrix.begin(0x70);
}

static const uint8_t PROGMEM
  smiley[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 };

void loop() {
  matrix.setTextWrap(false);  
  matrix.setTextColor(LED_GREEN);
  for (int8_t x=0; x>=-10; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Du");
    matrix.writeDisplay();
    Serial.println("Display: Du");
    delay(100);
  }
  matrix.setTextWrap(false);
  matrix.setTextColor(LED_YELLOW);
  for (int8_t x=9; x>=-40; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("hast es");
    matrix.writeDisplay();
    Serial.println("Display: hast es");
    delay(100);
  }
  matrix.setTextWrap(false);
  matrix.setTextColor(LED_RED);
  for (int8_t x=9; x>=-60; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("geschafft!");
    matrix.writeDisplay();
    Serial.println("Display: geschafft!");
    delay(100);
  }
  matrix.clear();
  matrix.drawBitmap(0, 0, smiley, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  Serial.println("Display: Smiley");
  delay(2000);

}
