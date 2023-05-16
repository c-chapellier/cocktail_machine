
#pragma once

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Adafruit_NeoPixel.h>
#include <HX711.h>

#include "colors.hpp"
#include "i18n.hpp"
#include "settings.hpp"

#define LANDSCAPE 3

MCUFRIEND_kbv tft;

TouchScreen ts(XP, YP, XM, YM, 300);

int touchX, touchY;
bool getTouch();

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

Recipe recipes[RECIPES_COUNT] = {                                  //   G | V | M | O | A | S
    Recipe( "Mojito Sprite",        CM_COLORS_GREEN,        (int []){   0,  0,  1,  0,  0,  1 },    10 ),
    Recipe( "Vodka orange",         CM_COLORS_ORANGE,       (int []){   0,  1,  0,  4,  0,  0 },    10 ),
    Recipe( "Gin orange",           CM_COLORS_ORANGE,       (int []){   1,  0,  0,  4,  0,  0 },    10 ),
    Recipe( "Mojito ananas",        CM_COLORS_YELLOW,       (int []){   0,  0,  1,  0,  1,  0 },    10 ),
    Recipe( "Gin Sprite ananas",    CM_COLORS_GREENYELLOW,  (int []){   1,  0,  0,  0,  2,  2 },    10 ),
    Recipe( "Vodka orange ananas",  CM_COLORS_GREENYELLOW,  (int []){   0,  1,  0,  2,  2,  0 },    10 ),
    Recipe( "Jus d'orange",         CM_COLORS_ORANGE,       (int []){   0,  0,  0,  1,  0,  0 },    10 ),
    Recipe( "Jus d'ananas",         CM_COLORS_YELLOW,       (int []){   0,  0,  0,  0,  1,  0 },    10 )
};

int selectedRecipe = 0;

/* *************************************************************** *\
 *                            HARDWARE                             *
\* *************************************************************** */

#include "hardware/Hardware.hpp"
#include "hardware/RGBStrip.hpp"
#include "hardware/LevelSensor.hpp"
#include "hardware/StepperMotor.hpp"
#include "hardware/Valve.hpp"
#include "hardware/LoadCell.hpp"

RGBStrip rgbStrip(RGB_STRIP_LEDS_COUNT, RGB_STRIP_PIN_SIGNAL, RGBStrip::Mode::RAINBOW);

LevelSensor levelSensors[TANKS_COUNT] = {
    LevelSensor(LEVEL_SENSOR_0_PIN),
    LevelSensor(LEVEL_SENSOR_1_PIN),
    LevelSensor(LEVEL_SENSOR_2_PIN),
    LevelSensor(LEVEL_SENSOR_3_PIN),
    LevelSensor(LEVEL_SENSOR_4_PIN),
    LevelSensor(LEVEL_SENSOR_5_PIN)
};

StepperMotor stepperMotor(STEPPER_MOTOR_PIN_DIR, STEPPER_MOTOR_PIN_STEP);

Valve valves[TANKS_COUNT] = {
    Valve(VALVE_0_PIN),
    Valve(VALVE_1_PIN),
    Valve(VALVE_2_PIN),
    Valve(VALVE_3_PIN),
    Valve(VALVE_4_PIN),
    Valve(VALVE_5_PIN)
};

LoadCell loadCell(LOAD_CELL_PIN_DATA, LOAD_CELL_PIN_CLOCK);

/* *************************************************************** *\
 *                              TANK                               *
\* *************************************************************** */

#include "Tank.hpp"

Tank tanks[TANKS_COUNT] = {
    Tank(0),
    Tank(1),
    Tank(2),
    Tank(3),
    Tank(4),
    Tank(5)
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
#include "containers/pages/ManualControlPage.hpp"
