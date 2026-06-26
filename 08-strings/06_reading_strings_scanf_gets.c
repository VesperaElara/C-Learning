#include <stdio.h>

int main() {
    char a[10];

    // 1. Safe implementation using scanf() with a width-limit specifier (%9s)
    // This protects against buffer overflows by reading at most 9 characters,
    // leaving 1 slot free for the null terminator ('\0').
    printf("Enter a string (scanf bound test): ");
    scanf("%9s", a);
    printf("Stored string in a: %s\n", a);

    return 0;
}

/*
================================================================================
                    C PROGRAMMING STUDY NOTES: READING STRINGS
================================================================================

1. READING STRINGS USING scanf()
--------------------------------------------------------------------------------
The scanf() function can read a sequence of characters from standard input and 
store them into a destination character array using the "%s" format specifier.

Syntax:
scanf("%s", a);

- Omission of the Address-Of Operator (&): Like any array identifier name, the 
  variable 'a' automatically degrades into a pointer pointing to the first 
  element of the character array. Therefore, an explicit '&' symbol is NOT 
  required inside the scanf call.

- The White-Space Limitation: 
  The standard "%s" specifier instructs scanf() to skip initial whitespace, read 
  non-whitespace characters, and terminate processing the moment it encounters 
  any whitespace element (spaces, tabs, newlines).
  
  Example: If the user inputs "You are most welcome", scanf("%s", a) reads only 
  the string "You" and stops processing right there. The remaining part of the 
  input string stays in the standard input buffer.

2. THE RISK OF BUFFER OVERFLOWS (scanf vs gets)
--------------------------------------------------------------------------------
Both a basic scanf("%s", a) execution and the alternative gets(a) standard 
function suffer from a fundamental architectural flaw: lack of bounds checking.

- Buffer Overflow Vulnerability: Neither function natively stops processing once 
  the target character array becomes full. If an array is declared with 10 slots, 
  and the input stream feeds 15 characters, these functions will write data past 
  the array boundaries.
- Consequences: This overwrites neighboring segments of stack memory, leading to 
  unpredictable runtime bugs, memory corruption, vulnerabilities, or immediate 
  program crashes.

3. UNDERSTANDING THE UNCONSTRAINED gets() FUNCTION
--------------------------------------------------------------------------------
The gets() function was originally designed to resolve the whitespace truncation 
issue of scanf() by reading an entire line of input text until it encounters a 
newline character ('\n').

Syntax:
gets(a);

- The Unsafe Nature of gets(): 
  Because gets() has absolutely no interface parameter to enforce a limit on the 
  number of incoming characters, it will systematically write beyond allocated 
  memory buffers if given an input line longer than the array capacity.
- Modern Status: It is considered critically UNSAFE and is obsolete in modern 
  software development frameworks. Its use is strongly discouraged.

4. THE MITIGATION STRATEGY: FIELD-WIDTH SPECIFIERS
--------------------------------------------------------------------------------
To read string inputs securely using scanf without risking buffer overruns, you 
can append a numeric field-width modifier directly inside the format specifier.

Syntax:
scanf("%ns", a); // Where 'n' is a positive integer constant

- Operational Behavior: The integer 'n' sets a strict limit on the maximum number 
  of text characters allowed to be copied from the input buffer.
- Choosing the Correct Size Constraint: To safely store a string inside an array 
  of size X, set your field limit explicitly to (X - 1). This ensures that the 
  remaining final slot is preserved exclusively to house the null terminator ('\0').

  Example:
  char a[10];
  scanf("%9s", a);
  
  If the input string "Youaremostwelcome" is submitted, scanf will cleanly copy 
  the first 9 characters ("Youaremos") into the array, append a terminal '\0' into 
  index 9, and return safely without overflowing memory boundaries.
================================================================================
*/