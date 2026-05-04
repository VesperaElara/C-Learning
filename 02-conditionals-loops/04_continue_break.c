#include <stdio.h>

int main()
{
    /*

    break completely stops the loop and prevents the compiler from 
    reading the commands placed after it inside the loop.

    continue restarts the loop and prevents the compiler from reading 
    the commands placed after it inside the loop.
    
    */
   
    int i;
    while (1)
    {
        printf("Which number is neither positive nor negative?\n");
        scanf("%d", &i);
        if (i != 0)
        {
            printf("Oops. That's wrong! Retry!\n");
            continue;
        }
        else
        {
            printf("Good job, math wizard!\n");
            break;
        }
    }

    // A loop to print odd numbers upto 20

    int start;
    printf("Odd numbers between 0 and 20: \n");

    for (start = 1; start < 20; start = start + 2)
    {
        printf("%d ", start);
    }
    printf("\n");

    int x;
    int n = 2;
    for (x = 1; x <= 20; x++)
    {
        if (x == n)
        {
            n = n + 2;
            continue;
        }

        printf("%d ", x);
    }
    printf("\n");

    int y;
    for (y = 1; y < 20; y++)
    {
        if (y%2 == 0)
        {
            continue;
        }
        printf("%d ", y);

    }
    printf("\n");

    return 0;
}