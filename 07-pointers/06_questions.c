/*
================================================================================
                    C PROGRAMMING NOTES: POINTER ESSENTIALS & FAQs
================================================================================

1. THE DOUBLE MEANING OF THE ASTERISK (*) SYMBOL
--------------------------------------------------------------------------------
In C, the `*` symbol performs entirely different actions depending on where it 
is used. Mixing these up is a classic beginner mistake.

A. Context 1: At Declaration (Creating a Pointer Variable)
   - When used with a data type (e.g., `int *p;`), the `*` does NOT read or 
     modify memory. 
   - It simply informs the compiler: "p is a variable that stores a memory 
     address of an integer."

B. Context 2: In Statements (Indirection / Dereferencing Operator)
   - When used on an already declared pointer in an executable line of code, 
     the `*` acts as an indirection operator.
   - It means: "Go to the address stored in this pointer and grab/change the 
     value stored there."

Let's look at why assignments are structured the way they are:

    int i = 10;
    int *p = &i;  // Statement 1: Declaration & Initialization
    p = &i;       // Statement 2: Pure Assignment

- Why is `p` not preceded by `*` in Statement 2?
  Because you want to update the pointer variable `p` itself to store the address 
  of `i`. 
  
  If you wrote `*p = &i;`, it would be a compilation error. It tells the machine 
  to go to the memory target of `p` (which is an integer space) and forcefully 
  save a hexadecimal address into it. You cannot assign a pointer address directly 
  to a plain integer variable.

--------------------------------------------------------------------------------
2. CONSTANT POINTERS AND READ-ONLY MEMORY PROTECTION
--------------------------------------------------------------------------------
When you declare a function parameter as `const data_type *pointer_name`, you are 
creating a "Pointer to a Constant". 

- This ensures the function treats the data at that address as read-only.
- It is a security feature to prevent a function from accidentally altering 
  variables passed from elsewhere.

Example Analysis:
--------------------------------------------------------------------------------
void fun(const int *p) {
    *p = 0; // ERROR: Assignment of read-only location '*p'
}

int main() {
    const int i = 10;
    fun(&i);
    return 0;
}

Because parameter `p` is protected with the `const` qualifier, any attempt to 
dereference it (`*p`) and modify the underlying value will cause the compiler 
to block execution with a read-only modification error.

--------------------------------------------------------------------------------
3. HOW TO CORRECTLY PRINT MEMORY ADDRESSES
--------------------------------------------------------------------------------
To display the actual memory address stored inside a pointer or the location of 
a variable using `printf()`, you must use the `%p` format specifier.

Key Rules for Address Printing:
- Use `%p` inside the format string.
- Pass the raw pointer variable or use the address-of operator (`&`).
- The output is typically rendered in hexadecimal format (e.g., `0x7ffd5b9a987c`).

Example:
--------------------------------------------------------------------------------
#include <stdio.h>

int main() {
    int i = 10;
    int *p = &i;
    
    // Prints the memory address layout
    printf("The address of variable i is %p", (void *)p); 
    return 0;
}

--------------------------------------------------------------------------------
4. UNDERSTANDING POINTER ALIASES
--------------------------------------------------------------------------------
An "alias" means another expression that refers directly to the exact same 
memory space as the original variable. 

Suppose we have:
    int i = 10;
    int *p = &i; // p points to i

Let's evaluate which expressions are identical aliases to `i`:

- `*p`  --> YES. Dereferencing the pointer brings you directly to the value of `i`.
- `*&p` --> NO. This resolves to the value of `p` itself (the address of `i`), 
            not the value of `i`.
- `&p`  --> NO. This is the memory address where the pointer tool `p` resides.
- `*i`  --> INVALID. You cannot dereference a normal integer variable.
- `*&i` --> YES. `&i` gets the address of `i`, and the leading `*` immediately 
            dereferences that address. The operators cancel each other out, 
            returning you back to `i`.

+------------------------------------------------------------------------------+
| CRITICAL TRICK: The operators '*' and '&' are exact opposites. When placed   |
| consecutively like '*&', they completely cancel each other out.              |
+------------------------------------------------------------------------------+
================================================================================
*/