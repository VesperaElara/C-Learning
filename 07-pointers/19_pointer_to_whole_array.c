/*
================================================================================
                    C PROGRAMMING: POINTER TO AN ARRAY
================================================================================

--------------------------------------------------------------------------------
1. Introduction: Pointer to the First Element vs. Pointer to the Whole Array
--------------------------------------------------------------------------------
When working with arrays in C, it is crucial to understand the difference 
between pointing to the first element of an array and pointing to the entire 
array structure itself.

Consider the following array declaration:
int a[5] = {1, 2, 3, 4, 5};

Case A: Pointer to the First Element
- Syntax: int *p = a;
- Explanation: The array name 'a' decays into a pointer to its first element. 
  Therefore, 'p' holds the address of a[0].
- Dereferencing: *p yields the value of the first element, which is 1.

Case B: Pointer to the Whole Array
- Syntax: int (*p)[5] = &a;
- Explanation: Here, 'p' is not pointing to an individual integer. Instead, 
  it is a pointer to an entire array of 5 integers. The address-of operator '&' 
  is used to get the address of the whole array block.

--------------------------------------------------------------------------------
2. Syntax breakdown: int (*p)[5]
--------------------------------------------------------------------------------
The parentheses around (*p) are mandatory due to operator precedence rules in C.

- Parentheses matter:
  int (*p)[5];  --> 'p' is a pointer to an array of 5 integers.
  int *p[5];    --> 'p' is an array of 5 pointers to integers (Array of Pointers).

By enclosing *p in parentheses, we force the compiler to treat 'p' as a pointer 
variable first, which then points to a data type of 'int[5]'.

--------------------------------------------------------------------------------
3. Memory Representation and Address Evaluation
--------------------------------------------------------------------------------
Assume the array 'a' starts at memory address 1000, and an integer occupies 4 bytes.

+---------------+-------+-------+-------+-------+-------+
| Element Index |  [0]  |  [1]  |  [2]  |  [3]  |  [4]  |
+---------------+-------+-------+-------+-------+-------+
| Element Value |   1   |   2   |   3   |   4   |   5   |
+---------------+-------+-------+-------+-------+-------+
| Address       | 1000  | 1004  | 1008  | 1012  | 1016  |
+---------------+-------+-------+-------+-------+-------+

- The value of 'a' (pointer to first element) is 1000.
- The value of '&a' (pointer to the whole array) is also 1000.

Even though 'a' and '&a' evaluate to the same memory address value (1000), 
their types and pointer arithmetic behaviors are completely different:
- (a + 1) increments by sizeof(int), pointing to address 1004.
- (&a + 1) increments by sizeof(int[5]), pointing to address 1020 (skipping 
  the entire array).

--------------------------------------------------------------------------------
4. Accessing Values (Double Dereferencing)
--------------------------------------------------------------------------------
When you have a pointer to an array:
int (*p)[5] = &a;

To print the actual values inside the array using 'p', you must dereference it 
twice:

- First Dereference (*p):
  Since 'p' points to the entire array 'a', dereferencing it once gives the 
  array name itself (*p is equivalent to 'a'). In expressions, this decays 
  again into the address of the first element (1000).

- Second Dereference (**p):
  Dereferencing a second time gets the value stored at that base address 
  (**p is equivalent to *a, which is a[0]).

Example Snippet:
printf("%d", **p); 
Output: 1

--------------------------------------------------------------------------------
5. Relationship with Multidimensional Arrays
--------------------------------------------------------------------------------
This concept forms the foundation of how 2D arrays are handled in C. 
A 2D array is essentially an array of 1D arrays.

If you have a 2D array 'b':
- '*b' represents a pointer to the 1st element of the 1st 1D array.
- '&*b' is equivalent to 'b', which represents a pointer to the 1st 1D array itself.
================================================================================
*/

#include <stdio.h>

int main()
{
  int a[5] = {1,2,3,4,5};
  int (*p)[5] = &a;
  printf("*p = %p\n", *p);
  printf("**p =  %d\n", **p);
  printf("*p + 1 =  %p\n", *p + 1);
  printf("*(*p + 1) =  %d\n", *(*p + 1));
  printf("*p + 4 =  %p\n", *p + 4);
  printf("*(*p + 4) =  %d\n", *(*p + 4));
  // printf("*p + 5 =  %p\n", *p + 5);
  // printf("*(*p + 5) =  %d\n", *(*p + 5));
  // The lines above attempt to read past the array bounds. 
  // C doesn't stop this, resulting in garbage data or potential crashes.
}