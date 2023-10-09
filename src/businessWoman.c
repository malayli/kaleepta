#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "businessWoman.h"
#include "choice.h"
#include "data.h"
#include "utils.h"
#include "continue.h"

char **businessWomanChoices = NULL;
int businessWomanChoicesCount = 0;
VoidFunc *businessWomanFunctions = NULL;
int businessWomanFunctionsCount = 0;

void showCyborg() {
    clearScreen();

    if (hasArmor) {
        printf("\nKaleepta successfully defeats the cyborg assassin and earns $100.\n\n");
        money += 100;
        businessWomanChoicesCount = removeChoice(&businessWomanChoices, businessWomanChoicesCount, 0);
        businessWomanFunctionsCount = removeFunction(&businessWomanFunctions, businessWomanFunctionsCount, 0);

        businessWomanChoicesCount = removeChoice(&businessWomanChoices, businessWomanChoicesCount, 0);
        businessWomanFunctionsCount = removeFunction(&businessWomanFunctions, businessWomanFunctionsCount, 0);

        businessWomanChoicesCount = addChoice(&businessWomanChoices, businessWomanChoicesCount, "Nothing to say.\n");
        businessWomanFunctionsCount = addFunction(&businessWomanFunctions, businessWomanFunctionsCount, emptyFunction);

        pressContinue();

    } else {
        printf("\nWithout armor, Kaleepta is overpowered by the cyborg assassin and dies.\n\n");
        exit(0);
    }
}

void initBusinessWoman() {
    businessWomanChoicesCount = addChoice(&businessWomanChoices, businessWomanChoicesCount, "Accept the job to kill the cyborg assassin.\n");
    businessWomanChoicesCount = addChoice(&businessWomanChoices, businessWomanChoicesCount, "Decline.\n");

    businessWomanFunctionsCount = addFunction(&businessWomanFunctions, businessWomanFunctionsCount, showCyborg);
    businessWomanFunctionsCount = addFunction(&businessWomanFunctions, businessWomanFunctionsCount, emptyFunction);
}

void showBusinessWoman() {
    clearScreen();
    printf("\nKaleepta approaches the businesswoman.\n\n");
    printChoices(businessWomanChoices, businessWomanChoicesCount, businessWomanFunctions);
}

void clearBusinessWoman() {
    free(businessWomanChoices);
    free(businessWomanFunctions);
}
