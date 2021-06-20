#include <OneWire.h>
#include <UTFT.h>
#include "Wire.h"
#include <String.h>
#define DS1307_ADDRESS 0x68
UTFT myGLCD(TFT32MEGA_2, 38,39,40,41);
OneWire  ds(2);

extern uint8_t SevenSegNumFont[]; 
extern uint8_t BigFont[];
//extern uint8_t BigFont[];
 
void setup(){  
  Wire.begin();  
    Serial.begin(9600);                              
   myGLCD.InitLCD();     
   myGLCD.setFont(BigFont);                      
}  
void loop(void){
  myGLCD.clrScr();
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;
  
  if ( !ds.search(addr)) {
    Serial.println("No more addresses.");
   // Serial.println();
    ds.reset_search();
    //delay(2000);
    return;
  }
  if (OneWire::crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return;
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44);
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);
  for ( i = 0; i < 9; i++) {
    data[i] = ds.read();}
    int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; 
    if (data[7] == 0x10) { 
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;  
    else if (cfg == 0x20) raw = raw & ~3; 
    else if (cfg == 0x40) raw = raw & ~1; 
  }
  celsius = (float)raw / 16.0;
  myGLCD.fillScr(VGA_WHITE); 
myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setFont(SevenSegNumFont); 
  myGLCD.setColor(VGA_BLUE);
  String celsius_1_string="";
  String celsius_2_string="";
  float celsius_2=celsius*100;
  int celsius_2_1=(int)celsius_2%100;
  celsius_1_string.concat((int)celsius);
  celsius_2_string.concat(celsius_2_1);
  //myGLCD.print(celsius_string, CENTER, 0); 
  //myGLCD.print(printDate(), CENTER, 100);
  myGLCD.setFont(BigFont); 
  myGLCD.print("Temp(in)", LEFT, 120); 
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(celsius_1_string, 345, 100);
  myGLCD.setFont(BigFont);
  myGLCD.print(",", 405, 140); 
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(celsius_2_string, 420, 100);
  
  Serial.print("  Temperature = ");
  Serial.print(celsius);
  Serial.print(" Celsius, ");
  
  printDate();
  Serial.println("");  
                              
  delay(10000);
   
}
byte bcdToDec(byte val)  {
  return ( (val/16*10) + (val%16) );
  }
String printDate(){

  Wire.beginTransmission(DS1307_ADDRESS);

  byte zero = 0x00;
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  int second = bcdToDec(Wire.read());
  int minute = bcdToDec(Wire.read());
  int hour = bcdToDec(Wire.read() & 0b111111);
  /*int weekDay = bcdToDec(Wire.read()); 
  int monthDay = bcdToDec(Wire.read());
  int month = bcdToDec(Wire.read());
  int year = bcdToDec(Wire.read());*/
  
  String minute_s="";
  String hour_s="";
  hour_s.concat(hour);
  minute_s.concat(minute);
  myGLCD.setColor(VGA_BLUE);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(hour_s, 170, 7);
  myGLCD.setFont(BigFont); 
  myGLCD.print(":", 230, 20);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(minute_s, 245, 7);
  //return now;
   //Serial.print(month);
  //Serial.print("/");
  //Serial.print(monthDay);
  //Serial.print("/");
 // Serial.print(year);
  //Serial.print(" ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
   }
