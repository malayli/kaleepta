#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choice.h"
#include "intro.h"
#include "utils.h"
#include "graphics.h"

char **introChoices = NULL;
int introChoicesCount = 0;
VoidFunc introFunctions[] = {
    emptyFunction,
    exit
};

void initIntro() {
    introChoicesCount = addChoice(&introChoices, introChoicesCount, "Start.\n");
    introChoicesCount = addChoice(&introChoices, introChoicesCount, "Exit.\n");
}

void showIntro() {
    clearScreen();
    printKaleeptaFace();
    puts("");
    printTitle();
    puts("");
    printf("An ASCII cyberpunk adventure game.\n\n");
    printChoices(introChoices, introChoicesCount, introFunctions);
}
