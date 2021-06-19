#include <Servo.h>
#include <Scheduler.h>
#include <LedControl.h>
#include "LEDvars.h"

const int DIN_PIN = 10;
const int CS_PIN = 9;
const int CLK_PIN = 8;
const int Max_Hits = 15;
LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);
Servo servo;

void displayImage(uint64_t image)
{
    for (int i = 0; i < 8; i++)
    {
        byte row = (image >> i * 8) & 0xFF;
        for (int j = 0; j < 8; j++)
        {
            display.setLed(0, i, j, bitRead(row, j));
        }
    }
}

int READ = 0;
int Hits = 0;
bool X_Button_Pressed = 0;
bool S_Button_Pressed = 0;
void servoloop()
{
    if (X_Button_Pressed)
    {
        delay(50);
        X_Button_Pressed = 0;
    }

    servo.write(180);
    delay(150);
    if (X_Button_Pressed)
    {
        delay(50);
        X_Button_Pressed = 0;
    }

    servo.write(165);
    delay(150);
}
void check()
{
    delay(1);
    READ = Serial.read();
    if (READ == 120)
    {
        READ = 0;
        X_Button_Pressed = 1;
        Hits++;
        servo.write(90);
        delay(50);
        Serial.print("Hit");
        Serial.print(Hits);
        Serial.println("!");
    }
    else if (READ == 115)
    {
        S_Button_Pressed = 1;
        READ = 0;
    }
}
void setup()
{
    Serial.begin(9600);
    displayImage(0xffffffffffffffff);
    servo.attach(3);
    display.shutdown(0, false);
    display.setIntensity(0, 10);
    Scheduler.startLoop(servoloop);
    Scheduler.startLoop(check);
}
void loop()
{
    displayImage(0xffffffffffffffff);

    if (Hits == Max_Hits)
    {
        for (int i = 0; i < FATALITY_LEN; i++)
        {
            displayImage(FATALITY[i]);
            delay(200);
        }
        displayImage(0xffffffffffffffff);
        delay(500);

        for (int i = 0; i < TEST_LEN; i++)
        {
            displayImage(TEST[i]);
            delay(250);
        }
        displayImage(0xffffffffffffffff);
        delay(500);
        READ = 0;
        X_Button_Pressed = 0;
        Hits=0;
    }
    if (S_Button_Pressed)
    {
        for (int i = 0; i < NUMBERS_LEN; i++)
        {
            displayImage(NUMBERS[i]);
            delay(200);
        }
        displayImage(0xffffffffffffffff);
        delay(500);
        for (int i = 0; i < FIGHT_LEN; i++)
        {
            displayImage(FIGHT[i]);
            delay(250);
        }
        displayImage(0xffffffffffffffff);
        delay(1000);
        READ = 0;
        S_Button_Pressed = 0;
    }
    delay(1);
}
