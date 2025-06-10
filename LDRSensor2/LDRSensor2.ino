int ledPin = 9;
int ldrPin = A0;
int lightVal;
int waitTime = 500;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(ldrPin);
  Serial.println(lightVal);
  int brightness = map(lightVal, 0, 1023, 255, 0);
  analogWrite(ledPin, brightness);
  delay(waitTime);
}
