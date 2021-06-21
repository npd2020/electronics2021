#define LED1 4
#define NUMLED 5
int i;
// the setup function runs once when you press reset or power the board
void setup() {
  
  for (i=LED1; i<LED1+NUMLED; i++){
    pinMode(i,OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  
  int num = map (analogRead(A0),0,1000,0,NUMLED+1);
  if (num==NUMLED+1){
    for (i=LED1; i<LED1+ NUMLED; i++){
    digitalWrite(i, HIGH); 
  }
  delay(200);
    for (i=LED1; i<LED1+ NUMLED; i++){
    digitalWrite(i, LOW); 
  }
  delay(200);
  } else{
  for (i=LED1; i<LED1+num; i++){
    digitalWrite(i, HIGH); 
  }
  for (i=LED1+num; i<LED1+NUMLED; i++){
    digitalWrite(i, LOW); 
  }
  }
}
