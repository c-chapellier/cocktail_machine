
#pragma once

#include "../global.hpp"

class EditRecipeDialog : public Dialog
{
private:

public:
    EditRecipeDialog()
        : Dialog()
    {}

    ~EditRecipeDialog() {}

    void init()
    {
        Dialog::init();

        for (int i = 0; i < 7; i++)
            sliders[i].init();
    }

    void render()
    {
        Dialog::render();

        for (int i = 0; i < 7; i++)
        {
            sliders[i].setValue(recipes[selectedRecipe].getQuantity(i));
            sliders[i].render();
        }
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < 7; i++)
            sliders[i].update(down);

        if (down && !this->container.contains(pixelX, pixelY))
        {
            for (int i = 0; i < 7; i++)
                recipes[selectedRecipe].setQuantity(i, sliders[i].getValue());
            return RECIPES_PAGE;
        }

        return -1;
    }
};
