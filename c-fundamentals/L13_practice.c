// QUESTION-1
#include <stdio.h>

int main()
{
    int var = 052; // --> OCTAL VALUE: 8^2 8^1 8^0, NOT DECIMAL VALUE: 2^2 2^1 2^0
    printf("%d\n", var);
    return 0;
    // ANSWER: OCTAL VALUE: 0*64 + 5*8 + 2*1 = 40 + 2 = 42

    int var = 052;
    printf("%o\n", var); //%d changes to %o - OCTAL VALUE
    return 0;
    // ANSWER: Since we have already specified this is an octal value, we get 52 on the screen.

    #define STRING "%s\n" // --> These are called Macros
    #define NESO "Welcome to our home!"
    printf(STRING, NESO);
}