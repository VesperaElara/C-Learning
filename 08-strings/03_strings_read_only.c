#include <stdio.h>

int main() {
    /* 1. Assigning a string literal to a character pointer.
          The pointer 'ptr' stores the address of the first character ('H').
    */
    char *ptr = "Hello";

    /* 2. Direct string literal subscripting vs pointer subscripting.
          Both resolve to individual characters via pointer arithmetic.
    */
    printf("Using pointer subscripting ptr[1]: %c\n", ptr[1]);
    printf("Using direct literal subscripting \"Hello\"[1]: %c\n", "Hello"[1]);

    /* 3. The pointer itself can be updated to point to a new string literal 
          because the pointer variable resides in read-write memory.
    */
    ptr = "World";
    printf("Updated pointer target: %s\n", ptr);

    /* CRITICAL WARNING:
       The following operation is commented out because it causes UNDEFINED BEHAVIOR.
       String literals are stored in read-only memory.

       *ptr = 'M'; 
    */

    return 0;
}

/*
===============================================================================
                 ASSIGNING STRING LITERALS TO POINTERS IN C
===============================================================================

1. Pointer Assignment Mechanics
-------------------------------------------------------------------------------
When you write an assignment statement like:
    char *ptr = "Hello World!";

The compiler does not copy the text string into the variable 'ptr'. Instead, 
remembering that C treats string literals as a pointer to their first element, 
the variable 'ptr' simply receives and holds the memory address of the first 
character (the letter 'H').


2. Direct String Literal Subscripting (Pointer Arithmetic)
-------------------------------------------------------------------------------
Because a string literal resolves directly to a pointer value, you can apply 
array subscript brackets [] directly to the literal itself!

For example: "Hello"[1]

Behind the scenes, the compiler converts array subscripting into pointer 
arithmetic according to the standard rule:
    array[i]  ==>  *(array + i)

Let's trace how "Hello"[1] evaluates assuming "Hello" starts at memory 
address 1000:

    "Hello"[1] ==> *(Pointer to 'H' + 1)
               ==> *(1000 + 1)
               ==> *(1001)
               ==> 'e'

Similarly:
* "Hello"[0] => 'H'
* "Hello"[2] => 'l'
* "Hello"[3] => 'l'
* "Hello"[4] => 'o'


3. Read-Only Memory vs Read-Write Memory
-------------------------------------------------------------------------------
Understanding where things are stored in memory prevents critical runtime 
faults:

A. String Literals (String Constants):
   * Allocated inside a Read-Only section of memory.
   * You CANNOT alter individual characters inside a literal.
   * Attempting to modify them (e.g., *ptr = 'M'; or ptr[0] = 'M';) results 
     in Undefined Behavior (typically a Segmentation Fault crash).

B. The Character Pointer Variable:
   * Allocated inside normal Read-Write memory.
   * While you cannot alter the characters it currently points to, you CAN 
     change the pointer itself to look at an entirely different string literal 
     later on (e.g., changing ptr from "Hello" to "World").
===============================================================================
*/