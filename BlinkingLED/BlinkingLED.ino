int ledPins[4] = {5, 4, 3, 2};
int waitTime = 500;
void setup()
{
  for(int i=0; i<4; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  for(int count=0; count<16; count++){
    display(count);
    delay(waitTime);
  }
}

void display(int count){
  for(int i=0; i<4; i++){
    int bit = (count>>i)&1;
    digitalWrite(ledPins[i], bit);
  }
}