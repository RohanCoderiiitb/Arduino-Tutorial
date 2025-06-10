int buzzPin = 9;
int voltagePin = A0;
int voltage = 0;
void setup() {
  pinMode(buzzPin, OUTPUT);
  pinMode(voltagePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(voltagePin);
  int delayMicro = map(voltage, 0, 1023, 10000, 60);
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayMicro);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayMicro);
}
