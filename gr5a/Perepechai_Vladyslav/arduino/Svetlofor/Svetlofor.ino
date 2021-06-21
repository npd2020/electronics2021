void setup() {
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(8, HIGH); 
  delay(3000);                     
  digitalWrite(10, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  delay(3000);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  digitalWrite(10, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(10, LOW);
}
