#include <stdio.h>

int main(void) {
    char c[] = "GATE2011";
    char *p = c;
    printf("%s\n", p + p[3] - p[1]);
    return 0;
}

/*
=========================================================
ANALYSIS OF POINTER ARITHMETIC WITH CHARACTERS
=========================================================

1. Array and Pointer Initialization:
   The character array c is initialized with the string 
   "GATE2011". A character pointer p is set to point 
   to the beginning of this array (index 0).

   Index and Character Mapping:
   c[0] = 'G'
   c[1] = 'A'
   c[2] = 'T'
   c[3] = 'E'
   c[4] = '2'
   c[5] = '0'
   c[6] = '1'
   c[7] = '1'

2. Evaluating the Pointer Expression:
   The printf statement uses the format specifier %s 
   and evaluates the pointer expression: p + p[3] - p[1]

   In C, character literals and elements in a character 
   array are treated as their integer ASCII values when 
   used in arithmetic expressions.

   Let us look at the individual array elements:
   p[3] corresponds to the character 'E'
   p[1] corresponds to the character 'A'

   Therefore, the expression p[3] - p[1] is equivalent 
   to the subtraction of their ASCII values:
   'E' - 'A' = 69 - 65 = 4

3. Final Pointer Resolution:
   Substituting this difference back into the expression:
   p + 4

   Since p points to the start of the array (index 0), 
   adding 4 to the pointer offsets it by 4 elements. 
   This means the resulting pointer points to index 4, 
   which contains the character '2'.

4. Program Output:
   The %s format specifier prints characters starting 
   from the memory address given by the pointer until 
   it encounters the null terminator. 

   Starting from index 4, the remaining string is 
   "2011". Thus, the final output printed by the 
   program matches option (c): 2011.
*/