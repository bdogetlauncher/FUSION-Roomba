// C++ code
//
#include "Arduino.h"
#include "pins_arduino.h"

#define enA 9 
#define in1 13  
#define in2 12

#define enB 6
#define in3 11
#define in4 10



//define motor pins
#define enA 11 
#define in1 12  
#define in2 13

#define enB 3
#define in3 4
#define in4 2

//define sensor pins
#define lsTrig 8
#define lsEcho 7

#define fsTrig 10
#define fsEcho 9

#define rsTrig 6
#define rsEcho 5


int speed = 100;
int dir = 0; // in degrees [0,360)
int func = 1;

int distance;
int duration;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  analogWrite (enA,240);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  analogWrite (enB,240);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
}


void moveForward() {
  // both wheels backwards
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward () {
  // both wheels backwards
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
}

void moveLeft() {
  // left wheel back, right wheel forward
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveRight() {
  // left wheel forward, right wheel back
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
}


void loop(){
  if (func == 0) {
    moveForward();
  } else if (func == 1) {
    moveLeft();
  } else if (func == 2) {
    moveRight();
  } else if (func == 3) {
    moveBackward();
  }
  func = (func +1) % 4;
  delay(500); 
 

}
  
  
void SonarSensor(int trigPin,int echoPin) {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration/2)* 0.034;
  	Serial.print("Distance: ");
  	Serial.println(distance);
  
}
// CODE FOR SENSORS


/*
{
  // Clears the trigPin
  digitalWrite(lsTrig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(lsTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(lsTrig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(lsEcho, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}


*/
