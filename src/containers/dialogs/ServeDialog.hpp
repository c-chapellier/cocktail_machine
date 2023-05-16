
#pragma once

#include "global.hpp"

class ServeDialog : public Dialog
{
private:
    Adafruit_GFX_Button startBtn, stopBtn;
    Adafruit_GFX_Button titleContainer;
    Slider progressBar = Slider(NULL, dialogContentBox.getCaseX(0), dialogContentBox.getCenterY() - dialogContentBox.getCaseHeight()/2, dialogContentBox.getCaseWidth()*2 + dialogContentBox.getHSpacing(), dialogContentBox.getCaseHeight());
    const int nStep = 10;
    int currentStep = 0;

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

    void startRoutine()
    {
        rgbStrip.setMode(RGBStrip::Mode::UNICOLOR);
        rgbStrip.setUnicolorModeColor(colors[recipes[selectedRecipe].getColorCode()][FORMAT_COLOR_32]);
    }

    bool step()
    {
        if (this->checkStop(getTouch())) return false;
        if (this->currentStep >= this->nStep) return true;

        this->progressBar.setValue(this->currentStep * 10);
        this->progressBar.render();

        rgbStrip.setBrightness(this->currentStep * 25);
        rgbStrip.update();

        ++this->currentStep;
        return true;
    }

    bool serveLiquid(int i, double volume)
    {
        valves[i].open();

        long int startValve = millis(), startVolumeCount = startValve, now = startValve;
        while (now - startValve < 1000*volume / DEBIT_PER_SECOND)
        {
            // if (tanks[i].checkLevel())
            //     startVolumeCount = millis();
        
            if (this->checkStop(getTouch())) return false;

            now = millis();
        }
        valves[i].close();

        Serial.println("Served " + String(volume) + "cl of " + String(i));
        Serial.println("Time: " + String(now - startValve) + "ms");
        Serial.println("Theoric time: " + String(1000*volume / DEBIT_PER_SECOND) + "ms");
        Serial.println("Weight: " + String(loadCell.read()) + "g");

        // tanks[i].serve((now - startVolumeCount) * DEBIT_PER_MILLIS);
        
        this->step();

        return true;
    }

    void endRoutine()
    {
        this->progressBar.setValue(100);
        this->progressBar.render();

        for (int i = 0; i < 3; ++i)
        {
            rgbStrip.setBrightness(0);
            rgbStrip.update();
            delay(500);
            if (this->checkStop(getTouch())) return;

            rgbStrip.setBrightness(255);
            rgbStrip.update();
            delay(500);
            if (this->checkStop(getTouch())) return;
        }

        rgbStrip.setMode(RGBStrip::Mode::RAINBOW);
        rgbStrip.setBrightness(255);
        rgbStrip.update();
    }

public:
    ServeDialog()
        : Dialog()
    {}

    ~ServeDialog() {}

    void init()
    {
        Dialog::init();

        this->titleContainer.initButton(&tft,
            pageContentBox.getCenterX(),
            dialogContentBox.getCaseCenterY(0),
            pageContentBox.getCaseWidth(),
            pageContentBox.getCaseHeight(),
            colors[DEFAULT_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[DEFAULT_BACKGROUND_COLOR][FORMAT_COLOR_16],
            colors[DEFAULT_TEXT_COLOR][FORMAT_COLOR_16],
            (char *)"Lets get this done",
            2,
            2
        );

        this->startBtn.initButton(&tft,
            dialogContentBox.getCaseCenterX(6),
            dialogContentBox.getCaseCenterY(6),
            dialogContentBox.getCaseWidth(),
            dialogContentBox.getCaseHeight(),
            colors[START_BUTTON_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[START_BUTTON_BACKGROUND_COLOR][FORMAT_COLOR_16],
            colors[START_BUTTON_TEXT_COLOR][FORMAT_COLOR_16],
            (char *)"START",
            2,
            2
        );

        this->stopBtn.initButton(&tft,
            dialogContentBox.getCaseCenterX(7),
            dialogContentBox.getCaseCenterY(7),
            dialogContentBox.getCaseWidth(),
            dialogContentBox.getCaseHeight(),
            colors[STOP_BUTTON_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[STOP_BUTTON_BACKGROUND_COLOR][FORMAT_COLOR_16],
            colors[STOP_BUTTON_TEXT_COLOR][FORMAT_COLOR_16],
            (char *)"STOP",
            2,
            2
        );
        
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

        if (this->checkStop(down))
            return SERVICE_PAGE;

        return -1;
    }

    bool serveRecipe()
    {
        double volume = 27.0;

        // for (int i = 0; i < NB_TANKS; ++i)
        //     if (tanks[i].canFill(recipes[selectedRecipe].getProportion(i) * volume))
        //         return false;

        this->startRoutine();

        if (this->checkStop(getTouch())) return false;
        if (!this->step()) return false;


        if (recipes[selectedRecipe].getIceQuantity() > 0)
        {
            for (int i = 0; i < 3; ++i)
            {
                stepperMotor.setDirection(false);
                for(int x = 0; x < STEPPER_MOTOR_STEPS_PER_REVOLUTION * 16 / 4; x++)
                    stepperMotor.step(-1);

                delay(1000);

                stepperMotor.setDirection(true);
                for(int x = 0; x < STEPPER_MOTOR_STEPS_PER_REVOLUTION * 16 / 4; x++)
                    stepperMotor.step(-1);

                delay(1000);

                if (this->checkStop(getTouch())) return false;
            }
        }

        if (this->checkStop(getTouch())) return false;
        if (!this->step()) return false;

        for (int i = 0; i < NB_TANKS; ++i)
        {
            double proportion = recipes[selectedRecipe].getProportion(i);

            if (proportion > 0.0 && !this->serveLiquid(i, proportion * volume))
                    return false;
        }

        this->endRoutine();
        return true;
    }
};
