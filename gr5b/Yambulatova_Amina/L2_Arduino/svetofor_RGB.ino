#define RED_PIN 11  
#define GREEN_PIN 9 
#define BLUE_PIN 10  
 
void setup() {
   pinMode(RED_PIN, OUTPUT);  
   pinMode(GREEN_PIN, OUTPUT); 
   pinMode(BLUE_PIN, OUTPUT);  
}
 
void loop() {
 
   digitalWrite(RED_PIN, HIGH); 
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, LOW);
 
   delay(1000); 

   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW); 

   delay(1000); 
  
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW);

   delay(1000); 
}
