/*
================================================================================
TOPIC: DESIGNATED INITIALIZATION OF 1D ARRAYS IN C
================================================================================

1. WHAT IS DESIGNATED INITIALIZATION?
-------------------------------------
Designated initialization allows you to assign values to specific array indices 
directly during initialization, rather than filling the array in a fixed, 
sequential order.

Syntax:
    int arr[size] = {[index1] = value1, [index2] = value2, ...};

Example:
    int arr[10] = {[0] = 1, [5] = 2, [6] = 3};
    // This assigns 1 to arr[0], 2 to arr[5], and 3 to arr[6]. 
    // Unassigned locations are automatically initialized to 0.

2. KEY ADVANTAGES
-----------------
* Skipping Zeros: You do not need to explicitly list zeros for array elements 
  you do not want to set.
* Order Independence: You can specify indices in any order. The compiler 
  correctly places the values in the requested positions.

    // Example of order independence:
    int a[15] = {[5] = 2, [0] = 1}; // Same as {[0] = 1, [5] = 2}

3. AUTOMATIC LENGTH DEDUCTION
-----------------------------
If you omit the array size (leaving it blank), the compiler will automatically 
calculate the length based on the highest index (designator) provided.

    int a[] = {[5] = 90, [20] = 4, [49] = 78};
    // The compiler deduces a length of 50 (indices 0 through 49).

4. MIXING SEQUENTIAL AND DESIGNATED INITIALIZATION
--------------------------------------------------
You can mix standard and designated initialization. 

    int a[] = {1, 7, 5, [5] = 90, 6, [8] = 4};
    // 1, 7, 5 occupy indices 0, 1, 2.
    // [5] = 90 forces the value at index 5.
    // Index 3 and 4 are automatically set to 0.
    // 6 follows index 5 at index 6.

5. HANDLING CLASHES
-------------------
If you assign a value to an index that was already initialized, the designated 
initializer value will overwrite the previous one.

    int a[] = {1, 2, 3, [2] = 4}; 
    // Initially, index 2 is 3, but the designated initializer [2] = 4 
    // overwrites it. The final value at index 2 is 4.

6. IMPORTANT WARNINGS
---------------------
* Index Bounds: If the array length is 'n', every designator must be 
  between 0 and n-1. Using a designator equal to or greater than the 
  length will result in an error.
================================================================================
*/