
#include "global.hpp"
#include "Container.hpp"
#include "pages/Page.hpp"
#include "pages/MenuPage.hpp"
#include "pages/ServicePage.hpp"
#include "pages/RecipesPage.hpp"
#include "pages/SettingsPage.hpp"
#include "pages/AboutPage.hpp"
#include "dialogs/ServeDialog.hpp"
#include "dialogs/EditRecipeDialog.hpp"
#include "components/Slider.hpp"

static bool touchGetXY();

Container *pages[] = {
    new MenuPage(),
    new ServicePage(),
    new RecipesPage(),
    new ServeDialog(),
    new SettingsPage(),
    new AboutPage(),
    new EditRecipeDialog()
};
int numPages = sizeof(pages) / sizeof(pages[0]);

void setup()
{
    Serial.begin(9600);
    
    tft.begin(tft.readID());
    tft.setRotation(LANDSCAPE);
    tft.fillScreen(TFT_BLACK);

    for (int i = 0; i < numPages; i++)
        pages[i]->init();
}

int currentPage = MENU_PAGE;
bool pageChanged = true;

void loop()
{
    if (pageChanged)
    {
        pages[currentPage]->render();
        pageChanged = false;
    }

    bool down = touchGetXY();
    int nextPage = pages[currentPage]->update(down);

    if (nextPage != -1)
    {
        currentPage = nextPage;
        pageChanged = true;
    }
}

static bool touchGetXY()
{
    TSPoint p = ts.getPoint();
    
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);      //because TFT control pins
    
    bool pressed = (p.z > MIN_PRESSURE && p.z < MAX_PRESSURE);
    if (pressed)
    {
        pixelX = map(p.y, TS_RT, TS_LEFT, 0, 480);
        pixelY = map(p.x, TS_TOP, TS_BOT, 0, 320);
    }
    
    return pressed;
}
