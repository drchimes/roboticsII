/*
This code is modifed from:
Using Serial Monitor to Control Servo Motor (11/14/2018). Kub_Luk
<https://projecthub.arduino.cc/Kub_Luk/using-serial-monitor-to-control-servo-motor-c55083>
Accessed on 11/17/2024
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 50
/////Update these values as needed to control a motor and its position
int servonum = 0;
int posValue = 160;

void setup(){
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
}
void loop(){
  pwm.setPWM(servonum, 0, posValue);
  message();
}

void message(){
  Serial.print("Servo ");
  Serial.print(servonum);
  Serial.print(" is at ");
  Serial.println(posValue);
  delay(500);
}



////////////////////Ignore this code//////////////////////////
/*
  while (!Serial);
  Serial.println("-------------------------");
  Serial.println("ARos   is loading....");
  delay(1000);
  Serial.println("ARos loaded successfully");
  Serial.println("-------------------------");

Serial.println("calibrating   servo...");
for(pos = 1600; pos <= 600; pos += 1)
pwm.setPWM(0,0,160);//myservo.write(0);
delay(1000);
pwm.setPWM(0,0,600);//myservo.write(180);
delay(1000);
pwm.setPWM(0,0,380);//myservo.write(90);
delay(1000);
Serial.println("servo   calibrated");
Serial.println("-------------------------");
Serial.println("Comand   input online, write command to perform action");
Serial.println("-------------------------");

}

void   loop() {
  
for(pos = 160; pos <= 600; pos += 1)
if (Serial.available()){
   int state = Serial.parseInt();
  if (state < 165){
    Serial.print(">");
    Serial.println(state);
    Serial.println("cannot execute command, the number is too lowr");
  }
  if (state >= 165 && state < 595){
    Serial.print(">");
    Serial.println(state);
    Serial.print("turning servo to ");
    Serial.print(state);
    Serial.println(" PWM");
    pwm.setPWM(0,0,state);//myservo.write(state);
  }
}
}
*/


  
