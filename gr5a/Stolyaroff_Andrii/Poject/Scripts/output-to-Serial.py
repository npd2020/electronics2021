import serial
import time
import subprocess
from serial.serialposix import Serial
waitingForReply = False
link = serial.Serial(port='/dev/ttyUSB0', baudrate=115200)
file = open("frames.csv", "r")
for i in range(3, 0, -1):
   print(i)
   time.sleep(1)
data = file.readlines()
print(0)
subprocess.Popen(['vlc-ctrl', 'play']) # Vlc Auto Play
time.sleep(0.4)
for i in data:
    while not link.writable():
      pass
    print(i)
    link.write(i.encode('utf-8'))
    time.sleep(0.0332)
    
