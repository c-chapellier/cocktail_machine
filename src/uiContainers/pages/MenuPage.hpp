
#pragma once

#include "global.hpp"

class MenuPage : public Page
{
private:
    static const int nItems = 4;
    const int items[MenuPage::nItems] = { SERVICE_PAGE, RECIPES_PAGE, SETTINGS_PAGE, ABOUT_PAGE };
    Adafruit_GFX_Button btns[MenuPage::nItems];

public:
    MenuPage()
        : Page(translate(uiContainersNames[MENU_PAGE]))
    {}

    ~MenuPage() {}

    void init()
    {
        Page::init();

        for (int i = 0; i < MenuPage::nItems; i++)
        {
            this->btns[i].initButton(
                &tft,
                pageContentBox.getCaseCenterX(2 + i),
                pageContentBox.getCaseCenterY(2 + i),
                pageContentBox.getCaseWidth(),
                pageContentBox.getCaseHeight(),
                colors[i + 1][FORMAT_COLOR_16],
                TFT_BLACK,
                colors[i + 1][FORMAT_COLOR_16],
                (char *)translate(uiContainersNames[this->items[i]]),
                2,
                2
            );
        }
    }

    void render()
    {
        Page::render();

        for (int i = 0; i < MenuPage::nItems; i++)
            this->btns[i].drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = Page::update(down);
        if (nextPage != -1) return nextPage;

        for (int i = 0; i < MenuPage::nItems; i++)
        {
            this->btns[i].press(down && this->btns[i].contains(touchX, touchY));
            if (this->btns[i].justReleased())
                this->btns[i].drawButton(false);
            if (this->btns[i].justPressed())
            {
                this->btns[i].drawButton(true);
                return this->items[i];
            }
        }

        return -1;
    }
};