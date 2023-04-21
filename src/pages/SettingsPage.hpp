
#pragma once

#include "NavigablePage.hpp"

class SettingsPage : public NavigablePage
{
private:

public:
    SettingsPage()
        : NavigablePage("Settings")
    {}

    ~SettingsPage() {}

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
