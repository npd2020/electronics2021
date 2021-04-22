#define LED1 2
#define LED5 6
#define LED_ON 2

//Pim to read
#define ANALOG_IN A0

void setup() {
  for(int i= LED1; i <= LED5; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  //Proportional scaling
  int lastLed = map(analogRead(ANALOG_IN), 0, 1023, 2, 6);
  

  //Blinking of the lights
  for(int i = LED1; i <= lastLed; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }

}
