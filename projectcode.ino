#include <Adafruit_CircuitPlayground.h>

float value; 

int points = 0;
bool shouldContinue = true;
const int switchPin = 7;

void setup() {
Serial.begin(9600);
CircuitPlayground.begin();

pinMode(switchPin, INPUT_PULLUP);
shouldContinue = (digitalRead(switchPin) == LOW);
}

void addPoints(int amount){
  points += amount;
}


void loop() {

if(digitalRead(switchPin) == LOW){
if(!shouldContinue){
  return;
}

delay(1000);

value = CircuitPlayground.mic.soundPressureLevel(5);

 if (value < 60){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 255, 0, 0);//red
delay(50);
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
}
addPoints(1);}
else if (value < 70){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 255, 255, 0);//yellow
   delay(50);
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
}
addPoints(2);}
else if (value < 80){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 0, 255, 0);//green
      delay(50);
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
}
addPoints(3);}
else if (value < 90){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 0, 0, 255);//blue
      delay(50);
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
}
addPoints(4);}
else if (value < 100){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 255, 0, 255);//purple
      delay(50);
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
}
addPoints(5);}
else if (value > 105){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 255, 255, 255);//white
      delay(50);
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
}
addPoints(10);}

Serial.print("Current Points:");
Serial.println(points);

if(points >= 100){
  shouldContinue = false;
}

delay(10);
}
else{
  digitalRead(switchPin) == HIGH;
}}
