#include <Arduino.h>
//sketch created by Akshay Joseph
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 1, 2);

int sensorPin = A0;
int sensorValue = 0;
int voltage = 0;
int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT);
  sensorValue = analogRead(sensorPin); //read the value from the sensor
	lcd.begin();
	lcd.backlight();
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print(sensorValue);
}

void loop()
{
  delay(10);
  lcd.clear();
  sensorValue = analogRead(sensorPin); //read the value from the sensor
  //voltage = sensorValue * 5.0/1023;
  //Serial.println(sensorValue);
  lcd.setCursor(2,0);
  lcd.print("Voltage: ");
  lcd.setCursor(2,1);
  lcd.print(analogRead(sensorPin)* 5.0/1023);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
