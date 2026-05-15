#include <stdio.h>

// This function receives COPIES of the numbers
void fun(int x, int y)
{
    // These 'x' and 'y' are like photocopies
    // Changing them here does NOT change the originals
    x = 30; 
    y = 40; 
}

int main()
{
    // 1. Create the original variables
    int x = 10;
    int y = 20;

    // 2. Call the function
    // We send the VALUES (10 and 20), not the actual variables
    fun(x, y);

    // 3. Print the results
    // Even though the function changed its copies to 20 and 10,
    // the originals here remain 10 and 20.
    printf("x = %d, y = %d", x, y);

    return 0;
}

/*

One way to look at it:
Call by Value = You are playing with clones. If a clone gets a haircut, the original person doesn't lose any hair.

*/
