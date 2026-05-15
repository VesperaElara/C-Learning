#include <stdio.h>

int function1(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num >>= 1;
    }
    return count;
}

int function2(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num >>= 2;
    }
    return count;
}

int main()
{
    int number = 435;
    int result1 = function1(435);
    int result2 = function2(435);
    printf("The value of count for function1(%d) = %d\n", number , result1);
    printf("The value of count for function2(%d) = %d\n", number , result2);
}

/*
factorization of 435;
435 = 256 + 128 + 32 + 16 + 2 + 1 = 2^8 + 2^7 + 2^5 + 2^4 + 2^1 + 2^0
435 = 0001 1011 0010

            count    right shift
loop1:      1        0000 1101 1001 
loop2:      2        0000 0110 1100
loop3:      3        0000 0011 0110
loop4:      4        0000 0001 1011
loop5:      5        0000 0000 1101
loop6:      6        0000 0000 0110
loop7:      7        0000 0000 0011
loop8:      8        0000 0000 0001
loop9:      9        0000 0000 0000

LOOP ENDS

Value of count for function1(435) = 9
Similarly:
Value of count for function2(435) = 5

*/