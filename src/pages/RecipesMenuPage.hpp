
#pragma once

#include "../global.hpp"

class RecipesMenuPage : public NavigablePage
{
private:
    Adafruit_GFX_Button recipesBtns[RECIPES_COUNT];
    const int recipeDialog;

public:
    RecipesMenuPage(int recipeDialog)
        : NavigablePage(containerNames[recipeDialog]), recipeDialog(recipeDialog)
    {}

    ~RecipesMenuPage() {}

    void init()
    {
        NavigablePage::init();

        for (int i = 0; i < RECIPES_COUNT; i++)
        {
            this->recipesBtns[i].initButton(
                &tft, pageContentBox.getCaseCenterX(2 + i),
                pageContentBox.getCaseCenterY(2 + i),
                pageContentBox.getCaseWidth(),
                pageContentBox.getCaseHeight(),
                colors[recipes[i].getColorCode()][FORMAT_COLOR_16],
                TFT_BLACK,
                colors[recipes[i].getColorCode()][FORMAT_COLOR_16],
                (char *)recipes[i].getName(),
                2
            );
        }
    }

    void render()
    {
        NavigablePage::render();

        for (int i = 0; i < RECIPES_COUNT; i++)
            this->recipesBtns[i].drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = NavigablePage::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < RECIPES_COUNT; i++)
        {
            this->recipesBtns[i].press(down && this->recipesBtns[i].contains(touchX, touchY));
            
            if (this->recipesBtns[i].justReleased())
                this->recipesBtns[i].drawButton(false);
                    
            if (this->recipesBtns[i].justPressed())
            {
                this->recipesBtns[i].drawButton(true);
                selectedRecipe = i;
                return this->recipeDialog;
            }
        }

        return -1;
    }
};
