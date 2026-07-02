#include <stdio.h>

int add(int a, int b) 
{
    return a + b;
}

int main(void) 
{
    int result1;
    int result2;

    /* Method 1: Explicit syntax using address-of and dereference operators */
    int (*ptr1)(int, int) = &add;
    result1 = (*ptr1)(10, 20);
    printf("Result 1: %d\n", result1);

    /* Method 2: Implicit shorthand notation allowed by C standard */
    int (*ptr2)(int, int) = add;
    result2 = ptr2(10, 20);
    printf("Result 2: %d\n", result2);

    return 0;
}

/*
================================================================================
UNDERSTANDING FUNCTION POINTERS IN C
================================================================================

A function pointer is a specialized pointer variable that stores the starting 
address of executable code (a function) in the text segment of memory, rather 
than storing the address of data values on the stack or heap.

---
1. THE PRECEDENCE PITFALL: ARRAY OF POINTERS VS. POINTER TO AN ARRAY
---
When learning pointers, understanding operator precedence is crucial. The array 
subscript operator [] has higher precedence than the dereference operator *.

* Correct Declaration of an Array of Pointers:
  int *ptr[10];
  Because [] binds tighter than *, this creates an array of 10 pointers to 
  integers.

* Correct Declaration of a Pointer to an Array:
  int (*ptr)[10];
  Parentheses override default precedence, forcing the * to bind to the 
  identifier first. This creates a single pointer that references an entire 
  array of 10 integers.

---
2. DECLARING A FUNCTION POINTER
---
The exact same precedence logic applies when declaring function pointers. 
To declare a function pointer, match the signature (return type and parameter 
types) of the target function exactly, using parentheses to wrap the pointer.

Syntax Pattern:
return_type (*pointer_name)(parameter_type_1, parameter_type_2);

Example Breakdown:
For a function declared as: int add(int a, int b);
The matching function pointer is declared as: int (*ptr)(int, int);

Without the parentheses around *ptr, the compiler interprets the statement 
as a function prototype returning an integer pointer (int *), which is an 
entirely different type.

---
3. ASSIGNING AND CALLING VIA FUNCTION POINTERS
---
C provides two acceptable syntax styles for working with function pointers, 
both of which produce identical machine instructions:

* The Explicit Approach:
  int (*ptr)(int, int) = &add; // Assigning address explicitly
  int result = (*ptr)(10, 20); // Invoking function explicitly

* The Implicit Shorthand Approach:
  int (*ptr)(int, int) = add;  // Automatically decays to address
  int result = ptr(10, 20);    // Direct invocation syntax

The C language allows the implicit shorthand because a function identifier 
naturally evaluates to its memory address when used without parentheses, 
similarly to how array names decay into base pointers.

---
4. REAL-WORLD UTILITY
---
Function pointers form the foundation of advanced runtime patterns in systems 
programming, including:
- Callback Mechanisms: Passing a function as an argument to another routine.
- Dynamic Event Dispatch: Implementing state machines and event loops.
- Object-Oriented C: Building virtual method tables (v-tables) for structs.
*/