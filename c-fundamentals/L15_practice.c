#include <stdio.h>

static int i; // All global variables are initialized with 0 by default.
static int i = 26; // However, the manually initialized variable is the one preferred.
static int i;
// i = 75; 
// --> NOT ALLOWED, (re)assigning/redefining value to a global variable isn't 
// allowed outside of the main function.

int main()
{
    int var = 0x43FF; // --> Hexadecimal value. --> Both x and X can be used interchangably.
    printf("%x\n", var); // %x gives ff as the output, %X gives FF as the output
    printf("%X\n", var);
    printf("%d\n", var); // converting the hexadecimal to its corresponding decimal value

    static int i; 
    /*
    However, 1st preference is given to the local variable static int i.
    Static variables are, however, initialized with 0 by default.
    Removing this local variable "static int i;" would result in the 
    initialized global one to be preferred.
    */
    printf("%d", i);




    
}