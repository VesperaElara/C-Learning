// AI was used to refine initial code to increase readability.

#include <stdio.h>

/*

int main()
{
    int i = 1024;
    for (; i ; i>>=1) // condition (i) is a boolean (true); i>>= (same thing as) i = i >> 1
    {
        printf("Hello, world!\n");
    }
    return 0;
}

*/

int main()
{
    int i = 1024;

    /* 
       STEP 1: Initialization 
       (Only happens once when the computer first hits the loop)
    */
    for (; 
    
    /* 
       STEP 2: The Condition Check
       (Computer asks: "Is i non-zero?" BEFORE every iteration)
    */
    i ; 
    
    /* 
       STEP 4: The Update 
       (Computer jumps here ONLY AFTER Step 3 is finished)
    */
    i >>= 1) 
    {
        /* 
           STEP 3: The Body 
           (The actual work. Runs only if Step 2 was true)
        */
        printf("Hello, world!\n");

        /* 
           STEP 5: The Loopback
           (After this brace, the computer 'teleports' up to Step 4)
        */
    }

    return 0;
}

/*
initialization is already specified in line 5. So it need not be mentioned again in the for-loop.
the condition (i) is a boolean which will be true for all values but 0. (same as i > 0)
the increment part is right-shifting.
2^10 = 1024:        0100 0000 0000
2^9 = 512:          0010 0000 0000
2^8 = 256:          0001 0000 0000
2^7 = 128:          0000 1000 0000
2^6 = 64:           0000 0100 0000
2^5 = 32:           0000 0010 0000
2^4 = 16:           0000 0001 0000
2^3 = 8:            0000 0000 1000
2^2 = 4:            0000 0000 0100
2^1 = 2:            0000 0000 0010
2^0 = 1:            0000 0000 0001
0:                  0000 0000 0000 (NOT printed)
"Hello, world!" is printed 11 (i.e., 10 + 1) times.
*/

