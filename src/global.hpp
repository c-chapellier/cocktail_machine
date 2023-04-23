
#pragma once

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Adafruit_NeoPixel.h>

#include "helpers/i18n.hpp"
#include "helpers/colors.hpp"

#define RGB_STRIP_SIGNAL_PIN 47
#define RGB_STRIP_LEDS_COUNT 120

#define LANDSCAPE 1

#define MIN_PRESSURE 200
#define MAX_PRESSURE 1000

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

#define V_SPACING 10
#define H_SPACING 20

MCUFRIEND_kbv tft;

const int XP = 8, XM = A2, YP = A3, YM = 9;
const int TS_LEFT = 128, TS_RT = 910, TS_TOP = 960, TS_BOT = 93;
TouchScreen ts(XP, YP, XM, YM, 300);

int touchX, touchY;
bool touchGetXY();

void setup();

#include "Recipe.hpp"

// BLACK | NAVY | DARKGREEN | DARKCYAN | MAROON | PURPLE | OLIVE | LIGHTGREY | DARKGREY
// BLUE | GREEN | CYAN | RED | MAGENTA | YELLOW | WHITE | ORANGE | GREENYELLOW

#define RECIPES_COUNT 8

Recipe recipes[RECIPES_COUNT] = {
    Recipe("Mojito", CM_COLORS_GREEN, (int []){ 30, 10, 40, 0, 0, 0}, true),
    Recipe("Pina Colada", CM_COLORS_DARKCYAN, (int []){ 30, 10, 40, 0, 0, 0}, true),
    Recipe("Caipirinha", CM_COLORS_MAGENTA, (int []){ 30, 10, 40, 0, 0, 0}, true),
    Recipe("Cosmopolitan", CM_COLORS_YELLOW, (int []){ 30, 10, 40, 0, 0, 0}, true),
    Recipe("Margarita", CM_COLORS_PINK, (int []){ 30, 10, 40, 0, 0, 0}, true),
    Recipe("Grenadine", CM_COLORS_RED, (int []){ 30, 10, 40, 0, 0, 0}, true),
    Recipe("Ricard", CM_COLORS_YELLOW, (int []){ 30, 10, 40, 0, 0, 0}, true),
    Recipe("Spritz", CM_COLORS_RED, (int []){ 30, 10, 40, 0, 0, 0}, true)
};

int selectedRecipe = 0;

/* *************************************************************** *\
 *                            HARDWARE                             *
\* *************************************************************** */

#include "hardware/Hardware.hpp"
#include "hardware/RGBStrip.hpp"

RGBStrip rgbStrip(RGB_STRIP_LEDS_COUNT, RGB_STRIP_SIGNAL_PIN, RGBStrip::Mode::RAINBOW);

/* *************************************************************** *\
 *                          UI_CONTAINERS                          *
\* *************************************************************** */

#include "helpers/Box.hpp"

const Box pageContentBox(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT, H_SPACING, V_SPACING, 2, 5);
const Box dialogContentBox(SCREEN_WIDTH/2, V_SPACING + pageContentBox.getCaseHeight() + (SCREEN_HEIGHT - V_SPACING - pageContentBox.getCaseHeight()) / 2, SCREEN_WIDTH * 4/5, SCREEN_HEIGHT * 2/3, H_SPACING, V_SPACING, 2, 4);

/* *************************************************************** *\
 *                          UI_CONTAINERS                          *
\* *************************************************************** */

#include "uiContainers/UIContainer.hpp"

#include "uiContainers/components/Slider.hpp"

#include "uiContainers/dialogs/Dialog.hpp"
#include "uiContainers/dialogs/EditRecipeDialog.hpp"
#include "uiContainers/dialogs/ServeDialog.hpp"

#include "uiContainers/pages/Page.hpp"
#include "uiContainers/pages/MenuPage.hpp"
#include "uiContainers/pages/NavigablePage.hpp"
#include "uiContainers/pages/RecipesMenuPage.hpp"
#include "uiContainers/pages/SettingsPage.hpp"
#include "uiContainers/pages/AboutPage.hpp"
