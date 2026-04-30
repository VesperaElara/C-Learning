/*
Bitwise operations:
Refer to: https://www.youtube.com/watch?v=jlQmeyce65Q&list=PLBlnK6fEyqRggZZgYpPMUxdY1CYkZtARR
for better understanding of truth tables.
bitwise AND: represented by "&"     >>> 1&1 gives 1, all the rest give 0.
bitwise OR: represented by "|"      >>> 0|0 gives 0, all the rest give 1.
bitwise NOT: represented by "~"     >>> Changes 1 to 0, and 0 to 1.
*/

// NOTE: Initial code written by me @DishaSrivastava27
// AI was used to reformat the code and comments for increased readability.

#include <stdio.h>

/*

 TOPIC: BITWISE VS. LOGICAL OPERATORS
 
 WHY CHAR? 
 We use 'char' (1 byte / 8 bits) instead of 'int' (4 bytes / 32 bits) 
 to make the binary math easier to visualize. 
 
 THE CORE DIFFERENCE:
 - Bitwise (&, |, ~): Operates on the individual 1s and 0s of the number.
 - Logical (&&, ||, !): Treats any non-zero number as "TRUE" (1) and zero as "FALSE" (0).

*/

int main() 
{
    // x = 0000 0001 (Decimal 1)
    // y = 0000 0010 (Decimal 2)
    char x = 1, y = 2; 

    /* --- 1. BITWISE AND (&) --- */
    /* Comparing columns:
       0000 0001 (x)
     & 0000 0010 (y)
     -----------
       0000 0000 (Result is 0)
    */
    if (x & y) 
    {
        // This block will NOT execute because the result is 0 (False).
        printf("Result of x & y is non-zero.\n"); 
    }

    /* --- 2. BITWISE NOT (~) --- */
    /* This flips EVERY bit in the container.
       Before: 0000 0000 (The result of x & y)
       After:  1111 1111 
       
       TRAP: In C, a signed container with all bits set to 1 represents -1.
       Because -1 is NOT zero, the 'if' statement sees it as 'TRUE'.
    */
    if (~(x & y)) {
        printf("BITWISE NOT: ~(x & y) = %d\n", ~(x & y)); 
        printf("Insight: Even though the result is negative, C treats it as TRUE.\n\n");
    }

    /* --- 3. LOGICAL AND (&&) --- */
    /* Here, C doesn't care about the bits. It asks:
       Is x != 0? Yes (True)
       Is y != 0? Yes (True)
       True && True = True (1)
    */
    if (x && y) {
        printf("LOGICAL AND: (x && y) = %d\n", x && y);
        printf("Insight: Logical operators always return 1 (True) or 0 (False).\n");
    }

    return 0;
}
