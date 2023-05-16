
#pragma once

#include "global.hpp"

class ServeDialog : public Dialog
{
private:
    static const double ICE_GRAMMS_TO_CL = .07;
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

        // rgbStrip.setBrightness(this->currentStep * 25);
        // rgbStrip.update();

        ++this->currentStep;
        return true;
    }

    bool serveIce(double desiredWeightInGramms)
    {
        if (desiredWeightInGramms <= 0.0)
            return true;

        double initialWeight = loadCell.readInGramms();
        int i = 0;
        
        Serial.println("Ice: desiredWeightInGramms " + String(desiredWeightInGramms) + "g");

        while (loadCell.readInGramms() - initialWeight < desiredWeightInGramms)
        {
            Serial.println("Ice: i: " + String(i));
            Serial.println("Ice: Weight: " + String(loadCell.readInGramms() - initialWeight) + "g");

            if (i > 10)
                break;

            stepperMotor.setDirection(false);
            for(int x = 0; x < STEPPER_MOTOR_MICROSTEPS_PER_REVOLUTION * 2./16.; x++)
                stepperMotor.step();

            delay(100);
            if (this->checkStop(getTouch())) return false;

            stepperMotor.setDirection(true);
            for(int x = 0; x < STEPPER_MOTOR_MICROSTEPS_PER_REVOLUTION * 2./16.; x++)
                stepperMotor.step();

            delay(200);
            if (this->checkStop(getTouch())) return false;
            
            ++i;
        }

        Serial.println("Ice: i: " + String(i));
        Serial.println("Ice: Weight: " + String(loadCell.readInGramms() - initialWeight) + "g");

        return true;
    }

    bool serveLiquid(int i, double volume)
    {
        double initialWeight = loadCell.readInGramms();
        
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

        Serial.println("Liquid: Served " + String(volume) + "cl of " + String(i));
        Serial.println("Liquid: Time: " + String(now - startValve) + "ms");
        Serial.println("Liquid: Theoric time: " + String(1000*volume / DEBIT_PER_SECOND) + "ms");
        Serial.println("Liquid: Weight: " + String(loadCell.readInGramms() - initialWeight) + "g");

        // tanks[i].serve((now - startVolumeCount) * (DEBIT_PER_SECOND / 1000.));
        // Serial.println("Liquid: tanks: volume total " + String(tanks[i].getVolume()) + "cl");
        // Serial.println("Liquid: tanks: volume restant " + String((now - startVolumeCount) * (DEBIT_PER_SECOND / 1000.)) + "cl");
        
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
            (char *)"Cocktail",
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
        double volume = 33.0;

        // do not take into account ice volume
        // for (int i = 0; i < TANKS_COUNT; ++i)
        // {
        //     if (tanks[i].canFill(recipes[selectedRecipe].getProportion(i) * volume))
        //     {
        //         Serial.println("tank can fill False " + String(i));
        //         return false;
        //     }
        // }

        this->startRoutine();

        if (this->checkStop(getTouch())) return false;
        if (!this->step()) return false;

        double initialWeight = loadCell.readInGramms();

        if (!this->serveIce(.7 * volume * recipes[selectedRecipe].getIceQuantity()))
            return false;

        double iceWeight = loadCell.readInGramms() - initialWeight;
        double iceVolume = iceWeight * ServeDialog::ICE_GRAMMS_TO_CL;

        Serial.println("Ice: Weight: " + String(iceWeight) + "g");
        Serial.println("Ice: Volume: " + String(iceVolume) + "cl");

        if (this->checkStop(getTouch())) return false;
        if (!this->step()) return false;

        for (int i = 0; i < TANKS_COUNT; ++i)
        {
            double proportion = recipes[selectedRecipe].getProportion(i);

            if (proportion > 0.0)
            {   
                rgbStrip.setUnicolorModeColor(colors[8 + i][FORMAT_COLOR_32]);
                rgbStrip.update();

                if (!this->serveLiquid(i, proportion * (volume - iceVolume)))
                    return false;
            }
        }

        this->endRoutine();
        return true;
    }
};
