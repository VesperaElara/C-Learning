#include <stdio.h>
int main()
{
    int a[][3] = {1, 2, 3, 4, 5, 6};
    int (*ptr)[3] = a; // 1D array
    printf("%d %d ", (*ptr)[1], (*ptr)[2]);
    ++ptr;
    printf("%d %d\n", (*ptr)[1], (*ptr)[2]);
}

/*
================================================================================
               C PROGRAMMING NOTES: POINTERS TO MULTIDIMENSIONAL ARRAYS
================================================================================

1. CORE CONCEPT: POINTER TO AN ARRAY
--------------------------------------------------------------------------------
A pointer to an array (also called an array pointer) is a pointer variable that 
points to an entire array as a single unit, rather than pointing to just a single 
scalar element.

Syntax:
    data_type (*pointer_name)[array_size];

Example from the code:
    int (*ptr)[3] = a;

* Why the parentheses matter: 
  - `int (*ptr)[3]` declares a pointer to an array of 3 integers.
  - `int *ptr[3]` (without parentheses) declares an array of 3 pointers to integers.


2. MEMORY LAYOUT OF A 2D ARRAY
--------------------------------------------------------------------------------
A 2D array is stored in memory sequentially (Row-Major Order). 
The array `int a[][3] = {1, 2, 3, 4, 5, 6};` creates a 2x3 grid (2 rows, 3 columns).

Visual Layout:
+-----------+-----------+-----------+-----------+-----------+-----------+
|     1     |     2     |     3     |     4     |     5     |     6     |
+-----------+-----------+-----------+-----------+-----------+-----------+
[   Row 0: Elements 0, 1, 2         ][   Row 1: Elements 0, 1, 2         ]


3. HOW THE POINTER NAVIGATES THE 2D ARRAY
--------------------------------------------------------------------------------
When you assign a 2D array to an array pointer (`ptr = a`), the pointer points 
to the first entire row (Row 0), which is a block of 3 integers.

* Pointer Arithmetic (++ptr):
  - Incrementing the pointer moves it by the size of the entire data type it 
    points to.
  - Since `ptr` points to an array of 3 integers, `++ptr` moves the pointer 
    forward by exactly `3 * sizeof(int)` bytes.
  - This effectively shifts `ptr` from Row 0 to Row 1.

* Dereferencing and Subscripting:
  - `(*ptr)` gives access to the row that `ptr` currently points to.
  - `(*ptr)[i]` accesses the element at index `i` within that specific row.


4. STEP-BY-STEP CODE EXECUTION TRACE
--------------------------------------------------------------------------------
Initial State:
  - `ptr` points to Row 0 -> {1, 2, 3}

First printf statement:
  - `printf("%d %d ", (*ptr)[1], (*ptr)[2]);`
  - Explanations:
    - `(*ptr)[1]` looks at Row 0, index 1 -> Value is 2
    - `(*ptr)[2]` looks at Row 0, index 2 -> Value is 3
  - Output so far: 2 3

Pointer Modification:
  - `++ptr;`
  - `ptr` now shifts to point to Row 1 -> {4, 5, 6}

Second printf statement:
  - `printf("%d %d", (*ptr)[1], (*ptr)[2]);`
  - Explanations:
    - `(*ptr)[1]` looks at Row 1, index 1 -> Value is 5
    - `(*ptr)[2]` looks at Row 1, index 2 -> Value is 6
  - Output so far: 5 6

Final Program Output:
  2 3 5 6


5. KEY TAKEAWAYS FOR BEGINNERS
--------------------------------------------------------------------------------
- A 2D array identifier decays into a pointer to its first row (not its first 
  element).
- `(*ptr)[i]` is syntactically equivalent to `ptr[0][i]`.
- Modifying `ptr` with `++` or `--` changes the row context, allowing you to 
  traverse through multidimensional structures row by row.
================================================================================
*/