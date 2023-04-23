
#pragma once

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Adafruit_NeoPixel.h>

#define RGB_STRIP_SIGNAL_PIN 47
#define RGB_STRIP_LEDS_COUNT 120

#define LANDSCAPE 1

#define MIN_PRESSURE 200
#define MAX_PRESSURE 1000

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

#define V_SPACING 10
#define H_SPACING 20

#define MENU_PAGE 0
#define SERVICE_PAGE 1
#define RECIPES_PAGE 2
#define SERVE_DIALOG 3
#define SETTINGS_PAGE 4
#define ABOUT_PAGE 5
#define EDIT_RECIPE_DIALOG 6

const char *containerNames[] = {
    "Menu",
    "Service",
    "Recettes",
    "Service",
    "Paramètres",
    "A propos",
    "Recettes"
};

#define RGB_TO_COLOR(r, g, b) (((uint32_t)(r) << 16) | ((uint32_t)(g) << 8) | (b))

#define FORMAT_COLOR_16 0
#define FORMAT_COLOR_32 1

#define CM_COLORS_BLACK       0
#define CM_COLORS_NAVY        1
#define CM_COLORS_DARKGREEN   2
#define CM_COLORS_DARKCYAN    3
#define CM_COLORS_MAROON      4
#define CM_COLORS_PURPLE      5
#define CM_COLORS_OLIVE       6
#define CM_COLORS_LIGHTGREY   7
#define CM_COLORS_DARKGREY    8
#define CM_COLORS_BLUE        9
#define CM_COLORS_GREEN       10
#define CM_COLORS_CYAN        11
#define CM_COLORS_RED         12
#define CM_COLORS_MAGENTA     13
#define CM_COLORS_YELLOW      14
#define CM_COLORS_WHITE       15
#define CM_COLORS_ORANGE      16
#define CM_COLORS_GREENYELLOW 17
#define CM_COLORS_PINK        18

const uint32_t colors[][2] = {
    { TFT_BLACK, RGB_TO_COLOR(  0,   0,   0) },
    { TFT_NAVY, RGB_TO_COLOR(  0,   0, 128) },
    { TFT_DARKGREEN, RGB_TO_COLOR(  0, 128,   0) },
    { TFT_DARKCYAN, RGB_TO_COLOR(  0, 128, 128) },
    { TFT_MAROON, RGB_TO_COLOR(128,   0,   0) },
    { TFT_PURPLE, RGB_TO_COLOR(128,   0, 128) },
    { TFT_OLIVE, RGB_TO_COLOR(128, 128,   0) },
    { TFT_LIGHTGREY, RGB_TO_COLOR(192, 192, 192) },
    { TFT_DARKGREY, RGB_TO_COLOR(128, 128, 128) },
    { TFT_BLUE, RGB_TO_COLOR(  0,   0, 255) },
    { TFT_GREEN, RGB_TO_COLOR(  0, 255,   0) },
    { TFT_CYAN, RGB_TO_COLOR(  0, 255, 255) },
    { TFT_RED, RGB_TO_COLOR(255,   0,   0) },
    { TFT_MAGENTA, RGB_TO_COLOR(255,   0, 255) },
    { TFT_YELLOW, RGB_TO_COLOR(255, 255,   0) },
    { TFT_WHITE, RGB_TO_COLOR(255, 255, 255) },
    { TFT_ORANGE, RGB_TO_COLOR(255, 180,   0) },
    { TFT_GREENYELLOW, RGB_TO_COLOR(180, 255,   0) },
    { TFT_PINK, RGB_TO_COLOR(255,  00, 128) },
};

MCUFRIEND_kbv tft;

const int XP = 8, XM = A2, YP = A3, YM = 9;
const int TS_LEFT = 128, TS_RT = 910, TS_TOP = 960, TS_BOT = 93;
TouchScreen ts(XP, YP, XM, YM, 300);
int touchX, touchY;

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

#include "hardware/Hardware.hpp"
#include "hardware/RGBStrip.hpp"

RGBStrip rgbStrip(RGB_STRIP_LEDS_COUNT, RGB_STRIP_SIGNAL_PIN, RGBStrip::Mode::RAINBOW);

#include "components/Box.hpp"

const Box pageContentBox(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT, H_SPACING, V_SPACING, 2, 5);
const Box dialogContentBox(SCREEN_WIDTH/2, V_SPACING + pageContentBox.getCaseHeight() + (SCREEN_HEIGHT - V_SPACING - pageContentBox.getCaseHeight()) / 2, SCREEN_WIDTH * 4/5, SCREEN_HEIGHT * 2/3, H_SPACING, V_SPACING, 2, 4);

#include "Container.hpp"
#include "components/Slider.hpp"

#include "dialogs/Dialog.hpp"
#include "dialogs/EditRecipeDialog.hpp"
#include "dialogs/ServeDialog.hpp"

#include "pages/Page.hpp"
#include "pages/MenuPage.hpp"
#include "pages/NavigablePage.hpp"
#include "pages/RecipesMenuPage.hpp"
#include "pages/SettingsPage.hpp"
#include "pages/AboutPage.hpp"
