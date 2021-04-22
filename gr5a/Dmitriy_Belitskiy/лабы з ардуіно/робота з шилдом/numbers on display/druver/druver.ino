int a=0;
int mess[4];//сюди будемо складати цифри з ком порта
int i=0;
#define LATCH_DIO 4 
#define CLK_DIO 7 
#define DATA_DIO 8 

//цей скетч працює 
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};//кожен елемент масива являє собою набір байтів, які вмикають потріюну цифру 

const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};//тут кожен елемент масива-набір байтів, який вмикає потрібний індікатор 
 
void setup (){
 Serial.begin(9600);


pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO,OUTPUT);
pinMode(DATA_DIO,OUTPUT);
}

void loop(){
 
if (Serial.available()>0){ //перевыряэмо на наявнысть данних ком порт
    
    { a=Serial.read()-'0'; //зчитуємо в звінну а введене число(вводимо в ком порт 4 цифри)
     mess[i]=a;             //якщо ми ввели 4 цифри в ком порт, то цей цикл виконається 4 рази
     
      i++;
      }
      
     }
   for (int j=0;j<4;j++){
    Write(j ,mess[j]);
    }
    if (Serial.available()==0){i=0;}//якщовсе прочитали з порта, то скидуємо лічільник на нуль
   




  
}


void Write(byte Segment, byte Value)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
digitalWrite(LATCH_DIO,HIGH);
}





















  





 
  
  
