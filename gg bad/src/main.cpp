#include <Arduino.h>
const int  Red = 5; 
const int  Blue = 18; 
const int  Green = 19; 

void setup() 
{
  Serial.begin(115200);
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
}

void loop() 
{
  digitalWrite(Red, LOW);
  delay(500);
  digitalWrite(Red, HIGH);
  delay(500);
  digitalWrite(Blue, LOW);


  digitalWrite(Green, HIGH);
}
  