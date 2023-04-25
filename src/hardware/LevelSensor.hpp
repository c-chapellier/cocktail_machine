
#pragma once

#include "global.hpp"

class LevelSensor : public Hardware
{
    private : 
        const int pin ;
    public :
        LevelSensor( int pin) : pin(pin) 
        {}
    void LevelSensor::setup(void)
    {
        pinMode(pin,OUTPUT);
    }

    bool LevelSensor::LiquidDetected(void)

    {
        if(digitalRead(pin)==0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};