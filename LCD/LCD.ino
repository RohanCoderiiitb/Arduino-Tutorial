#include<LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float number1;
float number2;
String op;
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("First number");
  while(Serial.available()==0);
  number1 = Serial.parseFloat();
  while(Serial.available()) Serial.read();
  lcd.setCursor(0,1);
  lcd.print(number1);
  delay(1000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Second number");
  while(Serial.available()==0);
  number2 = Serial.parseFloat();
  while(Serial.available()) Serial.read();
  lcd.setCursor(0,1);
  lcd.print(number2);
  delay(1000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Operator(+,-,*,/)");
  while(Serial.available()==0);
  op = Serial.readStringUntil('\n');
  while(Serial.available()) Serial.read();
  lcd.setCursor(0,1);
  lcd.print(op);
  delay(1000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("The answer is");
  lcd.setCursor(0, 1);
  if(op=="+") lcd.print(number1+number2);
  else if(op=="-") lcd.print(number1-number2);
  else if(op=="*") lcd.print(number1*number2);
  else if(op=="/") lcd.print(number1/number2);
  
  delay(2000);
  lcd.clear();
}