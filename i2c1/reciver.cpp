// Code for I2C slave

// Using Wire.h

#include <Wire.h>

#include <LiquidCrystal.h>

// Initializze LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  Wire.begin(4);
  Wire.onReceive(reciveId);
  
  lcd.begin(16, 2);
  
}

void loop()
{
  delay(100);
  
}

void reciveId(int numreq) {
  String str = "";
  	while(1 < Wire.available()) 
  {
    char c = Wire.read(); // receive byte as a character
    lcd.setCursor(0, 0);
    str.concat(c);
    
  }
  lcd.print(str); // print the string

}