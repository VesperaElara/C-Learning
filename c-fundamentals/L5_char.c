// relation b/w ASCII and char

#include <stdio.h>

int main()
{
    char var1 = 'N';
    char var2 = 65; // in the ASCII table, 65 is associated with A

    printf("%c is a char data type.\n"
           "65 represents %c in char data type.\n", var1, var2);


    printf("size of char data type = %zu byte\n", sizeof(char)); 
    
    // char can only hold 1 byte of information
    // char has both types - signed and unsigned.
    // in signed, the 8th bit (2^7) is taken to be negative.

    char var3 = 128;
    printf("128 in char data type represents %c character\n", var3);
    
    char var4 = 129;
    char var5 = -127;

    printf("129 in char data type represents %c character.\n"
           "-127 in char data type represents %c character too.\n", var4, var5);

    return 0;
}