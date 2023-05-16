
#pragma once

#define N_LANGUAGES 5
#define FRENCH 0
#define ENGLISH 1
#define SPANISH 2
#define DUTCH 3
#define GERMAN 4

int language = FRENCH;

#define translate(str) ((str)[language])

const char *languagesNames[N_LANGUAGES][N_LANGUAGES] = {
    { "Francais", "French", "Frances", "Frans", "Franzosisch" },
    { "Anglais", "English", "Ingles", "Engels", "Englisch" },
    { "Espagnol", "Spanish", "Espanol", "Spaans", "Spanisch" },
    { "Neerlandais", "Dutch", "Holandes", "Nederlands", "Niederlandisch" },
    { "Allemand", "German", "Aleman", "Duits", "Deutsch" }
};

const char *colorModesNames[N_COLOR_MODES][N_LANGUAGES] = {
    { "Sombre", "Dark", "Oscuro", "Donker", "Dunkel" },
    { "Clair", "Light", "Claro", "Licht", "Hell" }
};

#define N_UI_CONTAINERS 8
#define MENU_PAGE                   0
#define SERVICE_PAGE                1
#define RECIPES_PAGE                2
#define SERVE_DIALOG                3
#define SETTINGS_PAGE               4
#define ABOUT_PAGE                  5
#define EDIT_RECIPE_DIALOG          6
#define MANUAL_CONTROL_PAGE         7

const char *uiContainersNames[N_UI_CONTAINERS][N_LANGUAGES] = {
    { "Menu", "Menu", "Menu", "Menu", "Menu" },
    { "Service", "Service", "Servicio", "Service", "Service" },
    { "Recettes", "Recipes", "Recetas", "Recepten", "Rezepte" },
    { "Service", "Service", "Servicio", "Service", "Service" },
    { "Parametres", "Settings", "Ajustes", "Instellingen", "Einstellungen" },
    { "A propos", "About", "Acerca de", "Over", "Über" },
    { "Recettes", "Recipes", "Recetas", "Recepten", "Rezepte" },
    { "Controle manuel", "Manual control", "Control manual", "Handmatige bediening", "Manuelle Steuerung" }
};

#define TANKS_COUNT 6

const char *physicalContainersNames[TANKS_COUNT][N_LANGUAGES] = {
    { "Gin", "Gin", "Ginebra", "Gin", "Gin" },
    { "Vodka", "Vodka", "Vodka", "Wodka", "Wodka" },
    { "Mojito", "Mojito", "Mojito", "Mojito", "Mojito" },
    { "Jus d'orange", "Orange juice", "Jugo de naranja", "Sinaasappelsap", "Orangensaft" },
    { "Jus d'ananas", "Pineapple juice", "Jugo de pina", "Ananassap", "Ananassaft" },
    { "Sprite", "Sprite", "Sprite", "Sprite", "Sprite" }
};

const char *iceContainerName[N_LANGUAGES] = { "Glace", "Ice", "Hielo", "Ijs", "Eis" };

const char *vidangeName[N_LANGUAGES] = { "Vidange", "Drain", "Drenaje", "Drain", "Ablassen" };