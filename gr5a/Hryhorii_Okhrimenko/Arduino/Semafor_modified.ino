#define RED_PIN 9
#define GREEN_PIN 11 

int red_on = 3000;
int yellow_on = 1000;
int green_on = 3000;
int green_blink = 500;
void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //Step 1
  digitalWrite(RED_PIN, HIGH);   // red, 3 sec
  delay(red_on);                   
  digitalWrite(GREEN_PIN, HIGH);    // yellow, 1 sec
  delay(yellow_on);  
  //Step 2    
  
  digitalWrite(RED_PIN, LOW);   // red, off                     
  digitalWrite(GREEN_PIN, LOW);    // yellow, off
  digitalWrite(GREEN_PIN, HIGH);   // green, 3 sec
  delay(green_on);                       
  digitalWrite(GREEN_PIN, LOW);    // green, off
  //Step 3 Green on & off for half-second
  for (int i =0; i<3; i++)
  {
  delay(green_blink);
  digitalWrite(GREEN_PIN, HIGH); 
  delay(green_blink);
  digitalWrite(GREEN_PIN, LOW);
  }
  
  //Step 4 Yellow once again
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  delay(yellow_on);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
               
}
