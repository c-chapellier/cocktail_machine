
#pragma once

#include "global.hpp"

class ManualControlPage : public NavigablePage
{
private:
    Adafruit_GFX_Button tanksBtns[TANKS_COUNT + 1];

public:
    ManualControlPage()
        : NavigablePage(translate(uiContainersNames[MANUAL_CONTROL_PAGE]))
    {}

    ~ManualControlPage() {}

    void init()
    {
        NavigablePage::init();

        for (int i = 0; i < TANKS_COUNT + 1; i++)
        {
            const char tankName[] = { '1' + i, '\0' };

            this->tanksBtns[i].initButton(
                &tft,
                pageContentBox.getCaseCenterX(2 + i),
                pageContentBox.getCaseCenterY(2 + i),
                pageContentBox.getCaseWidth(),
                pageContentBox.getCaseHeight(),
                colors[recipes[i].getColorCode()][FORMAT_COLOR_16],
                colors[DEFAULT_BACKGROUND_COLOR][FORMAT_COLOR_16],
                colors[recipes[i].getColorCode()][FORMAT_COLOR_16],
                (char *)(i == 6 ? translate(vidangeName) : tankName),
                2,
                2
            );
        }
    }

    void render()
    {
        NavigablePage::render();

        for (int i = 0; i < TANKS_COUNT + 1; i++)
            this->tanksBtns[i].drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = NavigablePage::update(down);
        if (nextPage != -1)
        {
            for (int i = 0; i < TANKS_COUNT; ++i)
                valves[i].close();
            return nextPage;
        }

        for (int i = 0; i < TANKS_COUNT + 1; i++)
        {
            this->tanksBtns[i].press(down && this->tanksBtns[i].contains(touchX, touchY));

            if (this->tanksBtns[i].justReleased())
            {
                for (int j = 0; j < TANKS_COUNT; ++j)
                    valves[j].close();
                this->tanksBtns[i].drawButton(false);
            }

            if (this->tanksBtns[i].justPressed())
            {
                if (i == 6)
                    for (int j = 0; j < TANKS_COUNT; ++j)
                        valves[j].open();
                else valves[i].open();

                this->tanksBtns[i].drawButton(true);
                return -1;
            }
        }

        return -1;
    }
};
