/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 9 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
void setup() {
  // initialize digital pins (9"R",10"B",11"G") as an output.
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //Step 1
  digitalWrite(9, HIGH);   // red, 3 sec
  delay(3000);                   
  digitalWrite(11, HIGH);    // yellow, 1 sec
  delay(1000);  
  //Step 2    
  
  digitalWrite(9, LOW);   // red, off                     
  digitalWrite(11, LOW);    // yellow, off
  digitalWrite(11, HIGH);   // green, 3 sec
  delay(3000);                       
  digitalWrite(11, LOW);    // green, off
  //Step 3 Green on & off for half-second
  delay(500);
  digitalWrite(11, HIGH); 
  delay(500);
  digitalWrite(11, LOW);
  delay(500);
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(11, LOW);
  delay(500);
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(11, LOW);
  //Step 4 Yellow once again
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  digitalWrite(9, LOW);
               
}
