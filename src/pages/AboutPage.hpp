
#pragma once

#include "NavigablePage.hpp"

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
    }

    int update(bool down)
    {
        return NavigablePage::update(down);
    }
};
