int readPin = A3;
int readVoltage = 0;
int waitTime = 500;
void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readVoltage = analogRead(readPin);
  float actualVoltage = (readVoltage/(1023.0))*5;
  Serial.println(actualVoltage);
  delay(waitTime);
}
