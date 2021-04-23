#include <OneWire.h>

OneWire hoho(10);
void setup() {
  Serial.begin(9600);

}

void loop() {
byte data[2];
hoho.reset();
hoho.write(0xCC);
hoho.write(0x44);
delay(1000);
hoho.reset();
hoho.write(0xCC);
hoho.write(0xBE);
data[0]=hoho.read();
data[1]=hoho.read();
float temperature =  ((data[1] << 8) | data[0]) * 0.0625;
Serial.println(temperature);
}
