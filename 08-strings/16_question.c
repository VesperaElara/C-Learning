#include <stdio.h>

void foo(char *a) 
{
    if (*a && *a != ' ') 
    {
        foo(a + 1);
        putchar(*a);
    }
}

int main(void) 
{
    char str[] = "ABCD EFGH";
    foo(str);
    putchar('\n');
    return 0;
}

/*
================================================================================
RECURSION AND STRING PROCESSING IN C
================================================================================

The foo function demonstrates the application of structural recursion over a
character pointer (string) in C. It specifically illustrates how the call stack
can be used to reverse a sequence of characters up to a specific delimiter.

---
1. FUNCTION ANALYSIS
---
The function processes the input string character by character using pointer 
arithmetic. Let us break down its key architectural components:

* Base Condition (The 'if' statement):
  The expression (*a && *a != ' ') checks two distinct conditions:
  - '*a': Ensures the current character is not the null terminator ('\0'). 
    This prevents the pointer from reading past the end of the string.
  - '*a != ' '': Ensures the current character is not a space. 
  
  If either condition evaluates to false (i.e., the pointer reaches a space 
  or the null terminator), the condition fails, recursion stops, and the 
  unwinding phase begins.

* Recursive Call (foo(a + 1)):
  The expression 'a + 1' increments the memory address by one byte, passing 
  the pointer to the next character in the sequence. Because this call occurs 
  BEFORE the character is printed, the function continues to push new stack 
  frames without producing any output yet.

* Output Execution (putchar(*a)):
  The 'putchar' function executes only after the recursive call returns. 
  This creates a Last-In, First-Out (LIFO) execution order, effectively 
  reversing the sequence of processed elements.

---
2. STEP-BY-STEP TRACE (Input: "ABCD EFGH")
---
Let us trace the exact state of the execution stack when the input string 
is passed to the function:

Frame 1: foo("ABCD EFGH") -> *a is 'A' (Valid) -> Calls foo("BCD EFGH")
Frame 2: foo("BCD EFGH")  -> *a is 'B' (Valid) -> Calls foo("CD EFGH")
Frame 3: foo("CD EFGH")   -> *a is 'C' (Valid) -> Calls foo("D EFGH")
Frame 4: foo("D EFGH")    -> *a is 'D' (Valid) -> Calls foo(" EFGH")
Frame 5: foo(" EFGH")     -> *a is ' ' (Space detected -> Condition Fails!)

At Frame 5, the base condition is triggered because a space character is 
encountered. Frame 5 immediately terminates and returns control back to 
the previous frame without executing a 'putchar' statement.

---
3. STACK UNWINDING AND OUTPUT GENERATION
---
As control returns back up the call stack, the remaining statements in 
each respective frame are executed in reverse order:

- Control returns to Frame 4: Executes putchar('D') -> Output: D
- Control returns to Frame 3: Executes putchar('C') -> Output: DC
- Control returns to Frame 2: Executes putchar('B') -> Output: DCB
- Control returns to Frame 1: Executes putchar('A') -> Output: DCBA

Once Frame 1 finishes executing, control returns to the main calling function. 
The remaining segment of the string (" EFGH") is never reached or processed 
because the space character permanently halted the forward recursion.

---
4. CONCLUSION
---
The final output of the function for the given input is:
DCBA

This matches option (d) from the standard problem set.
*/