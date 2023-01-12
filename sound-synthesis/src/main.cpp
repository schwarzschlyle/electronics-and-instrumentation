#include <Arduino.h>

#define LaserPin 8


void setup ()
{
   pinMode (LaserPin, OUTPUT);
}
void loop () {
   digitalWrite (LaserPin, HIGH);
   delay (100);
   digitalWrite (LaserPin, LOW);
   delay (100);
}
