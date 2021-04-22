import processing.serial.*;

Serial port;

float g;
float h;
float distance;
String data="";
int index = 0;
int index2 = 0;
int xpos = 0;
int ypos= 0;


void setup()
{
 size (1200,600);
 port = new Serial(this , "COM6",9600);
 port.bufferUntil(';');
 background(255,255,255);
}

void draw()
{
if(distance<50){fill(distance,0,0);}
if(50<distance && distance<=150){fill(0,distance,0);};
if(distance>150){fill(0,0,distance);};

noStroke();
rect(xpos,ypos,5,5);

  
}

void serialEvent(Serial port)
{
data = port.readStringUntil(';');
data = data.substring(0,data.length() - 1);

index = data.indexOf(':');
index2 = data.indexOf(':',index+1);



g = 5*int(data.substring(0,index));
h = 5*int(data.substring(index+1,index2));


distance = float(data.substring(index2+1, data.length()));

xpos= int(g);
ypos= int(h);
 
xpos=-xpos+600;
ypos=100+ypos;

println(distance);
}
