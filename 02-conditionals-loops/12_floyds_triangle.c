#include <stdio.h>

int main() 

{

int i, x;
int n = 8;
int k = 1;

for (i = 0; i < n; i++)
  {
    for (x = 0; x < i; x++)
    {
        printf("%d ", k);
        k++;
    }
    printf("\n");
  }

return 0;

}
