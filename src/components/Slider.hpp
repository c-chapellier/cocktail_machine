
#pragma once

#include "../global.hpp"

class Slider : public Container
{
private:
    const char *name;
    const int x, y, w, h;
    int value = 0;          // 0-100

public:
    Slider(const char *name, int x, int y, int w, int h)
        : name(name), x(x), y(y), w(w), h(h)
    {}

    virtual void init() {}

    virtual void render()
    {
        tft.drawRect(this->x, this->y, this->w, this->h, TFT_WHITE);
        tft.fillRect(this->x + 2, this->y + 2, this->w - 4, this->h - 4, TFT_BLACK);
        tft.fillRect(this->x + 2, this->y + 2, ((long int)(this->w - 4)) * this->value/100, this->h - 4, TFT_WHITE);

        if (this->name != NULL)
        {
            tft.setCursor(this->x, this->y);
            tft.setTextColor(TFT_RED, TFT_CYAN);
            tft.setTextSize(2);
            tft.setTextWrap(true);
            tft.print(this->name);
        }

        tft.setCursor(this->x, this->y + 18);
        tft.setTextColor(TFT_CYAN, TFT_RED);
        tft.setTextSize(2);
        tft.setTextWrap(true);
        tft.print(this->value);
    }

    virtual int update(bool down)
    {
        if (down && (x <= touchX && touchX <= x + w && y <= touchY && touchY <= y + h))
        {
            this->value = (touchX - x) * 100/w;
            this->render();
        }

        return -1;
    }

    int getValue() const
    {
        return this->value;
    }

    void setValue(int value)
    {
        if (value < 0 || value > 100)
            return;

        this->value = value;
    }
};
