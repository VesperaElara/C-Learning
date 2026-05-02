/*

Logical Operators in C: 
&& (and) 
|| (or)
! (not)

0 is used to represent false.
1 is usually used to represent true.
All non-zero numbers, string literals, etc. are "true."

Short Circuit:

&&: If the first condition is false, the subsequent conditions are ignored and 
    "false (0)" is returned immediately.

||: If the first condition is true, the subsequent conditions are ignored and 
    "true (1)" is returned immediately.

*/

// NOTE: Initial code written by me @DishaSrivastava27
// AI was used to reformat the code and comments for increased readability.

/*
 REFINEMENT: Structure refined to isolate "Result" vs "Memory State" 
 to demystify Post-increment behavior in logical expressions.
 CONCEPT: Post-increment is "Read Now, Pay Later."

 
*/

#include <stdio.h>

int main ()
{
    // --- CASE 1: The AND Short-Circuit ---
    int a = 7; int b = 13;
    int condition;

    /* Logic: (a >= b) is (7 >= 13) which is 0 (FALSE).
       Because the first part is 0, '&&' STOPS immediately. 
       The expression (b++) is NEVER executed. */
    condition = (a >= b) && (b++); 
    
    printf("CASE 1 - Result: %d (False)\n", condition);
    printf("CASE 1 - b state: %d (Remains 13 because of short-circuit)\n\n", b);


    // --- CASE 2: Post-Increment vs. Logic ---
    int c = -1; int d = 13;
    int condition1;

    /* Logic: (c++) is Post-increment. 
       1. READ: It returns the current value: -1.
       2. EVALUATE: -1 is non-zero, so it's TRUE.
       3. CONTINUE: Since it's TRUE, the '&&' must check the next part (d++).
       4. UPDATE: After the line finishes, 'c' finally becomes 0. */
    condition1 = (c++) && (d++); 
    
    printf("CASE 2 - Result: %d (True, because -1 and 13 are non-zero)\n", condition1);
    printf("CASE 2 - Memory: c is now %d, d is now %d\n\n", c, d);


    // --- CASE 3: Pre-Increment vs. Logic ---
    int e = -1; int f = 13;
    int condition2;

    /* Logic: (++e) is Pre-increment.
       1. UPDATE: 'e' becomes 0 IMMEDIATELY.
       2. READ: It returns the new value: 0.
       3. EVALUATE: 0 is FALSE.
       4. SHORT-CIRCUIT: The '&&' stops here. (f++) is NEVER touched. */
    condition2 = (++e) && (f++); 

    printf("CASE 3 - Result: %d (False, because ++e resulted in 0)\n", condition2);
    printf("CASE 3 - Memory: e is now %d, f is still %d\n", e, f);

    return 0;
}