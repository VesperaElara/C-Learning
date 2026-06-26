#include <stdio.h>
#include <string.h>

int main() {
    char source[10] = "Hello";
    char destination[10];

    // Using strcpy to copy source into destination
    strcpy(destination, source);

    // Demonstration of returning pointer
    printf("Result from strcpy return: %s\n", strcpy(destination, source));
    printf("Value in destination: %s\n", destination);

    return 0;
}

/*
TOPIC: THE C STRING COPY FUNCTION (strcpy)

OVERVIEW
In C, strings are represented as arrays of characters terminated 
by a null character (\0). Because C arrays do not support direct 
assignment (e.g., str1 = str2 is invalid), the <string.h> library 
provides the strcpy function to perform string copying.

FUNCTION PROTOTYPE
char* strcpy(char* destination, const char* source);

PARAMETERS
1. destination: A pointer to the destination character array where 
   the content is to be copied. It must be large enough to hold 
   the source string and the null terminator.
2. source: A pointer to the null-terminated string to be copied. 
   The 'const' qualifier ensures the source string is not modified.

KEY BEHAVIOR
- Copies the entire string from source to destination, including 
  the null terminator (\0).
- Returns a pointer to the destination string, allowing for 
  chaining or direct usage within other functions.

MEMORY SAFETY WARNING
- strcpy does not check if the destination array has enough space.
- If the source string is larger than the destination, a buffer 
  overflow occurs. Always ensure sufficient buffer size or use 
  strncpy for safer operations.

ASCII ILLUSTRATION OF MEMORY
+---------------------------------------+
| Index | 0 | 1 | 2 | 3 | 4 | 5 |
+---------------------------------------+
| Char  | H | e | l | l | o | \0|
+---------------------------------------+
Copying proceeds character by character until \0 is reached.
*/