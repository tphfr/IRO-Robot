#include "UnknowMotor.h"
#include "UnknowSensor.h"
#include "UnknowTurn.h"

int LastError_F, LastError_B;
int Error_F = 0, Error_B = 0;
double k;

void setk(double a) {
  k = a;
}

int readPositionF(int Track, int noise) {
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrateF();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = F[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}



int readPositionB(int Track, int noise) {
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrateB();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = B[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}

void PIDF(int Speed, float Kp, float Kd) {
  Speed *= k;
  int Pos = readPositionF(250, 50);
  int Error = Pos - 3500;
  int PID_Value = (Kp * Error) + (Kd * (Error - LastError_F));
  LastError_F = Error;
  int LeftPower = Speed + PID_Value;
  int RightPower = Speed - PID_Value;
  if (LeftPower > 100) LeftPower = 100;
  if (LeftPower < 0) LeftPower = -5;
  if (RightPower > 100) RightPower = 100;
  if (RightPower < 0) RightPower = -5;
  Motor(LeftPower, RightPower);
}

void PIDB(int Speed, float Kp, float Kd) {
  Speed *= k;
  int Pos = readPositionB(250, 50);
  int Error = Pos - 3500;
  int PID_Value = (Kp * Error) + (Kd * (Error - LastError_B));
  LastError_B = Error;
  int LeftPower = Speed + PID_Value;
  int RightPower = Speed - PID_Value;
  if (LeftPower > 100) LeftPower = 100;
  if (LeftPower < 0) LeftPower = 0;
  if (RightPower > 100) RightPower = 100;
  if (RightPower < 0) RightPower = 0;
  Motor(-LeftPower, -RightPower);
}

void FFtimer(int baseSpeed, int totalTime) {
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDF(baseSpeed, PID_KP, PID_KD);
  }
}

void BBtimer(int baseSpeed, int totalTime) {
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDB(baseSpeed, PID_KP, PID_KD);
  }
}

///////////////////////////////////////////////////////////////////////////////////////
void TrackSelectF(int spd, char x) {
  if (x == 's'||x == 'S') {
    MotorStop();
  } else if (x == 'p') {
    Motor(spd, spd);
    delay(20);
    ReadCalibrateF();
    while (1) {
      Motor(spd, spd);
      ReadCalibrateF();
      if (F[1] < Ref && F[6] < Ref) {
        break;
      }
    }
  } else if (x == 'l') {
    ToCenter();
    SpinL();
  } else if (x == 'L') {
    ToCenterC();
    SpinL();
  } else if (x == 'r') {
    ToCenter();
    SpinR();
  } else if (x == 'R') {
    ToCenterC();
    SpinR();
  } else if (x == 'q') {
    while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[0] < Ref) {
        break;
      }
    }
    TurnLeft();
  } else if (x == 'e') {
    while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[7] < Ref) {
        break;
      }
    }
    TurnRight();
  } else if (x == 'c') {
    ToCenter();
  } else if (x == 'C') {
    ToCenterC();
  } else if (x == 'b') {
    ToCenterCB();
  } else if (x == 'P') {
    Motor(spd, spd);
    delay(30);
  } 
}

void TrackSelectFR(int spd, char x) {
  if (x == 's'||x == 'S') {
    MotorStop();
  } else if (x == 'p') {
    Motor(spd, spd);
    delay(30);
    ReadCalibrateF();
    while (1) {
      PIDF(spd, PID_KP, PID_KD);
      ReadCalibrateF();
      if (F[1] < Ref && F[6] < Ref) {
        break;
      }
    }
  } else if (x == 'l') {
    ToCenterR();
    SpinL();
  } else if (x == 'L') {
    ToCenterCR();
    SpinL();
  } else if (x == 'r') {
    ToCenterR();
    SpinR();
  } else if (x == 'R') {
    ToCenterCR();
    SpinR();
  } else if (x == 'q') {
     while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[0] < Ref ) {
        break;
      }
    }
    TurnLeft();
  } else if (x == 'e') {
    while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[7] < Ref) {
        break;
      }
    }
    TurnRight();
  } else if (x == 'c') {
    ToCenterR();
  } else if (x == 'C') {
    ToCenterCR();
  }
}

void TrackSelectFL(int spd, char x) {
  if (x == 's'||x == 'S') {
    MotorStop();
  } else if (x == 'p') {
    Motor(spd, spd);
    delay(30);
    ReadCalibrateF();
    while (1) {
      PIDF(spd, PID_KP, PID_KD);
      ReadCalibrateF();
      if (F[1] < Ref && F[6] < Ref) {
        break;
      }
    }
  } else if (x == 'l') {
    ToCenterL();
    SpinL();
  } else if (x == 'L') {
    ToCenterCL();
    SpinL();
  } else if (x == 'r') {
    ToCenterL();
    SpinR();
  } else if (x == 'R') {
    ToCenterCL();
    SpinR();
  } else if (x == 'q') {
     while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[0] < Ref ) {
        break;
      }
    }
    TurnLeft();
  } else if (x == 'e') {
     while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if ( F[7] < Ref) { 
        break;
      }
    }
    TurnRight();
  } else if (x == 'c') {
    ToCenterL();
  } else if (x == 'C') {
    ToCenterCL();
  }
}


void TrackSelectB(int spd, char x) {
  if (x == 's'||x == 'S') {
    MotorStop();
  } else if (x == 'p') {
    Motor(-spd, -spd);
    delay(20);
    while (1) {
      Motor(-spd, -spd);
      ReadCalibrateB();
      if ((B[1] < Ref && B[6] < Ref)) {
        Motor(-spd, -spd);
        delay(5);
        break;
      }
    }
  } else if (x == 'l') {
    BackCenter();
    SpinL();
  } else if (x == 'L') {
    BackCenterC();
    SpinL();
  } else if (x == 'r') {
    BackCenter();
    SpinR();
  } else if (x == 'R') {
    BackCenterC();
    SpinR();
  } else if (x == 'c') {
    BackCenter();
  } else if (x == 'C') {
    BackCenterC();
  }
}

void FF(int Speed, char select) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[0] > Ref && F[7] > Ref) || (F[0] > Ref && F[2] > Ref) || (F[5] > Ref && F[7] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFC(int Speed, char select) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[0] > Ref && F[7] > Ref)||(F[1] > Ref && F[6] > Ref)||(F[2] > Ref && F[3] > Ref&& F[4] > Ref&& F[5] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFL(int Speed, char select) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[0] > Ref && F[2] > Ref)) {
      break;
    }
  }
  TrackSelectFL(Speed, select);
}

void FFL2(int Speed, char select) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if (F[0] > Ref && F[1] > Ref && F[2] > Ref && F[3] > Ref ) {
      break;
    }
  }
  TrackSelectFL(Speed, select);
}

void FFR(int Speed, char select) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[5] > Ref && F[7] > Ref)) {
      break;
    }
  }
  TrackSelectFR(Speed, select);
}


void FFR2(int Speed, char select) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if (F[4] > Ref && F[5] > Ref && F[6] > Ref && F[7] > Ref) {
      break;
    }
  }
  TrackSelectFR(Speed, select);
}

void FFWhite(int Speed, char select) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[0] < Ref && F[1] < Ref&& F[2] < Ref&& F[3] < Ref&& F[4] < Ref&& F[5] < Ref&& F[6] < Ref && F[7] < Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFBlack(int SpeedL,int SpeedR, char select) {
  Move(SpeedL,SpeedR,50);
  while (1) {
    Motor(SpeedL,SpeedR);
    ReadCalibrateF();
    if (F[2] > Ref || F[3] > Ref || F[4] > Ref || F[5] > Ref) {
      break;
    }
  }
  TrackSelectF(SpeedL, select);
}

void FFNUM(int Speed, char select, int numm) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    ReadCalibrateF();
    if ((F[numm] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FF_DISTANCE(int Speed, char select, int DisT) {
  while (1) {
    PIDF(Speed, PID_KP, PID_KD);
    if (DistanceValue() >= 4 and DistanceValue() <= DisT) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}


void BB(int Speed, char select) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((B[0] > 200 && B[7] > 200) || (B[0] > 200 && B[2] > 200) || (B[5] > 200 && B[7] > 200)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBC(int Speed, char select) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref)||(B[1] > Ref && B[6] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBL(int Speed, char select) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((B[0] > Ref && B[2] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBR(int Speed, char select) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((B[5] > Ref && B[7] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBNUM(int Speed, char select, int numm) {
  while (1) {
    PIDB(Speed, PID_KP, PID_KD);
    ReadCalibrateB();
    if ((B[numm] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}
