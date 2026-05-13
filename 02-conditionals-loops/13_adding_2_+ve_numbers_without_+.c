#include <stdio.h>

int main()
{
    int x , y, sum;
    
    do
    {
        printf("x = ");
        scanf("%d", &x);
    }
    while (x < 0);

    do
    {
        printf("y = ");
        scanf("%d", &y);
    }
    while (y < 0);

    int xx = x;
    int yy = y;

    for (xx; xx > 0; xx--)
    {
        yy++;
    }

    printf("%d + %d = %d\n", x , y , yy);

}