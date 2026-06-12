#include <stdio.h>
int main()
{
    int sum = 0;
    int *p;
    int a[] = {21, 43, 87, -99, 79, 42, 55, 9, -11, 28, -37, 90};
    int len = sizeof(a)/sizeof(a[0]);
    for (int x = 0; x < len; x++)
    {
        p = &a[x];
        sum += *p;
    }
    printf("Sum of array elements = %d\n", sum);
}