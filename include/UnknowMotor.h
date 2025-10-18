int BalanceMotorLeft, BalanceMotorRight;

#define PH1 4  // พินควบคุมทิศทาง
#define EN1 5  // พินควบคุมความเร็ว (PWM)

#define PH2 7  // พินควบคุมทิศทาง
#define EN2 6  // พินควบคุมความเร็ว (PWM)

void Motor1(int Pow) {
  bool dir = (Pow >= 0 ? true : false);
  Pow = abs(Pow);
  Pow = (Pow * 255) / 100;
  digitalWrite(PH1, dir);
  analogWrite(EN1, Pow);
}

void Motor2(int Pow) {
  bool dir = (Pow >= 0 ? true : false);
  Pow = abs(Pow);
  Pow = (Pow * 255) / 100;
  digitalWrite(PH2, dir);
  analogWrite(EN2, Pow);
}

void Motor(int leftsp, int rightsp) {
  Motor2(rightsp + BalanceMotorRight);
  Motor1(leftsp + BalanceMotorLeft);
}

void Move(int l, int r, int deelay) {
  Motor(l, r);
  delay(deelay);
}




void MotorStop() {
  analogWrite(EN1, 0);  
  analogWrite(EN2, 0);
  delay(5);
}