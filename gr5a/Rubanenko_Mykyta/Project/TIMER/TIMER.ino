#include <TimerOne.h>
#include <MultiFuncShield.h>

int Mode = 0;
int seconds = 0;
int minutes = 0;

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
  MFS.write(0);
  
  Serial.begin(9600);
}


void loop() {
  byte btn = MFS.getButton();  
  switch (Mode)
  {
    case 0:
        if (btn == BUTTON_1_SHORT_RELEASE && (minutes + seconds) > 0)
        {
          Mode = 1;
        }
        else if (btn == BUTTON_1_LONG_PRESSED)
        {
          seconds = 0;
          minutes = 0;
          MFS.write(minutes*100 + seconds);
        }
        else if (btn == BUTTON_2_PRESSED)
        {
          minutes++;
          if (minutes > 60)
          {
            minutes = 0;
          }
          MFS.write(minutes*100 + seconds);
        }
        else if (btn == BUTTON_3_PRESSED)
        {
          seconds += 1;
          if (seconds >= 60)
          { 
            minutes++;
            seconds = 0;
          }
          MFS.write(minutes*100 + seconds);
        }
        break;
        
    case 1:
        if (btn == BUTTON_1_SHORT_RELEASE)
        {
          seconds++;
          Mode = 0;
        }
        else
        {
          seconds--;
            
            if (seconds < 0 && minutes > 0)
            {
              seconds = 59;
              minutes--;
            }
            
            if (minutes == 0 && seconds == 0)
            {
              MFS.beep(100,50,3);
              MFS.write("End");
              delay(3000);
              Mode = 0;
            }
            MFS.write(minutes*100 + seconds);
          }
          delay(1000);
        
        break;
  }
}
