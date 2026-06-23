/*
================================================================================
                    C PROGRAMMING NOTES: POINTER ARITHMETIC
                    (Increment and Decrement Operators)
================================================================================

Pointer arithmetic allows you to navigate through an array by modifying the 
memory address stored in a pointer variable. Because array elements are stored 
in contiguous (side-by-side) memory locations, incrementing or decrementing a 
pointer moves it to the next or previous element.

CRITICAL CONCEPT: Pointer Scale Factor
When you increment a pointer (p++) or decrement a pointer (p--), the address 
does NOT simply change by 1 byte. Instead, it changes by:
    
    1 * sizeof(pointer_data_type)

For an integer pointer (int *p) on most modern systems, sizeof(int) is 4 bytes.
- p++ increases the memory address by 4 bytes (moves to the next integer).
- p-- decreases the memory address by 4 bytes (moves to the previous integer).

--------------------------------------------------------------------------------
1. POST-INCREMENT OPERATOR (*(p++))
--------------------------------------------------------------------------------
The post-increment operator evaluates the current expression using the original 
pointer address first, and THEN increments the pointer address.

Example Code Behavior:
    int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
    int *p = &a[0]; // Assume base address of a[0] is 1000

    printf("%d ", *(p++)); 
    // Step 1: Evaluates *(p) -> Value at 1000 is printed: 5
    // Step 2: Increments p -> p now points to 1004 (&a[1])

    printf("%d", *p);      
    // Step 3: Evaluates *p -> Value at 1004 is printed: 16

Output: 
    5 16

--------------------------------------------------------------------------------
2. PRE-INCREMENT OPERATOR (*(++p))
--------------------------------------------------------------------------------
The pre-increment operator increments the pointer address FIRST, and THEN 
evalives the expression using the new address.

Example Code Behavior:
    int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
    int *p = &a[0]; // Assume base address of a[0] is 1000

    printf("%d", *(++p));
    // Step 1: Increments p -> p now points to 1004 (&a[1])
    // Step 2: Evaluates *(p) -> Value at 1004 is printed: 16

Output: 
    16

--------------------------------------------------------------------------------
3. PRE AND POST-DECREMENT OPERATORS
--------------------------------------------------------------------------------
Decrement operators work exactly like increment operators, but they move the 
pointer backward to lower memory addresses.

Example Code Behavior:
    int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
    int *p = &a[2]; // p points to a[2] (value 7, assume address 1008)

    printf("%d ", *(--p));
    // Pre-decrement execution:
    // Step 1: Decrements p -> p moves from 1008 to 1004 (&a[1])
    // Step 2: Evaluates *(p) -> Value at 1004 is printed: 16

    printf("%d", *(p--));
    // Post-decrement execution:
    // Step 1: Evaluates *(p) -> Value at 1004 is printed: 16
    // Step 2: Decrements p -> p moves from 1004 to 1000 (&a[0])

Output: 
    16 16

--------------------------------------------------------------------------------
SUMMARY QUICK-REFERENCE TABLE
--------------------------------------------------------------------------------
Expression  | Operation Order                         | Effect on Pointer
------------|-----------------------------------------|-------------------------
*(p++)      | 1. Dereference current address          | Moves to NEXT element
            | 2. Increment pointer address            | AFTER value is used
------------|-----------------------------------------|-------------------------
*(++p)      | 1. Increment pointer address            | Moves to NEXT element
            | 2. Dereference new address              | BEFORE value is used
------------|-----------------------------------------|-------------------------
*(--p)      | 1. Decrement pointer address            | Moves to PREV element
            | 2. Dereference new address              | BEFORE value is used
------------|-----------------------------------------|-------------------------
*(p--)      | 1. Dereference current address          | Moves to PREV element
            | 2. Decrement pointer address            | AFTER value is used
================================================================================
*/

#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    int *p = &a[3], *q = &a[3], *r = &a[3], *s = &a[3];

    printf("*p = *q = *r = *s : %d\n", *p);
    printf("*(p++) : %d\n", *(p++));    // Post-increment   : 4
    printf("*(++q) : %d\n", *(++q));    // Pre-increment    : 5
    printf("*(r--): %d\n", *(r--));     // Post-decrement   : 4
    printf("*(--s) : %d\n", *(--s));    // Pre-decrement    : 3

    printf("\n");

    printf("*p : %d\n", *p);
    printf("*q : %d\n", *q);
    printf("*r : %d\n", *r);
    printf("*s : %d\n", *s);
}