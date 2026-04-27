// float = 4 bytes = 32 bits
// double = 8 bytes = 64 bits
// long double = 16 bytes = 128 bits

#include <stdio.h>

int main()
{
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(long double));
    float pi1 = 3.1415926535897932384626433832795028; //upto 35 decimal places - lost accuracy after 6 decimal points
    double pi2 = 3.1415926535897932384626433832795028; //upto 35 decimal places - lost accuracy after 15 decimal points
    long double pi3 = 3.1415926535897932384626433832795028L; //upto 35 decimal places - lost accuracy after 18 decimal points
    printf("%.16f\n", pi1);
    printf("%.16f\n", pi2);
    printf("%.21Lf\n", pi3); //Lf is used for long double

    /*
    Without adding the L at the end of pi3, you will notice both pi2 and pi3 display the same precision.
    (15 decimal points each, pi3 is treated like a double, not a long double)
    */

    int var = 4/9;
    printf("Integer division of 4/9 gives: %d\n", var);
    float var1 = 4/9;
    printf("Float division of 4/9 gives: %.2f\n", var1);
    float var2 = 4.0f/9.0f;
    printf("Float division of 4.0f/9.0f gives: %.2f\n", var2);
}