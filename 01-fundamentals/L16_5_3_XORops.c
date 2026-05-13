/*
OR (also called Inclusive OR): 0|0 gives 0, all the rest give 1.
XOR (called Exclusive OR): both 0|0 and 1|1 gives 0, all the remaining give 1.
Bitwise XOR is represented by ^
7       : 0 1 1 1
4       : 0 1 0 0
        -----------
7^4     : 0 0 1 1 (represents 3)
7^4 = 3
*/

#include <stdio.h>

int main()
{
    int a = 4;
    int b = 3;
    a = a ^ b; // 0100 ^ 0011 = 0111 (7 = a)
    b = a ^ b; // 0111 ^ 0011 = 0100 (4 = b)
    a = a ^ b; // 0111 ^ 0100 = 0011 (3 = a)
    printf("Final values after XOR: a = %d , b = %d\n", a , b);
    return 0;

    // XOR gives 0 when the bits are identical (1|1 or 0|0)
    // XOR gives 1 when the bits are not identical
    // XNOR gives 1 when the bits are identical.
    // XNOR gives 0 when the bits are not identical.
}

// 0100
// 0011
// 0111 = 7