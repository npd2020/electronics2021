#define LED_PIN 13
#define ANALOG_IN A0

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
 //If signal is more than 512 -- light is on
  if(analogRead(ANALOG_IN) > 512)
  {
    digitalWrite(LED_PIN, HIGH);
  }
 
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}
