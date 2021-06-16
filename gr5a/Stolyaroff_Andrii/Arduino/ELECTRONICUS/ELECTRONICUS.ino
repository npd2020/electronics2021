#include <Servo.h>
#include <Scheduler.h>
#include <LedControl.h>

const int DIN_PIN = 10;
const int CS_PIN = 9;
const int CLK_PIN = 8;

const uint64_t IMAGES[] = {
    0x3c6660603e067e00,
    0x3c6660603e067e00,
    0xc3999f9fc1f981ff,
    0x30307e3234383000,
    0x30307e3234383000,
    0xcfcf81cdcbc7cfff,
    0x3c66603860663c00,
    0x3c66603860663c00,
    0xc3999fc79f99c3ff,
    0x7e060c3060663c00,
    0x7e060c3060663c00,
    0x81f9f3cf9f99c3ff,
    0x7e1818181c181800,
    0x7e1818181c181800,
    0x81e7e7e7e3e7e7ff,
    0x0000000000000000,
    0x0000000000000000,
    0xffffffffffffffff,
    0x0000000000000000,
    0x0000000000000000,
    0x7e06063e06067e00,
    0x3f03031f03033f00,
    0x1f01010f01011f00,
    0xfc0c0c0c0c0c0c00,
    0x7e06060606060600,
    0x3f03030303030300,
    0xfc0c0c7c0c0cfc00,
    0x7e06063e06067e00,
    0x3f03031f03033f00,
    0x78cc0c0c0ccc7800,
    0x3c66060606663c00,
    0x1e33030303331e00,
    0x3030303030b4fc00,
    0x18181818185a7e00,
    0x0c0c0c0c0c2d3f00,
    0xcc6c3c7ccccc7c00,
    0x66361e3e66663e00,
    0x331b0f1f33331f00,
    0x78cccccccccc7800,
    0x3c66666666663c00,
    0x1e33333333331e00,
    0x8c8cccecbc9c8c00,
    0xc6c6e6f6decec600,
    0x6363737b6f676300,
    0xf06060606060f000,
    0x3c18181818183c00,
    0x1e0c0c0c0c0c1e00,
    0x78cc0c0c0ccc7800,
    0x3c66060606663c00,
    0x1e33030303331e00,
    0xf8cccccccccccc00,
    0x7c66666666666600,
    0x3e33333333333300,
    0x78ccc0780ccc7800,
    0x3c66603c06663c00,
    0x1e33301e03331e00,
    0x0000000000000000,
    0x0000000000000000,
    0xffffffffffffffff,
    0x0000000000000000,
    0x0000000000000000,
    0x33330101e1e10387,
    0x99998080f0f081c3,
    0x66667f7f0f0f7e3c,
    0xccccfefe1e1efc78,
    0x66667f7f0f0f7e3c,
    0xccccfefe1e1efc78,
    0xccccfefe1e1efc78,
    0x66667f7f0f0f7e3c,
    0xccccfefe1e1efc78,
    0x33330101e1e10387,
    0x99998080f0f081c3};
const int IMAGES_LEN = sizeof(IMAGES) / 8;

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);
Servo servo;

void setup()
{
    servo.attach(3);
    display.clearDisplay(0);
    display.shutdown(0, false);
    display.setIntensity(0, 10);
    Scheduler.startLoop(loopA);
}

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

int i = 0;
int pos = 0;
void loop()
{
    displayImage(IMAGES[i]);
    if (++i >= IMAGES_LEN)
    {
        i = 0;
        display.clearDisplay(0);
        delay(3000);
    }
    if (i >= 21 && i <= 56)
        delay(100);
    else
        delay(200);
}
void loopA()
{
    if (pos == 0)
        pos = 180;
    else
        pos = 0;
    servo.write(pos);
    delay(200);
}