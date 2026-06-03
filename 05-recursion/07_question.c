#include <stdio.h>

int argument = 5;

int fun(int n)
{
    int x = 1, k;
    if (n == 1)
    {
        return x;
    }
    for (k = 1; k < n; ++k)
    {
        x = x + fun(k)*fun(n-k);
    }
    return x;
}

int main()
{
    printf("fun(%d) = %d\n", argument, fun(argument));
}

/*
===============================================================================
               TOPIC: ADVANCED RECURSION & DYNAMIC MEMORY TRACING
===============================================================================

1. CODE STRUCTURE ANALYSIS
-------------------------------------------------------------------------------
The function 'fun(int n)' is a recursive function where each state computes a 
value using a 'for' loop. The loop uses a local variable 'x' initialized to 1.

Key Components:
- Base Case: if (n == 1), the function immediately returns x, which is 1.
- Local Variable Scope: 'x' is local to each function call instance. It starts 
  at 1 every time a new activation record is pushed onto the stack.
- Loop & Recursive Splits: For values of n > 1, the loop runs from k = 1 up to 
  k = n - 1. In each iteration, 'x' accumulates the product of two sub-problems: 
  'fun(k) * fun(n - k)'.


2. STEP-BY-STEP EVALUATION (BOTTOM-UP APPROACH)
-------------------------------------------------------------------------------
Because higher values of 'n' depend heavily on lower values, calculating the 
results bottom-up avoids redundant stack tracing.

- For n = 1:
  Hits the base case 'if (n == 1)'.
  Returns: 1
  -> fun(1) = 1

- For n = 2:
  Initial x = 1.
  Loop runs for k = 1 (since k < 2):
    x = x + fun(1) * fun(2 - 1)
    x = 1 + fun(1) * fun(1)
    x = 1 + (1 * 1) = 2
  Returns: 2
  -> fun(2) = 2

- For n = 3:
  Initial x = 1.
  Loop runs for k = 1 and k = 2 (since k < 3):
    k = 1: x = x + fun(1) * fun(3 - 1) 
           x = 1 + fun(1) * fun(2) = 1 + (1 * 2) = 3
    k = 2: x = x + fun(2) * fun(3 - 2)
           x = 3 + fun(2) * fun(1) = 3 + (2 * 1) = 5
  Returns: 5
  -> fun(3) = 5

- For n = 4:
  Initial x = 1.
  Loop runs for k = 1, k = 2, and k = 3 (since k < 4):
    k = 1: x = x + fun(1) * fun(3) = 1 + (1 * 5) = 6
    k = 2: x = x + fun(2) * fun(2) = 6 + (2 * 2) = 10
    k = 3: x = x + fun(3) * fun(1) = 10 + (5 * 1) = 15
  Returns: 15
  -> fun(4) = 15

- For n = 5:
  Initial x = 1.
  Loop runs for k = 1, k = 2, k = 3, and k = 4 (since k < 5):
    k = 1: x = x + fun(1) * fun(4) = 1 + (1 * 15) = 16
    k = 2: x = x + fun(2) * fun(3) = 16 + (2 * 5) = 26
    k = 3: x = x + fun(3) * fun(2) = 26 + (5 * 2) = 36
    k = 4: x = x + fun(4) * fun(1) = 36 + (15 * 1) = 51
  Returns: 51
  -> fun(5) = 51


3. SUMMARY REFERENCE TABLE
-------------------------------------------------------------------------------
|  n  | Calculations (Accumulating x)                         | Final fun(n) |
|-----|-------------------------------------------------------|--------------|
|  1  | Base Case                                             |      1       |
|  2  | 1 + (1*1)                                             |      2       |
|  3  | 1 + (1*2) + (2*1)                                     |      5       |
|  4  | 1 + (1*5) + (2*2) + (5*1)                             |     15       |
|  5  | 1 + (1*15) + (2*5) + (5*2) + (15*1)                   |     51       |


4. CONCLUSION & CORRECT OPTION
-------------------------------------------------------------------------------
- Option (a): 0  -> Incorrect
- Option (b): 26 -> Incorrect (This is an intermediate state during n=5 evaluation)
- Option (c): 51 -> CORRECT
- Option (d): 71 -> Incorrect

Correct Answer: c
===============================================================================
*/