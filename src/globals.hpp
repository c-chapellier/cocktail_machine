
#pragma once

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>

#include "Recipe.hpp"

#define LANDSCAPE 1

#define MIN_PRESSURE 200
#define MAX_PRESSURE 1000

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

#define V_SPACING 10
#define H_SPACING 20

#define V_NB_CASES 5
#define H_NB_CASES 2

#define CASE_WIDTH (SCREEN_WIDTH - (H_SPACING * (H_NB_CASES + 1))) / H_NB_CASES
#define CASE_HEIGHT (SCREEN_HEIGHT - (V_SPACING * (V_NB_CASES + 1))) / V_NB_CASES

#define CASE_X(n) H_SPACING + (n) * (CASE_WIDTH + H_SPACING) + CASE_WIDTH/2
#define CASE_Y(n) V_SPACING + (n) * (CASE_HEIGHT + V_SPACING) + CASE_HEIGHT/2

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

int pixelX, pixelY;     //touchGetXY() updates global vars

Recipe recipes[8] = {
    Recipe("Mojito", { 30, 10, 40, 0, 0, 0 }, true),
    Recipe("Pina Colada", { 30, 10, 40, 0, 0, 0 }, true),
    Recipe("Caipirinha", { 30, 10, 40, 0, 0, 0 }, true),
    Recipe("Cosmopolitan", { 30, 10, 40, 0, 0, 0 }, true),
    Recipe("Margarita", { 30, 10, 40, 0, 0, 0 }, true),
    Recipe("Grenadine", { 30, 10, 40, 0, 0, 0 }, true),
    Recipe("Ricard", { 30, 10, 40, 0, 0, 0 }, true),
    Recipe("Spritz", { 30, 10, 40, 0, 0, 0 }, true)
}

int selectedRecipe = 0;
