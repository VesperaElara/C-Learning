#include <stdio.h>

int main()
{
    unsigned int x = 0;
    unsigned int y = 1;
    int counter, i;
    int n = 25;

    printf("The first %d numbers of the fibonacci sequence:\n", n);

    printf("%d %d ", x , y);

    for (counter = 0; counter < n - 2; counter++)
    {
        i = x + y;
        printf("%d ", i);
        x = y;
        y = i;
    }

    printf("\n");

    return 0;
}