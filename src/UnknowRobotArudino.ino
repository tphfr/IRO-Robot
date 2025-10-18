#include <UnknowStormXIGathering2.h>
void setup() {
  RobotSetup();
  // CalibrateSensor();  // >> Calibrate Robot Senso99r <<
  LightValue_FrontSensor(57, 57, 56, 56, 53, 56, 53, 58, 665, 733, 603, 694, 550, 590, 558, 718);
  LightValue_BackSensor(61, 57, 58, 55, 56, 56, 58, 57, 797, 733, 732, 621, 717, 629, 733, 677);
  LightValue_CenterSensor(53, 57, 54, 52, 55, 55, 573, 717, 653, 526, 665, 544);
  RefLineValue(300);        // ค่าในการจับเส้น เซนเซอร์หน้า หลัง
  RefCenterLineValue(300);  // ค่าในการจับเส้น เซนเซอร์คู่กลาง

  SetToCenterSpeed(40);      // ความเร็วเข้ากลางหุ่น
  SetTurnSpeed(35);          // ความเร็วเลี้ยวเข้าแยก
  SetRobotPID(0.014, 0.04);  // ค่า PID

  TurnSpeedLeft(25, 80, 50);
  TurnSpeedRight(80, 25, 50);

  BalanceMotorLeft = 0;
  BalanceMotorRight = 0;

  setOpen(125, 55);
  setClose(140, 45);
  setCloseSmall(73, 107); // left side less is close right side more is close
  setUpDowm(180, 130, 95);

  ////////////////////////////////////////////////////////////////////
  //////////////////////////////เช็คค่าเซนเซอร์//////////////////////////
  // SerialDistance();                // Serial Monitor เซนเซอร์วัดระยะ
  // Serial_FrontSensor();            // Serial Monitor เซนเซอร์หน้า
  // Serial_BackSensor();             // Serial Monitor เซนเซอร์หลัง
  // Serial_CenterSensor();           // Serial Monitor เซนเซอร์กลาง
  // SerialCalibrate_FrontSensor();   // Serial Monitor เซนเซอร์หน้า คาริเบทแล้ว
  // SerialCalibrate_BackSensor();    // Serial Monitor เซนเซอร์หลัง คาริเบทแล้ว
  // SerialCalibrate_CenterSensor();  // Serial Monitor เซนเซอร์กลาง คาริเบทแล้ว
  ////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////

  ServoOpen();
  ServoClose();
  OK();

//Calibration
//spin('R',180);
//OK();

}











































void loop() {
  while (1) {
    MotorStop();
    delay(100);
  }
  
  while(1) {  // Run continuously
        if(SW_START()) {  // Check if START button is pressed
            R(180);       // Turn 180 degrees
            while(SW_START()) {  // Wait for button release
                delay(10);
            }
            delay(500);   // Debounce delay
        }
    }
}

//for small wave
void wavesmall() {
  FF(60,'p');
  go(30,0.32);
}

//for big wave, char is first turn
void wavebig(char direction) {
  if (direction == 'R') {
  FFL(60, 'l');
  FFR(60, 'R');
  FFL(60, 'l');
  } else if (direction == 'L') {
  FFR(60, 'r');
  FFL(60, 'L');
  FFR(60, 'r');
  } else {
    // do nothing 
  }
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

// move on line for certain meters at certain speed, 60 for default


