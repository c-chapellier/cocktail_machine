
#pragma once

#include "../Container.hpp"

class Slider :  public Container
{
private:
    int value;

public:
    Slider(int value)
        : value(value)
    {}

    virtual void init()
    {
    }

    virtual void render()
    {
    }

    virtual int update(bool down)
    {
        if (down && this->servicePageBtn.contains(pixelX, pixelY))
        return -1;
    }

    int getValue()
    {
        return this->value;
    }
};
