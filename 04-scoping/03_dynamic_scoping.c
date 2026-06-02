/*
================================================================================
                           DYNAMIC SCOPING IN C
================================================================================

1. WHAT IS DYNAMIC SCOPING?
---------------------------
Dynamic scoping is an alternative rule for resolving variable names. Unlike 
static scoping (which looks outward at how the code is written on the page), 
dynamic scoping looks backward at the timeline of execution. 

Under dynamic scoping, when a variable name needs to be resolved, the computer 
searches the current function first. If the variable isn't found, it looks at 
the *calling function* (the one that triggered this function). If it's still 
not found, it looks at the function that called *that* one, traveling down 
the active runtime Call Stack.

NOTE: Standard C uses static scoping. However, understanding dynamic scoping 
is crucial for computer science theory, debugging, and understanding how 
the Call Stack interacts with variable resolution in other languages (like Perl 
or Lisp).


2. THE CALL CHAIN RULE
----------------------
Instead of looking at structural code layers, think of dynamic scoping as a 
genealogy tree of execution. If a function doesn't have a variable local to 
itself, it asks its immediate parent (the function that called it) for a 
variable of that name.



3. CODE EXAMPLE ANALYSIS
------------------------
Let's analyze how the exact same program from our previous lesson behaves 
differently under dynamic scoping rules:

    int a = 5; // Global variable (Data Segment)

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
        c = a + b; // <-- UNDER DYNAMIC SCOPING: Which 'a' is used here?
        return c;
    }


4. THE DESK TRACE & CALL STACK VISUALIZATION
---------------------------------------------
When `fun2` is executing the line `c = a + b;`, look at how the computer navigates 
the Call Stack vertically from top to bottom to resolve the value of `a`:

       THE CALL STACK (Dynamic Lookup Direction)
       =========================================
       
             +-------------------------+
   Top  [1]  |      FRAME: fun2()      | 
             |  b = 20                 | 
             |  c = ?                  | <-- C looks for 'a' here. Not found!
             +-------------------------+
        |    |      FRAME: fun1()      | 
        v    |  b = 20                 | <-- C looks for 'a' here. Not found!
   Look Down +-------------------------+
        |    |      FRAME: main()      | 
        v    |  a = 10                 | <-- C looks for 'a' here. FOUND 'a = 10'!
             +-------------------------+
   Base      
             ===========================
             |  DATA SEGMENT (Global)  | 
             |  a = 5                  | <-- Skipped entirely!
             ===========================


5. STEP-BY-STEP TRACE
---------------------

* Step 1: `main()` starts executing. Its local variable `a` is allocated on 
  the stack with a value of 10.
* Step 2: `main()` calls `fun1(a)`, passing the value 10 into parameter `b`.
* Step 3: Inside `fun1()`, the operation `b = b + 10` updates its local `b` to 20.
* Step 4: `fun1()` calls `fun2(b)`, passing the value 20 into `fun2`'s parameter `b`.
* Step 5: Inside `fun2()`, the line `c = a + b;` runs. The program needs to find `a`.
* Step 6: RESOLVING VARIABLE 'a' DYNAMICALLY:
  * Check `fun2()`'s frame: No variable named `a` exists here.
  * Look down the stack to the caller, `fun1()`'s frame: No variable named `a` here.
  * Look down the stack to `fun1`'s caller, `main()`'s frame: Found `int a = 10`!
  * The lookup stops immediately. The global variable `a = 5` is completely ignored.
* Step 7: The math is performed: `c = 10 (from main) + 20 (local b) = 30`.
* Step 8: `fun2()` returns 30 to `fun1()`. `fun1()` returns 30 to `main()`.
* Step 9: `main()` updates its local `a` to 30, and prints `30`.


================================================================================
THE GOLDEN TAKEAWAY
* Static Scoping  = Look where the code was WRITTEN (C standard). Result = 25
* Dynamic Scoping = Look at how the code was CALLED (Stack history). Result = 30
================================================================================
*/