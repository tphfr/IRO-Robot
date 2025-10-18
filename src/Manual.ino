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

<<<<<<< HEAD


=======
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
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

<<<<<<< HEAD
FL(speed = 30); is forward, stopping when end of the line
BL(speed = 30); is backward, stopping when end of the line
=======
FE(speed = 30); is forward, stopping when end of the line
BE(speed = 30); is backward, stopping when end of the line
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986

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

<<<<<<< HEAD
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
=======
void F_(double speed = 55) {
  FF(speed, 'a');
  ToCenterC();
}

void f_(double speed = 55) {
  FF(speed, 'a');
  ToCenter();
}

void B_(double speed = 55) {
  BB(speed, 'a');
  BackCenterC();
}

void b_(double speed = 55) {
  BB(speed, 'a');
  BackCenter();
}

void R_(double angle = 0) {
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
  if (angle == 0) {
    SpinR();
  }
  spin('R', angle);
<<<<<<< HEAD
  delay(50);
}

void L(double angle = 0) {
=======
  //delay(50);
}

void L_(double angle = 0) {
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
  if (angle == 0) {
    SpinL();
  }
  spin('L', angle);
<<<<<<< HEAD
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
=======
  //delay(50);
}

void FS_(double speed = 30) {
  FF(speed, 's');
}

void BS_(double speed = 30) {
  BB(speed, 's');
}

void _S() {
  MotorStop();
}

void S_() {
  MotorStop();
}

void FE_(double Speed = 30) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[2] < Ref && F[5] < Ref && F[3] < Ref && F[4] < Ref)) {
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
      break;
    }
  }
  MotorStop();
}

<<<<<<< HEAD
void BL(double speed = 30) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref)) {
=======
void BE_(double Speed = 30) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((F[2] < Ref && F[5] < Ref && F[3] < Ref && F[4] < Ref)) {
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
      break;
    }
  }
  MotorStop();
}

void _F(int Distance) {
<<<<<<< HEAD
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
=======
  movement(Distance);
}

void _B(int Distance) {
  movement(-Distance);
}


void _R(int angle = 90) {
  spin('R', angle);
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
}

void _L(int angle = 90) {
  spin('L', angle);
}

<<<<<<< HEAD
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
=======
void _FR(double distance = 1) {
  movement(distance);
  spin('R', 90);
  movement(distance);
}

void _FL(double distance = 10) {
  movement(distance);
  spin('L', 90);
  movement(distance);
}

void _BR(double distance = 10) {
  movement(-distance);
  spin('L', 90);
  movement(-distance);
}

void _BL(double distance = 10) {
  movement(-distance);
  spin('R', 90);
  movement(-distance);
}

void P() {
  _B(3.3);
  ServoDown();
  delay(50);
  ServoClose();
  delay(50);
  ServoUp();
  delay(50);
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
}

void R() {
  ServoDown();
  delay(100);
  ServoOpen();
  delay(100);
  ServoUp();
  delay(100);
<<<<<<< HEAD
  ServoClose();
=======
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
}




//Fundamental Functions

void movement (double distance) {
  if (distance < 0) {
<<<<<<< HEAD
    Move(-15*k, -15*k, -distance * 6870);
    MotorStop();
    return;
  }
  Move(15*k, 15*k, distance * 6870);
=======
    Move(-15*k, -15*k, -distance * 68.7);
    MotorStop();
    return;
  }
  Move(15*k, 15*k, distance * 43.7);
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
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

<<<<<<< HEAD
void go(double meters, double speed = 30) {
  if (meters > 0) {
    FFtimer(speed, meters * 65600 / (speed));
  }
  else if (meters < 0) {
    BBtimer(speed, -meters * 65600 / (speed));
=======
void go(double cm, double speed = 30) {
  if (cm > 0) {
    FFtimer(speed, cm * 656 / (speed));
  }
  else if (cm < 0) {
    BBtimer(speed, -cm * 656 / (speed));
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
  }
  MotorStop();
}

<<<<<<< HEAD
=======
void got(double distance, double speed = 40) {
  double target = speed - 15;
  double traveldistance = distance * 2.0 / 3.0 - 5;

  // ---- Initial forward movement (fixed 5 units) ----
  Move(15*k, 15*k, 5 * 68.7 * (15.0 / 15.0));

  // ---- Acceleration phase (15 → speed) ----
  Move((15 + target/4)*k, (15 + target/4)*k, (traveldistance/6) * 68.7 * (15.0 / (15 + target/4)));
  Move((15 + target/2)*k, (15 + target/2)*k, (traveldistance/6) * 68.7 * (15.0 / (15 + target/2)));
  Move((15 + 3*target/4)*k, (15 + 3*target/4)*k, (traveldistance/6) * 68.7 * (15.0 / (15 + 3*target/4)));

  // ---- Max speed segment ----
  Move(speed*k, speed*k, (traveldistance/6) * 68.7 * (15.0 / speed));

  // ---- Deceleration phase (speed → 30) ----
  double decTarget = speed - 30;
  Move((speed - decTarget/2)*k, (speed - decTarget/2)*k, (traveldistance/6) * 68.7 * (15.0 / (speed - decTarget/2)));
  Move(30*k, 30*k, (traveldistance/6) * 68.7 * (15.0 / 30.0));

  MotorStop();
}


>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986


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

<<<<<<< HEAD
=======
//for small wave
void wavesmall() {
  FF(60,'p');
  go(32);
}

void RBIG () {
    FFL(60, 'l');
    FFR(60, 'R');
    FFL(60, 'l');
}

void LBIG () {
    FFR(60, 'r');
    FFL(60, 'L');
    FFR(60, 'r');
}

//for zigzag, char is first turn
void zigzag(char direction) {
  if (direction == 'R') {
  FFL(60, 'L');
  FFR(50, 'R');
  } else if (direction == 'L') {
  FFR(60, 'R');
  FFL(50, 'L');
  } else {
    // do nothing 
  }
}
>>>>>>> 8199dbe7b7320476617ac85cff020532c42c3986
