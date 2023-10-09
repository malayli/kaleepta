#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oldman.h"
#include "street.h"
#include "utils.h"
#include "continue.h"
#include "choice.h"
#include "localization.h"

int talkedToOldman = 1;

void showOldman() {
    clearScreen();
    if (talkedToOldman == 1) {
        talkedToOldman = 0;
        printf("%s\n\n", oldman1);
        addWeaponShop();

    } else {
        printf("%s\n\n", nothingtosay);
    }
    pressContinue();
}
