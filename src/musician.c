#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musician.h"
#include "street.h"
#include "utils.h"
#include "continue.h"
#include "choice.h"
#include "localization.h"

int talkedToMusician = 1;

void showMusician() {
    clearScreen();

    if (talkedToMusician == 1) {
        talkedToMusician = 0;
        printf("\n%s\n\n", musician1);
        addSecretPlace();

    } else {
        printf("%s\n\n", nothingtosay);
    }

    pressContinue();
}
