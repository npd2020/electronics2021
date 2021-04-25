#include <LedControl.h>

// Пины матрицы (SPI)
#define DIN 12
#define CS 11
#define CLK 10

#define ON_TIME  2000     
#define OFF_TIME 1000     

//Picture
byte idea[8]     =   {0x8,0x18,0x5A,0x7A,0x5E,0x5A,0x18,0x10};

//Matrix
LedControl matrix = LedControl(DIN, CLK, CS, 0);

//Printing rows
void printRow(byte character [])
{
  for (byte i = 0; i < 8; i++)
  {
    matrix.setRow(0, i, character[i]);
    delay(200);
  }
}

//Intensity low
void off() {
  for (byte k = 15; k >= 1; k--) {
    matrix.setIntensity(0, k);
    delay(60);
  }
  matrix.clearDisplay(0);
}

//Inlensity on
void on() {
  for (byte j = 1; j <= 15; j++){
    matrix.setIntensity(0, j);
    delay(70);
  }
}

//Displaying all rows
void breathing() {
  printRow(idea);
  on();
  delay(ON_TIME);
  off();
  delay(OFF_TIME);

}


void setup(){
 matrix.shutdown(0, false);        // MAX72XX is on
 matrix.setIntensity(0, 1);        // Intensity = min
 matrix.clearDisplay(0);           // Clear
}

void loop(){
  breathing();    // Main
  delay(300);
}
