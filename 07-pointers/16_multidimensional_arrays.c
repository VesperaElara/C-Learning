/*
================================================================================
               C PROGRAMMING: MULTIDIMENSIONAL ARRAYS AND POINTERS
================================================================================

1. THE MULTI-LAYERED POINTER CONCEPT IN 2D ARRAYS
--------------------------------------------------------------------------------
In a 1D array, the array name points directly to its first scalar element. 
However, in a 2D array, C treats the structure as an "array of 1D arrays". 

Consequently, the array name operates on a higher structural layer:
    - 1D Array Name: Points to an individual element (e.g., an integer).
    - 2D Array Name: Points to an entire 1D array row.

Example Definition:
    int a[2][2] = {{1, 2}, {3, 4}};

Here, 'a' is an array containing two elements. Each of those elements is itself 
a 1D array containing two integers.

Memory Layout (Assuming 4 bytes per integer, starting at base address 1000):
    Row index:   \________Row 0________/   \________Row 1________/
    Elem index:     a[0][0]     a[0][1]       a[1][0]     a[1][1]
    Value:       |     1     |     2     |     3     |     4     |
    Address:       1000        1004          1008        1012


2. POINTER ARITHMETIC WITH 2D ARRAYS
--------------------------------------------------------------------------------
Because the name of a 2D array points to a row, adding an integer shifts the 
address by entire rows, not by individual integers.

    a     => Points to Row 0 (Address: 1000)
    a + 1 => Points to Row 1 (Address: 1008)

Notice that 'a + 1' jumps 8 bytes forward in memory. This is because Row 0 
contains two integers (2 elements * 4 bytes = 8 bytes).


3. DEREFERENCING LEVELS: LEVEL 1 VS LEVEL 2
--------------------------------------------------------------------------------
To access the actual values inside a 2D array using pointer notation, you must 
dereference the structure twice.

Level 1 Dereference (*a):
    When you dereference the 2D array name once, you do NOT get a data value. 
    Instead, you step down a layer into that row. It converts the "pointer to 
    a row" into a "pointer to the first element of that row".
    
    *a => Points directly to the first integer of Row 0 (Address: 1000)
          Equivalent to: &a[0][0]

Level 2 Dereference (**a):
    Dereferencing a second time extracts the actual scalar value stored inside 
    that address.
    
    **a => Extracts the integer value at address 1000.
           Value: 1
           Equivalent to: a[0][0]


4. GENERAL CONVERSION FORMULAS FOR 2D ARRAYS
--------------------------------------------------------------------------------
To access any specific coordinate elements, use these direct structural mappings:

    Address Mapping:   &a[i][j]  ==  *(a + i) + j
    Element Mapping:    a[i][j]  ==  *(*(a + i) + j)

Breaking Down *(*(a + 1) + 1):
    1.  a           => Address 1000 (Points to Row 0)
    2. (a + 1)      => Address 1008 (Points to Row 1)
    3. *(a + 1)     => Evaluates to 1008, but shifts context to point to the 
                       first element inside Row 1 (i.e., &a[1][0])
    4. *(a + 1) + 1 => Shifts by 1 element size (4 bytes) -> Address 1012 (&a[1][1])
    5. *(*(a + 1) + 1) => Extracts value at 1012 -> 4


5. SCALING TO HIGHER DIMENSIONS: 3D ARRAYS
--------------------------------------------------------------------------------
The exact same logic scales infinitely up the dimensional hierarchy. C treats 
a 3D array as an "array of 2D arrays".

Example Definition:
    int a[2][2][2];

Hierarchy Layout breakdown:
    - 'a'       : Points to the first entire 2D array layer.
    - '*a'      : Points to the first 1D array row of that layer.
    - '**a'     : Points to the first individual integer element of that row.
    - '***a'    : Accesses the raw scalar integer value stored inside.

General Element Access Formula for 3D Arrays:
    a[i][j][k] == *(*(*(a + i) + j) + k)

================================================================================
*/

#include <stdio.h>

int main(void)
{
    /*----------------------------------------------------*/
    // 2D Array Configurations
    /*----------------------------------------------------*/
    int a[3][3] =
    {
        {5, 10, 15},
        {4, 8, 12},
        {8, 16, 24}
    };

    // --- ROW 0 ---
    // Output: Memory address of row 0, col 0 (Same as &a[0][0])
    printf("%p\n", (void*)(*(a + 0) + 0));     

    // Output: 5 (Value at &a[0][0], same as a[0][0])
    printf("%d\n", *(*(a + 0) + 0));  

    // --- ROW 1 ---
    // Output: Memory address of row 1, col 0 (Same as &a[1][0])
    printf("%p\n", (void*)(*(a + 1) + 0));     

    // Output: 4 (Value at &a[1][0], same as a[1][0])
    printf("%d\n", *(*(a + 1) + 0));  

    // --- ROW 2 ---
    // Output: Memory address of row 2, col 0 (Same as &a[2][0])
    printf("%p\n", (void*)(*(a + 2) + 0));     

    // Output: 8 (Value at &a[2][0], same as a[2][0])
    printf("%d\n", *(*(a + 2) + 0));  

    // --- ROW 2, COLUMN 2 ---
    // Output: Memory address of row 2, col 2 (Same as &a[2][2])
    printf("%p\n", (void*)(*(a + 2) + 2));   

    // Output: 24 (Value at &a[2][2], same as a[2][2])
    printf("%d\n", *(*(a + 2) + 2));  

    /*----------------------------------------------------*/
    // 3D Array Configurations
    /*----------------------------------------------------*/
    printf("----------------------------------------------------\n");

    int b[3][3][3] =
    {
        // Block 0
        {
            {5, 10, 15},
            {4, 8, 12},
            {8, 16, 24}
        },
        // Block 1
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        // Block 2
        {
            {15, 30, 45},
            {60, 75, 90},
            {105, 120, 135}
        }
    };

    // Accessing Element b[0][0][0] = 5
    printf("%p\n", (void*)(*(*(b + 0) + 0) + 0));     // Gives &b[0][0][0]
    printf("%d\n", *(*(*(b + 0) + 0) + 0));           // Gives b[0][0][0] -> 5

    // Accessing Element b[1][1][0] = 4 (Block 1, Row 1, Col 0)
    printf("%p\n", (void*)(*(*(b + 1) + 1) + 0));     // Gives &b[1][1][0]
    printf("%d\n", *(*(*(b + 1) + 1) + 0));           // Gives b[1][1][0] -> 4

    // Accessing Element b[2][1][2] = 90 (Block 2, Row 1, Col 2)
    printf("%p\n", (void*)(*(*(b + 2) + 1) + 2));     // Gives &b[2][1][2]
    printf("%d\n", *(*(*(b + 2) + 1) + 2));           // Gives b[2][1][2] -> 90

    return 0;
}
