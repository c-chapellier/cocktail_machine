
#pragma once

#include "Dialog.hpp"

class EditRecipeDialog : public Dialog
{
private:
    Slider sliders[6];

public:
    EditRecipeDialog()
        : Dialog()
    {
        for (int i = 0; i < 6; i++)
            this->sliders[i] = Slider(recipes[selectedRecipe].getQuantity(i));
    }

    ~EditRecipeDialog() {}

    void init()
    {
        Dialog::init();

        for (int i = 0; i < 6; i++)
            this->sliders[i].init();
    }

    void render()
    {
        Dialog::render();

        for (int i = 0; i < 6; i++)
            this->sliders[i].render();
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < 6; i++)
            this->sliders[i].update(down);

        if (down && !this->container.contains(pixelX, pixelY))
        {
            for (int i = 0; i < 6; i++)
                recipes[selectedRecipe].setQuantity(i, this->sliders[i].getValue());
            return RECIPES_PAGE;
        }

        return -1;
    }
};
