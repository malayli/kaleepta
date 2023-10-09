#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.h"
#include "save.h"
#include "continue.h"
#include "secretplace.h"
#include "utils.h"
#include "choice.h"
#include "businessWoman.h"
#include "data.h"
#include "street.h"
#include "intro.h"
#include "home.h"
#include "shop.h"
#include "story.h"

int main() {
    initIntro();
    initStreet();
    initBusinessWoman();
    initHome();
    initShop();
    initSecretPlace();
    showIntro();
    showStory();
    showStreet();
    return 0;
}
