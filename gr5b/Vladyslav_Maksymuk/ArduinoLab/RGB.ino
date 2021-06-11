int redPin = 11;

int greenPin = 10;

int bluePin = 9;

void setup()

{

pinMode(redPin, OUTPUT);

pinMode(greenPin, OUTPUT);

pinMode(bluePin, OUTPUT);

}

void loop()

{
delay(1200);

setColor(150, 93, 175); // св Фіолет

delay(10000);

setColor(65, 17, 15); // коричневий

delay(10000);

setColor(255, 0, 250); // розовий

delay(1000);

setColor(20, 249, 207); // бірюза

delay(1000);

setColor(255, 60, 0); // оранжевий

delay(1000);

setColor(255, 255, 255); // білий

delay(1000);

setColor(0x4A, 0x5, 0x82); // індіго

delay(1000);

setColor(255, 0, 0); // красный

delay(1000);


setColor(0, 255, 0); // зеленый

delay(1000);


setColor(0, 0, 255); // синий

delay(1000);

setColor(80, 0, 80); // фиолетовый

delay(1000);

setColor(0, 255, 255); // аквамарин

delay(10000);

}

void setColor(int red, int green, int blue)

{
analogWrite(redPin, red);

analogWrite(greenPin, green);

analogWrite(bluePin, blue);

}
