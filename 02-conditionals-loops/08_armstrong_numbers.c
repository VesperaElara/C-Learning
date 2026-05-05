#include <stdio.h>

/*

int main()
{
    int number = 375;
    int copy1 = number;
    int copy2 = number;
    int count = 0;
    int u, x, sum = 0;
    int p = 1;

    while (copy1 != 0)
    {
        copy1 = copy1/10;
        count++;
    }

    printf("Number of digits: %d\n", count);

    while (copy2 != 0)
    {
        u = copy2 % 10;
        for (x = 1; x <= count; x++)
        {
            p = p * u;
        }
        printf("%d ^ %d = %d\n", u, count, p);
        sum = sum + p;
        copy2 = (copy2)/10;
    }
    printf("Total sum = %d\n", sum);

}

 * LOGIC BUG TRACE (Version 1.0):
 * Symptom: 'p' values grew exponentially for the 2nd and 3rd digits.
 * Cause: Variable 'p' was initialized outside the while-loop.
 * It carried the product of the previous digit into the next iteration.
 * Fix: Move 'p = 1' inside the extraction loop to reset the "Power Machine."

*/

int main()
{
    int number = 371;
    int copy1 = number;
    int copy2 = number;
    int count = 0;
    int u, x, sum = 0;

    printf("Number given: %d\n", number);

    while (copy1 != 0)
    {
        copy1 = copy1/10;
        count++;
    }

    printf("Number of digits: %d\n", count);

    while (copy2 != 0)
    {
        u = copy2 % 10;
        int p = 1;
        for (x = 1; x <= count; x++)
        {
            p = p * u;
        }
        printf("%d ^ %d = %d\n", u, count, p);
        sum = sum + p;
        copy2 = (copy2)/10;
    }
    printf("Total sum = %d\n", sum);

    if (sum == number)
    {
        printf("%d = %d, the number is an Armstrong Number!\n", number, sum);
    }

    else
    {
        printf("%d != %d, the number is NOT an Armstrong Number!\n", number, sum);
    }

}

