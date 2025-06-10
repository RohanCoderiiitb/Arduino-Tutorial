int ldrPin = A0;
int ldrVal; 

int ledPin = 6;

int potPin = A2;
int potVal;

int switchPin = 8;
int currSwitchVal;
int prevSwitchVal;

int delayTime = 500;

int autoMode = 0;
String message1 = "Automode ON";
String message2 = "Automode OFF";

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  currSwitchVal = digitalRead(switchPin);
  if(currSwitchVal==HIGH && prevSwitchVal==LOW){
    autoMode = !autoMode;
    if(autoMode) Serial.println(message1);
    else Serial.println(message2);
    delay(delayTime);
  }
  if(autoMode) autoModeON();
  else autoModeOFF();
  prevSwitchVal = currSwitchVal;
}

void autoModeON(){
  ldrVal = analogRead(ldrPin);
  int brightness = map(ldrVal, 0, 1023, 255, 0);
  analogWrite(ledPin, brightness);
  delay(delayTime);
}

void autoModeOFF(){
  potVal = analogRead(potPin);
  int brightness = map(potVal, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  delay(delayTime);
}