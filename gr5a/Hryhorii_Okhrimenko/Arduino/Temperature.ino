#include <OneWire.h>
#include <DallasTemperature.h>

// линия данных подключена к цифровому выводу 2 Arduino
#define ONE_WIRE_BUS 2

// настройка объекта oneWire для связи с любым устройством OneWire
OneWire oneWire(ONE_WIRE_BUS);  

// передать ссылку на oneWire библиотеке DallasTemperature
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();  // запустить библиотеку
  Serial.begin(9600);
}

void loop(void)
{ 
  // отправить команду для получения температуры
  sensors.requestTemperatures(); 

  // напечатать температуру в градусах Цельсия
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println("C");// напечатать символ градусов

  
  delay(500);
}
