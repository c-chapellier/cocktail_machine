
#pragma once

#include "global.hpp"

class SettingsPage : public NavigablePage
{
private:
    Adafruit_GFX_Button langugesBtns[N_LANGUAGES];
    Adafruit_GFX_Button colorModeBtns[N_COLOR_MODES];

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
                colors[SETTINGS_BUTTON_OUTLINE_COLOR][FORMAT_COLOR_16],
                colors[SETTINGS_BUTTON_BACKGROUND_COLOR][FORMAT_COLOR_16],
                colors[SETTINGS_BUTTON_TEXT_COLOR][FORMAT_COLOR_16],
                (char *)translate(languagesNames[i]),
                2,
                2
            );
        }

        for (int i = 0; i < N_COLOR_MODES; i++)
        {
            this->colorModeBtns[i].initButton(
                &tft,
                pageContentBox.getCaseCenterX(1),
                pageContentBox.getCaseCenterY(2) - pageContentBox.getCaseHeight()/4 + i * (pageContentBox.getCaseHeight()/2 + pageContentBox.getVSpacing()),
                pageContentBox.getCaseWidth(),
                pageContentBox.getCaseHeight()/2,
                colors[SETTINGS_BUTTON_OUTLINE_COLOR][FORMAT_COLOR_16],
                colors[SETTINGS_BUTTON_BACKGROUND_COLOR][FORMAT_COLOR_16],
                colors[SETTINGS_BUTTON_TEXT_COLOR][FORMAT_COLOR_16],
                (char *)translate(colorModesNames[i]),
                2,
                2
            );
        }
    }

    void render()
    {
        NavigablePage::render();

        for (int i = 0; i < N_LANGUAGES; i++)
            this->langugesBtns[i].drawButton(false);

        for (int i = 0; i < N_COLOR_MODES; i++)
            this->colorModeBtns[i].drawButton(false);
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

        for (int i = 0; i < N_COLOR_MODES; i++)
        {
            this->colorModeBtns[i].press(down && this->colorModeBtns[i].contains(touchX, touchY));
            
            if (this->colorModeBtns[i].justReleased())
                this->colorModeBtns[i].drawButton(false);
                    
            if (this->colorModeBtns[i].justPressed())
            {
                this->colorModeBtns[i].drawButton(true);
                colorMode = i;
                setup();
                this->render();
                return -1;
            }
        }

        return -1;
    }
};
