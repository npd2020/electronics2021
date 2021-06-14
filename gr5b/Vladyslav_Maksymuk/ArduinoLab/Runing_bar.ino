
#define LED1 2
#define LED5 6

#define LED_ON 200

void setup() {
  for(int i= LED1; i <= LED5; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  for(int i = LED1; i <= LED5; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }

}
