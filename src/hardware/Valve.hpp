#pragma once 

#include "global.hpp"

class Valve : public Hardware
{
private :
    const int pin;
    bool isOpen = false;

public : 
    Valve(int pin)
        : pin(pin)
    {}

    void init(void)
    {
        pinMode(this->pin, OUTPUT);
    }

    void open()
    {
        if (this->isOpen)
            return;

        digitalWrite(this->pin, HIGH);
        this->isOpen = true;
    }

    void close()
    {
        if (!this->isOpen)
            return;

        digitalWrite(this->pin, LOW);
        this->isOpen = false;
    }
};