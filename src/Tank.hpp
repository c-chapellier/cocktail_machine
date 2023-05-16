
#pragma once

#include "global.hpp"

class Tank
{
private:
    const double levelSensorHeight = 70.0;
    const int index;
    double volume;
    bool wasBelowLevelSensor = false;

public:
    Tank(int index)
        : index(index), volume(this->levelSensorHeight)
    {}

    double canFill(double desiredVolume) const
    {
        return levelSensors[this->index].read() || this->volume >= desiredVolume;
    }

    bool checkLevel()
    {
        if (!this->wasBelowLevelSensor && !levelSensors[this->index].read())
        {
            this->volume = this->levelSensorHeight;
            this->wasBelowLevelSensor = true;
            return true;
        }

        return false;
    }

    bool isVolumeKnown() const
    {
        return this->volume <= this->levelSensorHeight;
    }

    void serve(double volume)
    {
        this->volume -= volume;
    }

    double getVolume() const
    {
        return this->volume;
    }
};
