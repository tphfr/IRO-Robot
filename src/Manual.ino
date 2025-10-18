////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// คู่มือการใช้งาน ////////////////////////////////////////////////////////////////////////////////////////////

// OK(); // wait for sw OK
// START(); // wait for sw START


////////////////////////////////// คำสั่งเคลื่อนที่ ///////////////////////////////////////////////////////////////////
// Motor(ความเร็วมอเตอร์ซ้าย , ความเร็วมอเตอร์ขวา); // คำสั่งเคลื่อนที่มอเตอร์
// Move(ความเร็วมอเตอร์ซ้าย , ความเร็วมอเตอร์ขวา, เวลาที่ใช้ ); // คำสั่งเคลื่อนที่มอเตอร์พร้อม delay เวลาที่ใช้ หน่วย 1000 = 1วินาที


////////////////////////////////// คำสั่งเลี้ยว //////////////////////////////////////////////////////////////////
// >> SpinL();                 // หมุนหุ่นยนต์ด้านซ้าย
// >> SpinL2();                // หมุนหุ่นยนต์ด้านซ้าย 2 แยก
// >> SpinR();                 // หมุนหุ่นยนต์ด้านขวา
// >> SpinR2();                // หมุนหุ่นยนต์ด้านขวา 2 แยก

////////////////////////////////// คำสั่งวิ่งนับแยก //////////////////////////////////////////////////////////////////
// >> คำสั่งเจอแยก 'l' = กลางหุ่นหน้าเลี้ยวซ้าย , 'r' = กลางหุ่นหน้าเลี้ยวขวา  , 'p' = ตรง     , 's' = หยุด        , 'c' = กลางหุ่นหน้า
// >> คำสั่งเจอแยก 'L' = กลางหุ่นเลี้ยวซ้าย    , 'R' = กลางหุ่นเลี้ยวขวา      , 'C' = กลางหุ่น , 'q' = หน้าเลี้ยวซ้าย , 'e' = หน้าเลี้ยวขวา


// >> FF(ความเร็ว, 'คำสั่งเจอแยก');   // วิ่งตามเส้น PID ไปด้านหน้าเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่ใดก็ได้
// >> FFC(ความเร็ว, 'คำสั่งเจอแยก');  // วิ่งตามเส้น PID ไปด้านหน้าเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่กลาง
// >> FFL(ความเร็ว, 'คำสั่งเจอแยก');  // วิ่งตามเส้น PID ไปด้านหน้าเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่ซ้าย
// >> FFR(ความเร็ว, 'คำสั่งเจอแยก');  // วิ่งตามเส้น PID ไปด้านหน้าเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่ขวา
// >> FFNUM(ความเร็ว, 'คำสั่งเจอแยก', 0->7);  // วิ่งตามเส้น PID ไปด้านหน้าเจอแยกให้ทำตามคำสั่ง >> ตำแหน่งเซนเซอร์ที่ใช้จับแยก
// >> FF_DISTANCE(ความเร็ว, 'คำสั่งเจอแยก', 4->30);  // วิ่งตามเส้น PID ไปด้านหน้าเจอแยกให้ทำตามคำสั่ง >> ตำแหน่งเซนเซอร์วัดระยะ

// >> BB(ความเร็ว, 'คำสั่งเจอแยก');   // วิ่งตามเส้น PID ไปด้านหลังเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่ใดก็ได้
// >> BBC(ความเร็ว, 'คำสั่งเจอแยก');  // วิ่งตามเส้น PID ไปด้านหลังเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่กลาง
// >> BBL(ความเร็ว, 'คำสั่งเจอแยก');  // วิ่งตามเส้น PID ไปด้านหลังเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่ซ้าย
// >> BBR(ความเร็ว, 'คำสั่งเจอแยก');  // วิ่งตามเส้น PID ไปด้านหลังเจอแยกให้ทำตามคำสั่ง >>  ด้านเซนเซอร์ที่ใช้ เซนเซอร์คู่ขวา
// >> BBNUM(ความเร็ว, 'คำสั่งเจอแยก', 0->7);  // วิ่งตามเส้น PID ไปด้านหลังเจอแยกให้ทำตามคำสั่ง >> ตำแหน่งเซนเซอร์ที่ใช้จับแยก

// >> FFtimer(ความเร็ว,เวลา);  // วิ่งตามเส้นด้วย PID Timer ไปข้างหน้า
// >> BBtimer(ความเร็ว,เวลา);  // วิ่งตามเส้นด้วย PID Timer ไปข้างหลัง


////////////////////////////////// คำสั่ง Servo //////////////////////////////////////////////////////////////////
// >> ServoOpen();   // อ้าที่คีบ
// >> ServoClose();  // หนีบที่คีบ
// >> ServoUp();     // ยกที่คีบ
// >> ServoDown();   // วางที่คีบ



/*Manual

3 speeds:
variable B: 10 (for going into blocks)
variable C: 35 (for unsafe curves) (also when entering pushing/circle area)
variable D: 55 (for normal movement) (also default when speed not specified)

F(speed = 55); is forward, robot centered, f(); is forward, head centered
B(speed = 55); is backward, robot centered, b(); is backward, head centered
R(angle = 0); is turn right, stopping when see line at front, with angle is degrees to turn
L(angle = 0); is turn left, stopping when see line at front, with angle is degrees to turn

FS(speed = 30); is forward, stopping when see line at front
BS(speed = 30); is backward, stopping when see line at back
S(); is MotorStop();

FL(speed = 30); is forward, stopping when end of the line
BL(speed = 30); is backward, stopping when end of the line

_F(distance); is forward outside line
_B(distance); is backward outside line
_R(angle); is turn right, 90 by default
_L(angle); is turn left, 90 by default

_FR(multiplier); is FORWARD TURNRIGHT FORWARD, use multiplier if it moves not enough, multiplier 1 is 10cm per direction
_FL(multiplier); is FORWARD TURNLEFT FORWARD, use multiplier if it moves not enough, multiplier 1 is 10cm per direction
_BR(multiplier); is BACKWARD TURNRIGHT BACKWARD, use multiplier if it moves not enough, multiplier 1 is 10cm per direction
_BL(multiplier); is BACKWARD TURNLEFT BACKWARD, use multiplier if it moves not enough, multiplier 1 is 10cm per direction

P(); is pick up object
R(); is release object

LS(); is left S
RS(); is right S
LH(); is left Hook
RH(); is right Hook
*/

void F(double speed = 55) {
  FF(speed, 'a');
  ToCenterC();
  //delay(50);
}

void f(double speed = 55) {
  FF(speed, 'a');
  ToCenter();
  MotorStop();

void B(double speed = 55) {
  BB(speed, 'a');
  ToCenterC();
  delay(50);
}

void b(double speed = 55) {
  BB(speed, 'a');
  ToCenter();
  MotorStop();
}

void R(double angle = 0) {
  if (angle == 0) {
    SpinR();
  }
  spin('R', angle);
  delay(50);
}

void L(double angle = 0) {
  if (angle == 0) {
    SpinL();
  }
  spin('L', angle);
  delay(50);
}

void FS(double speed = 30) {
  FF(speed, 's');
}

void BS(double speed = 30) {
  BB(speed, 's');
}

void S() {
  MotorStop();
}

void FL(double speed = 30) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[0] > Ref && F[7] > Ref)) {
      break;
    }
  }
  MotorStop();
}

void BL(double speed = 30) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref)) {
      break;
    }
  }
  MotorStop();
}

void _F(int Distance) {
  movement(Distance * 0.01);
  MotorStop();
}

void _B(int Distance) {
  movement(-Distance * 0.01);
  MotorStop();
}

void _R(int angle = 90) {
  spin('R', angle);
  MotorStop();
}

void _L(int angle = 90) {
  spin('L', angle);
}

void _FR(int multiplier = 1) {
  movement(0.1 * multiplier);
  spin('R', 90);
  movement(0.1 * multiplier);
}

void _FL(int multiplier = 1) {
  movement(0.1 * multiplier);
  spin('L', 90);
  movement(0.1 * multiplier);
}

void _BR(int multiplier = 1) {
  movement(-0.1 * multiplier);
  spin('L', 90);
  movement(-0.1 * multiplier);
}

void _BL(int multiplier = 1) {
  movement(-0.1 * multiplier);
  spin('R', 90);
  movement(-0.1 * multiplier);
}

void P() {
  _B(10);
  ServoOpen();
  delay(100);
  ServoDown();
  delay(100);
  _F(5);
  delay(100);
  _F(5);
  ServoClose();
  delay(100);
  ServoUp();
  delay(100);
}

void R() {
  ServoDown();
  delay(100);
  ServoOpen();
  delay(100);
  ServoUp();
  delay(100);
  ServoClose();
}




//Fundamental Functions

void movement (double distance) {
  if (distance < 0) {
    Move(-15*k, -15*k, -distance * 6870);
    MotorStop();
    return;
  }
  Move(15*k, 15*k, distance * 6870);
  MotorStop();
}

void spin(char direction, double angle) {
  if (direction == 'R') {
  Move(30*k*21/20, -30*k*21/20, angle * 2.665);
  MotorStop();
  } else if (direction == 'L') {
  Move(-30*k*21/20, 30*k*21/20, angle * 2.665);
  MotorStop();
  } else {
    // do nothing 
  }
  MotorStop();
}

void go(double meters, double speed = 30) {
  if (meters > 0) {
    FFtimer(speed, meters * 65600 / (speed));
  }
  else if (meters < 0) {
    BBtimer(speed, -meters * 65600 / (speed));
  }
  MotorStop();
}



//Pre-made Functions

//Left S
void LS() {
  FFR(50, 'r');
  FFL(50, 'l');
}

//Right S
void RS() {
  FFL(50, 'l'); 
  FFR(50, 'r');
  }

//Left Hook
void LH() {
  FFR(55, 'R');
  FFL(55, 'L');
}

//Right Hook
void RH() {
  FFL(55, 'L'); 
  FFR(55, 'R');
}

