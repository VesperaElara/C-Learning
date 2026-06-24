#include <stdio.h>

int main()
{
    int a, *b, **c;
    a = 4;
    b = &a;
    c = &b;
    **c = **c + 5;
    printf("%d", **c);
}

/*

c is a pointer to a pointer to an integer.
*c gets the value stored in b (which is the address of a).
**c dereferences a second time, getting the value stored in a (which is 4).

*/