#pragma once

#include "global.hpp"

class StepperMotor : public Hardware
{
private :
    const int dirPin, stepPin;
    bool direction = 0;

public :
    StepperMotor(int dirPin, int stepPin)
        : dirPin(dirPin), stepPin(stepPin)
    {}

    void init(void)
    {
        pinMode(this->dirPin, OUTPUT);
        pinMode(this->stepPin, OUTPUT);
        this->setDirection(this->direction);
    }

    void setDirection(bool direction)
    {
        this->direction = direction;
        digitalWrite(this->dirPin, this->direction ? HIGH : LOW);
    }

    void step(int delay)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(delay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(delay);
    }
};
