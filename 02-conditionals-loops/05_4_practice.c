#include <stdio.h>

int main()
{
    int i = 0;

    /* 
     * THE PRINTF TRUTH-TEST TRAP
     * --------------------------
     * This loop only prints "One" and then terminates. Here is why:
     * 
     * 1. THE CONDITION: i < 3 && printf("")
     *    In C, a loop continues if the condition is non-zero (TRUE).
     * 
     * 2. THE RETURN VALUE: 
     *    The printf() function returns the NUMBER OF CHARACTERS printed.
     *    - printf("S")  returns 1 (True)
     *    - printf("Hi") returns 2 (True)
     *    - printf("")   returns 0 (FALSE)
     * 
     * 3. THE LOGIC GATE:
     *    (i < 3) is 1 (True).
     *    printf("") is 0 (False).
     *    (True && False) results in 0.
     * 
     * RESULT: The loop condition fails on the very first attempt, 
     * so "Hi" is never printed.
     */

    for (printf("One\n"); i < 3 && printf(""); i++)
    {
        printf("Hi\n");
    }

    return 0;
}
