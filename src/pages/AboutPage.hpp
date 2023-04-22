
#pragma once

#include "../global.hpp"

class AboutPage : public NavigablePage
{
private:

public:
    AboutPage()
        : NavigablePage("About")
    {}

    ~AboutPage() {}

    void init()
    {
        NavigablePage::init();
    }

    void render()
    {
        NavigablePage::render();

        // tft.drawRGBBitmap(pageContentBox.getCaseX(0), pageContentBox.getCaseY(0), bmp, pageContentBox.getW() - pageContentBox.getHSpacing()*2, pageContentBox.getH() - pageContentBox.getVSpacing()*2);
    }

    int update(bool down)
    {
        return NavigablePage::update(down);
    }
};
