
#pragma once

#include "global.hpp"

class Page : public UIContainer
{
private:
    const char *name;
    Adafruit_GFX_Button title;

public:
    Page(const char *name)
        : name(name)
    {}

    ~Page() {}

    virtual void init()
    {
        this->title.initButton(
            &tft,
            SCREEN_WIDTH / 2,
            pageContentBox.getCaseCenterY(0),
            pageContentBox.getCaseWidth(),
            pageContentBox.getCaseHeight(),
            colors[PAGE_TITLE_OUTLINE_COLOR][FORMAT_COLOR_16],
            colors[PAGE_TITLE_BACKGROUND_COLOR][FORMAT_COLOR_16],
            colors[PAGE_TITLE_TEXT_COLOR][FORMAT_COLOR_16],
            (char *)this->name,
            2,
            2
        );
    }

    virtual void render()
    {
        tft.fillScreen(colors[DEFAULT_BACKGROUND_COLOR][FORMAT_COLOR_16]);
        this->title.drawButton(false);

        this->logoHenallux();
    }

    virtual int update(bool down)
    {
        return -1;
    }

    void logoHenallux()
    {
        const int r = 18;
        const int spikeOffset = 8;

        int originX = SCREEN_WIDTH - 50, originY = pageContentBox.getCaseCenterY(0) - spikeOffset/2;

        float angle1 = 0;

        float angle2 = M_PI_4;
        int x2 = originX + r*cos(angle2);
        int y2 = originY + r*sin(angle2);

        float angle3 = M_PI_4 * 3;
        int x3 = originX + r*cos(angle3);
        int y3 = originY + r*sin(angle3);

        float angle4 = 2*M_PI;

        int x4 = originX;
        int y4 = originY + r + spikeOffset;

        for (float i = angle1; i < angle2; i += .005)
            tft.drawPixel(originX + cos(i)*r, originY + sin(i)*r, colors[HENALLUX_LOGO_COLOR][FORMAT_COLOR_16]);

        for (float i = angle3; i < angle4; i += .005)
            tft.drawPixel(originX + cos(i)*r, originY + sin(i)*r, colors[HENALLUX_LOGO_COLOR][FORMAT_COLOR_16]);

        tft.drawLine(x2, y2, x4, y4, colors[HENALLUX_LOGO_COLOR][FORMAT_COLOR_16]);
        tft.drawLine(x3, y3, x4, y4, colors[HENALLUX_LOGO_COLOR][FORMAT_COLOR_16]);

        tft.setCursor(originX - 11, originY - 7);
        tft.setTextColor(colors[HENALLUX_LOGO_COLOR][FORMAT_COLOR_16]);
        tft.setTextSize(1);
        tft.print("HENA");
        tft.setCursor(originX - 11, originY + 2);
        tft.print("LLUX");
    }
};
