// Reciving side code
// Interrupts are only supported on pins 2 and 3 in this board
// So we must use some other method
// Here, we are usein polling, as we constantly check for the level
// of pin 5
int led = 13;
int control = 5;

int state = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(control, INPUT);
}

void loop()
{
  state = digitalRead(control);
  
  if(state) {
  	analogWrite(led, 255);
    delay(1000);
    state = 0;
    analogWrite(led, 0);
  }

}