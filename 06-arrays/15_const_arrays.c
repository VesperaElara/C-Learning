/*
================================================================================
CORE CONCEPT: CONSTANT ARRAYS IN C
================================================================================

In C programming, you can make an array "read-only" (constant) by using the 
'const' keyword during its declaration. Once an array is declared as const, 
its elements cannot be modified or reassigned throughout the program's 
execution.

--------------------------------------------------------------------------------
SYNTAX
--------------------------------------------------------------------------------
const data_type array_name[size] = {initial_values};

Example:
    const int numbers[5] = {10, 20, 30, 40, 50};

--------------------------------------------------------------------------------
BEHAVIOR & ERROR HANDLING
--------------------------------------------------------------------------------
If you attempt to modify any element of a constant array, the compiler will 
generate an error, preventing the operation.

Example of invalid operation:
    const int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a[1] = 45; // COMPILER ERROR: Assignment of read-only location

--------------------------------------------------------------------------------
ADVANTAGES
--------------------------------------------------------------------------------
1. Data Integrity:
   It guarantees that the program will not accidentally change data stored 
   in the array. This is critical when the array holds important reference 
   information or constant lookup tables.

2. Enhanced Compiler Safety:
   It communicates your intent to the compiler. By marking an array as const, 
   you enable the compiler to perform additional checks and optimization, 
   helping you catch bugs early if the program attempts to violate the 
   read-only constraint.

--------------------------------------------------------------------------------
APPLICABILITY
--------------------------------------------------------------------------------
This technique applies to both one-dimensional and multi-dimensional arrays, 
ensuring that constant data structures remain protected regardless of their 
dimensions.
================================================================================
*/