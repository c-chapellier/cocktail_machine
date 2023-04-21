
#pragma once

#include "../Container.hpp"

class Dialog :  public Container
{
protected:
    Adafruit_GFX_Button container;
    int x = SCREEN_WIDTH / 2;
    int y = V_SPACING + CASE_HEIGHT + (SCREEN_HEIGHT - V_SPACING - CASE_HEIGHT) / 2;
    int width = SCREEN_WIDTH * 4/5;
    int height = SCREEN_HEIGHT * 2/3;

public:
    Dialog() {}

    virtual ~Dialog() = default;

    virtual void init()
    {
        this->container.initButton(
            &tft,
            this->x,
            this->y,
            this->width,
            this->height,
            TFT_WHITE, TFT_BLACK, TFT_WHITE, "", 2
        );
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
