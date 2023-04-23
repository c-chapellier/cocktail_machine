
#pragma once

#include "../global.hpp"

class RGBStrip : public Hardware
{
public:
    enum Mode { RAINBOW = 0, UNICOLOR = 1 };

private:
    const uint16_t numLeds;
    Adafruit_NeoPixel leds;
    RGBStrip::Mode mode;
    uint32_t cycle = 0, unicolor_mode_color = 0;
    uint8_t brightness = 255;

public:
    RGBStrip(uint16_t numLeds, uint16_t pin, RGBStrip::Mode mode)
        : numLeds(numLeds), leds(numLeds, pin, NEO_GRB + NEO_KHZ800), mode(mode)
    {}

    void init()
    {
        this->leds.begin();
        this->leds.clear();
        this->leds.show();
    }

    // void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void update()
    {
        switch (this->mode)
        {
        case RGBStrip::Mode::RAINBOW:
            this->leds.rainbow(cycle, 1, 255, this->brightness, true);
            break;
        case RGBStrip::Mode::UNICOLOR:
            this->leds.setBrightness(this->brightness);
            this->leds.fill(this->unicolor_mode_color, 0, this->leds.numPixels());
            break;
        }

        this->leds.show();
        cycle += 65536 / 20;
        delay(100);
    }

    void setMode(Mode mode)
    {
        this->mode = mode;
    }

    void setUnicolorModeColor(uint32_t color)
    {
        this->unicolor_mode_color = color;
    }

    void setBrightness(uint8_t brightness)
    {
        this->brightness = brightness;
    }
};
