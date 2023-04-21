
#pragma once

#include "NavigablePage.hpp"

class RecipesPage : public NavigablePage
{
private:
    Adafruit_GFX_Button recipesBtns[8];

public:
    RecipesPage()
        : NavigablePage("Recettes")
    {}

    ~RecipesPage() {}

    void init()
    {
        NavigablePage::init();

        for (int i = 0; i < 8; i++)
            this->recipesBtns[i].initButton(&tft, CASE_X(i % 2), CASE_Y(i / 2 + 1), CASE_WIDTH, CASE_HEIGHT, TFT_WHITE, TFT_BLACK, TFT_WHITE, recipes[i].getName().c_str(), 2);
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
                return EDIT_RECIPE_DIALOG;
            }
        }

        return -1;
    }
};