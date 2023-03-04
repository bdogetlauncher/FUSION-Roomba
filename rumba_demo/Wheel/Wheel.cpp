
// #if (ARDUINO >= 100)
// #include <Arduino.h>
// #else
// #include <WProgram.h>
// #endif

#include "Wheel.h"
#include "Arduino.h"

// ---------------------------------------------------------------------------
void Wheel::init(int enA_, int in1_, int in2_)
{
    enA = enA;
    in1 = in1;
    in2 = in2;
}

void Wheel::moveSpeed(int speed)
{
    analogWrite(enA, speed);
    if (speed >= 0) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }
}

