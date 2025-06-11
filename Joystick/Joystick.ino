#include <Servo.h>

int servoPin = 9;
int xPin = A0;  
int yPin = A1;  
int sPin = 2;   
int buzzPin = 13;

int xVal, yVal, sVal;
int servoAngle;
int delayTime = 50;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  digitalWrite(sPin, HIGH); 
  myServo.attach(servoPin);
}

void loop() {
  digitalWrite(buzzPin, LOW);
  xVal = analogRead(xPin); 
  yVal = analogRead(yPin);  
  servoAngle = map(yVal, 1023, 0, 0, 180);
  servoAngle = constrain(servoAngle, 0, 180);
  if(servoAngle==180) ringBuzzer();
  static int prevAngle = -1;
  if (abs(servoAngle - prevAngle) >= 2) {
    myServo.write(servoAngle);
    prevAngle = servoAngle;
  }
  Serial.print("Servo angle = ");
  Serial.println(servoAngle);
  delay(delayTime);
}

void ringBuzzer(){
  digitalWrite(buzzPin, HIGH);
}