#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 20; i++)
    {
        switch(i)
        {
            case 0: i+=5;
            case 1: i+=2;
            case 5: i+=5;
            default: i+=4;
        }
        printf("%d ", i);
    }
    printf("\n");
}

// The OUTPUT is NOT: 5 10 15 20 
// This is because there is no "break" after each case!
// DON'T fall for this!
// Retry with break, and then you'll get the output: 5 10 15 20

/* 
 * CONCEPTUAL BREAKDOWN: THE FALL-THROUGH EFFECT
 * --------------------------------------------
 * A 'switch' is a JUMP TABLE, not an IF-ELSE chain.
 * 
 * 1. INITIAL ENTRY:
 *    i = 0. switch(0) jumps to 'case 0'.
 * 
 * 2. THE MOMENTUM (No 'break' statements):
 *    [Entry] case 0: i += 5  (i is now 5)
 *      |     case 1: i += 2  (i is now 7)  <-- No check performed here!
 *      |     case 5: i += 5  (i is now 12) <-- No check performed here!
 *      V     default: i += 4 (i is now 16) <-- No check performed here!
 * 
 * 3. RESULT:
 *    The program executes EVERY statement sequentially after the first match.
 *    i becomes 16, then prints "16 ".
 * 
 * 4. SECOND ITERATION:
 *    Loop increment (i++) makes i = 17.
 *    switch(17) finds no matching case -> jumps to 'default'.
 *    i += 4 makes i = 21, then prints "21 ".
 * 
 * 5. TERMINATION:
 *    i++ makes i = 22. Loop condition (22 < 20) is now FALSE.
 */

