/*
================================================================================
                    C PROGRAMMING TOPIC: POINTER ARITHMETIC
================================================================================

When you add an integer to a pointer, you are not simply adding that number to 
the memory address. Instead, you are moving the pointer forward in memory by a 
specific number of element positions.

--------------------------------------------------------------------------------
1. CONCEPTUAL VIEW (WHAT IT MEANS)
--------------------------------------------------------------------------------
Think of an array as a row of numbered slots. If a pointer 'p' points to the 
beginning of an array 'a' (index 0), adding an integer 'j' shifts the pointer 
forward by 'j' positions.

Initial assignment:
    p = &a[0];  // p points to the very first element

Adding an integer:
    p = p + 3;  // Moves the pointer 3 positions forward (points to a[3])

General Rule:
    Initially, if p points to a[i], then:
    p = p + j  ===>  p now points to &a[i + j]

--------------------------------------------------------------------------------
2. PHYSICAL VIEW (WHAT ACTUALLY HAPPENS IN MEMORY)
--------------------------------------------------------------------------------
Behind the scenes, memory is byte-addressed. When you perform pointer arithmetic, 
the compiler automatically scales the integer by the data type's size (in bytes).

Formula:
    New Address = Current Address + (Integer * Size of Data Type)

Example Breakdown (Using a 4-byte Integer Array):
Suppose we have an integer array 'a' where each element occupies 4 bytes, 
starting at base memory address 1000.

Element Index:     [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
Memory Address:   1000    1004    1008    1012    1016    1020    1024    1028
                    ^
                    |
               p = &a[0] (p contains address 1000)

If we execute:
    p = p + 1;

The pointer moves 1 position forward. The actual address calculation is:
    p = 1000 + (1 * 4) 
    p = 1004

Now, 'p' contains the memory address 1004, which correctly points to a[1].

--------------------------------------------------------------------------------
3. KEY TAKEAWAYS FOR BEGINNERS
--------------------------------------------------------------------------------
* Pointer arithmetic is type-aware. The compiler automatically figures out how 
  many bytes to skip based on the pointer's data type (e.g., 1 byte for char, 
  4 bytes for int).
* Adding 1 to a pointer means "go to the next element," NOT "add 1 byte to the 
  address."
================================================================================
*/

#include <stdio.h>

int main()
{
    int a[3] = {1,2,3};
    int *p;
    p = &a[0];
    printf("Initial address: %p\n", p);
    // incorrect syntax: this prints the exact "address" stored,
    // NOT the value present in that address.
    printf("Initial value: %d\n", *p);
    p = p + 2;
    printf("Final address: %p\n", p); 
    printf("Final value: %d\n", *p);
}