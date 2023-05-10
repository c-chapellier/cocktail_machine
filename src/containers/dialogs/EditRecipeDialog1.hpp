
#pragma once

#include "global.hpp"

class EditRecipeDialog1 : public Dialog
{
private:
    Slider sliders[7] = {
        Slider(translate(physicalContainersNames[0]), dialogContentBox.getCaseX(0), dialogContentBox.getCaseY(0), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[1]), dialogContentBox.getCaseX(1), dialogContentBox.getCaseY(1), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[2]), dialogContentBox.getCaseX(2), dialogContentBox.getCaseY(2), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[3]), dialogContentBox.getCaseX(3), dialogContentBox.getCaseY(3), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[4]), dialogContentBox.getCaseX(4), dialogContentBox.getCaseY(4), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(physicalContainersNames[5]), dialogContentBox.getCaseX(5), dialogContentBox.getCaseY(5), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
        Slider(translate(iceContainerName), dialogContentBox.getCaseX(6), dialogContentBox.getCaseY(6), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    };
    Adafruit_GFX_Button nextEditDialogBtn;

public:
    EditRecipeDialog1()
        : Dialog()
    {}

    ~EditRecipeDialog1() {}

    void init()
    {
        Dialog::init();

        for (int i = 0; i < 7; i++)
            this->sliders[i].init();

        this->nextEditDialogBtn.initButton(
            &tft,
            dialogContentBox.getCaseCenterX(7),
            dialogContentBox.getCaseCenterY(7),
            dialogContentBox.getCaseWidth(),
            dialogContentBox.getCaseHeight(),
            colors[DEFAULT_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[DEFAULT_BACKGROUND_COLOR][FORMAT_COLOR_16],
            colors[DEFAULT_TEXT_COLOR][FORMAT_COLOR_16],
            (char *)"-->",
            2,
            2
        );
    }

    void render()
    {
        Dialog::render();

        for (int i = 0; i < 7; i++)
        {
            this->sliders[i].setValue(recipes[selectedRecipe].getQuantity(i));
            this->sliders[i].render();
        }

        this->nextEditDialogBtn.drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < 7; i++)
            this->sliders[i].update(down);

        this->nextEditDialogBtn.press(down && this->nextEditDialogBtn.contains(touchX, touchY));
        if (this->nextEditDialogBtn.justReleased())
            this->nextEditDialogBtn.drawButton(false);  
        if (this->nextEditDialogBtn.justPressed())
        {
            this->nextEditDialogBtn.drawButton(true);
            return EDIT_RECIPE_DIALOG_2;
        }

        if (down && !this->container.contains(touchX, touchY))
        {
            for (int i = 0; i < 7; i++)
                recipes[selectedRecipe].setQuantity(i, this->sliders[i].getValue());
            return RECIPES_PAGE;
        }

        return -1;
    }
};
