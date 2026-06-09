/*
================================================================================
                    C PROGRAMMING NOTES: RETURNING POINTERS
================================================================================

1. CORE CONCEPT: RETURNING POINTERS FROM FUNCTIONS
--------------------------------------------------------------------------------
A function in C can return a pointer (a memory address) to the calling function, 
just like it can return an int, char, or float. 

The syntax requires placing an asterisk (*) before the function name in both 
the declaration and definition:

    data_type *function_name(parameters) {
        // function body
        return address;
    }

--------------------------------------------------------------------------------
2. VALID USE CASE: RETURNING ADDRESSES OF PERSISTENT MEMORY
--------------------------------------------------------------------------------
It is completely safe to return a pointer if the memory it points to remains 
valid after the function finishes execution. 

A common example is passing an array to a function and returning the address 
of one of its elements. Since the array is created in the main() function, its 
memory stays alive throughout the program execution.

Example Code: Finding the Middle Element of an Array
--------------------------------------------------------------------------------
#include <stdio.h>

// Function declaration: returns a pointer to an integer
int *findMid(int a[], int n) {
    // n / 2 finds the middle index. 
    // The & operator gets the exact memory address of that element.
    return &a[n / 2];
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]); // Calculates total elements (5)
    
    int *mid = findMid(a, n); // Receives the address of the middle element
    
    printf("%d", *mid); // Dereferences the pointer to print the value: 3
    return 0;
}

--------------------------------------------------------------------------------
3. CRITICAL WARNING: RETURNING THE ADDRESS OF LOCAL (AUTOMATIC) VARIABLES
--------------------------------------------------------------------------------
+------------------------------------------------------------------------------+
| WARNING: NEVER return the address of a local automatic variable from a       |
| function. Doing so results in a "Dangling Pointer" and Undefined Behavior.   |
+------------------------------------------------------------------------------+

Why is this dangerous?
- Local variables (also called automatic variables) are allocated on the Stack.
- These variables only exist while the function is executing.
- The moment the function finishes and returns, its local variables are destroyed, 
  and that stack memory is freed up for other tasks.
- If you return the address of a local variable, the calling function receives 
  a pointer pointing to a dead memory location. Trying to access or change this 
  memory later will cause bugs, crashes, or garbage data.

Incorrect Example Code (What NOT to do):
--------------------------------------------------------------------------------
#include <stdio.h>

int *fun() {
    int i = 10;    // 'i' is a local variable stored on the stack
    return &i;     // DANGEROUS: 'i' is destroyed right after this return
}

int main() {
    int *p = fun(); // 'p' now contains a dangling pointer
    
    // Compilers will throw a warning: "function returns address of local variable"
    printf("%d", *p); // UNDEFINED BEHAVIOR: Might print 10, 0, or crash the program
    
    return 0;
}

--------------------------------------------------------------------------------
4. SUMMARY RULES FOR BEGINNERS
--------------------------------------------------------------------------------
- OK: Returning pointers to arguments passed by reference (like arrays or pointers).
- OK: Returning pointers to dynamically allocated memory (using malloc or calloc).
- OK: Returning pointers to static or global variables (which stay alive all time).
- STRICTLY FORBIDDEN: Returning pointers to standard local variables initialized 
                      inside that same function.
================================================================================
*/

#include <stdio.h>

int *findMid(int a[], int n) {
    return &a[n / 2];
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    
    int *mid = findMid(a, n);
    
    printf("%d", *mid);
    return 0;
}