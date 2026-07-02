#include <stdio.h>
#include <string.h>

int main() {
    /* Example 1: Characters differ mid-string 
       "abcd" vs "abce" -> 'd' (ASCII 100) is less than 'e' (ASCII 101)
    */
    char *s1 = "abcd";
    char *s2 = "abce";

    /* Example 2: First characters differ */
    char *s3 = "abce";
    char *s4 = "bbce";

    /* Example 3: One string is a prefix of the other */
    char *s5 = "abc";
    char *s6 = "abcd";

    /* Example 4: Identical strings */
    char *s7 = "abcd";
    char *s8 = "abcd";

    printf("--- String Comparison Demonstrations ---\n");

    if (strcmp(s1, s2) < 0) {
        printf("Result 1: s1 is less than s2\n");
    } else {
        printf("Result 1: s1 is greater than or equal to s2\n");
    }

    if (strcmp(s3, s4) < 0) {
        printf("Result 2: s3 is less than s4\n");
    } else {
        printf("Result 2: s3 is greater than or equal to s4\n");
    }

    if (strcmp(s5, s6) < 0) {
        printf("Result 3: s5 is less than s6\n");
    } else {
        printf("Result 3: s5 is greater than or equal to s6\n");
    }

    if (strcmp(s7, s8) < 0) {
        printf("Result 4: s7 is less than s8\n");
    } else {
        printf("Result 4: s7 is greater than or equal to s8\n");
    }

    return 0;
}

/*
======================================================================
TECHNICAL DOCUMENTATION: THE STRCMP FUNCTION IN C
======================================================================

1. FUNCTION PROTOTYPE
----------------------------------------------------------------------
int strcmp(const char *s1, const char *s2);

The function accepts two pointers to constant character arrays 
(strings) and evaluates their lexicographical relationship.


2. RETURN VALUE MECHANICS
----------------------------------------------------------------------
The function processes characters sequentially from left to right.
It yields an integer result based on the following rules:

- Less than 0:    Returned if string s1 evaluates as lexicographically 
                  less than string s2 (s1 < s2).
- Greater than 0: Returned if string s1 evaluates as lexicographically 
                  greater than string s2 (s1 > s2).
- Equal to 0:     Returned if all corresponding characters match perfectly 
                  and both strings terminate simultaneously (s1 == s2).


3. UNDERLYING LEXICOGRAPHICAL COMPARISON CRITERIA
----------------------------------------------------------------------
The comparison relies entirely on the numerical ASCII value 
associated with each individual character. 

Condition A: Divergent Characters
The function traverses both strings character by character. 
When it finds a position i where the character in s1 does 
not equal the character in s2, it stops immediately. If the 
ASCII code of s1[i] is lower than s2[i], s1 is less than s2.

Condition B: Prefix Relationship
If every character in a shorter string s1 matches the 
corresponding character in a longer string s2, the shorter 
string is automatically considered less than the longer string. 
This occurs because the terminating null character '\0' in the 
shorter string has an ASCII value of 0, which is naturally 
smaller than any valid printing character in the longer string.


4. ASCII CHARACTER VALUE REFERENCE TABLE
----------------------------------------------------------------------
Character Group       ASCII Numerical Range    Relative Priority
----------------------------------------------------------------------
Space Character       32                       Lowest Value
Digits (0 - 9)        48 to 57                 Lower than Letters
Uppercase (A - Z)     65 to 90                 Lower than Lowercase
Lowercase (a - z)     97 to 122                Highest Value
----------------------------------------------------------------------

Practical Implications:
- Case Sensitivity: Due to the structural layout of ASCII ranges, 
  all uppercase combinations evaluate as smaller than lowercase 
  combinations. For example, "Apple" evaluates as less than "apple" 
  because 'A' (65) is less than 'a' (97).
- Whitespace Impact: A space character (32) evaluates as smaller 
  than any visible printing character, meaning "abc" evaluates 
  as greater than "abc " due to the trailing space block.
*/