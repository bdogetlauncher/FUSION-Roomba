
// #if (ARDUINO >= 100)
// #include <Arduino.h>
// #else
// #include <WProgram.h>
// #endif

#include "TwoWheel.h"
#include "Arduino.h"

// ---------------------------------------------------------------------------

void TwoWheel::init(int enA_, int in1_, int in2_, int enB, int in3_, int in4_)
{
    left = Wheel();
    left.init(enA_, in1_, in2_);
    right = Wheel();
    right.init(enB_, in3_, in4_);

    mSpeed = 0;
    tSpeed = 0;
    currSpeed = 0;
    currTSpeed = 0;
}

void TwoWheel::calibrate(float dist, float turn, float dTime = 1, float tTime = 1) {
    maxMoveSpeed = dist/dTime;
    maxTurnSpeed = turn/tTime;
}

bool TwoWheel::setSpeeds(float move, float turn) {
    if move > maxMoveSpeed or move < 0 or turn > maxTurnSpeed or turn < 0
        return false;
    mSpeed = move *255 / maxMoveSpeed;
    tSpeed = turn *255 / maxTurnSpeed;
    return true;
}

void TwoWheel::setPos(float x_, float y_, float dir_) {
    x = x_;
    y = y_;
    dir = dir_;
}

void TwoWheel::update(unsigned long newTime)
{
    double dTime = (newTime - currTime)/1000;
    currTime = newTime;

    // current time - last time * speed & dir
    if (currSpeed > 0)
    {
        x = mSpeed * cos(dir);
        y = mSpeed * sin(dir);
    }
    else if (currTSpeed > 0)
    {
        dir += currTSpeed;
        // currT
    }
}

void TwoWheel::moveStop()
{
    left.moveSpeed(0);
    right.moveSpeed(0);

    currSpeed = 0;
    currTSpeed = 0;
}

void TwoWheel::moveForward()
{
    left.moveSpeed(mSpeed);
    right.moveSpeed(mSpeed);

    currSpeed = mSpeed;
    currTSpeed = 0;
}

void TwoWheel::moveBackward()
{
    left.moveSpeed(-1*mSpeed);
    right.moveSpeed(-1*mSpeed);

    currSpeed = -1*mSpeed;
    currTSpeed = 0;
}

void TwoWheel::moveLeft()
{
    left.moveSpeed(-1*tSpeed);
    right.moveSpeed(tSpeed);

    currSpeed = 0;
    currTSpeed = -1*tSpeed;
}

void TwoWheel::moveRight()
{
    left.moveSpeed(tSpeed);
    right.moveSpeed(-1*tSpeed);

    currSpeed = 0;
    currTSpeed = tSpeed;
}

// # Debugs and gets

float TwoWheel::getSpeed() {
    return (mSpeed / 255.0 * maxMoveSpeed);
}

float TwoWheel::getTurnSpeed()
{
    return (tSpeed / 255.0 * maxTurnSpeed);
}

int TwoWheel::getPinSpeed()
{
    return mSpeed;
}

int TwoWheel::getPinTurnSpeed()
{
    return tSpeed;
}

void TwoWheel::setPinSpeeds(int move, int turn) {
    mSpeed = move;
    tSpeed = turn;
}
void TwoWheel::calibrateMode()
{
    // Helps bypass calibrate() and setSpeeds()
    setPinSpeeds(255,255);
}
