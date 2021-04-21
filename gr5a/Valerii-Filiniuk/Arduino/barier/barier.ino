int irsensor = 7;                   // Вывод OUT на модуле подключен к выходу 7 Arduino
int sensorvalue;                    // Переменная для хранения показаний датчика
int u = 0;// Установим вывод D0 как вход
bool flag = 0;

void setup()
{
  Serial.begin(9600);                // Задаем скорость передачи данных
  pinMode(irsensor, INPUT);
}

void loop()
{
  sensorvalue = digitalRead(irsensor); // Считываем показания в переменной sensorvalue.
  // Serial.print("Sensor ==");         // Выводим текст
  // Serial.println(sensorvalue);       // Выводим текст
  if ((sensorvalue == 1) && (flag == true))
  {
    flag = 0;
    digitalWrite(13, HIGH); 
    delay (10);                      // Ждем 500 мкс
  }
  if ((sensorvalue == 0) && (flag == 0))
  {
    u++;
    flag = 1;
    Serial.println(" Obstacle " + (String)u );      // Выводим текст
    digitalWrite(13, HIGH);            // Включаем светодиод
    delay (10);                       // Ждем 500 мкс
  }

}
