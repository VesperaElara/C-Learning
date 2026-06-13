/*
================================================================================
               C PROGRAMMING: 3D ARRAYS AND POINTER ARITHMETIC
================================================================================

1. HIERARCHICAL POINTER STRUCTURE
--------------------------------------------------------------------------------
A 3D array is conceptually an "array of 2D arrays." In memory, it is stored as 
one continuous block, but C allows us to navigate its depth using multiple 
levels of dereferencing.

Assume the following declaration for the examples below:
    int a[2][2][2]; 

Pointer Levels:
    a       => Pointer to the 1st 2D array
    *a      => Pointer to the 1st 1D array of the 1st 2D array
    **a     => Pointer to the 1st element of the 1st 1D array of the 1st 2D array
    ***a    => The actual value of the 1st element (Value: 1)


2. NAVIGATING DEPTH WITH ARITHMETIC
--------------------------------------------------------------------------------
By adding integers to the pointer at different levels, you can jump across 
entire 2D layers, 1D rows, or individual elements.

Jumping 2D Layers:
    a + 1      => Points to the 2nd 2D array (Address: 1016)
    *(a + 1)   => Pointer to the 1st 1D array of the 2nd 2D array

Jumping 1D Rows:
    * (a + 1) + 1  => Pointer to the 2nd 1D array of the 2nd 2D array
    * (*(a + 1))   => Pointer to the 1st element of the 1st 1D array of the 2nd 2D array

Jumping Individual Elements:
    **a + 1    => Pointer to the 2nd element of the 1st 1D array of the 1st 2D array
    * (**a + 1) => The actual value of the 2nd element (Value: 2)


3. HOMEWORK SOLUTION: ACCESSING THE SECOND-TO-LAST ELEMENT
--------------------------------------------------------------------------------
To access the second-to-last element (Value: 7 at address 1024) in a 3D array 
of size [2][2][2] using pointer arithmetic:

Step 1: Move to the 2nd 2D array layer.
    (a + 1)

Step 2: Move to the 2nd 1D array (row) of that layer.
    *(a + 1) + 1

Step 3: Move to the 1st element of that row.
    *(*(a + 1) + 1)

Step 4: Dereference to get the value.
    *(*(*(a + 1) + 1)) => Returns 7

Alternatively, using the pointer to the very first element of that row:
    *(*(a + 1) + 1) is a pointer to the element at address 1024.

================================================================================
*/