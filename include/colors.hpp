
#pragma once

#include <ctype.h>

#define RGB_TO_COLOR(r, g, b) (((uint32_t)(r) << 16) | ((uint32_t)(g) << 8) | (b))

#define N_COLOR_MODES       2
#define DARK_MODE           0
#define LIGHT_MODE          1
#define DEFAULT_COLOR_MODE  DARK_MODE

int colorMode = DEFAULT_COLOR_MODE;

#define FORMAT_COLOR_16     0
#define FORMAT_COLOR_32     1

// colors are default in dark mode
#define CM_COLORS_BLACK       (colorMode == DARK_MODE ? 0 : 15)
#define CM_COLORS_NAVY        (colorMode == DARK_MODE ? 1 : 1)
#define CM_COLORS_DARKGREEN   (colorMode == DARK_MODE ? 2 : 2)
#define CM_COLORS_DARKCYAN    (colorMode == DARK_MODE ? 3 : 3)
#define CM_COLORS_MAROON      (colorMode == DARK_MODE ? 4 : 4)
#define CM_COLORS_PURPLE      (colorMode == DARK_MODE ? 5 : 5)
#define CM_COLORS_OLIVE       (colorMode == DARK_MODE ? 6 : 6)
#define CM_COLORS_LIGHTGREY   (colorMode == DARK_MODE ? 7 : 7)
#define CM_COLORS_DARKGREY    (colorMode == DARK_MODE ? 8 : 8)
#define CM_COLORS_BLUE        (colorMode == DARK_MODE ? 9 : 9)
#define CM_COLORS_GREEN       (colorMode == DARK_MODE ? 10 : 10)
#define CM_COLORS_CYAN        (colorMode == DARK_MODE ? 11 : 11)
#define CM_COLORS_RED         (colorMode == DARK_MODE ? 12 : 12)
#define CM_COLORS_MAGENTA     (colorMode == DARK_MODE ? 13 : 13)
#define CM_COLORS_YELLOW      (colorMode == DARK_MODE ? 14 : 14)
#define CM_COLORS_WHITE       (colorMode == DARK_MODE ? 15 : 0)
#define CM_COLORS_ORANGE      (colorMode == DARK_MODE ? 16 : 16)
#define CM_COLORS_GREENYELLOW (colorMode == DARK_MODE ? 17 : 17)
#define CM_COLORS_PINK        (colorMode == DARK_MODE ? 18 : 18)

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
