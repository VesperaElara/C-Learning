#include <stdio.h>
#include <string.h>

int main() {
    // Example 1: Safe usage of strncat
    char str1[5] = "";
    char str2[100] = "";

    strcpy(str1, "He");
    strcpy(str2, "llo!");

    // Dynamically calculate the maximum remaining space
    // to prevent buffer overflow and reserve 1 byte for '\0'
    strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);

    printf("Result: %s\n", str1);

    return 0;
}

/*
======================================================================
C STRING CONCATENATION GUIDE: STRCAT VS STRNCAT
======================================================================

1. THE STRCAT FUNCTION
----------------------------------------------------------------------
The strcat function is used to append the content of a source string 
onto the end of a destination string.

Prototype:
char* strcat(char* destination, const char* source);

How it works:
- It finds the null terminator ('\0') of the destination string.
- It begins copying characters from the source string starting at 
  that position.
- It automatically appends a new null terminator at the end of the 
  combined string.
- It returns a pointer to the resulting destination string.


2. THE DANGER OF STRCAT (UNDEFINED BEHAVIOR)
----------------------------------------------------------------------
A major flaw of strcat is that it does not check if the destination 
array is large enough to hold the new characters. If the combined 
length of the strings exceeds the allocated size of the destination 
array, a buffer overflow occurs. 

This leads to memory corruption and undefined behavior, which means 
the program might crash, produce incorrect outputs, or create critical 
security vulnerabilities.


3. THE SAFER ALTERNATIVE: STRNCAT
----------------------------------------------------------------------
To prevent buffer overflows, the strncat function should be used. It 
allows you to specify the maximum number of characters to copy from 
the source string.

Prototype:
char* strncat(char* destination, const char* source, size_t n);

The third parameter 'n' limits how many bytes can be appended.


4. SAFE SPACE CALCULATION FORMULA
----------------------------------------------------------------------
To absolutely guarantee that you never overflow your destination 
buffer, you must calculate 'n' dynamically using this formula:

n = sizeof(destination) - strlen(destination) - 1

Explanation of terms:
- sizeof(destination): Total memory size allocated for the array.
- strlen(destination): The current number of characters already stored.
- minus 1: Preserves exactly 1 byte for the mandatory null character.

By limiting the copy operation to this calculated value, strncat will 
safely truncate the input string if it is too long, always leaving 
the destination string properly null-terminated.
======================================================================
*/