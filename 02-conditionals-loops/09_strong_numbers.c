#include <stdio.h>

int main()
{
    int number = 40585;
    int copy = number; // copy is created so that dismantling it does not effect the original number.
    int u, x, sum = 0;

    printf("Number: %d\n", number);

    do
    {
        u = copy % 10;
        int p = 1;
        for (x = 1; x <= u; x++)
        // What if u = 0? This loop doesn't run for u = 0. So p remains equal to 1.
        {
            p = p * x;
        }
        sum = sum + p;
        printf("%d! = %d\n", u , p);
        copy = copy/10;
    }
    while (copy != 0);

    // A do-while loop was used instead of a while loop to incorporate the case where number = 0;

    printf("Sum of factorial of all digits = %d\n", sum);

    if (sum == number)
    {
        printf("%d = %d\nThe given number is a Strong number.\n", sum, number);
    }
    else
    {
        printf("%d != %d\nThe given number is NOT a Strong number.\n", sum, number);
    }

}