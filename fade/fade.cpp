// Arduino code

int led = 9;		  

// It will take 51 changes to swing brightness from max to min
int brightness = 255;
int fade_rate = -5;

float N = 1.0f; // Last difit of ID number

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(led, brightness);
  Serial.println(brightness);
  
  if(fade_rate < 0) {
  	delay((1000*N)/(2*51));
  }
  if(fade_rate > 0) {
  	delay((1000*N)/(3*51));
  }
  
  if(brightness <= 0 || brightness > 255) {
  	fade_rate *= -1;
  }
  
  brightness += fade_rate;
  
  
}