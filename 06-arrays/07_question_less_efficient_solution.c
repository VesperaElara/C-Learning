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

    // No. of digits in the given number:

    int i = 0;

    while (copy1 != 0)
    {
        i++;
        copy1 = copy1/10;
    }

    printf("No. of digits in %d = %d\n", number , i);

    // Add each digit to the array

    int array[i];

    for (int n = 0; n < i; n++)
    {
        array[n] = copy2 % 10;
        copy2 = copy2/10;
    }

    printf("Array of all digits in the number %d:\n", number);

    for (int n = 0; n < i; n++)
    {
        printf("%d ", array[n]);
    }

    printf("\n");

    /*
    STRATEGY: Brute-force comparison.
    I'm comparing each digit (at index 'q') against all following digits (at index 'r')
    to check for duplicates. Using 'r = i-1' and 'r > q' ensures I don't re-check
    pairs I've already examined or compare a digit to itself.
    */


    int flag = 0;

    for (int q = 0; q < i; q++)
    {
        for (int r = i-1; r > q; r--)
        {
            if (array[q] == array[r])
            {
                flag++;
                break;
            }
        }
    }

    if (flag != 0)
    {
        printf("Yes, digits repeat.\n");
    }
    else
    {
        printf("No, digits do not repeat.\n");
    }
}