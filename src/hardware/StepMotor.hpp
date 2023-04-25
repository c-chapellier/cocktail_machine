#pragma once

#include "global.hpp"

class StepMotor : public Hardware
{
    private :
        const int dirPin;
        const int stepPin;
    public :
        StepMotor(int _dirPin,int _stepPin);
        
};