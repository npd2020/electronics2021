
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Servo.h>
int x;
int y;
int z;
int c;
int c1;
int z1;
int x1;
int y1;
int a,b;
RF24 radio(8,10); 

Servo zz;
Servo xx;
Servo yy;
Servo motor;
byte address[][6] = {"1Node","2Node","3Node","4Node","5Node","6Node"};  
int gotByte[4];

void setup(){
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
zz.attach(5);
xx.attach(3);
yy.attach(9);
motor.attach(6);
motor.writeMicroseconds(2600);
delay(2000);
motor.writeMicroseconds(800);
delay(6000);
  Serial.begin(9600); ПК
  radio.begin(); 
  radio.setAutoAck(0);         
  radio.setRetries(0,15);     
  radio.enableAckPayload();   
  radio.setPayloadSize(32);   

  radio.openReadingPipe(1,address[0]);     
  radio.setChannel(0x60); 

  radio.setPALevel (RF24_PA_HIGH);
  radio.setDataRate (RF24_250KBPS); 
  
  
  radio.powerUp(); 
  radio.startListening();  
}
int n=0;
void loop() {

    byte pipeNo;
                               
    while( radio.available(&pipeNo)){    
      radio.read( &gotByte, sizeof(gotByte) );         

 
    n=0;
   
    x=gotByte[0];   
    y=gotByte[2];
    z=gotByte[1];
    c=gotByte[3];
    x1=map(x,0,705,0,180);     
    c1=map(c,0,705,180,0);   
    y1=map(y,0,705,0,180);
    z1=map(z,342,705,800,2300);
 
   y1=y1-89;
  
   a=x1+y1;
   b=x1-y1;
   
   if (a>180){a=180;};
   if (a<23){a=23;};
   if (b>150){b=150;};   //управление откланяемыми поверхностями
   if (b<0){b=0;};
   if (z1>2300){z1=2300;};
   if (z1<800){z1=800;};
    
    motor.writeMicroseconds(z1);
    zz.write(a-4);
    xx.write(b);                     //керування двигуном
    yy.write(c1-14);
       Serial.println(a);   //для відладки

      
 delay(20);
     

 
 }
Serial.print("ERROR");Serial. println(n);
n=n+1;
if (n>10){zz.write(90);xx.write(90);yy.write(72); motor.writeMicroseconds(800); } //якщо втрачений зв'язок встановити всі
                                                                                   // керуючи поверхні в дефолтне положення та вимкнути мотор
delay(20);
}
