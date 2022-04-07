// Code for I2C Master

// Using the Wire.h library

#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("2641 ");        // sends id number 
  Wire.endTransmission();    // stop transmitting

  delay(500);
}