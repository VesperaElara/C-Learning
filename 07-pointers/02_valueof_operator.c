/*
================================================================================
                    C PROGRAMMING STUDY NOTES: DEREFERENCING
================================================================================

1. THE VALUE-OF / DEREFERENCE OPERATOR (*)
--------------------------------------------------------------------------------
The asterisk (*), when used outside of a declaration, is known as the 
"Value-of," "Indirection," or "Dereference" operator. It is used to 
access or manipulate the value stored at the memory location currently held 
by a pointer.

Essentially, it tells the computer to "go to the address stored in the pointer 
and take what is inside that object".

Code Example:
    int x = 5;      // x is at address 1000
    int *ptr = &x;  // ptr holds 1000
    printf("%d", *ptr); 

The output will be 5 because *ptr goes to address 1000 and retrieves the value 
stored there.


2. MODIFYING DATA THROUGH POINTERS
--------------------------------------------------------------------------------
Pointers can be used to change the value of the object they point to by using 
the dereference operator on the left side of an assignment.

Example:
    int x = 10;     // Initial value of x is 10
    int *ptr = &x;  // ptr points to x
    *ptr = 4;       // Change the value at the address held by ptr to 4
    printf("%d", x);

The output is now 4 because the memory location of 'x' was updated directly 
via the pointer.


3. CRITICAL CAUTION: UNINITIALIZED POINTERS
--------------------------------------------------------------------------------
You must NEVER apply the dereference/indirection operator to an uninitialized 
pointer.

* Undefined Behavior: Attempting to read from an uninitialized pointer (e.g., 
  printing *ptr when ptr has no assigned address) leads to "Undefined 
  Behaviour". The program might crash or output garbage data.

* Segmentation Faults: Assigning a value to an uninitialized pointer is 
  extremely dangerous.
  Example:
    int *ptr;
    *ptr = 1; // DANGEROUS

* Illegal Memory Access: This often results in a "Segmentation Fault (SIGSEGV)" 
  because the program is trying to read or write to an illegal memory location 
  that it does not own.

Always ensure a pointer is assigned a valid memory address before you attempt 
to use the (*) operator to read or write data.
================================================================================
*/

#include <stdio.h>

int main()
{
    int x = 10;     // Initial value of x is 10
    int *ptr = &x;  // ptr points to x
    *ptr = 4;       // Change the value at the address held by ptr to 4
    printf("%d\n", x);
}