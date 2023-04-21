
#pragma once

#include "Page.hpp"

class MenuPage : public Page
{
private:
    Adafruit_GFX_Button servicePageBtn, recipesPageBtn, settingsPageBtn, aboutPageBtn;

public:
    MenuPage()
        : Page("Menu")
    {}

    ~MenuPage() {}

    void init()
    {
        Page::init();

        this->servicePageBtn.initButton(&tft, CASE_X(0), CASE_Y(1), CASE_WIDTH, CASE_HEIGHT, TFT_WHITE, TFT_BLACK, TFT_WHITE, "Service", 2);
        this->recipesPageBtn.initButton(&tft, CASE_X(1), CASE_Y(1), CASE_WIDTH, CASE_HEIGHT, TFT_WHITE, TFT_BLACK, TFT_WHITE, "Recettes", 2);
        this->settingsPageBtn.initButton(&tft, CASE_X(0), CASE_Y(2), CASE_WIDTH, CASE_HEIGHT, TFT_WHITE, TFT_BLACK, TFT_WHITE, "Parametres", 2);
        this->aboutPageBtn.initButton(&tft, CASE_X(1), CASE_Y(2), CASE_WIDTH, CASE_HEIGHT, TFT_WHITE, TFT_BLACK, TFT_WHITE, "A propos", 2);
    }

    void render()
    {
        Page::render();

        this->servicePageBtn.drawButton(false);
        this->recipesPageBtn.drawButton(false);
        this->settingsPageBtn.drawButton(false);
        this->aboutPageBtn.drawButton(false);
    }

    int update(bool down)
    {
        int nextPage = Page::update(down);
        if (nextPage != -1) return nextPage;

        this->servicePageBtn.press(down && this->servicePageBtn.contains(pixelX, pixelY)); 
        if (this->servicePageBtn.justReleased())
            this->servicePageBtn.drawButton(false);    
        if (this->servicePageBtn.justPressed())
        {
            this->servicePageBtn.drawButton(true);
            return SERVICE_PAGE;
        }

        this->recipesPageBtn.press(down && this->recipesPageBtn.contains(pixelX, pixelY)); 
        if (this->recipesPageBtn.justReleased())
            this->recipesPageBtn.drawButton(false);    
        if (this->recipesPageBtn.justPressed())
        {
            this->recipesPageBtn.drawButton(true);
            return RECIPES_PAGE;
        }

        this->settingsPageBtn.press(down && this->settingsPageBtn.contains(pixelX, pixelY)); 
        if (this->settingsPageBtn.justReleased())
            this->settingsPageBtn.drawButton(false);    
        if (this->settingsPageBtn.justPressed())
        {
            this->settingsPageBtn.drawButton(true);
            return SETTINGS_PAGE;
        }

        this->aboutPageBtn.press(down && this->aboutPageBtn.contains(pixelX, pixelY)); 
        if (this->aboutPageBtn.justReleased())
            this->aboutPageBtn.drawButton(false);    
        if (this->aboutPageBtn.justPressed())
        {
            this->aboutPageBtn.drawButton(true);
            return ABOUT_PAGE;
        }

        return -1;
    }
};