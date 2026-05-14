#include <stdio.h>
#include <math.h>

int main()
{
    int copy = 496;
    int number = copy;
    // int result = (int)sqrt(copy + 1);
    int i;
    int quotient;
    int sum = 0;

    for (i = 1; i < copy; i++)
    {
        if (copy % i == 0)
        {
            sum = sum + i;
            printf("Divisor = %d: updated sum = %d\n", i , sum);
        }
    }

    if (sum == number)
    {
        printf("%d is a perfect number\n", number);
    }
    else
    {
        printf("%d is NOT a perfect number\n", number);
    }
}