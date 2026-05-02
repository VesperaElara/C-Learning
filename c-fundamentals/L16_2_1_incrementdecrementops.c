// NOTE: Initial code written by me, Disha (@VesperaElara)
// AI was used to reformat the code and comments for increased readability.

#include <stdio.h>

int main()
{
    // --- SECTION 1: The Lvalue vs. Rvalue Rule ---
    // Increment/Decrement operators require a modifiable "lvalue" (a memory container).
    int i = 5; 
    i++; // VALID: 'i' is a variable with a persistent address.
    
    int a = 2, b = 3;
    // (a + b)++; // INVALID: (a + b) results in an "rvalue" (a temporary result).
    // You cannot increment a temporary result because it has no "home" in memory to store the update.

    // --- SECTION 2: Isolated Pre-Increment Example ---
    int k = 3;
    int x = ++k; 
    /* Logic: PRE-increment (++k)
       1. k becomes 4 (Incremented first)
       2. x becomes 4 (Value assigned second)
    */
    printf("Pre-increment: (x = ++k) k is now %d, x captured %d\n", k, x);

    // --- SECTION 3: Isolated Post-Increment Example ---
    int l = 3;
    int y = l++; 
    /* Logic: POST-increment (l++)
       1. y becomes 3 (Current value assigned first)
       2. l becomes 4 (Incremented second - after the assignment 'sequence point')
    */
    printf("Post-increment: (y = l++) l is now %d, y captured %d\n", l, y);

    return 0;
}