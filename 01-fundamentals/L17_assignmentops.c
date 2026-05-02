/*

Short-hand assignment operators:
    +=      First addition, then assignment             e.g., a += 1 equivalent to a = a + 1
    -=      First subtraction, then assignment          
    *=      First multiplication, then assignment
    /=      First division, then assignment
    %=       First modulus then assignment
    <<=     First bitwise left shift then assignment
    >>=     First bitwise right shift then assignment
    &=      First bitwise AND then assignment
    |=      First bitwise OR then assignment
    ^=      First bitwise XOR then assignment

*/

#include <stdio.h>

int main()
{
    char a = 7; // 2^2 + 2^1 + 2^0 = 4 + 2 + 1 = 7 >>>> (0000 0111)

    a ^= 5; // 2^2 + 2^0 = 4 + 1 = 5 >>>> (0000 0101)

    /*
    a = a^5 = (0000 0111)
             ^(0000 0101) = 0000010 (representation of 2)
    */

    printf("ANSWER: %d\n", a += 3); // a = a + 3 = 2 + 3 = 5

}

/*
    Postfix operators have higher precendence than prefix operators.    
    Therefore, for both postfix and prefix operators: associativity is 
    not from left to right, but from right to left.
    All assignment operators have associativity from right to left.
*/
