#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#define s delay(500);
#define xs delay(100);
int count = 1;
            
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  Serial.begin(9600);
  Serial.println("Start Lichtorgel");
  
  matrix.begin(0x70);
}

static const uint8_t PROGMEM
  upper[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 };

void loop() {
  s
  matrix.setRotation(count);
  matrix.drawCircle(0,0, 1, LED_RED);
  matrix.drawPixel(0,0, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 2, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 3, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 4, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 5, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 6, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 7, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 8, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 9, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.fillRect(0,0, 8,8, LED_RED);
  matrix.writeDisplay();
  Serial.println("RED WRITTEN");
  s
  matrix.drawCircle(7,7, 1, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 2, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 3, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 4, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 5, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 6, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 7, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 8, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(7,7, 9, LED_GREEN);
  matrix.writeDisplay();
  xs
  matrix.fillRect(0,0, 8,8, LED_GREEN);
  matrix.writeDisplay();
  Serial.println("GREEN WRITTEN");
  s
  matrix.drawCircle(0,0, 1, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 2, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 3, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 4, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 5, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 6, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 7, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 8, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawCircle(0,0, 9, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.fillRect(0,0, 8,8, LED_YELLOW);
  matrix.writeDisplay();
  Serial.println("YELLOW WRITTEN");
  s
  matrix.drawLine(0,0, 3,0, LED_GREEN);
  matrix.drawLine(4,0, 7,0, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawLine(0,1, 3,1, LED_GREEN);
  matrix.drawLine(4,1, 7,1, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawLine(0,2, 3,2, LED_GREEN);
  matrix.drawLine(4,2, 7,2, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawLine(0,3, 3,3, LED_GREEN);
  matrix.drawLine(4,3, 7,3, LED_YELLOW);
  matrix.writeDisplay();
  xs
  matrix.drawLine(0,4, 3,4, LED_YELLOW);
  matrix.drawLine(4,4, 7,4, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawLine(0,5, 3,5, LED_YELLOW);
  matrix.drawLine(4,5, 7,5, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawLine(0,6, 3,6, LED_YELLOW);
  matrix.drawLine(4,6, 7,6, LED_RED);
  matrix.writeDisplay();
  xs
  matrix.drawLine(0,7, 3,7, LED_YELLOW);
  matrix.drawLine(4,7, 7,7, LED_RED);
  matrix.writeDisplay();
  delay(1000);
  Serial.println("FADE WRITTEN");
  

  //matrix.clear();
  matrix.fillRect(0,0, 4,4, LED_GREEN);
  matrix.fillRect(0,4, 4,4, LED_YELLOW);
  matrix.fillRect(4,4, 4,4, LED_RED);
  matrix.fillRect(4,0, 4,4, LED_YELLOW);  
  matrix.writeDisplay();
  Serial.println("SQUARES WRITTEN");

  matrix.fillRect(1,1, 2,2, LED_YELLOW);
  matrix.fillRect(5,1, 2,2, LED_RED);
  matrix.fillRect(1,5, 2,2, LED_GREEN);
  matrix.fillRect(5,5, 2,2, LED_YELLOW);
  matrix.writeDisplay();
  Serial.println("FILLS1 WRITTEN");
  s
  matrix.setRotation(count+1);
  matrix.fillRect(1,1, 2,2, LED_YELLOW);
  matrix.fillRect(5,1, 2,2, LED_RED);
  matrix.fillRect(1,5, 2,2, LED_GREEN);
  matrix.fillRect(5,5, 2,2, LED_YELLOW);
  matrix.writeDisplay();
  Serial.println("FILLS2 WRITTEN");
  s
  matrix.setRotation(count+2);
  matrix.fillRect(1,1, 2,2, LED_YELLOW);
  matrix.fillRect(5,1, 2,2, LED_RED);
  matrix.fillRect(1,5, 2,2, LED_GREEN);
  matrix.fillRect(5,5, 2,2, LED_YELLOW);
  matrix.writeDisplay();
  Serial.println("FILLS3 WRITTEN");
  s
   matrix.drawRect(0,0, 8,8, LED_GREEN);
 matrix.writeDisplay();
 xs
 matrix.drawRect(1,1, 6,6, LED_GREEN);
 matrix.writeDisplay();
 xs
 matrix.drawRect(2,2, 4,4, LED_GREEN);
 matrix.writeDisplay();
 xs
 matrix.drawRect(3,3, 2,2, LED_GREEN);
 matrix.writeDisplay();
 xs
 matrix.drawRect(3,3, 2,2, LED_RED);
 matrix.writeDisplay();
 xs
 matrix.drawRect(2,2, 4,4, LED_RED);
 matrix.writeDisplay();
 xs
 matrix.drawRect(1,1, 6,6, LED_RED);
 matrix.writeDisplay();
 xs
 matrix.drawRect(0,0, 8,8, LED_RED);
 matrix.writeDisplay();
 xs
 matrix.drawRect(0,0, 8,8, LED_YELLOW);
 matrix.writeDisplay();
 xs
 matrix.drawRect(1,1, 6,6, LED_YELLOW);
 matrix.writeDisplay();
 xs
 matrix.drawRect(2,2, 4,4, LED_YELLOW);
 matrix.writeDisplay();
 xs
 matrix.drawRect(3,3, 2,2, LED_YELLOW);
 matrix.writeDisplay();
 xs
 Serial.println("FADE2 WRITTEN");
  count = count+1;
  Serial.println("Starte Durchgang");Serial.println(count);
  }
  

