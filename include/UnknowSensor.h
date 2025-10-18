
#include "Adafruit_MCP3008.h"
Adafruit_MCP3008 adc;
#define NUM_SENSORS 8

uint8_t OK_PIN = 6;
uint8_t START_PIN = 7;

uint8_t sck = 13;
uint8_t miso = 12;
uint8_t mosi = 11;
uint8_t ssf = 10;
uint8_t ssb = 9;
uint8_t ssa = 8;

uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
uint8_t B_PIN[NUM_SENSORS] = { 7, 6, 5, 4, 3, 2, 1, 0 };
uint8_t C_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };

int F[NUM_SENSORS], B[NUM_SENSORS], C[NUM_SENSORS];
int F_REF[NUM_SENSORS], C_REF[NUM_SENSORS], B_REF[NUM_SENSORS];

int minValueF[NUM_SENSORS], maxValueF[NUM_SENSORS];
int minValueC[NUM_SENSORS], maxValueC[NUM_SENSORS];
int minValueB[NUM_SENSORS], maxValueB[NUM_SENSORS];

int Ref = 0;
int RefC = 0;

void LightValue_FrontSensor(uint16_t minF0, uint16_t minF1, uint16_t minF2, uint16_t minF3, uint16_t minF4, uint16_t minF5, uint16_t minF6, uint16_t minF7, uint16_t maxF0, uint16_t maxF1, uint16_t maxF2, uint16_t maxF3, uint16_t maxF4, uint16_t maxF5, uint16_t maxF6, uint16_t maxF7) {
  minValueF[0] = minF0;
  minValueF[1] = minF1;
  minValueF[2] = minF2;
  minValueF[3] = minF3;
  minValueF[4] = minF4;
  minValueF[5] = minF5;
  minValueF[6] = minF6;
  minValueF[7] = minF7;

  maxValueF[0] = maxF0;
  maxValueF[1] = maxF1;
  maxValueF[2] = maxF2;
  maxValueF[3] = maxF3;
  maxValueF[4] = maxF4;
  maxValueF[5] = maxF5;
  maxValueF[6] = maxF6;
  maxValueF[7] = maxF7;
}

void LightValue_CenterSensor(uint16_t minC0, uint16_t minC1, uint16_t minC2, uint16_t minC3, uint16_t minC4, uint16_t minC5, uint16_t maxC0, uint16_t maxC1, uint16_t maxC2, uint16_t maxC3, uint16_t maxC4, uint16_t maxC5) {
  minValueC[0] = minC0;
  minValueC[1] = minC1;
  minValueC[2] = minC2;
  minValueC[3] = minC3;
  minValueC[4] = minC4;
  minValueC[5] = minC5;

  maxValueC[0] = maxC0;
  maxValueC[1] = maxC1;
  maxValueC[2] = maxC2;
  maxValueC[3] = maxC3;
  maxValueC[4] = maxC4;
  maxValueC[5] = maxC5;
}

void LightValue_BackSensor(uint16_t minB0, uint16_t minB1, uint16_t minB2, uint16_t minB3, uint16_t minB4, uint16_t minB5, uint16_t minB6, uint16_t minB7, uint16_t maxB0, uint16_t maxB1, uint16_t maxB2, uint16_t maxB3, uint16_t maxB4, uint16_t maxB5, uint16_t maxB6, uint16_t maxB7) {
  minValueB[0] = minB0;
  minValueB[1] = minB1;
  minValueB[2] = minB2;
  minValueB[3] = minB3;
  minValueB[4] = minB4;
  minValueB[5] = minB5;
  minValueB[6] = minB6;
  minValueB[7] = minB7;

  maxValueB[0] = maxB0;
  maxValueB[1] = maxB1;
  maxValueB[2] = maxB2;
  maxValueB[3] = maxB3;
  maxValueB[4] = maxB4;
  maxValueB[5] = maxB5;
  maxValueB[6] = maxB6;
  maxValueB[7] = maxB7;
}

///////////////////////////////////////////////////////////////////////////////////////
void ReadF() {
  for (int _sensor = 0; _sensor < NUM_SENSORS; _sensor++) {
    digitalWrite(ssb, HIGH);
    digitalWrite(ssa, HIGH);
    adc.begin(sck, mosi, miso, ssf);
    F[_sensor] = adc.readADC(F_PIN[_sensor]);
  }
}

void ReadB() {
  for (int _sensor = 0; _sensor < NUM_SENSORS; _sensor++) {
    digitalWrite(ssf, HIGH);
    digitalWrite(ssa, HIGH);
    adc.begin(sck, mosi, miso, ssb);
    B[_sensor] = adc.readADC(B_PIN[_sensor]);
  }
}

void ReadC() {
  for (int _sensor = 0; _sensor < NUM_SENSORS; _sensor++) {
    digitalWrite(ssf, HIGH);
    digitalWrite(ssb, HIGH);
    adc.begin(sck, mosi, miso, ssa);
    C[_sensor] = adc.readADC(C_PIN[_sensor]);
  }
}



void ReadCalibrateF() {
  ReadF();
  for (int i = 0; i < NUM_SENSORS; i++) {
    int x = map(F[i], minValueF[i], maxValueF[i], 0, 1000);
    if (x < 0) x = 0;
    if (x > 1000) x = 1000;
    F[i] = x;
  }
}

void ReadCalibrateC() {
  ReadC();
  for (int i = 0; i < NUM_SENSORS; i++) {
    int x = map(C[i], minValueC[i], maxValueC[i], 0, 1000);
    if (x < 0) x = 0;
    if (x > 1000) x = 1000;
    C[i] = x;
  }
}

void ReadCalibrateB() {
  ReadB();
  for (int i = 0; i < NUM_SENSORS; i++) {
    int x = map(B[i], minValueB[i], maxValueB[i], 0, 1000);
    if (x < 0) x = 0;
    if (x > 1000) x = 1000;
    B[i] = x;
  }
}

void ReadSensor() {
  ReadCalibrateF();
  ReadCalibrateB();
  ReadCalibrateC();
}

void ReadSensorRaw() {
  ReadF();
  ReadB();
  ReadC();
}

void RefLineValue(int x) {
  Ref = x;
}

void RefCenterLineValue(int x) {
  RefC = x;
}

///////////////////////////////////////////////////////////////////////////////////////
void BEEP(int beepC, int beeptime, int beepsleep) {



}



void Beep(int delayb) {
   tone(2, 900, delayb);
  delay(delayb);
  noTone(2);
}

///////////////////////////////////////////////////////////////////////////////////////

int OK_PUSH() {
  ReadC();
  if (C[6] < 500) return 0;
  else {
    return 1;
  }
}

int START_PUSH() {
  ReadC();
  if (C[7] < 500) return 0;
  else {
    return 1;
  }
}

void OK() {
  while (1) {
    ReadSensorRaw();
    if (C[OK_PIN] < 500) {
      break;
    }
  }
  Beep(500);
}

void START() {
  while (1) {
    ReadSensorRaw();
    if (C[START_PIN] < 500) {
      break;
    }
  }
  Beep(200);
}
///////////////////////////////////////////////////////////////////////////////////////

void caribrateSensorF(int pauseTime, int samples) {
  for (int i = 0; i < NUM_SENSORS; i++) {
    minValueF[i] = 1023;
    maxValueF[i] = 0;
  }
  for (int startSamp = 0; startSamp <= samples; startSamp++) {
    ReadF();
    for (int i = 0; i < NUM_SENSORS; i++) {
      minValueF[i] = (F[i] <= minValueF[i] ? F[i] : minValueF[i]);
      maxValueF[i] = (F[i] >= maxValueF[i] ? F[i] : maxValueF[i]);
    }
    delay(pauseTime);
  }
  for (int i = 0; i < NUM_SENSORS; i++) {
    minValueF[i] += 20;
    maxValueF[i] -= 50;
  }
}

void caribrateSensorC(int pauseTime, int samples) {
  for (int i = 0; i < NUM_SENSORS; i++) {
    minValueC[i] = 1023;
    maxValueC[i] = 0;
  }
  for (int startSamp = 0; startSamp <= samples; startSamp++) {
    ReadC();
    for (int i = 0; i < NUM_SENSORS; i++) {
      minValueC[i] = (C[i] <= minValueC[i] ? C[i] : minValueC[i]);
      maxValueC[i] = (C[i] >= maxValueC[i] ? C[i] : maxValueC[i]);
    }
    delay(pauseTime);
  }
  for (int i = 0; i < NUM_SENSORS; i++) {
    minValueC[i] += 20;
    maxValueC[i] -= 50;
  }
}

void caribrateSensorB(int pauseTime, int samples) {
  for (int i = 0; i < NUM_SENSORS; i++) {
    minValueB[i] = 1023;
    maxValueB[i] = 0;
  }
  for (int startSamp = 0; startSamp <= samples; startSamp++) {
    ReadB();
    for (int i = 0; i < NUM_SENSORS; i++) {
      minValueB[i] = (B[i] <= minValueB[i] ? B[i] : minValueB[i]);
      maxValueB[i] = (B[i] >= maxValueB[i] ? B[i] : maxValueB[i]);
    }
    delay(pauseTime);
  }
  for (int i = 0; i < NUM_SENSORS; i++) {
    minValueB[i] += 20;
    maxValueB[i] -= 50;
  }
}
///////////////////////////////////////////////////////////////////////////////////////

void Serial_FrontSensor() {
  while (1) {
    ReadSensorRaw();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);
  }
}

void Serial_BackSensor() {
  while (1) {
    ReadSensorRaw();
    for (int _serialB = 0; _serialB < NUM_SENSORS; _serialB++) {
      Serial.print(B[_serialB]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);
  }
}

void Serial_CenterSensor() {
  while (1) {
    ReadSensorRaw();
    for (int _serialA = 0; _serialA < NUM_SENSORS; _serialA++) {
      Serial.print(C[_serialA]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);
  }
}

void SerialCalibrate_FrontSensor() {
  while (1) {
    ReadSensor();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(100);
  }
}

void SerialCalibrate_BackSensor() {
  while (1) {
    ReadSensor();
    for (int _serialB = 0; _serialB < NUM_SENSORS; _serialB++) {
      Serial.print(B[_serialB]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(100);
  }
}

void SerialCalibrate_CenterSensor() {
  while (1) {
    ReadSensor();
    for (int _serialC = 0; _serialC < NUM_SENSORS; _serialC++) {
      Serial.print(C[_serialC]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(100);
  }
}
///////////////////////////////////////////////////////////////////////////////////////

void CalibrateSensor() {
  Serial.println("Press OK to start caribrate Front Sensor");
  OK();
  Serial.println("Caribrating");
  Beep(100);
  delay(600);
  caribrateSensorF(20, 250);
  Beep(100);
  delay(600);
  Serial.println("Finish");
  Serial.println("  ");

  Serial.println("Press OK to start caribrate Back Sensor");
  OK();
  Serial.println("Caribrating");
  Beep(100);
  delay(600);
  caribrateSensorB(20, 250);
  Beep(100);
  delay(600);
  Serial.println("Finish");
  Serial.println("  ");

  Serial.println("Press OK to start Caribrate Center Sensor");
  OK();
  Serial.println("Caribrating");
  Beep(100);
  delay(600);
  caribrateSensorC(20, 350);
  Beep(100);
  delay(600);
  Serial.println("Finish");
  Serial.println("  ");

  Serial.print("LightValue_FrontSensor (");
  //MinValueF
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(minValueF[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.print(",");
  }
  //MaxValueF
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(maxValueF[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println(");");
  }
  Serial.print("LightValue_BackSensor (");
  //MinValueB
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(minValueB[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.print(",");
  }
  //MaxValueB
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(maxValueB[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println(");");
  }

  Serial.print("LightValue_CenterSensor (");
  //MinValueC
  for (int i = 0; i < 6; i++) {
    Serial.print(minValueC[i]);
    if (i < 6 - 1) Serial.print(",");
    else Serial.print(",");
  }
  //MaxValueC
  for (int i = 0; i < 6; i++) {
    Serial.print(maxValueC[i]);
    if (i < 6 - 1) Serial.print(",");
    else Serial.println(");");
  }
  while (1)
    ;
}


///////////////////////////////////////////////////////////////////////////////////////
int Diss = 0;

int DistanceValue() {
  Diss = 2076 / (analogRead(A6) - 11);
  if (Diss < 4) Diss = 4;
  if (Diss > 60) Diss = 60;
  return Diss;
}
void SerialDistance() {
  while (1) {
    Serial.println(DistanceValue());
    delay(50);
  }
}