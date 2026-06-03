/*
================================================================================
                           FUNDAMENTALS OF RECURSION IN C
================================================================================

1. DEFINITION
--------------------------------------------------------------------------------
Recursion is a process in which a function calls itself either directly or 
indirectly. 

* Direct Recursion: A function explicitly calls itself within its own body.
  
  int fun()
  {
      ...
      fun(); // Direct call
  }

* Core Purpose: It breaks down a complex problem into smaller, manageable 
  sub-problems of the same type.


2. THE MECHANICS OF A RECURSIVE FUNCTION
--------------------------------------------------------------------------------
Every successful recursive function requires two critical components:

* Base Case (Termination Condition): The condition under which the function 
  stops calling itself and begins returning a value. Without a proper base 
  case, a recursive function will call itself infinitely, leading to a Stack 
  Overflow error.
* Recursive Step: The part of the function where the problem is reduced in 
  size, and the function calls itself with the updated, smaller argument.

Consider the following program structure:

int fun(int n) {
    if (n == 1) 
        return 1; // Base Case
    else 
        return 1 + fun(n - 1); // Recursive Step
}

int main() {
    int n = 3;
    printf("%d", fun(n));
    return 0;
}


3. MEMORY MANAGEMENT: THE CALL STACK (METHOD 1)
--------------------------------------------------------------------------------
When a function is executed in C, the system allocates a chunk of memory called 
a "Stack Frame" (or Activation Record) inside the Call Stack. This frame stores 
the function's local variables, parameters, and the return address.

For the execution of fun(3), the stack behaves as follows:

[  fun(1)  ] -> Allocated when fun(2) calls fun(1) with n = 1. Hits Base Case.
[  fun(2)  ] -> Allocated when fun(3) calls fun(2) with n = 2. Suspended.
[  fun(3)  ] -> Allocated when main() calls fun(3) with n = 3. Suspended.
[  main()  ] -> Allocated initially with local variable n = 3. Suspended.
+----------+
|  STACK   |
+----------+

* Pushing to the Stack: Each recursive call adds a new layer to the top of 
  the stack. The calling function is suspended until the called function returns.
* Popping from the Stack: Once the base case (fun(1)) is met, it returns its 
  value. The control flows backward, popping each frame off the stack one by 
  one as they compute their final results.


4. TRACING RECURSIVE EXECUTION (METHOD 2)
--------------------------------------------------------------------------------
To track how values resolve during recursion, trace the execution downward 
until the base case is reached, then substitute the returned values upward.

Execution Trace for fun(3):

fun(3)
  │
  └──> Needs to compute: 1 + fun(2)
              │
              └──> Needs to compute: 1 + fun(1)
                          │
                          └──> Hits Base Case: returns 1

Resolution Trace (Backward Substitution):

* fun(1) returns 1
* fun(2) evaluates: 1 + fun(1) -> 1 + 1 = 2 (returns 2)
* fun(3) evaluates: 1 + fun(2) -> 1 + 2 = 3 (returns 3)

Finally, main() receives the value 3 and prints it to the output console.

================================================================================
*/

#include <stdio.h>

int fun(int n)
{
    if(n == 0) {
        return 1;
    }
    else
        return 7 + fun(n-2);
}

int main() {
    printf("%d\n", fun(4));
    return 0;
}

/*

fun(4) = 7 + fun(2) >> fun(4) = 7 + 8 = 15
fun(2) = 7 + fun(0) >> fun(2) = 7 + 1 = 8
fun(0) = 1

*/