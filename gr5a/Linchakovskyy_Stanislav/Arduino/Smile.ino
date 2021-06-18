#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 9;
int numberOfHorizontalDisplays = 1; // количество матриц по-горизонтали
int numberOfVerticalDisplays = 1; // количество матриц по-вертикали

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

const byte data1[8] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b01000010,
    0b00111100
};


const byte data2[8] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10111101,
    0b10011001,
    0b01000010,
    0b00111100
};

void setup() {
    matrix.setIntensity(7); // яркость от 0 до 15

    matrix.fillScreen(LOW); // очистка матрицы
    for ( int y = 0; y < 8; y++ ) {
        for ( int x = 0; x < 8; x++ ) {
            // зажигаем x-й пиксель в y-й строке
            matrix.drawPixel(x, y, data1[y] & (1<<x));
        }
    }
    matrix.write(); // вывод всех пикселей на матрицу
delay(5000);


    matrix.fillScreen(LOW); // очистка матрицы
    for ( int y = 0; y < 8; y++ ) {
        for ( int x = 0; x < 8; x++ ) {
            // зажигаем x-й пиксель в y-й строке
            matrix.drawPixel(x, y, data2[y] & (1<<x));
        }
    }
    matrix.write();


}

void loop() {
}
