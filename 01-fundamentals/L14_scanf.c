/* 
scanf is used to take input. It stands for "scan formatted string".
The ampersand sign "&" should ALWAYS come before the variable_name in the scanf action.
"&" in front of the variable_name implies "address-of"
While using "&" before a variable_name, you ask the compiler to give you the "memory location"
of the variable in order to store input from the user.
*/

#include <stdio.h>

int main()
{
    int x, y;
    printf("Adding x + y\n");
    printf("\n");
    printf("x = ");
    // scanf("%d\n", &x); --> NEVER add \n in a scanf command!
    // It tells the computer to wait until it finds a non-blank line.
    scanf("%d", &x);
    printf("\n");
    printf("y = ");
    scanf("%d", &y);
    printf("\n");
    printf("%d + %d = %d\n", x, y, (x+y));
}