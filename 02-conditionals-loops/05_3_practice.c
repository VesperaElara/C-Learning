#include <stdio.h>

int main() {
    unsigned int i = 500;

    // The semicolon at the end is a "null statement."
    // It tells the computer: "Do nothing inside this loop; just keep checking the condition."
    while(i++ != 0); 
    
    // If i was 0 during the final check, 
    // it is already 1 by the time it hits this line.
    printf("%d", i);

    return 0;
}

// You will notice the code takes 1-2 seconds before giving the result.

/*
FULL EXPLANATION:

1. THE NULL STATEMENT (The Semicolon):
   The ';' immediately after the while condition means the loop has no 
   body. It just cycles through the condition over and over until it 
   fails. Without that semicolon, the 'printf' would be part of the 
   loop and would try to print 4 billion times!

2. INCREMENT TIMING (The 'i++'):
   This is a post-increment. The logic follows this sequence:
   - EVALUATE: Compare 'i' to 0 for the 'while' condition.
   - INCREMENT: Immediately add 1 to 'i', regardless of whether the 
     comparison was true or false.
   - EXECUTE: Since the check happens BEFORE the increment, if i was 500 
     during the check, it is already 501 before the loop even repeats.

3. THE WRAP-AROUND (Overflow):
   'i' starts at 500 and counts up. Because it is 'unsigned', once it 
   hits the maximum possible value (4,294,967,295), adding 1 more 
   forces it to "wrap around" back to 0.

4. THE EXIT SEQUENCE:
   - Eventually, 'i' becomes 0.
   - The loop checks: "Does i (0) != 0?" -> This is FALSE.
   - HOWEVER, because it's 'i++', the computer still adds 1 to 'i' 
     immediately after that check.
   - The loop stops, and 'i' is now 1.

5. FINAL OUTPUT:
   The program moves to 'printf' and prints "1".
*/
