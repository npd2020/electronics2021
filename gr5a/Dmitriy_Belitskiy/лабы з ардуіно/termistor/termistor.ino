#define LATCH_DIO 4 
#define CLK_DIO 7 
#define DATA_DIO 8

byte a=0b00110010;

byte b[]={0b11111111,0b01111111,0b10111111,0b11011111,0b11101111,0b11110111,
0b11111011,0b11111101,0b11111110};


void setup() {
pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO,OUTPUT);
pinMode(DATA_DIO,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}
  
void loop() {
int b=analogRead(A0);
Serial.println(b);
b=map(b,454,500,1,9);
draw(b);
}



void draw(int num)
  {
    
  for(int i=8;i>num-1;i--){
     Write(a,b[i]);
  }  
  
  
}




void Write(byte a, byte b)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, a);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, b );

delay(1);
digitalWrite(LATCH_DIO,HIGH);
}
