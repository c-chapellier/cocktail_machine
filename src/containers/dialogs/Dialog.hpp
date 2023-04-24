
#pragma once

#include "global.hpp"

class Dialog :  public UIContainer
{
protected:
    Adafruit_GFX_Button container;

public:
    Dialog() {}

    virtual ~Dialog() = default;

    virtual void init()
    {
        this->container.initButton(
            &tft,
            dialogContentBox.getCenterX(),
            dialogContentBox.getCenterY(),
            dialogContentBox.getW(),
            dialogContentBox.getH(),
            colors[DIALOG_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[DIALOG_BACKGROUND_COLOR][FORMAT_COLOR_16],
            0,
            (char *)"",
            2,
            2,
            8
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
