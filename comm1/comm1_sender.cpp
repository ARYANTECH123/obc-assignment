// The code for the sender side

int control = 5;

void setup()
{
  pinMode(control, OUTPUT);
}

void loop()
{
  digitalWrite(control, HIGH);
  delay(50);
  digitalWrite(control, LOW);
  delay(3000);
}