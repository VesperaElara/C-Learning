#include <stdio.h>

int main()
{
    printf("%d\n", printf("%s", "Hello, World!\n"));
    // printf also returns the number of characters successfully printed on the screen.

    printf("%10s\n", "Hello!");
    // This will print 10 characters in total. 4 white spaces will be printed in the front.

    char c = 255;
    c += 10;
    printf("%d\n", c);

    unsigned i = 1; // the compiler automatically assumes i is an integer.
    int j = -4;
    printf("%u\n", i+j);

    return 0;
}
