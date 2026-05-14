#include <stdio.h>

int main()
{
    int year;

    do
    {
        printf("Year: ");
        scanf("%d", &year);
    }
    while (year < 0);

/*
    if (year % 400 == 0)
    {
        printf("The centurial year %d is a leap year.\n", year);
    }
    else if (year % 100 == 0)
    {
        printf("The centurial year %d is NOT a leap year.\n", year);
    }
    else if (year % 4 == 0)
    {
        printf("The year %d is a leap year.\n", year);
    }
    else // if (year % 4 != 0)
    {
        printf("The year %d is NOT a leap year.\n", year);
    }
*/

// Let's shrink down the entire code into a single sentence. DRY principle!

    if ( year % 400 == 0 || ((year % 100 != 0) && (year % 4 == 0)) )
    {
        printf("The year %d is a leap year.\n", year);
    }
    else
    {
        printf("The year %d is NOT a leap year.\n", year);
    }

}