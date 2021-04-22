#define PIN_ECHO 8
#define PIN_PULSE 9
#define PIN_G 5
#define PIN_H 6

#include <Servo.h> 
  Servo servo_g;
  Servo servo_h;

void setup() {
  pinMode(PIN_PULSE,OUTPUT);
  pinMode(PIN_ECHO,INPUT);
  servo_g.attach(PIN_G);
  servo_h.attach(PIN_H);
  Serial.begin(9600);

}
int g=0;
int h=0;








void loop() {
  for (h=90;h>=0;h--){
    servo_h.write(h);
    delay(50);
    if(h%2==0)grscan();
    if(h%2!=0)glscan();
}
  
  for (h=0;h<=90;h++){
    servo_h.write(h);
    delay(50);
    if(h%2==0)grscan();
    if(h%2!=0)glscan();
}
}

void grscan()
{
for (g=0;g<=90;g++){  
    servo_g.write(g);
    delay(10);
    sent();
  }
 

}
void glscan()
{
for (g=90;g>=0;g--){  
    servo_g.write(g);
    delay(10);
    sent();
  }

}


void sent()
{
  Serial.print(g);

    Serial.print(":");

    Serial.print(h);
    Serial.print(":");
    
    int b= distance();
    Serial.print(b);
    Serial.print(";");
    }



float distance(){
  float sum=0;
    for (int i=0;i<2;i++){
      sum+=probe();
      delay(10);
    }
   int p= constrain((sum/2),0,300);
    
return (map(p,0,300,0,250));

}

float probe()
{
 
 long duration, cm;
  digitalWrite(PIN_PULSE, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_PULSE, HIGH);

 
  delayMicroseconds(10);
  digitalWrite(PIN_PULSE, LOW);

  duration = pulseIn(PIN_ECHO, HIGH,18180);

  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2) / 29.1;
 return(cm);
} 
  
 
