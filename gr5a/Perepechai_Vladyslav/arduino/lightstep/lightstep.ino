#define PBP     2
#define MBP    3
#define LP             9

int brightness = 100;
boolean plusUp = true;
boolean minusUp = true;

void setup()
{
  pinMode(LP, OUTPUT);
  pinMode(PBP, INPUT_PULLUP);
  pinMode(MBP, INPUT_PULLUP);
}

void loop()
{
  analogWrite(LP, brightness);
  //реакція на нажимання за допомогою функції написаної нами
  plusUp = handleClick(PBP, plusUp, +35);
  minusUp = handleClick(MBP, minusUp, -35);
}
// Собственная функция с 3 параметрами: номером пина с кнопкой
// (buttonPin), состоянием до проверки (wasUp) и градацией
// яркости при клике на кнопку (delta). Функция возвращает
// (англ. return) обратно новое, текущее состояние кнопки
boolean handleClick(int buttonPin, boolean wasUp, int delta)
{
  boolean isUp = digitalRead(buttonPin);
  if (wasUp && !isUp) {
    delay(10);
    isUp = digitalRead(buttonPin);
    // если был клик, меняем яркость в пределах от 0 до 255
    if (!isUp)    
      brightness = constrain(brightness + delta, 0, 255);
  }
  return isUp; // возвращаем значение обратно, в вызывающий код
}
