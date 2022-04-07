
// Code for the i2c master
// Inckude code for handling the 7 segment display, and UART serial
#include <Wire.h>

int M = 0;

int displayPins[] = {13, 12, 11, 10, 9, 8, 7}; // Pinmap for 7seg

int displayNumbers[10][7] = { // Number map
  {13, 12, 11, 10, 9, 8, 0},
  {21, 11, 0, 0, 0 ,0 ,0},
  {13, 12, 7, 9, 10, 0, 0},
  {13, 12, 7, 11, 10, 0, 0},
  {8, 7, 12 ,11,0 ,0 ,0},
  {13, 8, 7, 11, 10, 0, 0},
  {13, 8 ,9, 10, 11, 7, 0},
  {13 ,12, 7, 0, 0, 0, 0},
  {13 ,12 ,11, 10, 9, 8, 7},
  {8, 13 ,7 ,12, 11 ,10, 0}
};

/*
*/
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  for(int i = 0; i < 7; i++) {
  	pinMode(displayPins[i], OUTPUT);
  }
}

void loop()
{
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("2641 ");        // sends id number 
  Wire.endTransmission();    // stop transmitting
  
  if(Serial.available()) {
  	M = Serial.parseInt();
  }
  showNumber(checksum(M));
  delay(500);
  return;
}

int checksum(int num) {
  int sum = 0;
  while (num > 0) {
    sum = sum + num % 10;
    num = num / 10;
  }
  return sum % 9;
}

void showNumber(int n) { // This functions displays number on 7seg
  for(int i = 0; i < 8; i++) {
    if(displayNumbers[n][i]) {
      digitalWrite(displayNumbers[n][i], HIGH);
    }
  }
}

void resetDisplay() {
  for(int i = 0; i < 8; i++) {
  	digitalWrite(displayPins[i], LOW);
  }
}