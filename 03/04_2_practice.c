#include <stdio.h>

#include <stdio.h>

void f1(int a, int b) {
    int c;
    c = a; a = b; b = c;
}

void f2(int *a, int *b) {
    int c;
    c = *a; *a = *b; *b = c;
}

int main() {
    int a = 4, b = 5, c = 6;
    printf("Initially: a = %d , b = %d , c = %d\n", a , b , c);
    f1(a, b);
    f2(&b, &c);
    printf("Finally: a = %d , b = %d , c = %d\n", a , b , c);
    printf("c - a - b = %d - %d - %d = %d\n", c , a , b , c - a - b);
    return 0;
}

/*
==============================================================================
    STEP-BY-STEP EXECUTION TRACE
==============================================================================

1. INITIAL STATE (in main):
   a = 4,  b = 5,  c = 6

2. CALLING f1(a, b):
   - This passes COPIES of the numbers 4 and 5.
   - f1 swaps its own local copies, but main's variables are completely untouched.
   - Status remains: a = 4,  b = 5,  c = 6

3. CALLING f2(&b, &c):
   - We pass the ADDRESS of main's 'b' into pointer 'a'. (pointer a = &b)
   - We pass the ADDRESS of main's 'c' into pointer 'b'. (pointer b = &c)

   Inside f2:
   - int c;       -> Creates a brand new temporary local variable 'c'.
   
   - c = *a;      -> Look inside pointer 'a' (main's b). Read its value (5).
                    Store 5 into local 'c'. (local c is now 5)
                    
   - *a = *b;     -> Look inside pointer 'b' (main's c), which holds 6.
                    Write that 6 into pointer 'a' (main's b).
                    (main's b changes from 5 to 6)
                    
   - *b = c;      -> Take the value of local 'c' (which is 5).
                    Write it into pointer 'b' (main's c).
                    (main's c changes from 6 to 5)

4. FINAL PRINT RESULTS:
   - printf("a = %d , b = %d , c = %d\n", a , b , c); 
     Outputs: a = 4 , b = 6 , c = 5
     
   - printf("%d", c - a - b);
     Math: 5 - 4 - 6 = -5
==============================================================================
*/