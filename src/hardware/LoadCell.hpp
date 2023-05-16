#pragma once 

#include "global.hpp"

class LoadCell : public Hardware
{
private :
    const int dataPin, clockPin;
    HX711 loadCell;

public : 
    LoadCell(int dataPin, int clockPin)
        : dataPin(dataPin), clockPin(clockPin)
    {}

    void init(void)
    {
        this->loadCell.begin(this->dataPin, this->clockPin);
        this->loadCell.set_scale(LOAD_CELL_CALIBRATION_FACTOR);
        this->loadCell.tare();                           // Assuming there is no weight on the loadCell at start up, reset the loadCell to 0
    }

    float read()
    {
        return this->loadCell.get_units();
    }
};