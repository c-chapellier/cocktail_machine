
#pragma once

#include "Page.hpp"

class NavigablePage : public Page
{
private:
    Adafruit_GFX_Button menuPageBtn;

public:
    NavigablePage(String name)
        : Page(name)
    {}

    ~NavigablePage() {}

    void init()
    {
        Page::init();

        this->menuPageBtn.initButton(&tft, H_SPACING + 40, CASE_Y(0), 80, CASE_HEIGHT/2, TFT_WHITE, TFT_BLACK, TFT_WHITE, "<-", 2);
    }

    void render()
    {
        Page::render();

        this->menuPageBtn.drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = Page::update(down);
        if (nextPage != -1) return nextPage;

        this->menuPageBtn.press(down && this->menuPageBtn.contains(pixelX, pixelY));
        
        if (this->menuPageBtn.justReleased())
            this->menuPageBtn.drawButton(false);
                
        if (this->menuPageBtn.justPressed())
        {
            this->menuPageBtn.drawButton(true);
            return MENU_PAGE;
        }

        return -1;
    }
};
