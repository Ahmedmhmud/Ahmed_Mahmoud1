#include <LiquidCrystal.h>
#define signalToRelay 8
#define sensorPin A0
#define buzzer 7

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp = ");
  pinMode(signalToRelay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(signalToRelay, LOW); //default 
  digitalWrite(buzzer, LOW); //default
}

void loop() {
  int reading = analogRead(sensorPin);
  float temp = 100 * (reading * 5 / 1023.0);
  lcd.setCursor(8, 0);
  lcd.print(temp);
  if(temp > 30){
    digitalWrite(signalToRelay, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Overheating");
  }
  else{ 
    if(temp < 25)
      digitalWrite(signalToRelay, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Normal     ");
  }
  delay(200);
}
