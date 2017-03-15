#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"
#define m delay(1000); //definieren von verschiedenen Verzögerungen, um code zu sparen
#define s delay(500);
#define xs delay(100);
#define xxs delay (50);
int count = 0; //setzt den Zähler am Anfang auf 0 fest
            
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix(); //definiert den Code für die Bicolor Matrix

void setup() {
  Serial.begin(9600); //Starten des seriellen Monitors
  Serial.println("Start Lichtorgel"); //zeigen das das Programm beginnt
  
  matrix.begin(0x70); //Die 7-Bit-Adresse der Matrix ist 0x70, hätte man mehrere Matrizen so wären die 0x71,0x72... 
}

static const uint8_t PROGMEM
  bigheart_bmp[] =
  { B00000000,
    B01100110,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000,
    B00000000 },
  smallheart_bmp[] =
  { B01010000,
    B11111000,
    B01110000,
    B00100000,
    B00000000,
    B00000000,
    B00000000,
    B00000000 };

void loop() {
  s
  matrix.setRotation(count); //lässt die Matrix sich je nach Zähler drehen (pro Durchgang um 90°)
  matrix.drawPixel(1,1, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(4,2, LED_RED); //darstellen einzelner Pixel
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(4,5, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(5,4, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(6,6, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(3,7, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(2,4, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,3, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,7, LED_RED);
  matrix.writeDisplay();
  xxs
  xxs
  matrix.drawPixel(6,6, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,0, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(1,6, LED_RED);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(0,0, LED_RED);
  matrix.writeDisplay();
  xxs
  Serial.println("RPIXEL WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
  xxs
  matrix.drawCircle(0,0, 1, LED_RED);
 
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
  matrix.drawPixel(1,1, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(3,2, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(5,3, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(3,5, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(1,6, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(2,4, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,7, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(4,2, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(3,7, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(5,4, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,3, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(6,6, LED_GREEN);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(2,3, LED_GREEN);
  matrix.writeDisplay();
  xxs
  Serial.println("GPIXEL WRITTEN");//im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
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
  Serial.println("GREEN WRITTEN");//im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
  s
  matrix.drawPixel(1,1, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(4,2, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(4,5, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(5,4, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(6,6, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(3,7, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(2,4, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,3, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,7, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  xxs
  matrix.drawPixel(6,6, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(7,0, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  matrix.drawPixel(0,0, LED_YELLOW);
  matrix.writeDisplay();
  xxs
  Serial.println("YPIXEL WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
  xs
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
  Serial.println("YELLOW WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
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
  Serial.println("FADE WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
  

  matrix.clear();
  matrix.fillRect(0,0, 4,4, LED_GREEN);
  matrix.fillRect(0,4, 4,4, LED_YELLOW);
  matrix.fillRect(4,4, 4,4, LED_RED);
  matrix.fillRect(4,0, 4,4, LED_YELLOW);  
  matrix.writeDisplay();
  Serial.println("SQUARES WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde

  matrix.fillRect(1,1, 2,2, LED_YELLOW);
  matrix.fillRect(5,1, 2,2, LED_RED);
  matrix.fillRect(1,5, 2,2, LED_GREEN);
  matrix.fillRect(5,5, 2,2, LED_YELLOW);
  matrix.writeDisplay();
  Serial.println("FILLS1 WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
  s
  matrix.setRotation(count+1);
  matrix.fillRect(1,1, 2,2, LED_YELLOW);
  matrix.fillRect(5,1, 2,2, LED_RED);
  matrix.fillRect(1,5, 2,2, LED_GREEN);
  matrix.fillRect(5,5, 2,2, LED_YELLOW);
  matrix.writeDisplay();
  Serial.println("FILLS2 WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
  s
  matrix.setRotation(count+2);
  matrix.fillRect(1,1, 2,2, LED_YELLOW);
  matrix.fillRect(5,1, 2,2, LED_RED);
  matrix.fillRect(1,5, 2,2, LED_GREEN);
  matrix.fillRect(5,5, 2,2, LED_YELLOW);
  matrix.writeDisplay();
  Serial.println("FILLS3 WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
  s
  matrix.setRotation(count);
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
 Serial.println("FADE2 WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
 matrix.clear();
 matrix.drawBitmap(0,0, bigheart_bmp, 8,8, LED_RED); //zeige das große Herz
 matrix.writeDisplay();
 xs xs xs 
 matrix.clear();
 matrix.drawBitmap(1,2, smallheart_bmp, 8,8, LED_RED); //zeige das kleine Herz, ein wenig nach rechts unten gerückt, damit es mittig vom großen ist
 matrix.writeDisplay();
 xs xs xs
 matrix.clear();
 matrix.drawBitmap(0,0, bigheart_bmp, 8,8, LED_RED); //mehrere Wiederholungen = Herzschlag
 matrix.writeDisplay();
 xs xs xs
 matrix.clear();
 matrix.drawBitmap(1,2, smallheart_bmp, 8,8, LED_RED);
 matrix.writeDisplay();
 xs xs xs
 matrix.clear();
 matrix.drawBitmap(0,0, bigheart_bmp, 8,8, LED_RED);
 matrix.writeDisplay();
 xs xs xs 
 matrix.clear();
 matrix.drawBitmap(1,2, smallheart_bmp, 8,8, LED_RED);
 matrix.writeDisplay();
 xs xs xs
 matrix.clear();
 matrix.drawBitmap(0,0, bigheart_bmp, 8,8, LED_RED);
 matrix.writeDisplay();
 xs xs xs 
 matrix.clear();
 matrix.drawBitmap(1,2, smallheart_bmp, 8,8, LED_RED);
 matrix.writeDisplay();
 Serial.println("HEARTBEAT WRITTEN"); //im Seriellen Monitor anzeigen lassen, dass der Vorgang abgeschlossen wurde
 xs xs xs
 count = count+1; //den Zähler um 1 erhöhen, damit sich die Ausrichtung um 90° ändert 
  Serial.println("Starte Durchgang"); //im Seriellen Monitor anzeigengen lassen, das der nächste Durchgang gestartet wird
  Serial.println(count+1); //Anzeige, der wievielte Durchgang gestartet ist. 
  }
  

