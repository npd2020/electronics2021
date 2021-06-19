#define LED1 2
#define LED4 5
#define LED_ON 2

//pin for reading analog signal
#define ANALOG_IN A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i= LED1; i <= LED4; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //сохранение в переменную результата работы map(), 
  //которая вернет значение, считанное с аналогового входа, 
  //и пропорционально отмасштабированное из диапазона 0-1023 в диапазон 2-11
  int sensVal = analogRead(ANALOG_IN);
  Serial.println(sensVal);
  int lastLed = map(constrain(sensVal, 0, 500), 0, 500, 2, 5);
  Serial.println(lastLed);

  //включение и выключение светодиодов на ножках 
  //от начальной до вычисленной выше конечной
  for(int i = LED1; i <= lastLed; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }
}
