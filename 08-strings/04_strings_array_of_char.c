#include <stdio.h>

int main() {
    // Correct demonstration of declaring, initializing, and printing a string
    char s[6] = "Hello"; // 5 characters + 1 room for the null terminator ('\0')
    char t[6];
    int i;

    // Manually copying the string character by character until '\0' is hit
    for (i = 0; s[i] != '\0'; i++) {
        t[i] = s[i];
    }
    
    // Crucial step: Explicitly terminate the destination string with a null character
    t[i] = '\0';

    // Printing the successfully copied string safely
    printf("Original: %s\n", s);
    printf("Copied:   %s\n", t);

    // Demonstration of modifying a character array (valid)
    s[0] = 'M';
    printf("Modified: %s\n", s);

    return 0;
}

/*
================================================================================
                    C PROGRAMMING STUDY NOTES: STRINGS
================================================================================

1. WHAT IS A STRING IN C?
--------------------------------------------------------------------------------
In C, a string is not a built-in primitive data type. Instead, a string is 
defined as a one-dimensional array of characters that is terminated by a special 
character called the "Null Character" ('\0'). 

The null character tells C libraries and functions (like printf) where the 
string officially ends in memory.

2. DECLARING A STRING VARIABLE
--------------------------------------------------------------------------------
Syntax:
char variable_name[size];

Example:
char s[6];

CRITICAL RULE FOR SIZE: Always make the array size at least ONE character longer 
than the actual text you want to store. If your string has 5 characters (like 
"Hello"), you must declare an array of size 6 to leave room for the '\0' character.

Failing to provide room for the null character causes unpredictable behavior, 
memory corruption, or garbage values to be printed, because C functions will keep 
reading memory past the end of your string until they happen to stumble upon a 0.

3. INITIALIZING STRINGS & MEMORY BEHAVIOR
--------------------------------------------------------------------------------
There are multiple ways to initialize a string, and the size provided yields 
different behaviors in memory:

A. Perfect Sizing (Recommended)
   char s[6] = "Hello";
   // This is exactly equivalent to:
   // char s[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   // Memory Layout: [ H ][ e ][ l ][ l ][ o ][ \0 ]

B. Short Length Initializer (Safe)
   char s[7] = "Hello";
   // If the specified size is larger than the string length + 1, C automatically 
   // fills all remaining trailing elements with '\0'.
   // Memory Layout: [ H ][ e ][ l ][ l ][ o ][ \0 ][ \0 ]

C. Equal Length Initializer (Dangerous!)
   char s[5] = "Hello";
   // The array has exactly 5 slots, so it fills them with 'H', 'e', 'l', 'l', 'o'.
   // There is NO room left for '\0'. This is no longer a valid C string; it is 
   // just a plain character array. Printing this via %s causes undefined behavior.
   // Memory Layout: [ H ][ e ][ l ][ l ][ o ]  <-- Missing \0 at the end!

D. Long Length Initializer / Overrun (Compilation Warning)
   char s[4] = "Hello";
   // The initializer string is too long for the array size. The compiler will 
   // issue a warning and truncate the string, fitting only what it can.
   // Memory Layout: [ H ][ e ][ l ][ l ]

4. MODIFYING STRINGS: CHAR ARRAYS VS POINTERS
--------------------------------------------------------------------------------
How you create your string completely changes whether you can modify its letters:

- Modifiable (Character Array):
  char s[6] = "Hello";
  s[0] = 'M'; // Valid! Changes "Hello" to "Mello". 
  // When a string literal is assigned to an array, it behaves like an ordinary 
  // array allocated on the stack, allowing its characters to be modified.

- Read-Only / Error (String Literal Pointer):
  char *ptr = "Hello";
  *ptr = 'M'; // RUNTIME ERROR / CRASH!
  // Direct pointers point straight to the read-only literal string pool in 
  // memory. Attempting to change characters here is illegal.

5. MANUAL STRING COPYING & MAINTENANCE
--------------------------------------------------------------------------------
When copying one character array to another using a loop, you must always look 
out for the null terminator:

- Loop Condition: Iterate using the condition (s[i] != '\0') so the loop stops 
  exactly when the text ends.
- Post-Loop Termination: After the loop ends, you MUST explicitly append the 
  null terminator to the target array:
  t[i] = '\0';
- Without this step, printing the destination array will output garbage data 
  following the copied characters because the system doesn't know where the 
  new string ends.
================================================================================
*/