/*
--------------------------------------------------------------------------------
THE QUESTION TO SOLVE:
--------------------------------------------------------------------------------
What is printed by the following C program:
*/

#include <stdio.h>

int f(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}

void main()
{
    int c, *b, **a; // a is a pointer to a pointer to an integer
    c = 4, b = &c, a = &b;
    printf( "%d\n", f(c,b,a));
}

/*
Options:
a) 18
b) 19
c) 21
d) 22
*/

/*
================================================================================
                    C PROGRAMMING NOTES: POINTERS AND DEFERENCING               
================================================================================

This note walks through a classic gate question analyzing how values change 
when passed by value versus passed by reference (using pointers and double 
pointers) in C.

--------------------------------------------------------------------------------
1. CODE BREAKDOWN & INITIAL STATE
--------------------------------------------------------------------------------

In the main() function, we initialize three variables:
* c: An integer initialized to 4.
* b: A pointer to an integer (int *), initialized to the address of c (&c).
* a: A double pointer (int **), initialized to the address of b (&b).

Visually, the relationships look like this:
[a] ---> [b] ---> [c = 4]

The function call is: f(c, b, a)
* Argument 1 (x): Receives a copy of the value of c. This is pass-by-value.
* Argument 2 (py): Receives the address stored in b (which points to c).
* Argument 3 (ppz): Receives the address stored in a (which points to b).

--------------------------------------------------------------------------------
2. STEP-BY-STEP EXECUTION TRACE INSIDE f()
--------------------------------------------------------------------------------

Initial function state:
* Local variable x = 4 (independent copy of c)
* Pointer py points to c in main
* Double pointer ppz points to b, which points to c in main

Let's execute the function line-by-line:

Line 1: **ppz += 1;
* **ppz dereferences twice: ppz -> b -> c.
* This directly increments the value of c in main.
* c changes from 4 to 5.

Line 2: z = **ppz;
* Dereferences twice to get the current value of c.
* Since c is now 5, local variable z is assigned 5.
* State: z = 5

Line 3: *py += 2;
* *py dereferences once: py -> c.
* This modifies the value of c in main.
* c changes from 5 to 7.

Line 4: y = *py;
* Dereferences py to read the current value of c.
* Since c is now 7, local variable y is assigned 7.
* State: y = 7

Line 5: x += 3;
* Modifies the local variable x.
* x changes from 4 to 7.
* State: x = 7

Line 6: return x + y + z;
* Substituting the local values: 7 + 7 + 5 = 19.

--------------------------------------------------------------------------------
3. FINAL CONCLUSION
--------------------------------------------------------------------------------

* The function returns 19.
* The printf statement in main() prints: 19

Correct Option: b) 19

--------------------------------------------------------------------------------
4. KEY TAKEAWAYS FOR BEGINNERS
--------------------------------------------------------------------------------
* Pass-by-value (like variable x) creates a local copy. Modifications inside 
  the function do not affect the original variable in main.
* Pass-by-reference using pointers (like py and ppz) allows a function to 
  directly access and modify the original variables in the calling function.
* Single asterisk (*) dereferences a pointer to get to the value it points to.
* Double asterisk (**) dereferences a double pointer twice to get to the final 
  target value.
================================================================================
*/