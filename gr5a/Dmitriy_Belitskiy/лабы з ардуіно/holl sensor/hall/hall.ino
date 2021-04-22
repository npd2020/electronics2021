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
int b=analogRead(A0); //до A0 підєднано сережній вивід датчика холо
Serial.println(b);    //виводимо в ком порт
b=map(b,490,530,1,9); 
draw(b);//виводимо на лінійний індикатор
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
