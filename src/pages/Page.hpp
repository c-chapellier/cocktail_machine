
#pragma once

#include "../Container.hpp"

class Page : public Container
{
private:
    String name;
    Adafruit_GFX_Button title;

public:
    Page(String name)
        : name(name)
    {}

    ~Page() {}

    virtual void init()
    {
        this->title.initButton(&tft, SCREEN_WIDTH/2, CASE_Y(0), CASE_WIDTH, CASE_HEIGHT, TFT_WHITE, TFT_BLACK, TFT_WHITE, this->name.c_str(), 2);
    }

    virtual void render()
    {
        tft.fillScreen(TFT_BLACK);
        this->title.drawButton(false);
    }

    virtual int update(bool down)
    {
        return -1;
    }
};
