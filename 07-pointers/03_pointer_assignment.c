/*
================================================================================
                    C PROGRAMMING STUDY NOTES: POINTERS
================================================================================

TOPIC: Pointer Assignment vs. Value Assignment (Dereferencing)

Understanding how pointer variables interact with each other is crucial. There 
is a major difference between copying a memory address from one pointer to 
another, and copying the actual data being pointed to.

--------------------------------------------------------------------------------
1. Pointer Assignment (q = p)
--------------------------------------------------------------------------------
When you assign one pointer directly to another (e.g., q = p), you are copying 
the memory address stored in 'p' into 'q'. 

* Result: Both pointers now point to the exact same memory location.

Example breakdown:
    int i = 10;
    int *p, *q;
    p = &i;     // 'p' stores the address of 'i' (e.g., 1000)
    q = p;      // 'q' now also stores the address of 'i' (1000)

Visual Memory Layout:
    +---------+          +---------+
    | p: 1000 | -----\   |  i: 10  |
    +---------+       +->+---------+
    | q: 1000 | -----/   Address: 1000
    +---------+

If you execute: printf("%d %d", *p, *q);
The output will be: 10 10

--------------------------------------------------------------------------------
2. Value Assignment via Dereferencing (*q = *p)
--------------------------------------------------------------------------------
When you use the dereference operator (*) on both sides (e.g., *q = *p), you 
are dealing with the values stored at those addresses, not changing where the 
pointers look.

* Result: The value at the memory address pointed to by 'q' is overwritten 
          by the value at the memory address pointed to by 'p'. The pointers 
          themselves still point to their original, distinct addresses.

Example breakdown:
    int i = 10, j = 20;
    int *p, *q;
    p = &i;     // 'p' points to 'i' (Address: 1000)
    q = &j;     // 'q' points to 'j' (Address: 2000)
    *q = *p;    // Value at 'q' (j) becomes the value at 'p' (i)

Visual Memory Layout:
    +---------+          +---------+
    | p: 1000 | -------->|  i: 10  | Address: 1000
    +---------+          +---------+
    | q: 2000 | -------->|  j: 10  | Address: 2000 (Value updated from 20 to 10)
    +---------+          +---------+

Key Takeaway: 
* q = p   -> Changes the pointer's target (Both point to the same variable).
* *q = *p -> Changes the value of the target (Pointers still point to different variables).

--------------------------------------------------------------------------------
3. Practical Application: Homework Problem Walkthrough
--------------------------------------------------------------------------------

Consider the following program sequence:

    int i = 1;      // An integer 'i' is initialized to 1.
    int *p = &i, *q;    // Pointer 'p' is initialized to point to 'i'.
    q = p;          // Pointer 'q' is assigned the address in 'p'. 
                    // Now, both 'p' and 'q' point to 'i'.
    *q = 5;         // The value at the address pointed to by 'q' 
                    // (which is 'i') is changed to 5.
    printf("%d", *p);

Analysis & Execution Flow:
1. 'i' starts with the value 1.
2. 'p' tracks 'i'.
3. 'q' tracks 'i' (via 'p').
4. *q = 5 modifies 'i' directly. Therefore, 'i' becomes 5.
5. Printing *p accesses the current value of 'i'.

Final Program Output:
5
================================================================================
*/

#include <stdio.h>

int main()
{
    int i = 1;          // An integer 'i' is initialized to 1.
    int *p = &i, *q;    // Pointer 'p' is initialized to point to 'i'.
    q = p;              // Pointer 'q' is assigned the address in 'p'. 
                        // Now, both 'p' and 'q' point to 'i'.
    *q = 5;             // The value at the address pointed to by 'q' 
                        // (which is 'i') is changed to 5.
    printf("%d", *p);
}