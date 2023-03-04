#include "Arduino.h"
#include "TwoWheel.h"


int func = 1;

int distance;
int duration;

unsigned long currT = 0;

TwoWheel rumba;
    
void setup() {
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
  rumba.setPos(0,0);
  rumba.setSpeed(1) // 1ft /sec

  rumba.moveForward();
  delay(100);
}

void loop() {
  currT = millis();
  Serial.print(rumba.x, float);
  Serial.println(rumba.y, float);
  rumba.update(currT);
  
  delay(1000);
}
