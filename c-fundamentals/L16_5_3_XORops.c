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
    a = a ^ b; // 0100 ^ 0011 = 0111 (7)
    b = a ^ b; // 
    a = a ^ b;
    printf("Final values after XOR: a = %d , b = %d\n", a , b);
    return 0;
}

// 0100
// 0011
// 0111 = 7