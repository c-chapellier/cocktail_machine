
#pragma once

#include "global.hpp"

class LevelSensor : public Hardware
{
private : 
    const int pin;

public :
    LevelSensor(int pin)
        : pin(pin) 
    {}

    void init(void)
    {
        pinMode(this->pin, INPUT);
    }

    bool read(void) const
    {
        return digitalRead(this->pin);
    }
};