/*
================================================================================
MULTIDIMENSIONAL ARRAYS IN C
================================================================================

1. DEFINITION
   A multidimensional array is essentially an "array of arrays." It allows
   you to organize data in a grid-like structure (e.g., a table) or higher
   dimensional data (e.g., a cube or a data volume).

2. SYNTAX
   To declare an N-dimensional array, use the following format:

   data_type name_of_array[size1][size2]...[sizeN];

   EXAMPLES:
   - Two-Dimensional Array: int a[3][4];
     (Think of this as a grid with 3 rows and 4 columns)

   - Three-Dimensional Array: int a[3][4][6];
     (Think of this as a collection of 3 matrices, each with 4 rows and 6 columns)

3. SIZE CALCULATION
   The memory footprint of a multidimensional array is determined by the
   total number of elements multiplied by the size of the data type used.

   FORMULA:
   Total Size = (Product of all dimension sizes) * (Size of one element in bytes)

   EXAMPLES:

   A) Two-Dimensional Array: int a[10][20]
      - Total Elements = 10 * 20 = 200
      - Assuming an integer takes 4 bytes:
      - Total Size = 200 * 4 = 800 bytes

   B) Three-Dimensional Array: int a[4][10][20]
      - Total Elements = 4 * 10 * 20 = 800
      - Assuming an integer takes 4 bytes:
      - Total Size = 800 * 4 = 3200 bytes

4. KEY TAKEAWAY
   Multidimensional arrays are powerful tools for handling structured,
   multi-indexed data. Always remember that the total capacity of the array
   is the product of its indices, and the actual memory consumed is that
   count multiplied by the byte-size of the underlying data type.
================================================================================
*/