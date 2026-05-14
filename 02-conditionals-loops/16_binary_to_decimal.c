#include <stdio.h>

int main()
{
    int binary = 110011011;
    int number = binary;
    int digit_counter = 0;
    int decimal = 0;
    int weight = 1;

    while (binary != 0)
    {
        int unit_digit = binary % 10;
        /*

        int weight = 1;
        for (int x = 0; x < digit_counter; x++) // Loop for exponentiation
        {
            weight = weight*2;
        }
        
        - Maybe you don't "need" to perform the exponentiation from scratch in each iteration.
        - You could just multiply the value of weight obtained from the previous loop 
          with 2 in the present loop, get it?
        - Code that works is good, but code that works faster is better.

        */

        /*
        
        if (digit_counter != 0)
        {
            weight = weight*2;
        }
        
        - We could write this, but you may realize this "extra" code becomes redundant
          if we simply shift weight = weight*2 to the end of the entire program.

        */
        
        int product = unit_digit * weight;
        decimal = decimal + product;
        binary = binary/10;
        digit_counter++;
        weight = weight*2;
    }

    printf("%d is %d-digit long.\n", number , digit_counter);
    printf("Binary number %d represents %d in decimal numbers.\n", number , decimal);

}