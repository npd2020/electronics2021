#define measures 10
#define sampleWindow 50               // Время измерения в мс

unsigned int sample;
int count = -1;
unsigned long lastRead = 0;
float inters[measures];
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
    while (Serial.available()) Serial.read();
    result();
  }
//   Cохраняем текущие значение millis в startMillis
  unsigned long startMillis = millis();
  //Создаем переменною peakToPeak, где храним разницу между минимальным и максимальным сигналом
  unsigned int peakToPeak = 0;

 //  signalMax максимальным значением
  unsigned int signalMax = 0;
  // signalMin минимальным значением
  unsigned int signalMin = 1024;

//   Пока в startMillis содержащиеся больше заданного sampleWindow, выполняется код в цикле while
  while (millis() - startMillis < sampleWindow)
  {
//     Сохраняем значение переменной sample считанное с аналогового входе 0
  sample = analogRead(0);
  //  Serial.println(sample);
    // Если значение sample меньше 1024, то есть максимальное значение, читаемое на аналоговом порту
    if (sample < 1024)
    {
      // Если значение sample больше максимального значения, найденного в signalMax
      if (sample > signalMax)
      {
        // Обновление значения signalMax, содержащимся в sample
        signalMax = sample;
      }
      //  В противном случае, если значение sample меньше, чем signalMin
      else if (sample < signalMin)
      {
        // Обновление значения signalMin, содержащимся в sample
        signalMin = sample;
      }
    }
  }
  //  В переменной peakToPeak будет хранится разницу между максимальным значением и минимальным значением.
  peakToPeak = signalMax - signalMin;
  // Значение peakToPeak умножается на 5 - это напряжение, с которым работает Arduino, а затем делим на 1024, поскольку на аналоговом порту от 0 до 1024.
  double volts = (peakToPeak * 5.0) / 1024;

  unsigned int inter = millis() - lastRead;
  if ((volts > 2.1) && (inter > 500) && (count < measures))
  {
    
    Serial.println("Clap!" + (String)millis());
    inters[count + 1] = inter; 
    count++;
  }
}

void result() {
  bool valid = 1;
  float diss[measures - 1];
  float lastEn = inters[0] * inters[0];
  for (int i = 0; i < measures - 1; i++) {
    if (inters[i + 1] == 0) {
      valid = 0;
      break;
    }
    float newEn = inters[i + 1] * inters[i + 1];
    diss[i] = newEn / lastEn;
    lastEn = newEn;
  }

  if (valid) {
    Serial.println("* * *");
    Serial.print("Energy dissipation: ");
    for (int i = 0; i < measures - 1; i++) {
      Serial.print(diss[i], 2);
      Serial.print(' ');
    }
    Serial.println();

    float mean = 0;
    for (int i = 0; i < measures - 1; i++) mean += diss[i];
    mean /= measures - 1;

    Serial.println("Average: " + (String)mean);
  } else Serial.println("Invalid results!!");

  count = -1;
  for (int i = 0; i < measures; i++) inters[i] = 0;
}
