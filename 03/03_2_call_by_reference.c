#include <stdio.h>

// The '*' means these are "Pointers"
// They act like remote controls for the original variables

int fun(int *ptr1, int *ptr2)
{
    // '*ptr1' means: "Go to the address and change the value there"
    *ptr1 = 30;
    *ptr2 = 40;
    
    return 0;
}

int main()
{
    int x = 10;
    int y = 20;

    // The '&' symbol means "Address of"
    // We send the 'Home Address' of x and y, not the numbers
    fun(&x, &y);

    // Because the function fun() changed the originals, output is now 20, 10
    printf("x = %d, y = %d", x, y);

    return 0;
}
