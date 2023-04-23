
#pragma once

#include "../../global.hpp"

class SettingsPage : public NavigablePage
{
private:

public:
    SettingsPage()
        : NavigablePage(translate(uiContainersNames[SETTINGS_PAGE]))
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
