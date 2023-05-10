
#pragma once

#include "global.hpp"

class EditRecipeNameDialog : public Dialog
{
private:
    static const int keyBtnsCount = 26 + 3;
    Adafruit_GFX_Button keyBtns[keyBtnsCount]; // 26 letters + space + backspace + enter
    const char keys[keyBtnsCount + 1] = "QWERTYUIOP<ASDFGHJKL>ZXCVBNM ";

    const int keyWidth = 25, keyHeight = 25, keySpacing = 4;

    char recipeName[100];
    int recipeNameLength;

public:
    EditRecipeNameDialog()
        : Dialog()
    {
        this->recipeName[0] = 'a';
        this->recipeName[1] = 'b';
        this->recipeName[2] = '\0';
        this->recipeNameLength = 2;
    }

    ~EditRecipeNameDialog() {}

    void init()
    {
        Dialog::init();

        for (int i = 0; i < keyBtnsCount; i++)
        {
            const char keyName[2] = { keys[i], '\0' };

            const int keyboardOriginX = dialogContentBox.getCenterX() - dialogContentBox.getW()/2;
            const int keyboardOriginY = dialogContentBox.getCenterY() + dialogContentBox.getH()/2 - this->keyHeight*3 - this->keySpacing*4;

            int x, y;
            switch (i)
            {
            case 0 ... 10:
                x = keyboardOriginX + (dialogContentBox.getW() - (11*(this->keyWidth + this->keySpacing)))/2 + i*(this->keyWidth + this->keySpacing) + this->keyWidth/2;
                y = keyboardOriginY + this->keySpacing;
                break;
            case 11 ... 20:
                x = keyboardOriginX + (dialogContentBox.getW() - (10*(this->keyWidth + this->keySpacing)))/2 + (i-11)*(this->keyWidth + this->keySpacing) + this->keyWidth/2;
                y = keyboardOriginY + this->keySpacing*2 + this->keyHeight;
                break;
            case 21 ... 28:
                x = keyboardOriginX + (dialogContentBox.getW() - (8*(this->keyWidth + this->keySpacing)))/2 + (i-21)*(this->keyWidth + this->keySpacing) + this->keyWidth/2;
                y = keyboardOriginY + this->keySpacing*3 + this->keyHeight*2;
                break;
            }

            this->keyBtns[i].initButton(
                &tft,
                x,
                y,
                this->keyHeight,
                this->keyHeight,
                colors[DEFAULT_OUTLINE_COLOR][FORMAT_COLOR_16],
                colors[DEFAULT_BACKGROUND_COLOR][FORMAT_COLOR_16],
                colors[DEFAULT_TEXT_COLOR][FORMAT_COLOR_16],
                (char *)keyName,
                2,
                2
            );
        }
    }

    void render()
    {
        Dialog::render();

        for (int i = 0; i < keyBtnsCount; i++)
            this->keyBtns[i].drawButton(false);

        this->renderText();
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < keyBtnsCount; i++)
        {
            if (this->keyBtns[i].contains(touchX, touchY))
            {
                this->keyBtns[i].press(down && !this->keyBtns[i].isPressed());
                if (this->keyBtns[i].justReleased())
                    this->keyBtns[i].drawButton(false);
                if (this->keyBtns[i].justPressed())
                {
                    this->keyBtns[i].drawButton(true);
                    if (this->keys[i] == '<')
                    {
                        if (this->recipeNameLength > 0)
                        {
                            this->recipeName[this->recipeNameLength - 1] = '\0';
                            --this->recipeNameLength;
                        }
                    }
                    else if (this->keys[i] == '>')
                    {
                        return EDIT_RECIPE_DIALOG_2;
                    }
                    else
                    {
                        this->recipeName[this->recipeNameLength] = this->keys[i];
                        this->recipeName[this->recipeNameLength + 1] = '\0';
                        ++this->recipeNameLength;
                    }
                    this->renderText();
                    return -1;
                }
            }
        }

        return -1;
    }

    void renderText()
    {
        tft.setCursor(dialogContentBox.getCenterX() - dialogContentBox.getW()/2 + 20, dialogContentBox.getCenterY() - 20);
        tft.setTextColor(colors[DEFAULT_TEXT_COLOR][FORMAT_COLOR_16]);
        tft.setTextSize(2);
        tft.print(this->recipeName);
    }
};
