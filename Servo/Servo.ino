#include<Servo.h>
int servoPin = 9;
int servoPos;
Servo myServo;
int ldrPin = A1;
int ldrVal;
int delayTime = 500;
void setup() {
  myServo.attach(servoPin);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);
  servoPos = map(ldrVal, 0, 1023, 0, 180);
  myServo.write(servoPos);
  delay(delayTime);
}
