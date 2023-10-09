#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choice.h"
#include "utils.h"

void pressContinue() {
    char choice[20];
    while (1) {
        printf("1. Continue.\n");
        printf("Please enter your choice (1): ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            clearScreen();
            break;

        } else {
            invalidchoice();
        }
    }
}
