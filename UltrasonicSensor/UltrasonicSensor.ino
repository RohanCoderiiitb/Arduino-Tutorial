const int trigPin = 12;
const int echoPin = 11;

unsigned long pingTravelTime;
float distance_cm;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH, 30000);
  if (pingTravelTime == 0 || pingTravelTime > 30000) {
    Serial.println("Out of range or no object detected.");
  } else {
    distance_cm = (pingTravelTime * 0.0343) / 2;
    if (distance_cm < 2.0) {
      Serial.println("Too close to measure!");
    } else {
      Serial.print(pingTravelTime);
      Serial.print("\t");
      Serial.println(distance_cm);
    }
  }
  delay(500);
}