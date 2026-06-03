/*
================================================================================
                    TYPES OF RECURSION: TAIL VS. NON-TAIL
================================================================================

1. TAIL RECURSION
--------------------------------------------------------------------------------
A recursive function is said to be tail recursive if the recursive call is the 
absolute last operation executed by the function. 

* Key characteristic: There is no computation or logic left to evaluate after 
  the recursive call returns.
* Memory Benefit: Because nothing happens after the call, the system does not 
  need to preserve the stack frame or state of the current function instance. 
  Modern compilers can optimize this (Tail Call Optimization) by reusing the 
  current stack frame, making tail recursion as memory-efficient as a loop.

Code Example:
void fun(int n) {
    if (n == 0)
        return;
    else {
        printf("%d ", n);
        return fun(n - 1); // Tail recursive call
    }
}

int main() {
    fun(3); // Output: 3 2 1
    return 0;
}


2. NON-TAIL RECURSION
--------------------------------------------------------------------------------
A recursive function is non-tail recursive if the recursive call is NOT the 
last thing done by the function. 

* Key characteristic: After the recursive call returns control back to the 
  current instance, there is still some work left to evaluate (e.g., printing, 
  adding, multiplying).
* Memory Impact: The stack frames cannot be optimized out. Every suspended 
  function call must stay safely active inside the call stack until its inner 
  recursive call yields a result.

Code Example:
void fun(int n) {
    if (n == 0)
        return;
    fun(n - 1);        // Non-tail recursive call
    printf("%d ", n);   // Post-recursive operation (Left to evaluate)
}

int main() {
    fun(3); // Output: 1 2 3
    return 0;
}


3. CALL STACK & TRACE DIFFERENCES
--------------------------------------------------------------------------------
Let's analyze how the call stack handles the non-tail recursion example `fun(3)`:

* Winding Phase (Stack Building):
  1. main() calls fun(3) -> suspended, waits for fun(2)
  2. fun(3) calls fun(2) -> suspended, waits for fun(1)
  3. fun(2) calls fun(1) -> suspended, waits for fun(0)
  4. fun(1) calls fun(0) -> reaches base case (n == 0), begins returning

* Unwinding Phase (Execution of Remaining Tasks):
  [  fun(0)  ] -> Returns immediately (Base case hit)
  [  fun(1)  ] -> Resumes, prints "1", exits frame
  [  fun(2)  ] -> Resumes, prints "2", exits frame
  [  fun(3)  ] -> Resumes, prints "3", exits frame
  [  main()  ] -> Resumes, returns 0, process terminates

Summary Comparison:
--------------------------------------------------------------------------------
| Feature            | Tail Recursion             | Non-Tail Recursion       |
|--------------------|----------------------------|--------------------------|
| Position of Call   | Absolute last statement    | Not the last statement   |
| Remaining Tasks    | None                       | Must resume to finish    |
| Stack Optimization | Possible (Compiler reuse)  | Not possible             |
================================================================================
*/

/*
================================================================================
               ADVANCED NON-TAIL RECURSION AND EVALUATION EXERCISES
================================================================================

1. LOGARITHMIC NON-TAIL RECURSION ANALYSIS
--------------------------------------------------------------------------------
Consider a recursive function where the problem size is halved (n/2) on each 
iteration and involves an addition operation after the recursive step.

Code Example:
int fun(int n) {
    if (n == 1)
        return 0;
    else
        return 1 + fun(n / 2);
}

int main() {
    printf("%d", fun(8));
    return 0;
}

Why is this Non-Tail?
The recursive call `fun(n / 2)` is enclosed in an expression `1 + fun(...)`. 
The addition operation must wait for the inner function call to completely 
resolve before it can execute. This forces the system to preserve each state.

Execution Stack Profile for fun(8):
[  fun(1)  ] -> Base Case: Returns 0.
[  fun(2)  ] -> Suspended: Evaluates 1 + fun(1)
[  fun(4)  ] -> Suspended: Evaluates 1 + fun(2)
[  fun(8)  ] -> Suspended: Evaluates 1 + fun(4)
[  main()  ] -> Suspended: Waits for fun(8) to return a value.
+----------+
|  STACK   |
+----------+

Mathematical Resolution (Unwinding Phase):
* fun(1) = 0
* fun(2) = 1 + fun(1) -> 1 + 0 = 1
* fun(4) = 1 + fun(2) -> 1 + 1 = 2
* fun(8) = 1 + fun(4) -> 1 + 2 = 3
Final Output Printed: 3 (Effectively computes $\log_2(n)$)


2. PRACTICE CASE STUDIES: CLASSIFICATION EXERCISES
--------------------------------------------------------------------------------

PROGRAM 1
------------------------------------------
void fun2(int n) {
    if (n == 0)
        return;
    fun2(n / 2);
    printf("%d", n % 2);
}

* Classification: NON-TAIL RECURSION
* Reason: Look closely at what happens after `fun2(n / 2)`. The function is 
  not finished; it still must execute `printf("%d", n % 2)` during the stack 
  unwinding phase. Because a computation (printing the remainder) occurs after 
  the recursive invocation, the compiler must preserve all activation records.


PROGRAM 2
-----------------------------------------------
void fun2(int n) {
    if (n <= 0)
        return;
    printf("%d ", n);
    fun2(2 * n);
    printf("%d ", n);
}

* Classification: NON-TAIL RECURSION
* Reason: Even though there is a `printf` statement *before* the recursive call, 
  there is a second `printf("%d ", n)` statement placed immediately *after* 
  `fun2(2 * n)`. Since control must return to the calling frame to execute that 
  final print operation, the stack frames cannot be optimized out.


3. SUMMARY CHECKPOINT FOR IDENTIFICATION
--------------------------------------------------------------------------------
To easily identify if a function is Tail or Non-Tail, ask yourself this question:
"Does the computer have to do ANY work inside this function frame after the 
nested function call returns?"

* If YES -> It is Non-Tail recursion (Stack frames must be held in memory).
* If NO  -> It is Tail recursion (Stack frames can be discarded or overwritten).

================================================================================
*/