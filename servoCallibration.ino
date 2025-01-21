//from: https://projecthub.arduino.cc/Kub_Luk/using-serial-monitor-to-control-servo-motor-c55083
#include <Servo.h>
Servo myservo;
int pos = 0;

void setup() {

  Serial.begin(9600);
  while (!Serial);
  Serial.println("-------------------------");
  Serial.println("ARos   is loading....");
  delay(1000);
  Serial.println("ARos loaded succesfully");
  Serial.println("-------------------------");
  myservo.attach(9);
  Serial.println("calibrating   servo...");
  myservo.write(0);///update
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  Serial.println("servo   calibrated");
  Serial.println("-------------------------");
  Serial.println("Comand   input online, write command to perform action");
  Serial.println("-------------------------");
}

void loop() {


  if (Serial.available()) {
    int state = Serial.parseInt();

    if (state < 10) {
      Serial.print(">");
      Serial.println(state);
      Serial.println("cannot execute command, too low number");
    }

    if (state >= 10 && state < 170) {
      Serial.print(">");
      Serial.println(state);
      Serial.print("turning servo to ");
      Serial.print(state);
      Serial.println(" degrees");
      myservo.write(state);
    }
  }
}
