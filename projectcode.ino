#include <Adafruit_CircuitPlayground.h> // libraries

//global variables
float value; 
float midi[127];
int A_four = 440;

int points = 0;
bool shouldContinue = true;
const int switchPin = 7;

int noise [6] = {60, 70, 80, 90, 100, 110};

//setup, includes start fuctions and initializers for switch
void setup() {
Serial.begin(9600);
CircuitPlayground.begin();

pinMode(switchPin, INPUT_PULLUP);
shouldContinue = (digitalRead(switchPin) == LOW);
}

//est. point system
void addPoints(int amount){
  points += amount;
}


void loop() {

//if the switch is LOW, or on, then the code will run. If it is not, the code will break and stop
if(digitalRead(switchPin) == LOW){
if(!shouldContinue){
  return;
}

//tone before color loop
CircuitPlayground.playTone(80, 100);

//sound gauge
value = CircuitPlayground.mic.soundPressureLevel(5);

// if the value is under the threshold (< 60 in this first part), then 1 point will be will be added and red will run
//if it's over the threshold, then it will go to the next part and run with points aloted until it reaches the correct threshold
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

//score keep
Serial.print("Current Points:");
Serial.println(points);

//if the points exceed 100, then the game ends
if(points >= 100){
  shouldContinue = false;
}

//small delay
//else statement is saying that if the switchPin is HIGH, or off, then the code will stop running
delay(10);
}
else{
  digitalRead(switchPin) == HIGH;
}}
