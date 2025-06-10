int ledPins[3] = {8,9,10};
String message = "Which color LED do you want to blink?";
String error = "Color not available!";
String color;
int waitTime = 500;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  Serial.println(message);
  while (Serial.available() == 0);
  color = Serial.readStringUntil('\n');
  while (Serial.available()) Serial.read(); 
  color.toLowerCase();
  if (color == "blue") blinkLED(ledPins[0]);
  else if (color == "green") blinkLED(ledPins[1]);
  else if (color == "red") blinkLED(ledPins[2]);
  else Serial.println(error);

  delay(waitTime);
}

void blinkLED(int pin) {
  for (int i = 0; i < 10; i++) {
    digitalWrite(pin, HIGH);
    delay(waitTime);
    digitalWrite(pin, LOW);
    delay(waitTime);
  }
}
