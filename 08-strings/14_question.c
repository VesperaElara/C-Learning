#include <stdio.h>
#include <string.h>

int main() {
    char p[20];
    char *s = "string";
    int length = strlen(s);
    int i;
    
    for (i = 0; i < length; i++) {
        p[i] = s[length - i];
    }
    
    /* To make the program print something visible, we would need to 
       properly terminate the string and avoid copying the null terminator 
       to the very first position. For example:
       for (i = 0; i < length; i++) {
           p[i] = s[length - 1 - i];
       }
       p[length] = '\0';
    */
    
    printf("%s", p);
    
    return 0;
}

/*
===================================================================
UNDERSTANDING STRING INDEXING AND NULL TERMINATION IN C
===================================================================

1. THE PROBLEM ANALYSIS
-----------------------
Let's analyze what happens during the execution of the given loop:
* The string s is "string", which has a length of 6.
* The characters of s are indexed from 0 to 5:
  s[0] = 's'
  s[1] = 't'
  s[2] = 'r'
  s[3] = 'i'
  s[4] = 'n'
  s[5] = 'g'
  s[6] = '\0' (The invisible null terminator that marks the end 
               of a string in C)

When the loop runs for the very first time (where i = 0):
* The assignment is: p[0] = s[length - 0]
* Since length is 6, this becomes: p[0] = s[6]
* As shown above, s[6] is the null character ('\0').

Therefore, after the very first iteration, the character array 
p starts with a null terminator at index 0 (p[0] = '\0').


2. WHY "NO OUTPUT IS PRINTED" IS THE CORRECT BEHAVIOR
-----------------------------------------------------
In standard C language implementation, the printf function uses 
the "%s" format specifier to print characters sequentially from 
a character array until it encounters the null character ('\0').

Because p[0] was explicitly assigned the value '\0', printf 
looks at the first element of the array, sees the null terminator, 
and immediately stops processing. It assumes the string is empty. 
As a result, no visible characters are printed to the console screen.


3. VISUAL TRACKING OF THE LOOP ITERATIONS
-----------------------------------------
Iteration | i | Target Index (length - i) | Value Assigned to p[i]
------------------------------------------------------------------
1st       | 0 | 6                         | s[6] -> '\0'
2nd       | 1 | 5                         | s[5] -> 'g'
3rd       | 2 | 4                         | s[4] -> 'n'
4th       | 3 | 3                         | s[3] -> 'i'
5th       | 4 | 2                         | s[2] -> 'r'
6th       | 5 | 1                         | s[1] -> 't'

Even though the characters 'g', 'n', 'i', 'r', and 't' are 
successfully copied into the subsequent slots of array p, they 
remain completely hidden from printf because the null character 
at index 0 blocks the print sequence entirely.


4. KEY TAKEAWAYS FOR BEGINNER PROGRAMMERS
-----------------------------------------
* Array indexing in C is zero-based. A string of length N has valid 
  characters from index 0 to N-1.
* Index N always holds the null terminator character ('\0').
* Always ensure that your string reversal loops use an offset of 
  minus one (length - 1 - i) to correctly target the last visible 
  character of the source string.
===================================================================
*/