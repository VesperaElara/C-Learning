#include <stdio.h>

int main()
{
    /*
    
    We need to "reverse" the number and equate the reversed number with its original.
    If reversed number = original, it is a palindrome.
    To "reverse" a given number, we divide it with 10. 
    The remainder gives the "unit-digit". The quotient is the number without the unit digit.

    Steps to reverse the number:
    Declare and define a variable: int result = 0
    The input = quotient (variable)
    In a while(quotient!=0) loop, the following takes place:
    unit digit is found using (quotient % 10)
    result is updated to result*10 + unit digit
    In the last step, quotient is updated to quotient/10.
    The loop continues until quotient/10 = 0 (integer division)
    
    */

    int result = 0;
    int palindrome = 569296; // You may change this value.
    int q = palindrome;
    int u;

    while (q != 0)
    {
        u = q % 10; // We get the unit digit
        result = result*10 + u; // We update the result variable
        q = q/10; // We update the value of q for the next loop
        printf("%d\n", result);
    }

    printf("\n");

    if (result == palindrome)
    {
        printf("%d reversed gives %d.\n", palindrome, result);
        printf("%d = %d. Therefore, this is a palindrome!\n", palindrome, result);
    }

    else
    {
        printf("%d reversed gives %d.\n", palindrome, result);
        printf("%d != %d. Therefore, this is NOT a palindrome!\n", palindrome, result);
    }

}