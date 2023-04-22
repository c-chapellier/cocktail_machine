
#pragma once

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>

#include "components/Box.hpp"
#include "Recipe.hpp"

#include "Container.hpp"

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

MCUFRIEND_kbv tft;

const int XP = 8, XM = A2, YP = A3, YM = 9;
const int TS_LEFT = 128, TS_RT = 910, TS_TOP = 960, TS_BOT = 93;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int pixelX, pixelY;     // touchGetXY() updates global vars

const Box pageContentBox(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT, H_SPACING, V_SPACING, 2, 5);
const Box dialogContentBox(SCREEN_WIDTH/2, V_SPACING + pageContentBox.getCaseHeight() + (SCREEN_HEIGHT - V_SPACING - pageContentBox.getCaseHeight()) / 2, SCREEN_WIDTH * 4/5, SCREEN_HEIGHT * 2/3, H_SPACING, V_SPACING, 2, 4);

int ingredients[8][6] = {
    { 30, 10, 40, 0, 0, 0 },
    { 30, 10, 40, 0, 0, 0 },
    { 30, 10, 40, 0, 0, 0 },
    { 30, 10, 40, 0, 0, 0 },
    { 30, 10, 40, 0, 0, 0 },
    { 30, 10, 40, 0, 0, 0 },
    { 30, 10, 40, 0, 0, 0 },
    { 30, 10, 40, 0, 0, 0 }
};

Recipe recipes[8] = {
    Recipe("Mojito", ingredients[0], true),
    Recipe("Pina Colada", ingredients[1], true),
    Recipe("Caipirinha", ingredients[2], true),
    Recipe("Cosmopolitan", ingredients[3], true),
    Recipe("Margarita", ingredients[4], true),
    Recipe("Grenadine", ingredients[5], true),
    Recipe("Ricard", ingredients[6], true),
    Recipe("Spritz", ingredients[7], true)
};

int selectedRecipe = 0;

#include "components/Slider.hpp"

Slider sliders[7] = {
    Slider("Reservoir 1", dialogContentBox.getCaseX(0), dialogContentBox.getCaseY(0), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    Slider("Reservoir 2", dialogContentBox.getCaseX(1), dialogContentBox.getCaseY(1), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    Slider("Reservoir 3", dialogContentBox.getCaseX(2), dialogContentBox.getCaseY(2), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    Slider("Reservoir 4", dialogContentBox.getCaseX(3), dialogContentBox.getCaseY(3), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    Slider("Reservoir 5", dialogContentBox.getCaseX(4), dialogContentBox.getCaseY(4), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    Slider("Reservoir 6", dialogContentBox.getCaseX(5), dialogContentBox.getCaseY(5), dialogContentBox.getCaseWidth(), dialogContentBox.getCaseHeight()),
    Slider("Glacons", dialogContentBox.getCaseX(6), dialogContentBox.getCaseY(6), dialogContentBox.getCaseWidth()*2 + dialogContentBox.getHSpacing(), dialogContentBox.getCaseHeight()),
};

#include "dialogs/Dialog.hpp"
#include "dialogs/EditRecipeDialog.hpp"
#include "dialogs/ServeDialog.hpp"

#include "pages/Page.hpp"
#include "pages/MenuPage.hpp"
#include "pages/NavigablePage.hpp"
#include "pages/ServicePage.hpp"
#include "pages/RecipesPage.hpp"
#include "pages/SettingsPage.hpp"
#include "pages/AboutPage.hpp"
