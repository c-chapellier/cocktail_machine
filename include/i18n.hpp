
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

#define N_UI_CONTAINERS 7
#define MENU_PAGE 0
#define SERVICE_PAGE 1
#define RECIPES_PAGE 2
#define SERVE_DIALOG 3
#define SETTINGS_PAGE 4
#define ABOUT_PAGE 5
#define EDIT_RECIPE_DIALOG 6

const char *uiContainersNames[N_UI_CONTAINERS][N_LANGUAGES] = {
    { "Menu", "Menu", "Menu", "Menu", "Menu" },
    { "Service", "Service", "Servicio", "Service", "Service" },
    { "Recettes", "Recipes", "Recetas", "Recepten", "Rezepte" },
    { "Service", "Service", "Servicio", "Service", "Service" },
    { "Parametres", "Settings", "Ajustes", "Instellingen", "Einstellungen" },
    { "A propos", "About", "Acerca de", "Over", "Über" },
    { "Recettes", "Recipes", "Recetas", "Recepten", "Rezepte" }
};

#define N_PHYSICAL_CONTAINERS 6

const char *physicalContainersNames[N_PHYSICAL_CONTAINERS][N_LANGUAGES] = {
    { "Coca", "Coke", "Coca", "Coca", "Coca" },
    { "Eau", "Water", "Agua", "Water", "Wasser" },
    { "Ricard", "Ricard", "Ricard", "Ricard", "Ricard" },
    { "Rhum", "Rum", "Ron", "Rum", "Rum" },
    { "Vodka", "Vodka", "Vodka", "Wodka", "Wodka" },
    { "Glucose", "Glucose", "Glucosa", "Glucose", "Glucose" }
};

const char *iceContainerName[N_LANGUAGES] = { "Glace", "Ice", "Hielo", "Ijs", "Eis" };
