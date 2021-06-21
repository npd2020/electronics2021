#define PIN_LED 3
#define PIN_PHOTO_SENSOR A0

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

int process (int val){
  return val;         //Here we can process our value to make it suit our perticular needs
                      //Now, leave if blank, it works just fine
}

void loop() {
  int val = analogRead(PIN_PHOTO_SENSOR);
  Serial.println(val);

  val=process(val);
  
  int ledPower = map(val, 0, 1023, 0, 255); // Converting input signal into output
  analogWrite(PIN_LED, ledPower); // Changing brightness, introducing new duty cycle
}
