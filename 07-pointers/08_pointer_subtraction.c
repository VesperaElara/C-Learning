/*
================================================================================
               C PROGRAMMING TOPIC: POINTER SUBTRACTION & DISTANCE
================================================================================

Pointer arithmetic also supports subtraction. There are two primary use cases for 
subtracting in pointer arithmetic:
1. Subtracting an integer from a pointer (Moving backward).
2. Subtracting one pointer from another pointer (Finding the distance).

--------------------------------------------------------------------------------
1. SUBTRACTING AN INTEGER FROM A POINTER
--------------------------------------------------------------------------------
Subtracting an integer from a pointer shifts the pointer backward by a specific 
number of element positions.

General Rule:
    Initially, if p points to a[i], then:
    p = p - j  ===>  p now points to &a[i - j]

Behind the scenes (Physical View):
The compiler automatically scales the integer by the size of the data type.
    New Address = Current Address - (Integer * Size of Data Type)

Example:
Assume an integer array (4 bytes per element) with a base address of 1000.
If 'p' initially points to index 3 (&a[3]), its memory address value is 1012.

Executing:
    p = p - 3;

Calculation:
    p = 1012 - (3 * 4)
    p = 1012 - 12
    p = 1000  (This is the address of &a[0])

--------------------------------------------------------------------------------
2. SUBTRACTING ONE POINTER FROM ANOTHER
--------------------------------------------------------------------------------
When you subtract two pointers pointing to elements of the same array, the 
result is NOT the raw number of bytes between them. Instead, the result is the 
**distance measured in the number of elements** between those two pointers.

Conceptual Rule:
    If q points to a[6] and p points to a[2], then:
    q - p = 6 - 2 = 4 elements

Physical View (How the compiler computes it):
To get the actual element count, the compiler subtracts the memory addresses 
and then divides the result by the size of the underlying data type.

Formula:
    Result = (Address of q - Address of p) / Size of Data Type

Example Breakdown (4-byte Integers):
Using an array starting at base address 1000:
* Pointer 'p' points to a[2] ===> Address = 1008
* Pointer 'q' points to a[6] ===> Address = 1024

Step 1: Subtract raw addresses:
    1024 - 1008 = 16 bytes

Step 2: Divide by the size of the data type (sizeof(int) = 4):
    16 / 4 = 4 elements

Therefore:
    q - p = 4

--------------------------------------------------------------------------------
3. KEY TAKEAWAYS FOR BEGINNERS
--------------------------------------------------------------------------------
* Pointer - Integer = A new pointer (address shifted backward).
* Pointer - Pointer = An integer (the number of elements separating them).
* You can only subtract two pointers if they point to elements of the same array. 
  Subtracting unrelated pointers results in undefined behavior.
================================================================================
*/

#include <stdio.h>

int main()
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int *p = &a[1];
    int *q = &a[6];
    printf("q - p = %d\n", q-p);
}

/*
--------------------------------------------------------------------------------
4. CRITICAL RULES: UNDEFINED BEHAVIORS
--------------------------------------------------------------------------------
Pointer arithmetic is dangerous if rules are violated. The C language standard 
declares the following scenarios as Undefined Behavior (unpredictable results):

Scenario A: Arithmetic on pointers not targeting an array
----------------------------------------------------------
You cannot perform offset arithmetic on a pointer that references a single, 
standalone variable.
    int i = 10;
    int *p = &i;
    printf("%d", *(p + 3)); // UNDEFINED BEHAVIOR: Accessing illegal memory

Scenario B: Subtracting pointers from different arrays
----------------------------------------------------------
You cannot subtract two pointers unless they point to elements within the 
exact same array structure.
    int a[] = {1, 2, 3, 4};
    int b[] = {10, 20, 30, 40};
    int *p = &a[0];
    int *q = &b[3];
    int diff = q - p;       // UNDEFINED BEHAVIOR: Output varies by environment

--------------------------------------------------------------------------------
5. SUMMARY FOR BEGINNERS
--------------------------------------------------------------------------------
* Pointer + Integer = Moves forward to another element address.
* Pointer - Integer = Moves backward to another element address.
* Pointer - Pointer = Total number of array slots separating the two pointers.
* Array Safety: Never push a pointer past the legal boundaries of its array.
================================================================================
*/