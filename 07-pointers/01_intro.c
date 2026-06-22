/*
================================================================================
                    C PROGRAMMING STUDY NOTES: POINTERS
================================================================================

1. WHAT IS A POINTER?
--------------------------------------------------------------------------------
A pointer is a special variable in C that is capable of storing the memory 
address of another variable, rather than storing a direct value (like an 
integer or character). 

* Memory Structure: Every variable created in a program is allocated a specific
  location in the computer's memory. This location has a unique address.
* First Byte Rule: When a variable occupies multiple bytes of memory, the 
  pointer points directly to the memory location where the very first byte 
  is stored.

Conceptual Visualization:
+-----------+               +-----------+
|  Pointer  | ------------> | Variable  |
|    (p)    |               |    (i)    |
+-----------+               +-----------+
[Holds Address: 1002]       [Address: 1002]


2. SYNTAX FOR DECLARING POINTER VARIABLES
--------------------------------------------------------------------------------
To declare a pointer, specify the type of data it will point to, followed by 
the asterisk (*) operator and the pointer's name.

Syntax:
data_type *pointer_name;

Crucial Rule: The "data_type" refers to the type of the VALUE that the pointer 
will point to, not the type of the pointer itself.

Examples:
* int *ptr;    -> Points to an integer value
* char *ptr;   -> Points to a character value
* float *ptr;  -> Points to a float value


3. NEED FOR THE ADDRESS-OF OPERATOR (&) & INITIALIZATION
--------------------------------------------------------------------------------
Simply declaring a pointer is not enough. Before using a pointer, it must be 
initialized. Using an uninitialized pointer can lead to unpredictable program 
behavior or crashes.

* Initialization: One common way to initialize a pointer is to assign it the 
  address of an existing variable.
* Address-of Operator (&): The ampersand symbol (&) is used to retrieve the 
  exact memory address of a variable.

Detailed Allocation Example:
If we have a variable 'x' stored at memory address 1000 with a value of 5, 
and a pointer 'ptr' stored at memory address 2000:

Code Statement:  ptr = &x;

Memory State:
Variable (x)                Pointer (ptr)
+---------------+           +---------------+
|       5       | <-------- |     1000      |
+---------------+           +---------------+
Address: 1000               Address: 2000


4. DECLARATION AND INITIALIZATION METHODS
--------------------------------------------------------------------------------
You can declare and initialize a pointer using two equivalent code styles:

Method A: Multi-line (Declaration followed by Initialization)
    int x = 5;
    int *ptr;
    ptr = &x;

Method B: Single-line (Combined Declaration and Initialization)
    int x = 5, *ptr = &x;

Method C: Single-line Declaration and Initialization
    int x = 5;
    int *ptr = &x;

Both methods achieve identical results in memory: 'ptr' successfully holds 
the memory address of 'x'.
================================================================================
*/

#include <stdio.h>
int main()
{
  int x = 5;
  int *p = &x;
  printf("Address of x = %p\nValue stored in x = %d\n", p, *p);
}