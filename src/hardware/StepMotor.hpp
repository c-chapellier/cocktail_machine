#pragma once

#include "global.hpp"

class StepMotor : public Hardware
{
    private :
        const int dirPin;
        const int stepPin;
        const int stepsPerRevolution;
    public :
        StepMotor(int _dirPin,int _stepPin,int _stepsPerRevolution) : dirPin(_dirPin), stepPin(_stepPin), stepsPerRevolution(_stepsPerRevolution)
        {}

        void init(void)
        {
            pinMode(dirPin,OUTPUT);
            pinMode(stepPin,OUTPUT);
        }

        void direction(bool sens)
        {
            if(sens)
            {
                digitalWrite(dirPin,HIGH);
            }
            else
            {
                digitalWrite(dirPin,LOW);
            }
        }

        void run(int rapidity)
        {
            digitalWrite(stepPin,HIGH);
            delayMicroseconds(rapidity);
            digitalWrite(stepPin,LOW);
            delayMicroseconds(rapidity);
        }
        
};

