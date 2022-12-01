// #include <Wire.h>
// void setup()
// {
// Wire.begin();
// Serial.begin(9600);
// Serial.println("\nI2C Scanner");
// }
// void loop()
// {
// byte error, address;
// int Devices;
// Serial.println("Scanning...");
// Devices = 0;
// for(address = 1; address < 127; address++ )
// {
//
// Wire.beginTransmission(address);
// error = Wire.endTransmission();
// if (error == 0)
// {
// Serial.print("I2C device found at address 0x");
// if (address<16)
// Serial.print("0");
// Serial.print(address,HEX);
// Serial.println("  !");
// Devices++;
// }
// else if (error==4)
// {
// Serial.print("Unknown error at address 0x");
// if (address<16)
// Serial.print("0");
// Serial.println(address,HEX);
// }
// }
// if (Devices == 0)
// Serial.println("No I2C devices found\n");
// else
// Serial.println("done\n");
// delay(5000);
// }







// Servo


#include <Servo.h>


Servo servo;

#include <Arduino.h>
//sketch created by Akshay Joseph
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 1, 2);

int sensorPin = A0; int sensorValue = 0;
int voltage = 0; float slope = -56.27;
float intercept = 314.25; float angle = 0;

void setup()
{ servo.attach(9); // First, we tell the system what pin was the servo motor attached to
  servo.write(180);  // The servo was set to an initial angle state at 180 degrees
  lcd.begin(); // LCD was initialized as follows
  lcd.backlight();
  lcd.clear(); }

void loop()
{ servo.write(180); // Servo is reset to 180 degrees after each loop
  delay(1000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Angle: ");
  lcd.setCursor(2,1);
  angle = ((analogRead(sensorPin)* 5.0/1023)*slope) + intercept;
  lcd.print(angle); // Then, the angle of the potentiometer was displayed on the LCD
  delay(1000);
  servo.write(180-(angle-33.45)); // Feedback control instructions were sent to the servo
  delay(100); }
}
