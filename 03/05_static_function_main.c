#include <stdio.h>

// FUNCTION PROTOTYPE:
// For functions, the 'extern' keyword is implicitly assumed by default.
// Writing 'int add(int, int);' is identical to 'extern int add(int, int);'.
int add(int, int); 

int main()
{
    int x = 5, y = 8;
    printf("%d + %d = %d\n", x, y, add(x, y));
}

/*
========================================================================
CROSS-FILE DECLARATION RULES: VARIABLES VS. FUNCTIONS
========================================================================
When sharing resources across different source files, C treats variables 
and functions differently:

1. FOR FUNCTIONS: 'extern' is IMPLICIT
   * A standard function prototype tells the compiler: "This function exists 
     somewhere; trust me, the linker will find its definition later."
   * Omitting 'extern' is standard, clean C practice.

2. FOR VARIABLES: 'extern' is MANDATORY
   * Unlike functions, if you omit 'extern' for a global variable declaration 
     (e.g., writing 'int count;' instead of 'extern int count;'), the compiler 
     attempts to allocate brand-new memory for it.
   * Leaving out 'extern' on a variable across files will cause a linker crash 
     due to "multiple definition" errors.
========================================================================
*/

/*

type in terminal:
gcc 05.c 05_1.c -o 05
./05

*/