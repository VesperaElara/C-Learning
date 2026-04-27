// understand what happens in this code, when we exceed the range for both signed and unsigned data.

#include <stdio.h>

int main ()
{
    unsigned int var1 = 4294967295;
    printf("%u\n", var1);

    unsigned int var2 = 4294967296;
    printf("%u\n", var2);

    unsigned int var3 = 4294967297;
    printf("%u\n", var3);

    unsigned int var4 = 4294967298;
    printf("%u\n", var4);

    int var5 = 2147483647;
    printf("%d\n", var5);

    int var6 = 2147483648;
    printf("%d\n", var6);

    int var7 = -2147483648;
    printf("%d\n", var7);

    int var8 = -2147483649;
    printf("%d\n", var8);

}

// for n bit unsigned data - this acts like mod 2^n