// Declare the function pointer type for functions that return void and take no arguments
typedef void (*VoidFunc)();

void invalidchoice();
void printChoices(char **choices, int length, VoidFunc functions[]);
int addChoice(char ***choices, int numChoices, const char *newChoice);
int removeChoice(char ***choices, int numChoices, int indexToRemove);
int addFunction(VoidFunc **functions, int currentCount, VoidFunc newFunction);
int removeFunction(VoidFunc **functions, int currentCount, int indexToRemove);
