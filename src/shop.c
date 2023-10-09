#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"
#include "data.h"
#include "utils.h"
#include "choice.h"
#include "continue.h"

char **shopChoices = NULL;
int shopChoicesCount = 0;
VoidFunc *shopFunctions = NULL;
int shopFunctionsCount = 0;

void buyKey() {
    clearScreen();
    if (money >= 50) {
        printf("\nKaleepta purchases a key, wondering what door it might open.\n\n");
        money -= 50;
        hasKey = 1;
        shopChoicesCount = removeChoice(&shopChoices, shopChoicesCount, 0);
        shopFunctionsCount = removeFunction(&shopFunctions, shopFunctionsCount, 0);
        pressContinue();

    } else {
        printf("\nKaleepta doesn't have enough money.\n\n");
        pressContinue();
    }
}

void initShop() {
    shopChoicesCount = addChoice(&shopChoices, shopChoicesCount, "Buy a key ($50).\n");
    shopChoicesCount = addChoice(&shopChoices, shopChoicesCount, "Leave the shop.\n");

    shopFunctionsCount = addFunction(&shopFunctions, shopFunctionsCount, buyKey);
    shopFunctionsCount = addFunction(&shopFunctions, shopFunctionsCount, emptyFunction);
}

void showShop() {
    clearScreen();
    printf("\nKaleepta enters a dimly lit shop, the air heavy with the tang of metal and oil.\n\n");
    printChoices(shopChoices, shopChoicesCount, shopFunctions);
}
