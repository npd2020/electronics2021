int RED_PIN = 11;
int GREEN_PIN = 10;
int BLUE_PIN = 9;
 
void setup(){

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}
 
void loop(){  

  setFadeColor(RED_PIN,GREEN_PIN,BLUE_PIN);
  setFadeColor(GREEN_PIN,BLUE_PIN,RED_PIN);
  setFadeColor(BLUE_PIN,RED_PIN,GREEN_PIN);
}

void setFadeColor(int cPin1,int cPin2,int cPin3){
  for(int i=0;i<=255;i++){
    analogWrite(cPin1, i);
    analogWrite(cPin2, 255-i);
    analogWrite(cPin3, 255);
    delay(10);
  }
}
