
#pragma once

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Adafruit_NeoPixel.h>

#include "colors.hpp"
#include "i18n.hpp"
#include "settings.hpp"

#define LANDSCAPE 1

MCUFRIEND_kbv tft;

TouchScreen ts(XP, YP, XM, YM, 300);

int touchX, touchY;
bool touchGetXY();

void setup();

/* *************************************************************** *\
 *                           ROOT CLASSES                          *
\* *************************************************************** */

#include "Box.hpp"

const Box pageContentBox(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT, H_SPACING, V_SPACING, 2, 5);
const Box dialogContentBox(SCREEN_WIDTH/2, V_SPACING + pageContentBox.getCaseHeight() + (SCREEN_HEIGHT - V_SPACING - pageContentBox.getCaseHeight()) / 2, SCREEN_WIDTH * 4/5, SCREEN_HEIGHT * 2/3, H_SPACING, V_SPACING, 2, 4);

#include "Recipe.hpp"

#define RECIPES_COUNT 8

// BLACK | NAVY | DARKGREEN | DARKCYAN | MAROON | PURPLE | OLIVE | LIGHTGREY | DARKGREY
// BLUE | GREEN | CYAN | RED | MAGENTA | YELLOW | WHITE | ORANGE | GREENYELLOW

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
#include "hardware/LevelSensor.hpp"
#include "hardware/StepMotor.hpp"
#include "hardware/Valve.hpp"
#define NB_TANKS 6

RGBStrip rgbStrip(RGB_STRIP_LEDS_COUNT, RGB_STRIP_SIGNAL_PIN, RGBStrip::Mode::RAINBOW);
LevelSensor sensor[NB_TANKS] = {
    LevelSensor(PIN_SENSOR_1),
    LevelSensor(PIN_SENSOR_2),
    LevelSensor(PIN_SENSOR_3),
    LevelSensor(PIN_SENSOR_4),
    LevelSensor(PIN_SENSOR_5),
    LevelSensor(PIN_SENSOR_6),
};
StepMotor stepMotor(DIR_PIN_MOTOR,STEP_PIN_MOTOR,REVOLUTION_STEP);
Valve electroValve[NB_TANKS]={
    Valve(PIN_VALVE_1,false),
    Valve(PIN_VALVE_2,false),
    Valve(PIN_VALVE_3,false),
    Valve(PIN_VALVE_4,false),
    Valve(PIN_VALVE_5,false),
    Valve(PIN_VALVE_6,false),
};


/* *************************************************************** *\
 *                          UI_CONTAINERS                          *
\* *************************************************************** */

#include "containers/UIContainer.hpp"

#include "containers/components/Slider.hpp"

#include "containers/dialogs/Dialog.hpp"
#include "containers/dialogs/EditRecipeDialog.hpp"
#include "containers/dialogs/ServeDialog.hpp"

#include "containers/pages/Page.hpp"
#include "containers/pages/MenuPage.hpp"
#include "containers/pages/NavigablePage.hpp"
#include "containers/pages/RecipesMenuPage.hpp"
#include "containers/pages/SettingsPage.hpp"
#include "containers/pages/AboutPage.hpp"
