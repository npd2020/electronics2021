#define R 3
#define G 5
#define B 6


void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);


}

void loop() {
 digitalWrite(R,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(B,HIGH);
 delay(1000);
 digitalWrite(R,LOW);
 digitalWrite(G,LOW);
 digitalWrite(B,LOW);
  delay(1000);
 
 }
