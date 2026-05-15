#include <stdio.h>

int main()
{
    int x = 0;
    printf("x = %d\n", x++); // x remains 0 in this line, x becomes 1 in the next line (post-increment)
    printf("x = %d\n", x++); // x is 1 in this step, x becomes 2 in the next line (post-increment)
    printf("x = %d\n", ++x); // x changes from 2 to 3 in this step (pre-increment)
    int y = 0;
    printf("y = %d\n", ++y); // y changes to 1 in this line due to pre-increment
    printf("y = %d\n", y++); // y remains 1 in this line due to post increment, y changes to 2 in the next line.
}