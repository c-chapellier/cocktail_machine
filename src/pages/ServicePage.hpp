
#pragma once

#include "../global.hpp"

class ServicePage : public NavigablePage
{
private:
    Adafruit_GFX_Button recipesBtns[8];

public:
    ServicePage()
        : NavigablePage("Service")
    {}

    ~ServicePage() {}

    void init()
    {
        NavigablePage::init();

        for (int i = 0; i < 8; i++)
            this->recipesBtns[i].initButton(&tft, pageContentBox.getCaseCenterX(2 + i), pageContentBox.getCaseCenterY(2 + i), pageContentBox.getCaseWidth(), pageContentBox.getCaseHeight(), TFT_WHITE, TFT_BLACK, TFT_WHITE, (char *)recipes[i].getName(), 2);
    }

    void render()
    {
        NavigablePage::render();

        for (int i = 0; i < 8; i++)
            this->recipesBtns[i].drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = NavigablePage::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < 8; i++)
        {
            this->recipesBtns[i].press(down && this->recipesBtns[i].contains(pixelX, pixelY));
            
            if (this->recipesBtns[i].justReleased())
                this->recipesBtns[i].drawButton(false);
                    
            if (this->recipesBtns[i].justPressed())
            {
                this->recipesBtns[i].drawButton(true);
                selectedRecipe = i;
                return SERVE_DIALOG;
            }
        }

        return -1;
    }
};
