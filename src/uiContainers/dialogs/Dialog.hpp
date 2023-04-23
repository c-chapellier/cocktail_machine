
#pragma once

#include "../../global.hpp"

class Dialog :  public UIContainer
{
protected:
    Adafruit_GFX_Button container;

public:
    Dialog() {}

    virtual ~Dialog() = default;

    virtual void init()
    {
        this->container.initButton(&tft, dialogContentBox.getCenterX(), dialogContentBox.getCenterY(), dialogContentBox.getW(), dialogContentBox.getH(), TFT_WHITE, TFT_BLACK, TFT_WHITE, (char *)"", 2);
    }

    virtual void render()
    {
        this->container.drawButton(false);
    }

    virtual int update(bool down)
    {
        return -1;
    }
};
