/*
For visual learning of token generation, refer to this video:
https://www.youtube.com/watch?v=3uRoSITqXRI&list=PLBlnK6fEyqRggZZgYpPMUxdY1CYkZtARR
*/

#include <stdio.h>

int main()
{
    // --- CASE 1: The "Maximal Munch" Rule ---
    int a = 4;
    int b = 3;

    /* The Lexical Analyzer reads left-to-right and groups the longest valid tokens.
       a+++b is parsed as (a++) + (b).
       
       Logic:
       1. (a++) returns the current value of 'a' (4) to the expression.
       2. 'a' is then incremented to 5 in memory.
       3. The expression becomes: 4 + 3 = 7.
    */
    printf("Result of a+++b: %d\n", a+++b); 
    printf("Final value of a: %d\n\n", a); // a is now 5

    // --- CASE 2: Forced Tokenization via Whitespace ---
    int x = 4;
    int y = 3;

    /* By adding a space, we force the Lexical Analyzer to terminate the first 
       token '+' and start a new one '++'.
       x + ++y is parsed as (x) + (++y).

       Logic:
       1. (++y) increments 'y' immediately (3 becomes 4).
       2. The updated value (4) is returned to the expression.
       3. The expression becomes: 4 + 4 = 8.
    */
    printf("Result of x + ++y: %d\n", x + ++y);
    printf("Final value of y: %d\n", y); // y is now 4

    return 0;
}

