#include <stdio.h>

/*
int main()
{
    int n = 10;
    int i = 1;
    while (i <= n)
    {
        if (i%2 != 0)
        {
            printf("%d ", (i + 1));
        }
        
        else
        {
            printf("%d ", (i - 1));
        }
        i++;
    }
}
*/


/*
================================================================================
                    TYPES OF RECURSION: DIRECT VS. INDIRECT
================================================================================

There are four primary classifications of recursion based on how and when the 
recursive call is made:
1. Direct Recursion
2. Indirect Recursion
3. Tail Recursion
4. Non-tail Recursion

This set of notes focuses comprehensively on the first two: Direct and Indirect.


1. DIRECT RECURSION
--------------------------------------------------------------------------------
A function is defined as direct recursive if it explicitly invokes itself from 
within its own body. This is the most common form of recursion.

* Structure:
  void fun() {
      // ... structural code ...
      fun(); // Explicit self-call
      // ... structural code ...
  }


2. INDIRECT RECURSION
--------------------------------------------------------------------------------
A function (let's say 'fun') is defined as indirect recursive if it calls a 
different function ('fun2'), which in turn calls 'fun' back, either directly 
or through a chain of other functions. This creates a circular dependency cycle.

* Structure:
  void fun() {                 void fun2() {
      // ... code ...              // ... code ...
      fun2();                      fun();
      // ... code ...              // ... code ...
  }                            }


3. PRACTICAL APPLICATION: INDIRECT RECURSION PROBLEM
--------------------------------------------------------------------------------
Problem Statement: 
Write a program to print numbers from 1 to 10. However, if the current number 
is odd, print (number + 1). If the current number is even, print (number - 1).

Expected Output Sequence:
2  1  4  3  6  5  8  7  10  9

Implementation in C:
--------------------------------------------------------------------------------
*/

#include <stdio.h>

// Function Declarations (Prototypes needed due to mutual dependency)
void odd();
void even();

// Global variable to maintain state across mutual calls
int n = 1; 

void odd() {
    if (n <= 10) {
        printf("%d ", n + 1); // If 1 (odd) -> prints 2
        n++;                  // n incremented to 2
        even();               // Indirect recursive call to even()
    }
    return;
}

void even() {
    if (n <= 10) {
        printf("%d ", n - 1); // If 2 (even) -> prints 1
        n++;                  // n incremented to 3
        odd();                // Indirect recursive call back to odd()
    }
    return;
}

int main() {
    odd(); // Program execution starts the cycle here
    return 0;
}

/*
4. EXECUTION TRACE & STATE ANALYSIS
--------------------------------------------------------------------------------
The program alternates execution context dynamically between both functions:

* Step 1: main() calls odd() with global n = 1.
          Condition (1 <= 10) is true. Prints (1 + 1) = 2.
          Increments n to 2. Calls even().

* Step 2: even() executes with global n = 2.
          Condition (2 <= 10) is true. Prints (2 - 1) = 1.
          Increments n to 3. Calls odd().

* Step 3: odd() executes with global n = 3.
          Condition (3 <= 10) is true. Prints (3 + 1) = 4.
          Increments n to 4. Calls even().

* ... This cycle continues until n becomes 11.

* Step 11: odd() executes with global n = 11.
           Condition (11 <= 10) is false. Hits return.
           The call stack unwinds completely back to main(), terminating safely.

================================================================================
*/
