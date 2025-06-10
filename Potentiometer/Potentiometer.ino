int redPin = 13;
int bluePin = 11;
int voltagePin = A3;
float readVoltage = 0.0;
int waitTime = 500;
String warning = "Voltage above 4V!";
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(voltagePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readVoltage = analogRead(voltagePin);
  float voltageVolts = (5.0/1023.0)*readVoltage;
  if(voltageVolts>4.0){
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, LOW);
    Serial.print(voltageVolts);
    Serial.print(" ");
    Serial.println(warning);
  }else{
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, LOW);
    Serial.println(voltageVolts);
  }
  delay(waitTime);
}
