int parabola1;
int parabola2;
void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int j=-4; j<=4; j++){
    parabola1 = j*j;
    parabola2 = -(j*j);
    Serial.print(parabola1);
    Serial.print("\t");
    Serial.println(parabola2);
    delay(100);
  }
}
