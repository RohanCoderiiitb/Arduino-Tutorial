#include<DHT.h>
int dhtPin = 2;
DHT dht(dhtPin, DHT11);
int delayTime = 2000;
void setup(){
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  int humidity = dht.readHumidity();
  int temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C\tHumidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  delay(delayTime);
}