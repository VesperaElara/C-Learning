/*
================================================================================
TOPIC: ACCESSING AND PROCESSING 1D ARRAYS IN C
================================================================================

1. UNDERSTANDING ARRAY ACCESS
-----------------------------
Arrays are collections of items stored in contiguous memory locations. In C,
array indexing is zero-based, meaning the first element is at index 0.

Syntax:
    array_name[index]

Example:
    If an array is named 'arr':
    - First element  = arr[0]
    - Second element = arr[1]
    - Nth element    = arr[n-1]

2. ITERATING THROUGH ARRAYS
---------------------------
To process or access every element in an array efficiently, we use loops.
Typically, a 'for' loop is used where the loop counter 'i' acts as the index.

3. PRACTICAL IMPLEMENTATION EXAMPLE
-----------------------------------
The following code demonstrates how to take user input for an array of size N
and subsequently display all elements.
*/

#include <stdio.h>
#define N 10  // Using a macro to define the array size

int main() {
    int a[N], i;

    // --- POPULATING THE ARRAY ---
    // The loop runs from i=0 to i=N-1 to fill each memory slot
    for(i=0; i<N; i++) {
        printf("Enter the integral input for index %d: ", i);
        scanf("%d", &a[i]); // '&a[i]' provides the address of the element
    }

    // --- DISPLAYING THE ARRAY ---
    printf("\nArray elements are as follows:\n");
    for(i=0; i<N; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

/*
4. KEY TAKEAWAYS
----------------
* Indexing: Always starts at 0 and ends at size-1.
* Input: Use 'scanf' with the address-of operator '&' followed by the
  indexed array variable (e.g., &a[i]).
* Macros: Using '#define' makes it easy to change the array size globally
  across your entire program.
* Loops: The loop counter is the most effective way to traverse the
  indices of an array programmatically.
================================================================================
*/