#include <stdio.h>

int main()
{
    int number;
    
    do
    {
        printf("Check whether any digit repeats in the given number:\n");
        printf("Enter number: ");
        scanf("%d", &number);
    }
    while (number < 0);

    int copy = number;

    int seen[10] = {0};

    while (copy != 0)
    {
        int unit_digit = copy % 10;
        if (seen[unit_digit] != 0)
        {
            break;
        }
        seen[unit_digit]++;
        copy = copy/10;
    }

    if (copy != 0)
    {
        printf("Yes. Digits repeat.\n");
    }
    
    else
    {
        printf("No. Digits do not repeat.\n");
    }
}