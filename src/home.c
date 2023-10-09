#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "home.h"
#include "data.h"
#include "street.h"
#include "utils.h"
#include "graphics.h"
#include "choice.h"
#include "continue.h"

char **homeChoices = NULL;
int homeChoicesCount = 0;
VoidFunc *homeFunctions = NULL;
int homeFunctionsCount = 0;

void showComputer() {
    clearScreen();
    printComputer();
    puts("");
    printf("Kaleepta turns on her computer and discovers her brother's birthdate: 2070/07/10. Today is his birthday.\n\n");

    char choice[20];
    while (1) {
        printf("1. Turn off the computer.\n");
        printf("Please enter your choice (1): ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            showHome();

        } else {
            invalidchoice();
        }
    }
}

void wearCyberamor() {
    hasArmor = 1;
    clearScreen();
    printf("Kaleepta wears her cyber armor and is ready to face any danger.\n\n");
    pressContinue();
    homeChoicesCount = removeChoice(&homeChoices, homeChoicesCount, 0);
    homeFunctionsCount = removeFunction(&homeFunctions, homeFunctionsCount, 0);
    showHome();
}

void initHome() {
    homeChoicesCount = addChoice(&homeChoices, homeChoicesCount, "Wear your cyber armor.\n");
    homeChoicesCount = addChoice(&homeChoices, homeChoicesCount, "Turn on the computer.\n");
    homeChoicesCount = addChoice(&homeChoices, homeChoicesCount, "Leave home.\n");

    homeFunctionsCount = addFunction(&homeFunctions, homeFunctionsCount, wearCyberamor);
    homeFunctionsCount = addFunction(&homeFunctions, homeFunctionsCount, showComputer);
    homeFunctionsCount = addFunction(&homeFunctions, homeFunctionsCount, showStreet);
}

void showHome() {
    clearScreen();
    printHome();
    puts("");
    printf("Kaleepta returns to her home.\n\n");
    printChoices(homeChoices, homeChoicesCount, homeFunctions);
}
