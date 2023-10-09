#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secretplace.h"
#include "graphics.h"
#include "continue.h"
#include "choice.h"
#include "utils.h"
#include "street.h"
#include "data.h"

char **secretPlaceChoices = NULL;
int secretPlaceChoicesCount = 0;
VoidFunc *secretPlaceFunctions = NULL;
int secretPlaceFunctionsCount = 0;

void exploreHiddenPath() {
    clearScreen();
    if (hasKey == 1) {
        printf("\nKaleepta unlocked a secret door and discovers an unexpected hall.\n\n");
        pressContinue();
        exit(0);

    } else {
        printf("\nKaleepta delves deeper into the shadows and discovers a locked door.\n\n");
        pressContinue();
        showSecretPlace();
    }
}

void goToStreet() {
    clearScreen();
    printf("\nKaleepta decides to stay in the safety of the known paths, retreating from the secret place.\n\n");
    pressContinue();
}

void initSecretPlace() {
    secretPlaceChoicesCount = addChoice(&secretPlaceChoices, secretPlaceChoicesCount, "Explore the hidden path.\n");
    secretPlaceChoicesCount = addChoice(&secretPlaceChoices, secretPlaceChoicesCount, "Retreat to the known paths.\n");

    secretPlaceFunctionsCount = addFunction(&secretPlaceFunctions, secretPlaceFunctionsCount, exploreHiddenPath);
    secretPlaceFunctionsCount = addFunction(&secretPlaceFunctions, secretPlaceFunctionsCount, goToStreet);
}

void showSecretPlace() {
    clearScreen();
    printf("\nKaleepta ventures into a dark and eerie alley, shadows whispering secrets of the unseen.\n\n");
    printChoices(secretPlaceChoices, secretPlaceChoicesCount, secretPlaceFunctions);
}
