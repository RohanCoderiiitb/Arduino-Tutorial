int ledPin = 9;
int voltagePin = A3;
int voltage = 0;
int waitTime = 500;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(voltagePin, INPUT);
}

void loop() {
  voltage = analogRead(voltagePin);
  int brightness = map(voltage, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  delay(waitTime);
}
