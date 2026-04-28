// QUESTION-1
#include <stdio.h>

int main()
{
    int var = 052; // --> OCTAL VALUE: 8^2 8^1 8^0, NOT DECIMAL VALUE: 2^2 2^1 2^0
    // Putting a 0 before an integral value changes it to an octal value, not a decimal one.
    printf("%d\n", var);
    // ANSWER: OCTAL VALUE: 0*64 + 5*8 + 2*1 = 40 + 2 = 42

    printf("%o\n", var); //%d changes to %o - OCTAL VALUE
    // ANSWER: Since we have already specified this is an octal value, we get 52 on the screen.

    #define STRING "%s\n" // --> These are called Macros
    #define NESO "Welcome to our home!"
    printf(STRING, NESO);

    return 0;
}