/*
Q. Write a program to check whether any of the digits in a number appears more than once:

Example:

Input: 67827
*/

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
    while (number <= 0);

    int copy1 = number, copy2 = number;

    int array[10] = {0};

    // No. of digits in the given number:

    int i = 0;

    while (copy1 != 0)
    {
        i++;
        copy1 = copy1/10;
    }

    printf("No. of digits in %d = %d\n", number , i);

    for (int x = 0; x < i; x++)
    {
        int unit_digit = copy2 % 10;
        array[unit_digit]++;
        copy2 = copy2 / 10;
    }

    int flag = 0;

    for (int x = 0; x < 10; x++)
    {
        if (array[x] != 0 && array[x] != 1)
        {
            printf("%d repeats %d times.\n", x , array[x]);
        }
        else
        {
            flag++;
        }
    }

    if (flag == 10)
    {
        printf("No digits repeat.\n");
    }
}