/*
================================================================================
TWO-DIMENSIONAL (2D) ARRAYS IN C
================================================================================

1. DEFINITION
   A 2D array is a collection of elements organized in rows and columns. It 
   can be visualized as a matrix or a table.

2. SYNTAX
   The general syntax for declaration is:

   data_type name_of_array[rows][columns];

   Example:
   int arr[4][5]; // Creates a grid with 4 rows and 5 columns.

3. MEMORY SIZE CALCULATION
   The total memory required for a 2D array is determined by the total number 
   of elements multiplied by the size of the data type (in bytes).

   Formula: Total Bytes = (rows * columns) * sizeof(data_type)

   Example for int arr[4][5]:
   - Total elements: 4 * 5 = 20
   - Assuming int is 4 bytes:
   - Total memory: 20 * 4 = 80 bytes

4. INITIALIZATION METHODS
   You can initialize a 2D array using two primary methods:

   Method 1: Linear Initialization
   int a[2][3] = {1, 2, 3, 4, 5, 6};
   // Fills the matrix row by row:
   // Row 0: 1, 2, 3
   // Row 1: 4, 5, 6

   Method 2: Row-wise Initialization (Recommended for readability)
   int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
   // Explicitly groups elements into separate rows using nested braces.

5. ACCESSING ELEMENTS
   Elements are accessed using row and column indices, both of which start 
   at 0.

   Syntax: array_name[row_index][column_index]

   Example:
   Given a 2x3 matrix 'a':
   Row 0: [1, 2, 3]
   Row 1: [4, 5, 6]

   To access the element in the 1st row (index 0) and 2nd column (index 1):
   a[0][1] // This will return the value 2.
================================================================================
*/