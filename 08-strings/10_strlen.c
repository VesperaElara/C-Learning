#include <stdio.h>
#include <string.h>

int main(void) {
    /* Example 1: Pointer to a string literal */
    const char *str1 = "Hello World";
    
    /* Example 2: Character array with explicit size */
    char str2[100] = "Hello World!";
    
    /* Printing lengths using strlen() */
    printf("Length of str1: %zu\n", strlen(str1));
    printf("Length of str2: %zu\n", strlen(str2));
    
    return 0;
}

/*
======================================================================
THE STRLEN (STRING LENGTH) FUNCTION IN C
======================================================================

The strlen function is a built-in standard library function in C
used to determine the number of characters in a given string.
It is declared inside the <string.h> header file.

--- FUNCTION PROTOTYPE ---

size_t strlen(const char *str);

* size_t: The return type of the function. It is an unsigned
  integer type (usually at least 16 bits) that represents sizes 
  and counts. When printing size_t with printf, the %zu format
  specifier should be used.
* const char *str: The parameter passed to the function, which
  is a pointer to the first character of the string whose length 
  you want to find. The const keyword ensures that the function
  does not modify the original string.

--- KEY OPERATIONAL RULES ---

1. Excludes the Null Terminator:
   In C, strings are null-terminated, meaning they end with a 
   special null character written as '\0'. The strlen function 
   counts characters by moving sequentially from the first memory
   address until it hits this null terminator. The '\0' character 
   itself is NOT counted in the returned length. For example, 
   the string "Hello World" contains 11 visible characters 
   including the space. Even though it occupies 12 bytes in memory 
   due to the trailing '\0', strlen returns exactly 11.

2. String Length vs. Array Capacity:
   When a string is stored inside a large character array, such 
   as char str[100] = "Hello World";, strlen calculates only 
   the length of the valid string data stored within it. It does 
   not return the total allocated size of the array (100). To 
   find the total memory size allocated for an array, the sizeof 
   operator must be used instead.

--- MEMORY VISUALIZATION ---

For char str[100] = "Hello World";

Index:   0   1   2   3   4   5   6   7   8   9   10  11   12 ... 99
Char:  ['H'|'e'|'l'|'l'|'o'|' '|'W'|'o'|'r'|'l'|'d'|'\0'| ? |...| ? ]
        ^                                           ^
        |------- counted by strlen = 11 ------------|

======================================================================
*/