#include <stdio.h>

int variable = 5; // Global variable used in 2nd last question.

int main()
{
    int i = 5;
    int var = sizeof(i++); // This would be 4 (bytes), but the operand i++ is NOT evaluated.
    printf("Current Value of i = %d , var = %d\n", i, var); // It would print 5, 4 NOT 6, 4

    /*
    C standard is the language specification which is adopted by all C compilers across the globe.

    According to C99 standard:

    The sizeof operator yields the size (in bytes) of its
    operand, which may be an expression or a parenthesized name
    of a type. The size is determined from the type of the
    operand. If the type of the operand is a variable length
    array type, then the operand is evaluated; otherwise, the
    operand is not evaluated and the result is an integer
    constant.
    */

    int a = 1;
    int b = 1;
    int c = ++a || b++; // a changes to 2.
                        // b not evaluated due to short-circuit, true returned immediately.
    int d = b-- && --a; // b-- is NOT zero (post-increment), it changes to zero in NEXT step.
                        // a changes from 2 to 1.
    // d is true (1), c is true (1), b becomes 0 (in next step), a is 1
    printf("d = %d, c = %d, b = %d, a = %d\n", d , c , b , a); 
    // ANSWER = d = 1, c = 1, b = 0, a = 1 

    int variable = variable;
    printf("Value of variable = %d\n", variable); // Garbage value

    unsigned int ten = 10; // 0000 1010
    printf("signed int (~ten) = %d\n", ~ten); // 1111 0101, but 2^7 is negative
    // ~x = -(x+1) >>> direct formula
    
    return 0;
}


