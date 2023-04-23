
#pragma once

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
