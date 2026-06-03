#include <stdio.h>

int argument = 3;

void count(int n)
{
    static int d = 1;
    printf("%d ", n);
    printf("%d ", d);
    d++;
    if (n > 1)
    {
        count(n-1);
    }
    printf("%d ", d);
}

int main()
{
    printf("count(%d) gives: ", argument);
    count(argument);
}

/*
===============================================================================
               TOPIC: RECURSION WITH STATIC VARIABLES IN C
===============================================================================

1. KEY CONCEPT: STATIC VARIABLES IN RECURSION
-------------------------------------------------------------------------------
- A 'static int' is initialized only ONCE when the program starts.
- It retains its updated value across multiple function calls.
- Unlike local automatic variables (which get a fresh copy on every recursive 
  stack frame), all recursive instances of 'count()' share the exact same 
  memory location for 'd'. Any changes made to 'd' persist globally across 
  the lifespan of the execution.


2. STEP-BY-STEP TRACE FOR count(3)
-------------------------------------------------------------------------------
Initial global/static state: d = 1

--- PHASE 1: RECURSIVE FORWARD PASS (Winding the stack) ---

[Call 1: count(3) with n = 3]
- Prints 'n': "3 "
- Prints 'd': "1 "
- Increments 'd': d becomes 2
- Condition check: 'if (n > 1)' -> (3 > 1) is true.
- Suspends count(3) and makes a recursive call to count(2).

[Call 2: count(2) with n = 2]
- Prints 'n': "2 "
- Prints 'd': "2 "
- Increments 'd': d becomes 3
- Condition check: 'if (n > 1)' -> (2 > 1) is true.
- Suspends count(2) and makes a recursive call to count(1).

[Call 3: count(1) with n = 1]
- Prints 'n': "1 "
- Prints 'd': "3 "
- Increments 'd': d becomes 4
- Condition check: 'if (n > 1)' -> (1 > 1) is false.
- Skips the recursive call.
- Executes final print statement: Prints 'd': "4 "
- count(1) finishes and returns execution control back to count(2).


--- PHASE 2: UNWINDING PASS (Popping off the stack) ---

[Resuming Call 2: count(2)]
- Resumes right after the line 'count(n-1);'
- Executes final print statement: Prints 'd'. Since 'd' is static and its 
  current shared value is 4, it prints: "4 "
- count(2) finishes and returns execution control back to count(3).

[Resuming Call 1: count(3)]
- Resumes right after the line 'count(n-1);'
- Executes final print statement: Prints 'd'. The shared value of 'd' remains 4. 
  It prints: "4 "
- count(3) finishes. Program completes.


3. OUTPUT ASSEMBLY & COMPARISON
-------------------------------------------------------------------------------
Let's concatenate every value printed sequentially:

From Call 1 forward pass:  3 1
From Call 2 forward pass:  2 2
From Call 3 entire run:    1 3 4
From Call 2 unwinding:     4
From Call 1 unwinding:     4

Combined Output Sequence:  3 1 2 2 1 3 4 4 4


4. CONCLUSION & CORRECT OPTION
-------------------------------------------------------------------------------
- Option (a): 3 1 2 2 1 3 4 4 4 -> CORRECT
- Option (b): 3 1 2 1 1 1 2 2 2 -> Incorrect (Assumes 'd' updates locally)
- Option (c): 3 1 2 2 1 3 4     -> Incorrect (Misses the unwinding print statements)
- Option (d): 3 1 2 1 1 1 2     -> Incorrect

Correct Answer: a
===============================================================================
*/