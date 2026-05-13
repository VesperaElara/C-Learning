/*

The hard-coding way:

#include <stdio.h>

int main()
{
    int x, y;
    printf("x = ");
    scanf("%d" , &x);
    printf("y = ");
    scanf("%d" , &y);

    if (x < 0 && y < 0)
    {
        int xx = -x;
        int yy = -y;

        while (yy != 0)
        {
            xx++;
            yy--;
        }

        printf("%d + %d = %d\n", x , y , -xx);
    }

    else if (x >= 0 && y >= 0)
    {
        int xx = x;
        int yy = y;

        while (yy != 0)
        {
            xx++;
            yy--;
        }

        printf("%d + %d = %d\n", x , y , xx);        

    }

    else if (x <= 0 && y >= 0)
    {
        // x is negative; y is positive
    
        int xx = x;
        int yy = y;

        while (yy != 0)
        {
            xx++;
            yy--;
        }

        printf("%d + %d = %d\n", x , y , xx);
    }

    else if (x >= 0 && y <= 0)
    {
        // x is positive; y is negative
    
        int xx = x;
        int yy = y;

        while (xx != 0)
        {
            yy++;
            xx--;
        }

        printf("%d + %d = %d\n", x , y , yy);
    }

}

*/

// The universal case method: Focus only on whether y is positive/negative.

#include <stdio.h>

int main()
{
    int x, y;
    printf("x = ");
    scanf("%d" , &x);
    printf("y = ");
    scanf("%d" , &y);

    if (y >= 0) // When y is positive (non-negative), you need to post-decrement it until it reaches 0.
    {
        int xx = x;
        int yy = y;

        while (yy != 0)
        {
            xx++; // Subtract 1 from yy and add it to xx
            yy--;
        }

        printf("%d + %d = %d\n", x , y , xx);

    }

    if (y < 0) // When y is negative, you need to post-increment it until it reaches 0.
    {
        int xx = x;
        int yy = y;

        while (yy != 0)
        {
            xx--; // Add 1 to yy; Subtract 1 from xx
            yy++;
        }

        printf("%d + %d = %d\n", x , y , xx);

    }

}



