#define RED_PIN 11
#define BLUE_PIN 10
#define GREEN_PIN 9

int red_on = 3000;
int red_yellow_on = 1000;
int green_on = 3000;
int green_blink = 500;
int yellow_on = 3000;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RED_PIN, HIGH);
  delay(red_on);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  delay(red_yellow_on);
  

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(green_on);
  digitalWrite(GREEN_PIN, LOW);
  
  for(int i = 0; i < 3; i = i+1)
  {
    delay(green_blink);
    digitalWrite(GREEN_PIN, HIGH);
    delay(green_blink);
    digitalWrite(GREEN_PIN, LOW);
  }

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  delay(yellow_on);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW); 
 
}
