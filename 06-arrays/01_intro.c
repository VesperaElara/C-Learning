/*
================================================================================
                      C PROGRAMMING LECTURE NOTES: ARRAYS                      
================================================================================

1. WHAT IS A DATA STRUCTURE?
--------------------------------------------------------------------------------
A Data Structure is a systematic format used for organizing and storing data in 
a computer's memory. Each specific data structure is engineered to handle data 
in a way that suits a particular programming requirement or purpose efficiently.

2. DEFINITION OF AN ARRAY
--------------------------------------------------------------------------------
An Array is a fundamental data structure capable of containing a fixed number of 
data values, where every single value MUST be of the exact same data type.

Conceptual Memory Model:
Imagine an array as one single, continuous chunk of computer memory that has 
been divided into smaller, equal-sized blocks. Each smaller block functions as 
a storage slot capable of holding an individual data value.

+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |  <- Continuous Memory Blocks
+---+---+---+---+---+---+---+---+---+---+

3. CORE CHARACTERISTICS OF ARRAYS
--------------------------------------------------------------------------------
* Fixed Capacity: 
  An array can be constructed to hold any specific quantity of data items based 
  on your program's needs (for example, a large array holding 10 values, or a 
  smaller array holding 5 values).

* Homogeneous Elements (Same Data Type):
  All elements inside an array must share an identical data type. You cannot mix 
  and match different types of data within a single array.

  Valid Data Examples:
  - An array consisting entirely of integers (e.g., 5, 10, 13, 56)
  - An array consisting entirely of characters (e.g., 'a', 'b', 'c', 'd')

  Invalid Data Example:
  - Mixing characters, integers, and floating-point decimals together inside 
    the same array (e.g., 'a', 1, 5.6, 'e') will result in a compilation error.

4. ONE-DIMENSIONAL (1D) ARRAYS
--------------------------------------------------------------------------------
The simplest structural form an array can take is a One-Dimensional Array. It 
represents a straightforward, linear sequence of elements arranged side-by-side 
in memory.

Visualizing a 1D Array named 'a' containing 10 integer values:

Array 'a':
+---+---+----+----+----+----+---+---+---+---+
| 5 | 6 | 10 | 13 | 56 | 76 | 1 | 2 | 4 | 8 |
+---+---+----+----+----+----+---+---+---+---+

================================================================================
*/