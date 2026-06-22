/*
================================================================================
                    C PROGRAMMING NOTES: MULTIDIMENSIONAL ARRAYS
================================================================================

This document explains pointer arithmetic and memory layouts of 2D arrays in C, 
using a concrete walkthrough of a common technical problem.

--------------------------------------------------------------------------------
1. CORE CONCEPT: 2D ARRAY MEMORY LAYOUT
--------------------------------------------------------------------------------
In C, a 2D array is essentially an "array of arrays". Even though we visualize 
it as a grid with rows and columns, the computer flattens and stores it 
contiguously (end-to-end) in linear memory.

Consider the declaration:
    unsigned int x[4][3];

* Base details:
  - This is an array containing 4 elements, where each element is a 1D array of 
    3 integers.
  - Assume the base address (starting address) of x is 2000.
  - Assume each 'unsigned int' occupies 4 bytes of memory.

* Size Calculations:
  - Size of one integer element = 4 bytes.
  - Size of one row (1D array of 3 integers) = 3 * 4 bytes = 12 bytes.
  - Total size of 2D array = 4 rows * 12 bytes = 48 bytes.

* Linear Memory Map Visualization:
  -------------------------------------------------------------------------
  | Row Index | Element | Row 1D Pointer Base | Linear Address (Decimal) |
  -------------------------------------------------------------------------
  |  Row 0    | x[0][0] | x or *(x+0)         | 2000                     |
  |           | x[0][1] |                     | 2004                     |
  |           | x[0][2] |                     | 2008                     |
  |  Row 1    | x[1][0] | x+1 or *(x+1)       | 2012                     |
  |           | x[1][1] |                     | 2016                     |
  |           | x[1][2] |                     | 2020                     |
  |  Row 2    | x[2][0] | x+2 or *(x+2)       | 2024                     |
  |           | x[2][1] |                     | 2028                     |
  |           | x[2][2] |                     | 2032                     |
  |  Row 3    | x[3][0] | x+3 or *(x+3)       | 2036                     |
  |           | x[3][1] |                     | 2040                     |
  |           | x[3][2] |                     | 2044                     |
  -------------------------------------------------------------------------

--------------------------------------------------------------------------------
2. POINTER ARITHMETIC RULES FOR 2D ARRAYS
--------------------------------------------------------------------------------
Understanding the difference between scales of addition is crucial when working 
with 2D arrays.

Rule A: Pointer to a Row (Array Level Pointer)
  When you perform arithmetic directly on the 2D array name 'x', the step size 
  is the size of an ENTIRE ROW.
  Formula: x + i = Base Address + (i * size of one row)
                 = Base Address + (i * number of columns * size of element)

Rule B: Pointer to an Element (Integer Level Pointer)
  When you dereference the row pointer once using the '*' operator, you get a 
  pointer to the first element of that specific row. Performing arithmetic 
  here shifts the pointer element by element.
  Formula: *(x + i) + j = Base Address of Row 'i' + (j * size of one element)

--------------------------------------------------------------------------------
3. PRACTICAL STEP-BY-STEP CODE ANALYSIS
--------------------------------------------------------------------------------
Let's analyze the following statement to predict its output:
    printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);

Given:
  - Base Address of x = 2000
  - Integer Size = 4 bytes
  - Row Size = 3 integers * 4 bytes = 12 bytes

--- Expression 1: x + 3 ---
* Meaning: Pointer to the 4th row (index 3) of the 2D array.
* Step Size: It skips 3 whole rows.
* Calculation:
    x + 3 = 2000 + (3 * Row Size)
          = 2000 + (3 * 12)
          = 2000 + 36
          = 2036
* Result: 2036

--- Expression 2: *(x + 3) ---
* Meaning: Dereferencing 'x + 3' changes its type from a "pointer to a row" 
  to a "pointer to the first integer element of the 4th row".
* Value: Because the 4th row begins at the exact same memory boundary where 
  the row itself starts, the numeric address remains unchanged.
* Calculation:
    *(x + 3) = Address of x[3][0]
             = 2036
* Result: 2036

--- Expression 3: *(x + 2) + 3 ---
* Meaning: 
  1. Break down *(x + 2): This is a pointer to the first element of the 3rd 
     row (index 2). 
     Address = 2000 + (2 * 12) = 2024.
  2. Add 3 to it: Since *(x + 2) is an integer-level pointer, adding 3 shifts 
     it forward by 3 individual integers.
* Calculation:
    *(x + 2) + 3 = 2024 + (3 * Integer Size)
                 = 2024 + (3 * 4)
                 = 2024 + 12
                 = 2036
* Result: 2036

--------------------------------------------------------------------------------
4. SUMMARY CONCLUSION
--------------------------------------------------------------------------------
All three expressions evaluate to the same physical memory address, despite 
having different pointer types and semantic meanings:

x + 3        -> Evaluates to 2036 (Type: Pointer to an array of 3 integers)
*(x + 3)     -> Evaluates to 2036 (Type: Pointer to an unsigned integer)
*(x + 2) + 3 -> Evaluates to 2036 (Type: Pointer to an unsigned integer)

Final Program Output:
2036, 2036, 2036
================================================================================
*/

#include <stdio.h>

int main()
{
    unsigned int x[4][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };
    printf("%u %u %u\n", x+3, *(x+3), *(x+2)+3);
}