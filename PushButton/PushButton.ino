int butIncPin = 8;
int butDecPin = 13;
int butIncVal;
int butDecVal;
int buzPin = 2;
int ledPin = 6;
int delayTime = 500;
int brightness = 0;
int step = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzPin, OUTPUT);
  pinMode(butIncPin, INPUT);
  pinMode(butDecPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  butIncVal = digitalRead(butIncPin);
  butDecVal = digitalRead(butDecPin);

  if (butIncVal == HIGH && butDecVal == LOW) {
    Serial.println("Increasing brightness!");
    increaseBrightness();
  } else if (butIncVal == LOW && butDecVal == HIGH) {
    Serial.println("Decreasing brightness!");
    decreaseBrightness();
  } else if (butIncVal == HIGH && butDecVal == HIGH) {
    Serial.println("Both buttons pressed!");
  } else {
    Serial.println("None of the buttons pressed!");
  }

  analogWrite(ledPin, brightness);
  delay(delayTime);
}

void increaseBrightness() {
  brightness += step;
  if (brightness > 255) {
    brightness = 255;
    Serial.println("Maximum brightness reached!");
    ringBuzzer();
  }
}

void decreaseBrightness() {
  brightness -= step;
  if (brightness < 0) {
    brightness = 0;
    Serial.println("Minimum brightness reached!");
    ringBuzzer();
  }
}

void ringBuzzer() {
  digitalWrite(buzPin, HIGH);
  delay(delayTime);
  digitalWrite(buzPin, LOW);
  delay(delayTime);
}