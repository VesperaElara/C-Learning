/*
================================================================================
THREE-DIMENSIONAL (3D) ARRAYS IN C
================================================================================

1. DEFINITION
   A 3D array is a collection of 2D arrays, often visualized as a "block" or 
   "stack" of matrices. It requires three indices for access.

2. SYNTAX AND INITIALIZATION
   Declaration:
   data_type name_of_array[depth][rows][columns];

   Example:
   int a[2][2][3] = {
       {{1, 2, 3}, {4, 5, 6}},
       {{7, 8, 9}, {10, 11, 12}}
   };
   // This structure creates 2 blocks, each containing a 2x3 matrix.

3. ACCESSING ELEMENTS
   Elements are accessed by specifying all three dimensions:
   array_name[block_index][row_index][column_index]

   Example:
   To access the element in the 1st block, 1st row, 3rd column:
   a[0][0][2] // Indices are 0-based.

4. PRINTING AND TRAVERSAL
   To process or print all elements in a 3D array, you use three nested loops.
   Each loop corresponds to one of the three dimensions.

   Example:
   for (int i = 0; i < 2; i++) {           // Loop through blocks
       for (int j = 0; j < 2; j++) {       // Loop through rows
           for (int k = 0; k < 3; k++) {   // Loop through columns
               printf("%d ", a[i][j][k]);
           }
       }
   }

5. CONCEPTUAL SUMMARY
   Think of a 3D array as:
   - i: The depth (or which 2D block you are in)
   - j: The row within that block
   - k: The column within that row

   Each increment of the innermost loop (k) moves you horizontally, the middle 
   loop (j) moves you vertically through rows, and the outer loop (i) moves 
   you to an entirely new 2D matrix layer.

================================================================================
*/

#include <stdio.h>

int main()
{
   int a[2][2][3] = {
       {{1, 2, 3}, {4, 5, 6}},
       {{7, 8, 9}, {10, 11, 12}}
   };

   for (int i = 0; i < 2; i++) {           // Loop through blocks
       for (int j = 0; j < 2; j++) {       // Loop through rows
           for (int k = 0; k < 3; k++) {   // Loop through columns
               printf("%d ", a[i][j][k]);
           }
       }
   }

   return 0;
}