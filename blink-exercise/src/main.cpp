#include <Arduino.h>




int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int inc = 0;
int inc_change = 0;
int init_del = 100;
void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
}

void loop() {
// left to right
digitalWrite(led1, HIGH);
delay(init_del - inc);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(init_del - inc);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(init_del - inc);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(init_del - inc);
digitalWrite(led4, LOW);
// right to left
digitalWrite(led3, HIGH);
delay(init_del - inc);
digitalWrite(led3, LOW);
digitalWrite(led2, HIGH);
delay(init_del - inc);
digitalWrite(led2, LOW);
digitalWrite(led1, HIGH);
inc = inc + inc_change;
}
