
#pragma once

#include "../../global.hpp"

class SettingsPage : public NavigablePage
{
private:
    Adafruit_GFX_Button langugesBtns[N_LANGUAGES];

public:
    SettingsPage()
        : NavigablePage(translate(uiContainersNames[SETTINGS_PAGE]))
    {}

    ~SettingsPage() {}

    void init()
    {
        NavigablePage::init();

        for (int i = 0; i < N_LANGUAGES; i++)
        {
            this->langugesBtns[i].initButton(
                &tft,
                pageContentBox.getCaseCenterX(0),
                pageContentBox.getCaseCenterY(2) - pageContentBox.getCaseHeight()/4 + i * (pageContentBox.getCaseHeight()/2 + pageContentBox.getVSpacing()),
                pageContentBox.getCaseWidth(),
                pageContentBox.getCaseHeight()/2,
                TFT_WHITE,
                TFT_BLACK,
                TFT_WHITE,
                (char *)translate(languagesNames[i]),
                2
            );
        }
    }

    void render()
    {
        NavigablePage::render();

        for (int i = 0; i < N_LANGUAGES; i++)
            this->langugesBtns[i].drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = NavigablePage::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < N_LANGUAGES; i++)
        {
            this->langugesBtns[i].press(down && this->langugesBtns[i].contains(touchX, touchY));
            
            if (this->langugesBtns[i].justReleased())
                this->langugesBtns[i].drawButton(false);
                    
            if (this->langugesBtns[i].justPressed())
            {
                this->langugesBtns[i].drawButton(true);
                language = i;
                setup();
                this->render();
                return -1;
            }
        }

        return -1;
    }
};
