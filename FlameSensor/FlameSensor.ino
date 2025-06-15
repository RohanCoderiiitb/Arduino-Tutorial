int ledPin = 13;
int buzPin = 3;
int flamePin = 2;
int isFlame;
int delayTime = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzPin, OUTPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  isFlame = digitalRead(flamePin);
  if (isFlame == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzPin, HIGH);
    Serial.println("🔥 Flame detected!!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzPin, LOW);
    Serial.println("No flame");
  }

  delay(delayTime);
}