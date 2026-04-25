#include <stdio.h>
#include <limits.h>

int main()
{
    int var1 = INT_MIN;
    int var2 = INT_MAX;

    printf("range of the signed integer is from: %d to %d\n", var1, var2);

    unsigned int var3 = 0;
    unsigned int var4 = UINT_MAX;

    printf("range of the unsigned integer is from: %u to %u\n", var3, var4);

    short int var5 = SHRT_MIN;
    short int var6 = SHRT_MAX;

    printf("range of the signed short integer is from: %d to %d\n", var5, var6);

    short unsigned int var7 = 0;
    short unsigned int var8 = USHRT_MAX;

    printf("range of the unsigned short integer is from: %u to %u\n", var7, var8);
}
/*
1. sizeof (short) <= sizeof (int) <= sizeof (long).
2. Writing signed int some_variable_name; is equivalent to writing int some_variable_name;
3. %d is used to print "signed integer"
4. %u is used to print "unsigned integer"
5. %ld is used to print "long integer" equivalent to "signed long integer"
6. %lu is used to print "unsigned long integer"
7. %lld is used to print "long long integer"
8. %llu is used to print "unsigned long long integer"
*/