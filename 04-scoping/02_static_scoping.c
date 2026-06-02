/*
================================================================================
                    STATIC SCOPING (LEXICAL SCOPING) IN C
================================================================================

1. WHAT IS STATIC SCOPING?
--------------------------
Static scoping (also called lexical scoping) is the rule C uses to look up the 
meaning of a variable name when multiple variables share the same name. 

Under static scoping, a variable's "scope" (where it can be seen and used) is 
determined entirely by where it is written in the source code text, long before 
the program even runs. 

The lookup policy follows a simple "Inside-Out" rule:
* C first searches the current, innermost curly-brace block `{ }` or function.
* If the variable isn't found there, it steps outward to the surrounding block.
* It keeps moving outward, layer by layer, until it hits global variables.
* If it still can't find it, the compiler throws an error.

Crucially, static scoping looks at the structure of the source code text, 
NOT the sequence of function calls at runtime.


2. THE INNERMOST OVERRIDING RULE (SHADOWING)
--------------------------------------------
Consider this structural code sequence:

    int a = 10, b = 20; // Global Variables (Outer Layer)

    int fun() 
    {
        int a = 5;      // Local Variable (Middle Layer - shadows global 'a')
        {
            int c;      // Innermost Block Layer
            c = b / a;  
            printf("%d", c); 
        }
    }

Tracing the Calculation of `c = b / a;`:
* C looks for `b`: It checks the innermost block (not found). It checks `fun()` 
  (not found). It checks the global scope and finds `b = 20`.
* C looks for `a`: It checks the innermost block (not found). It checks `fun()` 
  and finds `int a = 5`. C stops looking immediately! 

The local `a = 5` completely hides ("shadows") the global `a = 10`. 
Therefore, `c = 20 / 5`, which evaluates to `4`.


3. ADVANCED EXAMPLE: SCOPING VS. THE CALL STACK
------------------------------------------------
A common point of confusion is mixing up runtime function execution (the Call 
Stack) with compile-time variable visibility (Static Scoping). 

Let's look at this complete program layout:

    int a = 5; // Global variable (Initialized Data Segment)

    int main() 
    {
        int a = 10; // Local to main
        a = fun1(a);
        printf("%d", a);
    }

    int fun1(int b) 
    {
        b = b + 10;
        b = fun2(b);
        return b;
    }

    int fun2(int b) 
    {
        int c;
        c = a + b; // <-- CRITICAL POINT: Which 'a' is used here?
        return c;
    }


4. THE STRUCTURAL VISUALIZATION (ASCII ART)
--------------------------------------------
When `fun2` is executing, the program memory has two separate systems active: 
the Call Stack (how functions called each other) and the Static Code Structure 
(how code was written).

       THE CALL STACK (Runtime)            STATIC VISIBILITY (Compile-time)
       ========================            ================================
       
             +-------------+               The code text places fun2() 
       Top   |   [fun2]    |               completely outside of main().
             |   b = 20    |               Therefore, fun2() can ONLY see:
             |   c = 25    |               1. Its own local variables (b, c)
             +-------------+               2. Global variables
             |   [fun1]    |
             |   b = 20    |               It is physically impossible for 
             +-------------+               fun2() to look inside main()'s 
       Base  |   [main]    |               stack frame to see main's 'a'.
             |   a = 10    |               
             +-------------+               
                                                   +---------------+
                                                   | GLOBAL SPACE  |
                                                   |   a = 5       |
                                                   +-------+-------+
                                                           |
                                            +--------------+--------------+
                                            |                             |
                                    +-------+-------+             +-------+-------+
                                    |    main()     |             |    fun2()     |
                                    | Local: a = 10 |             | Can see global|
                                    +---------------+             +---------------+



5. STEP-BY-STEP TRACE OF THE COMPLEX EXAMPLE
---------------------------------------------
* Step 1: `main()` runs. Its local `a` is set to 10.
* Step 2: `main()` calls `fun1(a)`, passing the value 10.
* Step 3: Inside `fun1()`, its parameter `b` becomes 10. The line `b = b + 10;` 
  updates `b` to 20.
* Step 4: `fun1()` calls `fun2(b)`, passing the value 20.
* Step 5: Inside `fun2()`, its parameter `b` becomes 20.
* Step 6: `fun2()` evaluates `c = a + b;`. 
  * C looks for `a` inside `fun2()`. It is not found.
  * C looks for `a` in the surrounding textual scope. The text surrounding 
    `fun2()` is the global space.
  * It finds the global `a = 5`. It completely ignores `main()`'s local `a = 10` 
    because `fun2()` is not written inside `main()`.
  * Therefore, `c = 5 + 20 = 25`.
* Step 7: `fun2()` returns 25 back to `fun1()`. `fun1()` returns 25 back to 
  `main()`.
* Step 8: `main()` overwrites its local `a` with 25 and prints `25`.


================================================================================
THE GOLDEN TAKEAWAY
A function can never access the local variables of another function just because 
it was called by it. Visibility depends entirely on where the function code is 
physically written in your file. Since all functions in C are written at the 
global level (you cannot nest a function definition inside another function definition 
in standard C), a function can only ever see its own local variables and global 
variables!
================================================================================
*/

#include <stdio.h>

int a = 5; // Global variable (Initialized Data Segment)

int fun1(int);
int fun2(int);

int main() 
{
    int a = 10; // Local to main
    a = fun1(a);
    printf("%d\n", a);
}

int fun1(int b) 
{
    b = b + 10;
    b = fun2(b);
    return b;
}

int fun2(int b) 
{
    int c;
    c = a + b; // <-- CRITICAL POINT: Which 'a' is used here?
    return c;
}
