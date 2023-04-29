
#pragma once

#include "global.hpp"

class LevelSensor : public Hardware
{
    private : 
        const int pin ;
    public :
        LevelSensor( int pin) : pin(pin) 
        {}
    void init(void)
    {
        pinMode(pin,OUTPUT);
    }

    bool LiquidDetected(void)

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