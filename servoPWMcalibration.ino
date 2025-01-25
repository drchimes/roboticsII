/*
This code is modifed from:
Using Serial Monitor to Control Servo Motor (11/14/2018). Kub_Luk
<https://projecthub.arduino.cc/Kub_Luk/using-serial-monitor-to-control-servo-motor-c55083>
Accessed on 11/17/2024

the range Dr. Chris determined is 100 - 490. try yours
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
  while (!Serial)
    
  Serial.println("-------------------------");
  Serial.println("ARos   is loading....");
  delay(1000);
  Serial.println("ARos loaded succesfully");
  Serial.println("-------------------------");

  Serial.println("calibrating   servo...");
  pwm.setPWM(1, 0, 100);  ///update
  delay(1000);
  pwm.setPWM(1, 0, 490);
  delay(1000);
  pwm.setPWM(1, 0, 298);
  delay(1000);
  Serial.println("servo   calibrated");
  Serial.println("-------------------------");
  Serial.println("Comand   input online, write command to perform action");
  Serial.println("-------------------------");
}


void loop() {
  if (Serial.available()) {
    int state = Serial.parseInt();

    pwm.setPWM(1, 0, state);
    delay(1000);
    Serial.print("turning servo to ");
    Serial.println(state);
  }
}

