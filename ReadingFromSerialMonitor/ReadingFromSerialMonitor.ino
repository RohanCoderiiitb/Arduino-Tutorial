int ledPin = 8;
int myNumber;
int waitTime = 500;
String message = "How many times do you want the LED to blink?";
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  Serial.println(message);
  while(Serial.available()==0);
  int myNumber = Serial.parseInt();
  while(Serial.available()) Serial.read();
  for(int i=0; i<myNumber; i++){
    digitalWrite(ledPin, HIGH);
    delay(waitTime);
    digitalWrite(ledPin, LOW);
    delay(waitTime);
  }
  delay(waitTime);
}
