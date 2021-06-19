#define ON LOW   //задаем включение зуммера
#define OFF HIGH //задаем выключение зуммера
#define BUZZER 3 //подключаем зуммер к пину 3
#define KEY1 A1  //подключаем кнопку к пину А1
// Определяем контакты сдвигового регистра,используемые для семисегментного дисплея
#define LATCH_DIO 4 //линия синхронизации данных, защелка (LCHCLK)
#define CLK_DIO 7 //линия тактирования (SFTCLK)
#define DATA_DIO 8 //линия передачи данных(SDI)

int potpin=A0;//задаем вывод потенциометра A0.
int ledpin=12;//задаем переменную ledpin и подсоединяем к выводу 12（без ШИМ)
int ledpin1=11;//задаем переменную ledpin1 и подсоединяем к выводу 11（с ШИМ)

/* байты чисел от 0 до 9 */
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
/* Байт-карты для выбора разряда дисплея от 1 до 4 */
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};
 
int val=0;// задаем переменную Val

void setup(){
 
/* конфигурируем выводы*/
pinMode(KEY1, INPUT); //кнопка А1 как вход
pinMode(BUZZER,  OUTPUT); //зуммер 3 как выход
digitalWrite(BUZZER, OFF);//выключаем звук зуммера
Serial.begin(9600); 

/* Установите выходы DIO как выходы */
pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO,OUTPUT);
pinMode(DATA_DIO,OUTPUT);
}
 
void loop(){
 
if( digitalRead(KEY1)==ON ) //нажимаем кнопку KEY1
{
digitalWrite(BUZZER, ON); //зуммер включен
}
else{
digitalWrite(BUZZER, OFF); //зуммер выключен
}

val=analogRead(potpin);// считываем данные порта в переменную val
Serial.println(val);//отправляем значение переменной Val в порт.(от 0 до 1023)
analogWrite(ledpin,val/4);// при вращении потенциометра на ledpin значение будет менятся от 0 до 255. Яркость светодиода меняется скачком 0 или 1.(нет ШИМ(PWM))
analogWrite(ledpin1,val/4);// при вращении потенциометра на ledpin1 значение будет менятся от 0 до 255. Яркость светодиода меняется плавно.(есть ШИМ(PWM))
 
delay(10);//пауза 100мс

/* Обновить дисплей с текущим значением счетчика */
WriteNumberToSegment(0 , 5);//записываем в нулевой (старший) разряд 5
WriteNumberToSegment(1 , 6);//записываем в 1 разряд 6
WriteNumberToSegment(2 , 7);//записываем в 2 разряд 7
WriteNumberToSegment(3 , 8);//записываем в 3 разряд 8
}

/* отправляем десятичное число от 0 до 9 в один из четырех разрядов дисплея */
void WriteNumberToSegment(byte Segment, byte Value)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
digitalWrite(LATCH_DIO,HIGH);
}
