#include <stdio.h>
#include <math.h>

int main()
{
    int number = 97;
    int result = (int)sqrt(number + 0.5); // 0.5 is added for the purpose of a "safety net" 
    int x = 0;
    int i;

    if (number == 1)
    {
        printf("1 is neither a prime nor composite.\n");
    }

    else

    {

        for (i = 1; i <= result; i++)
        {
            if (number % i == 0)
            {
                x++;
            }
            // else
            // {
            //     continue;
            // } 
            // COMMENTED PART IS REDUNDANT
        }

        if (x > 1)
        {
            printf("%d is NOT a prime number.\n", number);
        }

        else
        {
            printf("%d is a prime number.\n", number);
        }

    }

}