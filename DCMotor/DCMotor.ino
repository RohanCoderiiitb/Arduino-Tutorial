// Motor
int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int motorSpeed = 128;

//Buttons 1 and 2
int speedIncPin = 2;
int speedDecPin = 12;
int prevButInc;
int prevButDec;
int currButInc;
int currButDec;

int delayTime = 500;
void setup()
{
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(speedIncPin, INPUT);
  pinMode(speedDecPin, INPUT);
  prevButInc = digitalRead(speedIncPin);
  prevButDec = digitalRead(speedDecPin);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
}

void loop()
{
  currButInc = digitalRead(speedIncPin);
  currButDec = digitalRead(speedDecPin);
  if(currButInc==HIGH && currButDec==HIGH) Serial.println("Both buttons pressed!");
  if(currButInc==HIGH && prevButInc==LOW){
    motorSpeed = motorSpeed+10;
    motorSpeed = constrain(motorSpeed, 0, 255);
    Serial.print("Motor speed = ");
    Serial.println(motorSpeed);
    analogWrite(speedPin, motorSpeed);
    delay(delayTime);
  }else if(currButDec==HIGH && prevButDec==LOW){
    motorSpeed = motorSpeed-10;
    motorSpeed = constrain(motorSpeed, 0, 255);
    Serial.print("Motor speed = ");
    Serial.println(motorSpeed);
    analogWrite(speedPin, motorSpeed);
    delay(delayTime);
  }
  prevButDec = currButDec;
  prevButInc = currButInc;
  delay(10);
}