#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choice.h"
#include "utils.h"
#include "continue.h"

void invalidchoice() {
    clearScreen();
    printf("\nInvalid choice. Please choose again.\n\n");
    pressContinue();
}

void printChoices(char **choices, int length, VoidFunc functions[]) {
    for(int i=0; i < length; i++) {
        printf("%d. %s", i+1, choices[i]);
    }

    printf("Please enter your choice (1-%d): ", length);

    char choice[20];
    scanf("%s", choice);
    int selectedChoice = atoi(choice);

    if (1 <= selectedChoice && selectedChoice <= length) {
        functions[selectedChoice-1]();

    } else {
        invalidchoice();
    }
}

int addChoice(char ***choices, int numChoices, const char *newChoice) {
    // Reallocate memory to accommodate the new choice
    *choices = realloc(*choices, (numChoices + 1) * sizeof(char *));
    if (*choices == NULL) {
        exit(1); // Exit if memory allocation fails
    }

    // Allocate memory for the new string and copy it over
    (*choices)[numChoices] = malloc(strlen(newChoice) + 1);
    if ((*choices)[numChoices] == NULL) {
        exit(1); // Exit if memory allocation fails
    }
    strcpy((*choices)[numChoices], newChoice);

    // Increase the count of choices
    numChoices++;

    return numChoices;
}

int removeChoice(char ***choices, int numChoices, int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove >= numChoices) {
        return numChoices; // Invalid index
    }

    // Free the memory of the choice to remove
    free((*choices)[indexToRemove]);

    // Shift all choices from the index onwards to the left by one position
    for (int i = indexToRemove; i < numChoices - 1; i++) {
        (*choices)[i] = (*choices)[i + 1];
    }

    // Decrease the count of choices
    numChoices--;

    if (numChoices > 0) {
        // Reallocate the memory of the array to decrease its size
        *choices = realloc(*choices, numChoices * sizeof(char *));
        if (*choices == NULL) {
            exit(1); // Exit if memory allocation fails
        }
    } else {
        // If no choices are left, free the array itself
        free(*choices);
        *choices = NULL;
    }

    return numChoices;
}

int addFunction(VoidFunc **functions, int currentCount, VoidFunc newFunction) {
    // Reallocate memory to accommodate the new function pointer
    *functions = realloc(*functions, (currentCount + 1) * sizeof(VoidFunc));
    
    if (*functions == NULL) {
        // Handle memory allocation error, maybe exit or return an error code
        exit(1);
    }
    
    // Add the new function pointer to the end of the array
    (*functions)[currentCount] = newFunction;

    // Increase the count of function pointers
    return currentCount + 1;  // Return the updated count
}

int removeFunction(VoidFunc **functions, int currentCount, int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove >= currentCount) {
        return currentCount; // Invalid index
    }

    // Shift all function pointers from the index onwards to the left by one position
    for (int i = indexToRemove; i < currentCount - 1; i++) {
        (*functions)[i] = (*functions)[i + 1];
    }

    // Decrease the count of function pointers
    currentCount--;

    if (currentCount > 0) {
        // Reallocate the memory of the array to decrease its size
        *functions = realloc(*functions, currentCount * sizeof(VoidFunc));
        if (*functions == NULL) {
            // Handle memory allocation error, maybe exit or return an error code
            exit(1);
        }
    } else {
        // If no function pointers are left, free the array itself
        free(*functions);
        *functions = NULL;
    }

    return currentCount;  // Return the updated count
}
