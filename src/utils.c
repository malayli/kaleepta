#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "continue.h"

void clearScreen() {
    system("clear");
}

int arraySize(char *arr[]) {
    int size = 0;
    while (arr[size] != NULL) {
        size++;
    }
    return size;
}

void emptyFunction() {
}
