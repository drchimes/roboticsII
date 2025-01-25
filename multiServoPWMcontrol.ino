#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

void setup() {

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
}

void loop() {
}

void simExample() {
  pwm.setPWM(0, 0, 200);
  pwm.setPWM(1, 0, 200);
  delay(500);
  pwm.setPWM(0, 0, 400);
  pwm.setPWM(1, 0, 400);
  delay(500);
}

void seq() {
  pwm.setPWM(0, 0, 200);
  delay(500);
  pwm.setPWM(1, 0, 200);
  delay(500);
  pwm.setPWM(0, 0, 400);
  delay(500);
  pwm.setPWM(1, 0, 400);
  delay(500);
}

void timeControl(int time) {
  //when you call this method you have to determine what time you want inbetween steps
  // use a value between 1-20
  for (int i = 100; i < 400; i++) {
    pwm.setPWM(0, 0, i);
    pwm.setPWM(1, 0, i);
    delay(time);
  }
  for (int i = 400; i > 100; i--) {
    pwm.setPWM(0, 0, i);
    pwm.setPWM(1, 0, i);
    delay(time);
  }
}
