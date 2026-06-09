#include <stdio.h>

/*
#define N 4

int main()
{
    int a[N] = {23, 45, 6, 98};
    int max = a[0], min = a[0];
    for (int x = 1; x < N; x++)
    {
        if (a[x] > a[0])
        {
            max = a[x];
        }
        else if (a[x] < a[0])
        {
            min = a[x];
        }
    }

    printf("max = %d\n", max);
    printf("min = %d\n", min);
}

// This code does not use pointers to find the
// largest and smallest elements in the array.

*/

#include <stdio.h>

void pointerfun(int arr[], int no_of_elements, int *MAX, int *MIN)
{
    // Defensive coding: Force local max/min to start at the first element
    // This makes your function independent and safe from main() errors!
    int maximum = arr[0];
    int minimum = arr[0];
    
    // Optimized: Start at x = 1 since index 0 is already handled above
    for (int x = 1; x < no_of_elements; x++)
    {
        if (arr[x] > maximum)
        {
            maximum = arr[x];
        }
        else if (arr[x] < minimum)
        {
            minimum = arr[x];
        }
    }
    
    // Passing the final results back to the original memory addresses
    *MAX = maximum;
    *MIN = minimum;
}

int main()
{
    int a[] = {23, 19, 8, 16, 45, 98, 31, 90, 73, 65, 58, 89, 69, 25, 14};
    int n = sizeof(a) / sizeof(a[0]);
    
    int max; 
    int min;
    
    // Notice how main() doesn't even need to initialize max/min anymore? 
    // Your function handles it perfectly!
    pointerfun(a, n, &max, &min);
    
    printf("Max = %d\nMin = %d\n", max, min);
    
    return 0;
}
