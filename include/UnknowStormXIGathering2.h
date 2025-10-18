#include "UnknowPID.h"
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
int OpenL,OpenR;
int CloseL ,CloseR;
int CloseLSmall ,CloseRSmall;
int Up,Up45,Down;
int OpenL2,OpenR2;
int OpenRMax,OpenLMax;
void RobotSetup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  servo1.attach(A0); // ต่อเซอร์โวตัวแรกที่ขา A0
  servo2.attach(A1); // ต่อเซอร์โวตัวที่สองที่ขา A1
  servo3.attach(A2); // ต่อเซอร์โวตัวที่สามที่ขา A2
  float a = analogRead(A3);
  a *= 5;
  float m = 11.1/a;
  Beep(50);
  delay(500);
  delay(200);
  delay(10);
  Beep(50);
  delay(50);
  Beep(50);

}


void Servo(int Ch, int Degree) {
  if(Ch == 0 )servo1.write(Degree);
  if(Ch == 1 )servo2.write(Degree);
  if(Ch == 2 )servo3.write(Degree);
}

void setOpen(int degree1,int degree2){
  OpenL = degree1;
  OpenR = degree2;
}

void setOpen2(int degree1,int degree2){
  OpenL2 = degree1;
  OpenR2 = degree2;
}

void setOpenMax(int degree1,int degree2){
  OpenLMax = degree1;
  OpenRMax = degree2;
}

void setClose(int degree1,int degree2){
  CloseL = degree1;
  CloseR = degree2;
}

void setCloseSmall(int degree1,int degree2){
  CloseLSmall = degree1;
  CloseRSmall = degree2;
}

void setUpDowm(int degree1,int degree2,int degree3){
  Up = degree1; 
  Up45 = degree2;
  Down = degree3;
}




