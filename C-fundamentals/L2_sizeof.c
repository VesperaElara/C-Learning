#include <stdio.h>

int main()
{
    printf("%d\n", sizeof(long int));
    printf("%d\n", sizeof(short int));
    return 0;
}
// if int = 4 bytes, short int = 2 bytes, long int = 8 bytes
// 1 byte = 8 bits
// a warning isn't the same thing as error