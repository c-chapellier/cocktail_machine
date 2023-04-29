#pragma once 

#include "global.hpp"

class Valve : public Hardware
{
    private :
        int pin;
        bool state;//between opened and closed
    public : 
        Valve(int pin, bool state) : pin(pin),state(state){}
        void init(void)
        {
            pinMode(pin,OUTPUT);
            state = false;
        };
        void valveState(bool opening)
        {
            if(opening == true)
            {
                digitalWrite(pin,HIGH);
            }
            else
            {
                digitalWrite(pin,LOW);
            }
            state = opening;
        };
};