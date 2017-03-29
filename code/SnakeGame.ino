//Auf Basis eines Projekts von Björn Fischer, erweitert und ergänzt, um mit einem Keypad als GameController zu funktionieren. 
//www.bjoernfi.de http://bjoernfi.de/category/arduino-als-spielekonsole/ 
//Unter Verwendung der Keypad, Adafuit GFX und Adafruit LEDBackpack Library 
//https://github.com/adafruit/Adafruit-GFX-Library/archive/master.zip
//https://github.com/adafruit/Adafruit_LED_Backpack/archive/master.zip
//https://github.com/Chris--A/Keypad


#include "gfxfont.h" 
#include "Wire.h"
#include "Adafruit_GFX.h" //einbinden der Matrix
#include "Adafruit_LEDBackpack.h" //einbinden der Matrix
#include "Keypad.h" //einbinden des Keypads

const byte ROWS = 4; //das Keypad hat vier Reihen
const byte COLS = 4; //das Keypad had vier Spalten
//definieren welcher Wert von welchem Button ausgegeben wir 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','*','D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //definieren an Welchen Pins die Reihen liegen
byte colPins[COLS] = {9, 8, 7, 6}; //definieren an Welchen Pins die Spalten liegen

 
 
//definieren von Länge und Breite des Spielfelds 
#define MATRIX_HORIZONTAL_LENGTH 8
#define MATRIX_VERTICAL_LENGTH 8
 
#define DIRECTION_TOP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_BOTTOM 2
#define DIRECTION_LEFT 3
 

#define SNAKE(a) (a > 0)
 
int field[MATRIX_HORIZONTAL_LENGTH][MATRIX_VERTICAL_LENGTH] = { 0 };
int snakeHeadX; //erstellen der Variablen für den Kopf der Schlange 
int snakeHeadY;
 
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix(); //initialisieren der Bicolor-Matrix 

int direction = DIRECTION_TOP; //definiert, dass die ausgangsrichtung nach oben ist 
int snakeLength = 3;   //definiert die anfängliche Länge der Schlange                         
unsigned long prevTime = 0;  
unsigned long delayTime = 400;  //definiert die Schrittgeschwindigkeit der Schlange als 1 Pixel/200ms 
 
int fruitX, fruitY; //kreiirt die Variablen für die Koordinaten der Frucht 
unsigned long fruitPrevTime = 0;
unsigned long fruitBlinkTime = 200; //definiert die Blinkzeit der Frucht als 1 Pixel/200ms
int fruitLed = LED_GREEN; //definiert die LED der Frucht als grün 
 
boolean gameOverShown = false; //sagt das gamerOverShown entweder wahr oder falsch ist und aktuell falsch ist 
boolean gameOver = false; //boolean gibt wieder wahr oder falsch an hier anfangs falsch


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //kreeirt das Keypad

 
void setup()
{
    // LED Matrix initialisieren
    Serial.begin(9600); //Startet den Seriellen Monitor
    matrix.begin(0x70); //Die 7-Bit-Adresse der Matrix ist 0x70
    randomSeed(analogRead(0)); //sorgt für Zufall
    matrix.setRotation(3); //Dreht die Matrix entsprechend der Ausrichtung in der Gamemachine
    Serial.println("Start Snake"); //zeigt das Snake gestartet wurde im Seriellen Monitor
  
    snakeHeadX = random(0, MATRIX_HORIZONTAL_LENGTH); //wählt eine Zufällige position für den Kopf der Schlange zwischen 0 und 8 (Länge der Matrix) 
    snakeHeadY = random(0, MATRIX_VERTICAL_LENGTH);
    field[snakeHeadX][snakeHeadY] = snakeLength; 
 
    makeFruit(); //führt void makeFruit aus, um die erste Fruct zu platzieren
}
   
void loop()
{
    
    checkButtons(); //führt void checkButtons aus, um evtl die Richtung zu ändern. 

     unsigned long currentTime = millis(); //sorgt, dafür, das void nextstep nur alle 400ms ausgeführt wird. 
    if (currentTime - prevTime >= delayTime) {
        nextstep();
        prevTime = currentTime;
        Serial.println(currentTime);//zeigt die verstrichene Zeit im seriellen Monitor an 
    }
 
    draw(); //führt das void draw aus 
    
}
void checkButtons()
{
    char key = keypad.getKey(); //definiert die Variable key als den Key, der gerdückt wird

    int currentDirection = direction;
    if (key == '7' && currentDirection != DIRECTION_RIGHT) { //Stellt die Bedingung, dass der Key 7 gedrückt wurde, und die aktuelle Richtung nicht die entgegengesetze ist 
        direction = DIRECTION_LEFT; //setzt die Richtung auf links 
        Serial.println("NEW DIRECTION LEFT"); //zeigt im Seriellen Monitor die neue Richtung an
    }
    else if (key == '9'  && currentDirection != DIRECTION_LEFT) { //wie bei links nur mit Key 9
        direction = DIRECTION_RIGHT;
        Serial.println("NEW DIRECTION RIGHT"); //zeigt im Seriellen Monitor die neue Richtung an
    }
    else if (key == '5' && currentDirection != DIRECTION_BOTTOM) { //wie bei links nur mit Key 5
        direction = DIRECTION_TOP;
        Serial.println("NEW DIRECTION TOP"); //zeigt im Seriellen Monitor die neue Richtung an
    }
    else if (key == '0' && currentDirection != DIRECTION_TOP) { //wie bei links nur mit Key 0
        direction = DIRECTION_BOTTOM; 
        Serial.println("NEW DIRECTION BOTTOM"); //zeigt im Seriellen Monitor die neue Richtung an
    }
}
 
void draw() //definieren der Funktion draw
{
    if (!gameOver) //! steht für wenn nicht Game over
    {
        for (int x = 0; x < MATRIX_HORIZONTAL_LENGTH; x++) //verschiebt die Schlange nach auf die andere Seite der Matrix wenn sie den Rand erreicht hat  
        {
            for (int y = 0; y < MATRIX_VERTICAL_LENGTH; y++)
                matrix.drawPixel(x, y, SNAKE(field[x][y]));
        }
 
        drawFruit(); //zeichnet die nächste Frucht 
         
        matrix.writeDisplay(); //Zeichnet alle ausgeführten Schritte auf die Matrix
    }
    // Wenn Game Over...
    else
    {
       
        matrix.setTextWrap(false);
        matrix.setTextColor(LED_GREEN);
         
        if (!gameOverShown) //wenn GameOver noch nicht angezeigt wurde 
        {
            Serial.println("Start GAME OVER Message");
            for (int8_t x = 0; x >= -107; x--) {
                matrix.clear();
                matrix.setCursor(x, 0);
                matrix.print("GAME OVER");//zeigt erst GAME OVER 
                matrix.print(" Score:");//dann Score: 
                matrix.print(snakeLength);//und dann die erreichte Länge an 
                matrix.writeDisplay();
                delay(100);
            }
            Serial.println("GAME OVER Message shown");//zeigt das die Nachri
            gameOverShown = true; //setzt die boolean variante auf true  
        }
        
        else {
             Serial.println("Waiting for reset"); 
              for (int16_t x = 7; x >= -197; x--) { //hier int16_t da mehr als -127 gebraucht wird 
                matrix.clear();
                matrix.setCursor(x, 0);
                matrix.print("Press side button to restart game");
                matrix.writeDisplay(); 
                delay(75);  
              }
        } 
    }
}
 
// Zeichnet die Frucht auf die Matrix und implementiert das Blinken des Pixels
void drawFruit()
{
    if (inPlayField(fruitX, fruitY)) { //führt draw nur aus wenn die Frucht im Feld liegt 
        unsigned long currenttime = millis(); //definiert die aktuelle Zeit in ms 
        if (currenttime - fruitPrevTime >= fruitBlinkTime) { //sorgt, dafür, das dieser Schritt nur alle 200ms ausgeführt wird
            fruitLed = (fruitLed == LED_GREEN) ? LED_OFF : LED_GREEN;
            fruitPrevTime = currenttime; 
        }
        matrix.drawPixel(fruitX, fruitY, fruitLed); //zeichnet die Frucht in der zuvor definierten Farbe
    }
}
 
boolean inPlayField(int x, int y) // boolean gibt entweder wahr oder falsch aus ob die Koordinaten im Feld liegen
{
    return (x >= 0) && (x<MATRIX_HORIZONTAL_LENGTH) && (y >= 0) && (y<MATRIX_VERTICAL_LENGTH); //prüft ob die Koordinaten im Feld der Matrix liegen. 
}
void nextstep() // definieren der Funktion nextstep, die die Schlage verschiebt und prüft ob das Spiel vorbei ist 
{
    int newX = snakeHeadX;
    int newY = snakeHeadY;
 
    switch (direction) { //switch passt die Länge der Schlange je nach Ausgangsrichtung an 
        case DIRECTION_TOP:
            newY--;
            break;
        case DIRECTION_RIGHT:
            newX++;
            break;
        case DIRECTION_BOTTOM:
            newY++;
            break;
        case DIRECTION_LEFT:
            newX--;
            break;
    }
 
    // Wenn neue Position über die Seiten der Matrix hinausragt, neue Position auf die andere Seite setzen
    if (newY >= MATRIX_VERTICAL_LENGTH)
        newY = 0;
    else if (newY < 0)
        newY = MATRIX_VERTICAL_LENGTH - 1;
 
    if (newX >= MATRIX_HORIZONTAL_LENGTH)
        newX = 0;
    else if (newX < 0)
        newX = MATRIX_HORIZONTAL_LENGTH - 1;
 
    if (isPartOfSnake(newX, newY))//wenn die neuen Koordinaten auf der Schlange liegen sollten 
    {
        gameOver = true; //wird gameover auf true gesetzt 
        delay(1000); //Zeit die vergeht bis der Text angezeigt wird
        return;
    }
 
    if ((newX == fruitX) && (newY == fruitY)) { //unter der Bedingung das newX und new Y der Frucht entsprechen,
        snakeLength++; //Schlange um 1 erweitern 
        makeFruit();  //Neue Frucht platzieren
    }
 
    for (int x = 0; x < MATRIX_HORIZONTAL_LENGTH; x++)
    {
        for (int y = 0; y < MATRIX_VERTICAL_LENGTH; y++)
        {
            int value = field[x][y];
            if (SNAKE(value))
                field[x][y] = value - 1;
        }
    }
 
    snakeHeadX = newX; //setzt die neuen Koordinaten als Kopf der Schlange 
    snakeHeadY = newY;
    field[newX][newY] = snakeLength; //definert die neue Länge der Schlange
    Serial.println(snakeLength); //zeigt die aktuelle Länge der Schlange im Seriellen Monitor an 
}
 
void makeFruit() //mit void makeFruit die Koordinaten für eine Frucht ertstellen 
{
    int x, y = 42; //Definiert x und y als Zahl, welche ist egal, 42 hat Stil
 
    do {
        x = random(0, MATRIX_HORIZONTAL_LENGTH); //erstellt eine zufällige Zahl im Bereich 0-8
        y = random(0, MATRIX_VERTICAL_LENGTH);
    } while (isPartOfSnake(x, y)); //unter der Bedingung das sie nicht auf der Schlange liegt 
 
    fruitX = x; //setzt die Schlangen-Überprüften Werte gleich den Frucht Koordinaten
    fruitY = y;
}
 
boolean isPartOfSnake(int x, int y) //prüft ob x und y in der Schlange liegen 
{
    return SNAKE(field[x][y]);
}
