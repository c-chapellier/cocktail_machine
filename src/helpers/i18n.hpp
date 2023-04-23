
#pragma once

#define N_LANGUAGES 5
#define FRENCH 0
#define ENGLISH 1
#define SPANISH 2
#define DUTCH 3
#define GERMAN 4

int language = GERMAN;

#define translate(str) ((str)[language])

#define N_UI_CONTAINERS 7
#define MENU_PAGE 0
#define SERVICE_PAGE 1
#define RECIPES_PAGE 2
#define SERVE_DIALOG 3
#define SETTINGS_PAGE 4
#define ABOUT_PAGE 5
#define EDIT_RECIPE_DIALOG 6

const char *uiContainersNames[N_LANGUAGES][N_UI_CONTAINERS] = {
    {
        "Menu",
        "Service",
        "Recettes",
        "Service",
        "Parametres",
        "A propos",
        "Recettes"
    },
    {
        "Menu",
        "Service",
        "Recipes",
        "Service",
        "Settings",
        "About",
        "Recipes"
    },
    {
        "Menu",
        "Servicio",
        "Recetas",
        "Servicio",
        "Ajustes",
        "Acerca de",
        "Recetas"
    },
    {
        "Menu",
        "Service",
        "Recepten",
        "Service",
        "Instellingen",
        "Over",
        "Recepten"
    },
    {
        "Menu",
        "Service",
        "Rezepte",
        "Service",
        "Einstellungen",
        "Uber",
        "Rezepte"
    }
};

#define N_PHYSICAL_CONTAINERS 6

const char *physicalContainersNames[N_LANGUAGES][N_PHYSICAL_CONTAINERS] = {
    {
        "Coca",
        "Eau",
        "Ricard",
        "Rhum",
        "Vodka",
        "Glucose"
    },
    {
        "Coca",
        "Water",
        "Ricard",
        "Rum",
        "Vodka",
        "Glucose"
    },
    {
        "Coca",
        "Agua",
        "Ricard",
        "Ron",
        "Vodka",
        "Glucosa"
    },
    {
        "Coca",
        "Water",
        "Ricard",
        "Rum",
        "Vodka",
        "Glucose"
    },
    {
        "Coca",
        "Wasser",
        "Ricard",
        "Rum",
        "Wodka",
        "Glucose"
    }
};

const char *iceContainerName[N_LANGUAGES] = {
    "Glace",
    "Ice",
    "Hielo",
    "Ijs",
    "Eis"
};
