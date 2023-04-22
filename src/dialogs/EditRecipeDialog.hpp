
#pragma once

#include "Dialog.hpp"
#include "../components/Slider.hpp"
#include "../components/Box.hpp"

Slider *sliders[6] = {
    new Slider(dialogContentBox.getCaseX(0), dialogContentBox.getCaseY(0), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    new Slider(dialogContentBox.getCaseX(1), dialogContentBox.getCaseY(1), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    new Slider(dialogContentBox.getCaseX(2), dialogContentBox.getCaseY(2), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    new Slider(dialogContentBox.getCaseX(3), dialogContentBox.getCaseY(3), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    new Slider(dialogContentBox.getCaseX(4), dialogContentBox.getCaseY(4), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    new Slider(dialogContentBox.getCaseX(5), dialogContentBox.getCaseY(5), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
};

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

        for (int i = 0; i < 6; i++)
            sliders[i]->init();
    }

    void render()
    {
        Dialog::render();

        for (int i = 0; i < 6; i++)
        {
            sliders[i]->setValue(recipes[selectedRecipe].getQuantity(i));
            sliders[i]->render();
        }
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < 6; i++)
            sliders[i]->update(down);

        if (down && !this->container.contains(pixelX, pixelY))
        {
            for (int i = 0; i < 6; i++)
                recipes[selectedRecipe].setQuantity(i, sliders[i]->getValue());
            return RECIPES_PAGE;
        }

        return -1;
    }
};
