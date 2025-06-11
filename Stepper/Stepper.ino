#include <Stepper.h>

int stepsPerRevolution = 2048;
int motorSpeed = 10;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int butPin = 13;
int currButVal;
int prevButVal;

bool clockwise = true;

void setup() {
  Serial.begin(9600);
  pinMode(butPin, INPUT); 
  prevButVal = digitalRead(butPin);
  myStepper.setSpeed(motorSpeed);
}

void loop() {
  currButVal = digitalRead(butPin);
  if (prevButVal == LOW && currButVal == HIGH) {
    clockwise = !clockwise;
    if (clockwise)
      Serial.println("Motor rotating in clockwise direction");
    else
      Serial.println("Motor rotating in counterclockwise direction");

    delay(200);
  }
  if (clockwise)
    myStepper.step(10);
  else
    myStepper.step(-10);
  delay(10);
  prevButVal = currButVal;
}