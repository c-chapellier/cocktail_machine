
#pragma once

#include "../../global.hpp"

class EditRecipeDialog : public Dialog
{
private:
    Slider sliders[7] = {
        Slider(translate(physicalContainersNames[0]), dialogContentBox.getCaseX(0), dialogContentBox.getCaseY(0), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[1]), dialogContentBox.getCaseX(1), dialogContentBox.getCaseY(1), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[2]), dialogContentBox.getCaseX(2), dialogContentBox.getCaseY(2), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[3]), dialogContentBox.getCaseX(3), dialogContentBox.getCaseY(3), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[4]), dialogContentBox.getCaseX(4), dialogContentBox.getCaseY(4), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[5]), dialogContentBox.getCaseX(5), dialogContentBox.getCaseY(5), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(iceContainerName), dialogContentBox.getCaseX(6), dialogContentBox.getCaseY(6), dialogContentBox.getCaseWidth()*2 + dialogContentBox.getHSpacing(), dialogContentBox.getCaseHeight()),
    };

public:
    EditRecipeDialog()
        : Dialog()
    {}

    ~EditRecipeDialog() {}

    void init()
    {
        Dialog::init();

        for (int i = 0; i < 7; i++)
            this->sliders[i].init();
    }

    void render()
    {
        Dialog::render();

        for (int i = 0; i < 7; i++)
        {
            this->sliders[i].setValue(recipes[selectedRecipe].getQuantity(i));
            this->sliders[i].render();
        }
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < 7; i++)
            this->sliders[i].update(down);

        if (down && !this->container.contains(touchX, touchY))
        {
            for (int i = 0; i < 7; i++)
                recipes[selectedRecipe].setQuantity(i, this->sliders[i].getValue());
            return RECIPES_PAGE;
        }

        return -1;
    }
};
