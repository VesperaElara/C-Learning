/*
================================================================================
                           THE CALL STACK IN C
================================================================================

1. WHAT IS A STACK?
-------------------
A stack is a specialized segment of computer memory used to store data 
temporarily during program execution. It acts as a container that dynamically 
grows and shrinks as your program runs.

2. CORE MECHANICS: LIFO
-----------------------
The stack operates on a strict Last-In, First-Out (LIFO) basis. This means the 
last piece of data placed onto the stack is always the first one to be removed. 

Think of it like a stack of plates: you add new plates to the top, and you 
must remove plates from the top down. You cannot access the bottom plate 
without removing the ones above it first.

There are two primary operations used to interact with a stack:
* PUSH: Adds a new data element to the top of the stack.
* POP:  Removes the top data element from the stack.

         +-------------+
   Top   |   [fun3]    | <-- Currently Executing
         +-------------+
         |   [fun2]    |
         +-------------+
         |   [fun1]    |
         +-------------+
   Base  |   [main]    |
         +-------------+

3. UNDERSTANDING THE CALL STACK (FUNCTION EXECUTION)
----------------------------------------------------
In C, the stack is heavily used to manage function calls. Every time a function 
is invoked, a dedicated chunk of memory (called a Stack Frame or Activation 
Record) is PUSHED onto the call stack. This frame stores the function's local 
variables, arguments, and return address.

When a function finishes execution (encounters a return statement or reaches 
its closing brace), its frame is POPPED off the stack, and control returns to 
the calling function.

4. TRACING FUNCTION CALLS (STEP-BY-STEP)
----------------------------------------
Consider the following nested execution sequence:

    main() -> fun1() -> fun2() -> fun3()

Here is how the Call Stack evolves over time:

Step 1: Program starts
* The main() function is called.
* The stack frame for main() is pushed to the bottom.
  [ Stack State: | main() | ]

Step 2: main() calls fun1()
* fun1() begins executing.
* The frame for fun1() is pushed on top of main().
  [ Stack State: | fun1() | main() | ]

Step 3: fun1() calls fun2()
* fun2() begins executing.
* The frame for fun2() is pushed on top of fun1().
  [ Stack State: | fun2() | fun1() | main() | ]

Step 4: fun2() calls fun3()
* fun3() begins executing.
* The frame for fun3() is pushed to the very top.
  [ Stack State: | fun3() | fun2() | fun1() | main() | ] <-- Peak Stack Depth

Step 5: fun3() returns
* fun3() completes its execution and returns.
* Its frame is popped off the stack.
  [ Stack State: | fun2() | fun1() | main() | ]

Step 6: fun2() returns
* fun2() completes its execution and returns.
* Its frame is popped off the stack.
  [ Stack State: | fun1() | main() | ]

Step 7: fun1() returns
* fun1() completes its execution and returns.
* Its frame is popped off the stack.
  [ Stack State: | main() | ]

Step 8: main() finishes
* The main function finishes, its frame is popped, and the stack becomes empty.

================================================================================
SUMMARY FOR BEGINNERS
* Functions are executed in the order they are called (pushed).
* Functions finish and unwind in the exact REVERSE order (popped).
* The function currently executing is always the one at the very top of the stack.
================================================================================
*/



/*
================================================================================
                UNDERSTANDING ACTIVATION RECORDS (THE SIMPLE WAY)
================================================================================

1. WHAT IS AN ACTIVATION RECORD?
--------------------------------
Think of an Activation Record (often called a "Stack Frame") as a temporary 
sticky note that C creates every single time a function is called. 

When a function runs, it needs its own private workspace so it doesn't mess 
up variables in other functions. C scribbles down everything that function 
needs on this sticky note and slaps it onto the top of the Call Stack. 

The moment the function finishes and hits a `return`, that sticky note is 
ripped off and thrown away completely.


2. THE THREE THINGS WRITTEN ON THE STICKY NOTE
----------------------------------------------
Every activation record contains exactly what the function needs to do its job:

* PARAMETERS:     The inputs given to the function (the data sent from the caller).
* LOCALS:         The variables created inside that specific function.
* RETURN ADDRESS: A literal note saying: "Hey CPU, when this function is done, 
                  go back to exactly this line in the main program."


3. THE CODE EXAMPLE
-------------------
Let's see how this plays out in code:

    int main() 
    {
        int a = 10;
        a = fun1(a);    // 2. Program pauses here to jump into fun1()
        printf("%d", a); // 5. Program resumes here with the new value of 'a'
    }

    int fun1(int a) 
    {
        int b = 5;
        b = b + a;
        return b;       // 4. fun1's sticky note is torn off right here!
    }


4. THE STACK IN ACTION (VISUAL DIAGRAM)
--------------------------------------
When `fun1` is in the middle of calculating `b = b + a`, this is what the 
computer's memory looks like:

         +---------------------------------------+
   Top   |        STICKY NOTE FOR: fun1()        |
         |---------------------------------------|
         |  Locals:     b = 15                   | <-- Active workspace
         |  Return to:  Line 'a = fun1(a);'     | <-- Where to go next
         |  Parameters: a = 10                   | <-- Input copy from main
         +=======================================+
         |        STICKY NOTE FOR: main()        |
         |---------------------------------------|
         |  Locals:     a = 10                   | <-- Frozen, waiting patiently
         |  Return to:  Operating System         |
         |  Parameters: None                     |
         +---------------------------------------+
   Base




5. STEP-BY-STEP BREAKDOWN
-------------------------

* Step 1: The program enters `main()`. A sticky note for `main()` is created 
  holding the local variable `a = 10`.
* Step 2: `main()` calls `fun1(a)`. C pauses `main()` right where it is and 
  creates a brand new sticky note for `fun1()`. 
* Step 3: Inside `fun1()`, the parameter `a` gets a fresh copy of the number 
  10. Then, a separate local variable `b = 5` is created. 
* Step 4: `fun1()` changes `b` to 15, and then returns it. Instantly, `fun1`'s 
  sticky note is wiped out and destroyed.
* Step 5: The computer looks at the "Return Address" on the old note, jumps back 
  to `main()`, updates `main`'s variable `a` to 15, and prints it out.


================================================================================
THE GOLDEN RULE
Because each function gets its own isolated sticky note, the variable `a` inside 
`main()` and the variable `a` inside `fun1()` are completely different pieces of 
memory. They share a name, but they never touch or overwrite each other directly!
================================================================================
*/

#include <stdio.h>

int fun1(int);

int main() 
{
  int a = 10;
  a = fun1(a);    // 2. Program pauses here to jump into fun1()
  printf("%d\n", a); // 5. Program resumes here with the new value of 'a'
}

int fun1(int a) 
{
  int b = 5;
  b = b + a;
  return b;       // 4. fun1's sticky note is torn off right here!
}