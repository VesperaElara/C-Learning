#include <stdio.h>
#define N 5

int main()
{
    int a[N];
    int *p = a;

    printf("Enter %d numbers:\n" , N);
    for (p = a; p <= a + (N-1); p++)
    {
        scanf("%d", p); // p (not *p)
    }

    printf("Numbers in reverse order:\n");
    for (p = a + (N-1); p >= a; p--)
    {
        printf("%d ", *p); // *p (not p)
    }
}