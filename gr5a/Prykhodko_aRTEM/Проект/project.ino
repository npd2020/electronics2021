int delaytime = 100;
int letterdelaytime = 300;
int worddelaytime = 700;
int led = 7;
void setup() {
     pinMode(led, OUTPUT);
}
void loop() {
//this is where you write what the arduino will say in morse.
//write worddelaytime if you are doing another word.
s();
delay(letterdelaytime);
o();
delay(letterdelaytime);
s();

delay(100000000000000000000);
}//loop
void a() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseA

void b() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseB

void c() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseC

void d() {     
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseD

void e() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseE

void f() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseF

void g() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseG

void h() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseH

void i() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseL

void j() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseJ

void k() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseK

void l() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseL

void m() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseM
void n() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseN

void o() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseO

void p() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseP

void q() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseQ

void r() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseR

void s() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseS

void t() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseT

void u() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseU

void v() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseV

void w() {
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseW

void x() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseX

void y() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
}//morseY

void z() {
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(300);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100);
}//morseZ
