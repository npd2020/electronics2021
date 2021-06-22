#include <Arduino.h>
#include <LedControl.h>
#include <Wire.h>
#include "PriUint64.h"

const int DIN_PIN = 10;
const int CS_PIN = 9;
const int CLK_PIN = 8;

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);

void displayImage(uint64_t image)
{
  for (int i = 0; i < 8; i++)
  {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++)
    {
      display.setLed(0, i, j, bitRead(row, 7 - j));
    }
  }
}
uint64_t convertStringToU64(String str)
{

  uint64_t val = 0;
  for (unsigned int i = 0; i < str.length(); i++)
  {
    val = val * 10;
    val = val + str[i] - '0';
  }
  return val;
}

void setup()
{
  Serial.begin(115200);
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);
}
int k = 0;
int j = 0;
int64_t image = 0;
String readString = "";
void loop()
{
  while (Serial.available())
  {
    char c = Serial.read();
    Serial.print(c);
    if (c != '\n')
      readString += c;
    else
    {
      Serial.print(readString + "|");
      image = convertStringToU64(readString);
      Serial.println(PriUint64<DEC>(image));
      displayImage(image);
      readString = "";
      delay(3.32);
    }
  }
}
