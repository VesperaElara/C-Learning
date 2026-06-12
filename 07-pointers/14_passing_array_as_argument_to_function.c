/*
================================================================================
               C PROGRAMMING: PASSING ARRAYS TO FUNCTIONS
================================================================================

1. THE FUNDAMENTAL RULE: PASS BY BASE ADDRESS
--------------------------------------------------------------------------------
In C, when you pass an array as an argument to a function, the compiler does 
NOT copy the entire array into memory. Instead, it passes only the base address 
(a pointer to the very first element).

This design approach makes programs efficient because it avoids duplicating large 
blocks of data in memory during function execution.

Example Analysis:
    int a[] = {1, 2, 3, 4};
    add(a, len);

    When 'add(a, len)' is invoked, the argument 'a' evaluates to the memory 
    address of its first element (the location of 1).


2. THE FUNCTION PARAMETER SYNTAX
--------------------------------------------------------------------------------
When writing a function that accepts an array, you can declare the parameter 
using square brackets '[]'. 

    int add(int b[], int len)

Inside the compiler, 'int b[]' is implicitly converted and treated exactly like a 
pointer declaration: 'int *b'. 

Because 'b' holds a memory address, we can use the regular subscript notation 
'b[i]' inside the function to jump to the respective elements.


3. THE NEED FOR THE ARRAY LENGTH PARAMETER
--------------------------------------------------------------------------------
Since a function receives only the base address pointer, it has no way of 
knowing how many elements are in the array by itself. 

    - Inside main(): 'sizeof(a)' returns the total size of the array in bytes.
    - Inside add(): 'sizeof(b)' would only give the size of a pointer variable 
                    (typically 4 or 8 bytes), completely losing the array size.

Therefore, you must always calculate the number of elements in the caller function 
and pass it explicitly as an extra argument ('len').

Formula to compute length:
    int len = sizeof(a) / sizeof(a[0]); // Total array bytes divided by element bytes


4. STEP-BY-STEP CODE EXECUTION TRACE
--------------------------------------------------------------------------------
Given the complete program sequence:

Code:
    int add(int b[], int len) {
        int sum = 0, i;
        for(i = 0; i < len; i++) {
            sum += b[i];
        }
        return sum;
    }

    int main() {
        int a[] = {1, 2, 3, 4};
        int len = sizeof(a) / sizeof(a[0]); // 16 bytes / 4 bytes = 4 elements
        printf("%d", add(a, len));
        return 0;
    }

Execution Steps:
    1. The array 'a' is initialized in main() with elements: [1, 2, 3, 4].
    2. 'len' evaluates to 4.
    3. 'add(a, len)' passes the base address of 'a' and the value 4 to the function.
    4. Inside add(), parameter 'b' points back to the exact same array in main().
    5. The loop iterates 4 times:
       - i = 0: sum = 0 + b[0] => 0 + 1 = 1
       - i = 1: sum = 1 + b[1] => 1 + 2 = 3
       - i = 2: sum = 3 + b[2] => 3 + 3 = 6
       - i = 3: sum = 6 + b[3] => 6 + 4 = 10
    6. The value 10 is returned and printed out.

================================================================================
*/