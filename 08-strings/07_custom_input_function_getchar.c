#include <stdio.h>

int input(char str[], int n) 
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

int main() 
{
    char string[100];
    printf("Enter: (max. 20 characters)\n");
  
  /* 
    WHY IT WAITS FOR INPUT HERE:
    Calling input() triggers the getchar() loop inside it.
    Since you haven't typed anything yet, getchar() physically 
    freezes the program and forces it to wait for your keyboard!
  */

    int n = input(string, 20);
    printf("No. of digits: %d\nString: %s\n", n, string);
    return 0;
}

/*
  === THE UNDER-THE-HOOD KITCHEN ANALOGY ===
  • main() is the MANAGER at the front counter.
  • getchar() is the PREP COOK in the back kitchen.
  • The Input Buffer is a CONVEYOR BELT holding user keys.

  HOW IT WORKS:
  1. main() calls input(), telling the Prep Cook: "Go get a character!"
  2. The Prep Cook (getchar) looks at the conveyor belt.
  3. If the belt is empty, the Cook FREEZES and waits for the user to type.
  4. Once you type "Cat" and press Enter, 'C','a','t','\n' drop onto the belt.
  5. The Cook grabs 'C', throws it to the Manager, and deletes it from the belt.
  6. 'a', 't', and '\n' stay waiting on the belt for the next loop!
*/

/*

getchar() function is used to read one character at a time from the user input.
It returns an integer equivalent to the ASCII code of the character.

DEFINITION: getchar() reads exactly ONE character from what the user typed.
It removes that character from the input queue forever and returns its ASCII code.
If the user types a whole word, it only grabs the very first letter left in line.

================================================================================
          C PROGRAMMING LESSON: DESIGNING A SECURE CUSTOM INPUT FUNCTION
================================================================================

1. THE PROBLEM WITH STANDARD INPUT FUNCTIONS
--------------------------------------------------------------------------------
Standard C functions like scanf() and gets() have inherent risks and limitations
when reading string inputs:
* gets(): Does not check the boundary of the destination array. If the user 
  inputs more characters than the buffer can hold, it causes a Buffer Overflow, 
  which can crash the program or create severe security vulnerabilities.
* scanf(): By default, stops reading as soon as it encounters any whitespace 
  character (like a space or a tab). This makes it difficult to read multi-word 
  sentences comfortably.

To solve these issues, we can design a custom input function using getchar().


2. REQUIREMENTS FOR THE CUSTOM INPUT FUNCTION
--------------------------------------------------------------------------------
Our custom function, input(), is designed with the following behaviors:
* Continuous Reading: It keeps reading characters even after encountering spaces.
* Newline Termination: It stops reading immediately when the user presses Enter 
  (the newline character '\n').
* Bound Checking & Discarding: It accepts a maximum limit 'n' for storage. Any 
  extra characters entered beyond 'n' are safely read and discarded from the 
  input buffer, preventing them from bleeding into subsequent inputs.
* Return Value: It returns the total number of valid characters successfully 
  stored inside the character array.


3. BEHIND THE SCENES: MEMORY TRACE & EXECUTION
--------------------------------------------------------------------------------
Let's trace what happens when we call: input(str, 5);
With the user input: "Hello, How are you?"

Initial State:
* The array 'str' starts at memory location 1000.
* Variable 'i' (index tracker) is initialized to 0.
* Variable 'n' (maximum size allowed to copy) is set to 5.

Step-by-Step Character Processing Loop:
+------+-----------+---------+--------------------+----------------+
| Loop | Character |  Is it  | Condition (i < n)? | Action Taken   |
| Iter | Read (ch) |  '\n'?  |   (Is 0/1/2.. < 5) |                |
+------+-----------+---------+--------------------+----------------+
| 1st  |    'H'    |   No    |    0 < 5 (True)    | str[0] = 'H'   |
| 2nd  |    'e'    |   No    |    1 < 5 (True)    | str[1] = 'e'   |
| 3rd  |    'l'    |   No    |    2 < 5 (True)    | str[2] = 'l'   |
| 4th  |    'l'    |   No    |    3 < 5 (True)    | str[3] = 'l'   |
| 5th  |    'o'    |   No    |    4 < 5 (True)    | str[4] = 'o'   |
| 6th  |    ','    |   No    |    5 < 5 (False)   | Discarded      |
| 7th  |    ' '    |   No    |    6 < 5 (False)   | Discarded      |
| ...  |  (etc.)   |   No    |    ...             | Discarded      |
+------+-----------+---------+--------------------+----------------+

Loop Termination:
* The loop continues discarding characters until it reads '\n'.
* Once ch == '\n', the loop breaks.

Finalizing the String:
* After the loop, str[i] = '\0'; is executed. Since 'i' incremented up to 5 
  during the first 5 successful iterations, str[5] is assigned the null 
  terminator '\0'.
* The function returns i (which is 5).

Final Output printed by main():
No. of digits: 5
String: Hello
================================================================================
*/