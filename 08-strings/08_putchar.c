#include <stdio.h>

int main() 
{
    int ch;
    
    // Loop from ASCII value of 'A' (65) to 'Z' (90)
    for (ch = 'A'; ch <= 'Z'; ch++) {
        putchar(ch);
    }
    
    putchar('\n'); // Print a newline character at the end
    return 0;
}

/*
================================================================================
                    C PROGRAMMING LESSON: THE putchar() FUNCTION
================================================================================

1. OVERVIEW AND FUNCTION PROTOTYPE
--------------------------------------------------------------------------------
The putchar() function is a standard library function in C used to write a single 
character to the standard output screen. It is declared in the <stdio.h> header.

Prototype:
    int putchar(int ch);

Parameters:
* ch: The character to be written. It is passed as an integer representing its 
  ASCII/binary character value.

Return Value:
* On success, it returns the integer representation of the character written.
* On failure, it returns EOF (End of File).


2. WHY DOES putchar() ACCEPT AN int INSTEAD OF A char?
--------------------------------------------------------------------------------
A common point of confusion for beginners is why the function prototype reads 
"int ch" instead of "char ch". 

* Internal Representation: In computer memory, characters are internally 
  represented entirely in binary form as integer codes (ASCII values). For 
  example, the character 'A' is stored as the integer 65, and 'Z' is stored 
  as 90.
* No Difference in Practice: Because C treats characters as small integers, it 
  makes no difference to the compiler whether the parameter is written as 
  "int ch" or "char ch". Passing a char directly into putchar() is safe because 
  it gets automatically promoted to an int.


3. CODE ANALYSIS & EXECUTION TRACE
--------------------------------------------------------------------------------
Let's trace how the program loops through and displays characters sequentially:

Initialization:
* The variable 'ch' is declared as an integer.
* The loop starts by assigning ch = 'A' (which corresponds to ASCII 65).

Execution Loop Table:
+------+------------+------------------+----------------+---------------+
| Loop | Expression | Current Value of | Condition Met? | Output        |
| Iter | Evaluation | Variable 'ch'    | (ch <= 'Z'?)   | Displayed     |
+------+------------+------------------+----------------+---------------+
| 1st  |  ch = 'A'  |       65         | 65 <= 90 (Yes) | A             |
| 2nd  |  ch++      |       66         | 66 <= 90 (Yes) | B             |
| 3rd  |  ch++      |       67         | 67 <= 90 (Yes) | C             |
| ...  |  ...       |       ...        | ...            | ...           |
| 26th |  ch++      |       90         | 90 <= 90 (Yes) | Z             |
| 27th |  ch++      |       91         | 91 <= 90 (No)  | Loop Ends     |
+------+------------+------------------+----------------+---------------+

Final Output:
ABCDEFGHIJKLMNOPQRSTUVWXYZ

================================================================================
*/