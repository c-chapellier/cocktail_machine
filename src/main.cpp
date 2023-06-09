
#include "global.hpp"

UIContainer *pages[] = {
    new MenuPage(),
    new RecipesMenuPage(SERVE_DIALOG),
    new RecipesMenuPage(EDIT_RECIPE_DIALOG),
    new ServeDialog(),
    new SettingsPage(),
    new AboutPage(),
    new EditRecipeDialog(),
    new ManualControlPage()
};
int numPages = sizeof(pages) / sizeof(pages[0]);

void setup()
{
    Serial.begin(9600);
    
    tft.begin(tft.readID());
    tft.setRotation(LANDSCAPE);
    tft.fillScreen(colors[APP_BACKGROUND_COLOR][FORMAT_COLOR_16]);

    for (int i = 0; i < numPages; i++)
        pages[i]->init();

    rgbStrip.init();
    stepperMotor.init();
    loadCell.init();
    for (int i = 0; i < TANKS_COUNT; ++i)
    {
        valves[i].init();
        levelSensors[i].init();
    }
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

    bool down = getTouch();
    int nextPage = pages[currentPage]->update(down);

    if (nextPage != -1)
    {
        currentPage = nextPage;
        pageChanged = true;
    }

    rgbStrip.update();
}

bool getTouch()
{
    TSPoint p = ts.getPoint();
    
    pinMode(YP, OUTPUT);
    pinMode(XM, OUTPUT);
    
    bool pressed = (p.z > MIN_PRESSURE && p.z < MAX_PRESSURE);
    if (pressed)
    {
        touchX = map(p.y, TS_LEFT, TS_RT, 0, 480);
        touchY = map(p.x, TS_BOT, TS_TOP, 0, 320);
    }
    
    return pressed;
}
