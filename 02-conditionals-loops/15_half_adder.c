#include <stdio.h>

int main()
{
    int a = 7; // 7 = 1 + 2 + 4 = 2^0 + 2^1 + 2^2 :        0111
    int b = 4; // 4 = 2^2 :                                0100
    int a_copy = a;
    int b_copy = b;
    int sum, carry;

    while (b != 0)
    {
        sum = a^b; // XOR operation: 0111 ^ 0100 = 0011 (3)
        carry = (a&b) << 1; // 0111 & 0100 = 0100 (8)
        printf("sum: %d     carry: %d\n", sum, carry);
        a = sum;
        b = carry;
    }

    printf("%d + %d = %d\n", a_copy, b_copy, sum);

    /*
    E.g., take a = 7; b = 7
    LOOP 1:
    a =         0111
    b =         0111
    a^b =       0000   = sum
    a&b =       0111
    a&b << 1 =  1110   = carry

    LOOP 2:
    a =         0000
    b =         1110
    a^b =       1110   = sum
    a&b =       0000
    a&b << 1 =  0000   = carry

    b = carry = 0 at loop 2; therefore the loop stops.
    final sum = 1110 = 8 + 4 + 2 = 14
    
    */
}