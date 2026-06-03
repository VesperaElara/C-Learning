/*

Basic structure of a recursive function:

return_type function_name(set_of_inputs)
{
    if
    {
        ...         >>> BASE CASE
    }
    
    else
    {
        ...         >>> RECURSIVE PROCEDURE
    }
}

*/


#include <stdio.h>

int factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }

    else
    {
        return (x * factorial(x-1));
    }
}


int main()
{
    int number;
    printf("Number = ");
    scanf("%d", &number);
    printf("%d! = %d\n", number , factorial(number));
}