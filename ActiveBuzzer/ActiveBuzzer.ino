int buzzPin = 8;
int voltagePin = A2;
int voltage = 0;
int time = 500;
int buzzTime = 1000;
void setup() {
  pinMode(buzzPin, OUTPUT);
  pinMode(voltagePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(voltagePin);
  float voltage_volts = (5.0/1023.0)*voltage;
  Serial.println(voltage_volts);
  if(voltage_volts>3.0){
    digitalWrite(buzzPin, HIGH);
    delay(buzzTime);
    digitalWrite(buzzPin, LOW);
  }else{
    digitalWrite(buzzPin, LOW);
  }
  delay(time);
}
