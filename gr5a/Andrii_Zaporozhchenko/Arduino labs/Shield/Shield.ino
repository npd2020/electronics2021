#define ON LOW  
#define OFF HIGH 
#define BUZZER 3 
#define KEY1 A1 
#define LATCH_DIO 4 
#define CLK_DIO 7
#define DATA_DIO 8 

int potpin=A0;
int ledpin=12;
int ledpin1=11;


const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};
 
int val=0;
void setup(){
 
pinMode(KEY1, INPUT); 
pinMode(BUZZER,  OUTPUT); 
digitalWrite(BUZZER, OFF);
Serial.begin(9600); 

pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO,OUTPUT);
pinMode(DATA_DIO,OUTPUT);
}
 
void loop(){
 
if( digitalRead(KEY1)==ON ) 
{
digitalWrite(BUZZER, ON); 
}
else{
digitalWrite(BUZZER, OFF);
}

val=analogRead(potpin);
Serial.println(val);
analogWrite(ledpin,val/4); 
analogWrite(ledpin1,val/4);
 
delay(10);

WriteNumberToSegment(0 , 5);//записываем в нулевой (старший) разряд 5
WriteNumberToSegment(1 , 6);//записываем в 1 разряд 6
WriteNumberToSegment(2 , 7);//записываем в 2 разряд 7
WriteNumberToSegment(3 , 8);//записываем в 3 разряд 8
}

void WriteNumberToSegment(byte Segment, byte Value)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
digitalWrite(LATCH_DIO,HIGH);
}
