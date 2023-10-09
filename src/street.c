#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "street.h"
#include "choice.h"
#include "data.h"
#include "save.h"
#include "businessWoman.h"
#include "secretplace.h"
#include "utils.h"
#include "continue.h"
#include "graphics.h"
#include "home.h"
#include "oldman.h"
#include "musician.h"
#include "shop.h"

char **streetChoices = NULL;
int streetChoicesCount = 0;
VoidFunc *streetFunctions = NULL;
int streetFunctionsCount = 0;

void addWeaponShop() {
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Go to the shop.\n");
    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, showShop);
}

void addSecretPlace() {
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Visit a dark place.\n");
    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, showSecretPlace);
}

void initStreet() {
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Talk to an old man.\n");
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Talk to a musician.\n");
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Talk to a businesswoman.\n");
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Go home.\n");
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Save.\n");
    streetChoicesCount = addChoice(&streetChoices, streetChoicesCount, "Exit the game.\n");

    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, showOldman);
    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, showMusician);
    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, showBusinessWoman);
    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, showHome);
    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, save);
    streetFunctionsCount = addFunction(&streetFunctions, streetFunctionsCount, exit);
}

void showStreet() {
    while (1) {
        clearScreen();
        printKaleeptaBody();
        puts("");
        printf("Kaleepta is on the street.\n\n");
        printChoices(streetChoices, streetChoicesCount, streetFunctions);
    }
}
