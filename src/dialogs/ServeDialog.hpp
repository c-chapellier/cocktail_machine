
#pragma once

#include "../global.hpp"

class ServeDialog : public Dialog
{
private:
    Adafruit_GFX_Button startBtn, stopBtn;
    Adafruit_GFX_Button titleContainer;
    Slider progressBar = Slider(NULL, dialogContentBox.getCaseX(0), dialogContentBox.getCenterY() - dialogContentBox.getCaseHeight()/2, dialogContentBox.getCaseWidth()*2 + dialogContentBox.getHSpacing(), dialogContentBox.getCaseHeight());

public:
    ServeDialog()
        : Dialog()
    {}

    ~ServeDialog() {}

    void init()
    {
        Dialog::init();

        this->titleContainer.initButton(&tft, pageContentBox.getCenterX(), dialogContentBox.getCaseCenterY(0), pageContentBox.getCaseWidth(), pageContentBox.getCaseHeight(), TFT_WHITE, TFT_BLACK, TFT_WHITE, (char *)"Lets get this done", 2);
        this->startBtn.initButton(&tft, dialogContentBox.getCaseCenterX(6), dialogContentBox.getCaseCenterY(6), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight(), TFT_WHITE, TFT_GREEN, TFT_WHITE, (char *)"START", 2);
        this->stopBtn.initButton(&tft, dialogContentBox.getCaseCenterX(7), dialogContentBox.getCaseCenterY(7), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight(), TFT_WHITE, TFT_RED, TFT_WHITE, (char *)"STOP", 2);
        
        this->progressBar.init();
    }

    void render()
    {
        Dialog::render();

        this->titleContainer.drawButton(false);
        this->startBtn.drawButton(false);
        this->stopBtn.drawButton(false);

        this->progressBar.setValue(0);
        this->progressBar.render();
    }

    int update(bool down)
    {
        int nextPage = Dialog::update(down);
        if (nextPage != -1) return nextPage;

        this->startBtn.press(down && this->startBtn.contains(touchX, touchY));
        if (this->startBtn.justReleased())
            this->startBtn.drawButton(false);
        if (this->startBtn.justPressed())
        {
            this->startBtn.drawButton(true);
            
            this->serveRecipe();
            return SERVICE_PAGE;
        }

        if (checkStop(down))
            return SERVICE_PAGE;

        return -1;
    }

    int checkStop(bool down)
    {
        this->stopBtn.press(down && this->stopBtn.contains(touchX, touchY));

        if (this->stopBtn.justReleased())
            this->stopBtn.drawButton(false);

        if (this->stopBtn.justPressed())
        {
            this->stopBtn.drawButton(true);
            return 1;
        }

        return 0;
    }

    void serveRecipe()
    {
        rgbStrip.setMode(RGBStrip::Mode::UNICOLOR);
        rgbStrip.setUnicolorModeColor(colors[recipes[selectedRecipe].getColorCode()][FORMAT_COLOR_32]);

        for (int i = 0; i < 11; i++)
        {
            this->progressBar.setValue(i * 10);
            this->progressBar.render();

            rgbStrip.setBrightness(i * 25);
            rgbStrip.update();

            delay(500);
            if (checkStop(touchGetXY())) return;
        }

        for (int i = 0; i < 3; i++)
        {
            rgbStrip.setBrightness(0);
            rgbStrip.update();
            delay(500);
            if (checkStop(touchGetXY())) return;

            rgbStrip.setBrightness(255);
            rgbStrip.update();
            delay(500);
            if (checkStop(touchGetXY())) return;
        }

        rgbStrip.setMode(RGBStrip::Mode::RAINBOW);
        rgbStrip.setBrightness(255);
        rgbStrip.update();
    }
};
