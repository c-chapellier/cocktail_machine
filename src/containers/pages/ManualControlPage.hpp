
#pragma once

#include "global.hpp"

class ManualControlPage : public NavigablePage
{
private:
    Adafruit_GFX_Button tanksBtns[NB_TANKS];

public:
    ManualControlPage()
        : NavigablePage(translate(uiContainersNames[recipeDialog]))
    {}

    ~ManualControlPage() {}

    void init()
    {
        NavigablePage::init();

        for (int i = 0; i < NB_TANKS; i++)
        {
            this->tanksBtns[i].initButton(
                &tft,
                pageContentBox.getCaseCenterX(2 + i),
                pageContentBox.getCaseCenterY(2 + i),
                pageContentBox.getCaseWidth(),
                pageContentBox.getCaseHeight(),
                colors[recipes[i].getColorCode()][FORMAT_COLOR_16],
                colors[DEFAULT_BACKGROUND_COLOR][FORMAT_COLOR_16],
                colors[recipes[i].getColorCode()][FORMAT_COLOR_16],
                (char *){ '1' + i, '\0' },
                2,
                2
            );
        }
    }

    void render()
    {
        NavigablePage::render();

        for (int i = 0; i < NB_TANKS; i++)
            this->tanksBtns[i].drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = NavigablePage::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < NB_TANKS; i++)
        {
            this->tanksBtns[i].press(down && this->tanksBtns[i].contains(touchX, touchY));
            
            if (this->tanksBtns[i].justReleased())
                this->tanksBtns[i].drawButton(false);
                    
            if (this->tanksBtns[i].justPressed())
            {
                this->tanksBtns[i].drawButton(true);
                return -1;
            }
        }

        return -1;
    }
};
