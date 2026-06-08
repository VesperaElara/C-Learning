/*
================================================================================
TRAVERSING AND PRINTING 2D ARRAYS
================================================================================

1. CONCEPT
   To print or process all elements in a 2D array, you must iterate through 
   every row and every column. This is achieved using nested loops, where the 
   outer loop tracks the row index and the inner loop tracks the column index.

2. LOGIC
   - Outer Loop: Iterates through each row index (from 0 to total_rows - 1).
   - Inner Loop: Iterates through each column index for the current row 
     (from 0 to total_columns - 1).

3. IMPLEMENTATION
   Given a 2D array: int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

   // Logic using nested for loops
   for (int i = 0; i < 2; i++) {       // i tracks rows
       for (int j = 0; j < 3; j++) {   // j tracks columns
           printf("%d ", a[i][j]);     // Access and print element
       }
   }

4. STEP-BY-STEP EXECUTION
   The nested loops process the elements in the following order:

   Row 0:
   - i=0, j=0 -> accesses a[0][0] (Value: 1)
   - i=0, j=1 -> accesses a[0][1] (Value: 2)
   - i=0, j=2 -> accesses a[0][2] (Value: 3)

   Row 1:
   - i=1, j=0 -> accesses a[1][0] (Value: 4)
   - i=1, j=1 -> accesses a[1][1] (Value: 5)
   - i=1, j=2 -> accesses a[1][2] (Value: 6)

   Resulting Output: 1 2 3 4 5 6

================================================================================
*/

#include <stdio.h>

int main()
{
   int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

   // Logic using nested for loops
   for (int i = 0; i < 2; i++) {       // i tracks rows
       for (int j = 0; j < 3; j++) {   // j tracks columns
           printf("%d ", a[i][j]);     // Access and print element
       }
   }
}