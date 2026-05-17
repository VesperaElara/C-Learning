#include <stdio.h>

// ============================================================================
// HOW STATIC AND POST-DECREMENT WORK HERE:
// 1. "static int num = 16;" -> This line runs ONLY ONCE at the very start.
//    'num' stays alive and remembers its changes across all function calls.
// 2. "return num--;" -> Returns the CURRENT value first, THEN subtracts 1.
// ============================================================================
int fun() {
    static int num = 16;
    return num--; // Return current value, then decrement num by 1
}

int main() {
    // ------------------------------------------------------------------------
    // THE FOR-LOOP ORDER: 
    // for ( INITIALIZATION ; CONDITION ; UPDATE ) { BODY }
    // ------------------------------------------------------------------------
    
    // ITERATION 1:
    // - Init: fun() returns 16. (num becomes 15)
    // - Condition: fun() returns 15 (True, since it's not 0). (num becomes 14)
    // - Body: printf prints fun() which returns 14. (num becomes 13) -> PRINTS 14
    // - Update: fun() returns 13. (num becomes 12)

    // ITERATION 2:
    // - Condition: fun() returns 12 (True). (num becomes 11)
    // - Body: printf prints fun() which returns 11. (num becomes 10) -> PRINTS 11
    // - Update: fun() returns 10. (num becomes 9)

    // ITERATION 3:
    // - Condition: fun() returns 9 (True). (num becomes 8)
    // - Body: printf prints fun() which returns 8. (num becomes 7)  -> PRINTS 8
    // - Update: fun() returns 7. (num becomes 6)

    // ITERATION 4:
    // - Condition: fun() returns 6 (True). (num becomes 5)
    // - Body: printf prints fun() which returns 5. (num becomes 4)  -> PRINTS 5
    // - Update: fun() returns 4. (num becomes 3)

    // ITERATION 5:
    // - Condition: fun() returns 3 (True). (num becomes 2)
    // - Body: printf prints fun() which returns 2. (num becomes 1)  -> PRINTS 2
    // - Update: fun() returns 1. (num becomes 0)

    // ITERATION 6:
    // - Condition: fun() returns 0 (FALSE!). Loop stops immediately.
    // - (num becomes -1, but the loop body never runs again)

    for(fun(); fun(); fun()) {
        printf("%d ", fun());
    }

    return 0;
}
