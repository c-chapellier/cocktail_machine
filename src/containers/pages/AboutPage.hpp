
#pragma once

#include "global.hpp"

class AboutPage : public NavigablePage
{
private:

public:
    AboutPage()
        : NavigablePage(translate(uiContainersNames[ABOUT_PAGE]))
    {}

    ~AboutPage() {}

    void init()
    {
        NavigablePage::init();
    }

    void render()
    {
        NavigablePage::render();

        int originX = dialogContentBox.getCenterX(), originY = dialogContentBox.getCenterY();

        int r1 = 90, r2 = 110;

        // tft.drawCircle(originX, originY, 90, TFT_WHITE);
        // tft.drawCircle(originX, originY, 110, TFT_WHITE);

        int n = 13;
        for (int i = 0; i < n; i++)
        {            
            float angle1 = 2*PI * i / n;
            int x1 = originX + r1*cos(angle1);
            int y1 = originY + r1*sin(angle1);

            float angle2 = 2*PI * (i + .15) / n;
            int x2 = originX + r2*cos(angle2);
            int y2 = originY + r2*sin(angle2);

            float angle3 = 2*PI * (i + .5) / n;
            int x3 = originX + r2*cos(angle3);
            int y3 = originY + r2*sin(angle3);

            float angle4 = 2*PI * (i + .65) / n;
            int x4 = originX + r1*cos(angle4);
            int y4 = originY + r1*sin(angle4);

            float angle5 = 2*PI * (i + 1) / n;

            tft.drawLine(x1, y1, x2, y2, TFT_WHITE);

            for (float i = angle2; i < angle3; i += .005)
                tft.drawPixel(originX + cos(i)*r2, originY + sin(i)*r2, TFT_WHITE);

            tft.drawLine(x3, y3, x4, y4, TFT_WHITE);

            for (float i = angle4; i < angle5; i += .005)
                tft.drawPixel(originX + cos(i)*r1, originY + sin(i)*r1, TFT_WHITE);

            delay(100);
        }

        delay(100);
        
        tft.setCursor(originX - 45, originY - 7);
        tft.setTextColor(TFT_WHITE);
        tft.setTextSize(2);
        tft.print("ISICLAMP");

        // tft.drawRGBBitmap(pageContentBox.getCaseX(0), pageContentBox.getCaseY(0), bmp, pageContentBox.getW() - pageContentBox.getHSpacing()*2, pageContentBox.getH() - pageContentBox.getVSpacing()*2);
    }

    int update(bool down)
    {
        return NavigablePage::update(down);
    }
};
