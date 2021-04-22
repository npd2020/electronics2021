#define LATCH_DIO 4 
#define CLK_DIO 7 
#define DATA_DIO 8

byte a=0b00110010;  //ці байти відповідають трьом горизонтальним рисочкам на індикаторі

byte b[]={0b11111111,0b01111111,0b10111111,0b11011111,0b11101111,0b11110111,  //ці байти відповідають за вмикання потрібного індикатора на дісплеї
0b11111011,0b11111101,0b11111110};


void setup() {
pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO,OUTPUT);
pinMode(DATA_DIO,OUTPUT);
pinMode(A0,INPUT); //на А0 підєднано середній вивід потенціометра
}
  
void loop() {
int b=analogRead(A0); //записуємо напругу в змінну b
b=map(b,0,1024,1,9); //відповідно перетворюємо значення b на нове в діапазоні від 1 до 9 
draw(b); //вивоимо на індикатор
}



void draw(int num)
  {
    
  for(int i=8;i>num-1;i--){ //ця конструкція виводить данні(почерзі вмикає необхідну кількість індикаторів) на дісплеї
     Write(a,b[i]);
  }  
  
  
}




void Write(byte a, byte b)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, a);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, b ); //ця конструкція вмикає три рисочки на на одному потрібному індикаторі і вимикає через 1 мілісекунду

delay(1);
digitalWrite(LATCH_DIO,HIGH);
}
