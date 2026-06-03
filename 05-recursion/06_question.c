#include <stdio.h>

int number = 4;

void fun1(int n)
{
    int i = 0;
    if (n > 1)
    {
        fun1(n-1);
    }
    for (i = 0; i < n; i++)
    printf("* ");

}

int main()
{
    fun1(number);
}


/*
===============================================================================
                       TOPIC: RECURSIVE FUNCTION ANALYSIS
===============================================================================

1. CODE STRUCTURE ANALYSIS
-------------------------------------------------------------------------------
The given function 'fun1(int n)' combines two fundamental concepts:
- Recursion: The function calls itself with a decremented argument 'fun1(n - 1)'.
- Iteration: A 'for' loop executes 'n' times at the current activation level.

Here is the logic breakdown:
- Base Condition (Implicit): The recursive call only happens 'if (n > 1)'. 
  If 'n' is 1 or less, the recursion stops, preventing an infinite loop.
- Recursive Step: Before printing anything at the current level, the function 
  suspends its execution and calls 'fun1(n - 1)'.
- Work Step: After returning from the recursive call, a loop runs from 'i = 0' 
  to 'i < n', printing a star '*' exactly 'n' times.


2. MATHEMATICAL TRACE (STEP-BY-STEP)
-------------------------------------------------------------------------------
To find the total number of stars printed, we track how the function executes 
from the bottom up (unwinding the recursion stack).

Let T(n) be the total number of stars printed for a given value of 'n'.

- For n = 1:
  The condition 'if (n > 1)' is false. No recursive call is made.
  The loop runs for i = 0 to i < 1. It prints 1 star.
  T(1) = 1

- For n = 2:
  The condition 'if (n > 1)' is true. It calls 'fun1(1)' first.
  'fun1(1)' executes completely and prints 1 star.
  Then, the loop for n = 2 runs from i = 0 to i < 2. It prints 2 stars.
  T(2) = T(1) + 2 = 1 + 2 = 3 stars.

- For n = 3:
  It calls 'fun1(2)' first, which finishes and prints 3 stars total.
  Then, the loop for n = 3 runs and prints 3 stars.
  T(3) = T(2) + 3 = (1 + 2) + 3 = 6 stars.


3. DERIVING THE GENERAL FORMULA
-------------------------------------------------------------------------------
Following the pattern, the total number of stars printed for any positive 
integer 'n' is the sum of the first 'n' natural numbers:

T(n) = 1 + 2 + 3 + ... + (n - 1) + n

This arithmetic progression matches the standard summation formula:
Total Stars = n * (n + 1) / 2


4. CONCLUSION & CORRECT OPTION
-------------------------------------------------------------------------------
- Option (a): n                 -> Incorrect (only accounts for one level)
- Option (b): n(n+1)/2          -> CORRECT (accounts for all recursive levels)
- Option (c): n*n               -> Incorrect
- Option (d): None of the above -> Incorrect

Correct Answer: b
===============================================================================
*/