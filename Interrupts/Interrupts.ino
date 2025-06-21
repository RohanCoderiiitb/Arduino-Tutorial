#include<TimerOne.h>
String ledStatus = "OFF";
int redPin = 6;
int yellowPin = 5;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(blinkYellow);
}

void loop() {
  digitalWrite(redPin, HIGH);
  delay(250);
  digitalWrite(redPin, LOW);
  delay(250);
}

void blinkYellow(){
  if(ledStatus == "ON"){
    digitalWrite(yellowPin, LOW);
    ledStatus = "OFF";
    return;
  }
  if(ledStatus == "OFF"){
    digitalWrite(yellowPin, HIGH);
    ledStatus = "ON";
    return;
  }
}