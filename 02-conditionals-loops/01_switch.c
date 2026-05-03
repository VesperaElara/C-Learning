#include <stdio.h>

/*

int main()
{
    int x = 2;
    if (x == 1)
    printf("x is 1\n"); // Curly brackets are optional for SINGLE statements ONLY.
    else if (x == 2)
    printf("x is 2\n");
    else if (x == 3)
    printf("x is 3\n");
    else
    printf("x is not 1 , 2 or 3\n");
}

This is a tedious process! It can be shrunk into cases using the "switch" conditional.

*/

int main ()
{
    int x = 2;
    switch(x)
    {
        case 1: printf("x is 1\n");
                break;
        case 2: printf("x is 2\n");
                break;
        case 3: printf("x is 3\n");
                break;
        default: printf("x is not 1 , 2 or 3\n");
                break;
    }
}

/*
POINTS TO REMEMBER:
- The argument of switch [x in this case] must always be an integer.
- The argument of the case(s) [1,2,3 in these cases] must always be an integer.
- Neither of the two can be a float value.
- The argument of case(s) is called the case label. It CANNOT be a variable.
- However, the case label can be a MACRO.
- You CANNOT make DUPLICATE CASES (e.g., "case 1" CANNOT be repeated twice).
- "default" is optional. It can be placed anywhere in the switch conditional.
    - "default" need not be placed in the last.
    - The compiler automatically calculates it at the last.
*/