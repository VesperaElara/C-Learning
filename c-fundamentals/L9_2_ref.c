#include <stdio.h>

int external_variable = 5;

// external_variable needs to be a global variable.
// Only then can it be accessed as the extern variable used in L9_2_externvar.c
// There must be no "main" function in this document. 
// Having a "main" function in both the documents confuses the compiler when it combines both files.