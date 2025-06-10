int ldrPin = A0;
int redPin = 8;
int yellowPin = 6;
int lightVal;
int delayTime = 500;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(ldrPin);
  Serial.println(lightVal);
  if(lightVal<300){
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
  }
  else{
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
  }
  delay(delayTime);
}