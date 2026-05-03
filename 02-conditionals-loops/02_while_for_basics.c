// Basics while loop and for loop

#include <stdio.h>

int main()
{
    int counter = 3;
    printf("Using while loop:\n");
    while (counter >= 0)
    {
        printf("%d\n", counter);
        counter--;
    }

    printf("Using for loop:\n");
    // for loop is represented as follows:
    // for (initialization; condition; increment/decrement)
    for (counter = 3; counter >= 0; counter--)
    {
        printf("%d\n", counter);
    }

    return 0;

    // Use a while loop when you don't know the end-point; use a for loop when you do."
}