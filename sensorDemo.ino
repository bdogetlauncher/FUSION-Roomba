#include "Arduino.h"
#include "TwoWheel.h"

// #define enA 9
// #define in1 13
// #define in2 12

// #define enB 6
// #define in3 11
// #define in4 10

// define sensor pins
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

unsigned long currT = 0;

TwoWheel rumba;

int SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.034;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
// CODE FOR SENSORS

void setup()
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  rumba = TwoWheel();
  rumba.init(9, 13, 12, 6, 11, 10);
  // rumba.calibrate(200, 500);
  rumba.calibrate2(2.54, 4); // moved 2.54 ft in 1 sec, 4 rads in 1 sec
  rumba.setPos(0, 0);
  rumba.setSpeed(1) //

      delay(100);
}

void loop()
{
  rumba.update(curr);
}
