#include <stdio.h>

int f(int *a, int n)
{
if(n <= 0) return 0;
else if(*a % 2 == 0) return *a + f(a+1, n-1);
else return *a - f(a+1, n-1);
}

int main()
{
int a[] = {12, 7, 13, 4, 11, 6};
printf("%d\n", f(a, 6));
return 0;
}

/*

Execution Tree/Call Stack Trace:

f(&a[0], 6)
   |
   v
12 + f(&a[1], 5)
   |
   v
7 - f(&a[2], 4)
   |
   v
13 - f(&a[3], 3)
   |
   v
4 + f(&a[4], 2)
   |
   v
11 - f(&a[5], 1)
   |
   v
6 + f(&a[6], 0) ----> return 0;

*/

