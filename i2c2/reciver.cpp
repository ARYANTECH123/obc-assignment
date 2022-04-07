// I2C slave code, with serial UART
//
#include <Wire.h>

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
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
    Serial.write(c);      // Send the character
  }
  lcd.print(str);

}