#include <SPI.h>         
#include "nRF24L01.h"     
#include "RF24.h"         

RF24 radio(9, 10); 


byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; 

int mess[4];

void setup() {
  Serial.begin(9600); 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  
  
  radio.begin(); 
  radio.setAutoAck(0);         
  radio.setRetries(0, 15);    
  radio.enableAckPayload();    
  radio.setPayloadSize(32);     //налаштування радіомодуля

  radio.openWritingPipe(address[0]);   
  radio.setChannel(0x60); 

  radio.setPALevel (RF24_PA_HIGH); 
  radio.setDataRate (RF24_250KBPS); 
 


  radio.powerUp(); 
  radio.stopListening(); 
}

void loop() {
  
  mess[0]=analogRead(A0);
  mess[1]=analogRead(A1);
  mess[2]=analogRead(A2);  //4 змінні приймають значення від 2-ох джойстиків з 2-ома степенями свободи
  mess[3]=analogRead(A3);
 
  
  radio.write(&mess, sizeof(mess));//відправляємо
  delay(2);

}
