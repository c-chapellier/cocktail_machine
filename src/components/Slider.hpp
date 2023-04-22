
#pragma once

#include "../Container.hpp"

class Slider :  public Container
{
private:
    int value = 0;
    int x, y, w, h;

public:
    Slider(int x, int y, int w, int h)
        : x(x), y(y), w(w), h(h)
    {}

    virtual void init() {}

    virtual void render()
    {
        tft.fillRect(this->x, this->y, this->w, this->h, TFT_WHITE);
    }

    virtual int update(bool down)
    {
        // if (down && this->servicePageBtn.contains(pixelX, pixelY))
        return -1;
    }

    int getValue()
    {
        return this->value;
    }

    void setValue(int value)
    {
        this->value = value;
    }
};
