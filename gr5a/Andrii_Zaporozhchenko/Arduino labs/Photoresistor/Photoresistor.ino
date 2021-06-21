#define LED1 2
#define LED4 5
#define LED_ON 2

#define ANALOG_IN A0

void setup() {
  Serial.begin(9600);
  for(int i= LED1; i <= LED4; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  int sensVal = analogRead(ANALOG_IN);
  Serial.println(sensVal);
  int lastLed = map(constrain(sensVal, 500, 900), 500, 900, 2, 5);
  Serial.println(lastLed);

 
  for(int i = LED1; i <= lastLed; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }
}
