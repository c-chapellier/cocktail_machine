
#pragma once

#include "global.hpp"

class NavigablePage : public Page
{
private:
    Adafruit_GFX_Button menuPageBtn;

public:
    NavigablePage(const char *name)
        : Page(name)
    {}

    ~NavigablePage() {}

    void init()
    {
        Page::init();

        this->menuPageBtn.initButton(
            &tft,
            H_SPACING + 40,
            pageContentBox.getCaseCenterY(0),
            80,
            pageContentBox.getCaseHeight() / 2,
            colors[MENU_PAGE_BUTTON_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[MENU_PAGE_BUTTON_BACKGROUND_COLOR][FORMAT_COLOR_16],
            colors[MENU_PAGE_BUTTON_TEXT_COLOR][FORMAT_COLOR_16],
            (char *)"<-",
            2,
            2
        );
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

        this->menuPageBtn.press(down && this->menuPageBtn.contains(touchX, touchY));
        
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
