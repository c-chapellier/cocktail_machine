
#pragma once

#include "global.hpp"

class EditRecipeDialog2 : public Dialog
{
private:
    Adafruit_GFX_Button nextEditDialogBtn, editRecipeNameBtn;

public:
    EditRecipeDialog2()
        : Dialog()
    {}

    ~EditRecipeDialog2() {}

    void init()
    {
        Dialog::init();

        this->editRecipeNameBtn.initButton(
            &tft,
            dialogContentBox.getCaseCenterX(0),
            dialogContentBox.getCaseCenterY(0),
            dialogContentBox.getCaseWidth(),
            dialogContentBox.getCaseHeight(),
            colors[DEFAULT_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[DEFAULT_BACKGROUND_COLOR][FORMAT_COLOR_16],
            colors[DEFAULT_TEXT_COLOR][FORMAT_COLOR_16],
            (char *)recipes[selectedRecipe].getName(),
            2,
            2
        );

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

        this->editRecipeNameBtn.drawButton(false);
        this->nextEditDialogBtn.drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        this->editRecipeNameBtn.press(down && this->editRecipeNameBtn.contains(touchX, touchY));
        if (this->editRecipeNameBtn.justReleased())
            this->editRecipeNameBtn.drawButton(false);
        if (this->editRecipeNameBtn.justPressed())
        {
            this->editRecipeNameBtn.drawButton(true);
            return EDIT_RECIPE_NAME_DIALOG;
        }

        this->nextEditDialogBtn.press(down && this->nextEditDialogBtn.contains(touchX, touchY));
        if (this->nextEditDialogBtn.justReleased())
            this->nextEditDialogBtn.drawButton(false);
        if (this->nextEditDialogBtn.justPressed())
        {
            this->nextEditDialogBtn.drawButton(true);
            return EDIT_RECIPE_DIALOG_1;
        }

        if (down && !this->container.contains(touchX, touchY))
            return RECIPES_PAGE;

        return -1;
    }
};
