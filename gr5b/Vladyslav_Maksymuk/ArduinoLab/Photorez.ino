#define LED1 2
#define LED4 5
#define LED_ON 3


#define ANALOG_IN A0

void setup() {
  for(int i= LED1; i <= LED4; i++)
    pinMode(i, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  int lastLed = map(analogRead(ANALOG_IN),1023 ,0 ,1 ,6 );
  for(int i =LED1; i <= lastLed; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }
   int sensorValue = analogRead(A0);
   Serial.println(sensorValue);
  delay(1);   
}
