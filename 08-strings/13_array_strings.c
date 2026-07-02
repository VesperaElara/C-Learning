#include <stdio.h>
#include <string.h>

int main() {
    /* Defining an array of string pointers */
    char *fruits[] = {
        "2 Oranges", 
        "2 Apples", 
        "3 Bananas", 
        "1 Pineapple"
    };

    /* Comparing fruits[1] ("2 Apples") and fruits[2] ("3 Bananas").
       The first characters differ: '2' (ASCII 50) vs '3' (ASCII 51).
       Since 50 < 51, fruits[1] is less than fruits[2].
    */
    if (strcmp(fruits[1], fruits[2]) < 0) {
        printf("%s are lesser than %s\n", fruits[1], fruits[2]);
    } else if (strcmp(fruits[1], fruits[2]) > 0) {
        printf("%s are greater than %s\n", fruits[1], fruits[2]);
    }

    return 0;
}

/*
======================================================================
TECHNICAL DOCUMENTATION: TWO-DIMENSIONAL ARRAYS VS. ARRAYS OF POINTERS
======================================================================

1. TWO-DIMENSIONAL CHARACTER ARRAYS (FIXED ALLOCATION)
----------------------------------------------------------------------
A two-dimensional char array allocates a rigid, rectangular block 
of memory. Every row must have the exact same capacity.

Syntax Example:
char fruits[][12] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};

Memory Layout Visualization:
-----------------------------------------------------------------
Index | Col 0 | Col 1 | Col 2 | Col 3 | ... | Col 9 | Col 10 | Col 11
-----------------------------------------------------------------
Row 0 |   2   |  ' '  |   O   |   r   | ... |  \0   |   \0   |   \0
Row 1 |   2   |  ' '  |   A   |   p   | ... |  \0   |   \0   |   \0
Row 2 |   3   |  ' '  |   B   |   a   | ... |  \0   |   \0   |   \0
Row 3 |   1   |  ' '  |   P   |   i   | ... |   l   |    e   |   \0
-----------------------------------------------------------------

Key Attributes:
- Total memory is determined by (Number of Rows) times (Fixed Columns).
- Short strings leave unused trailing space padded with null bytes (\0).
- This approach introduces memory fragmentation and internal waste if 
  string lengths vary dramatically.


2. ARRAY OF CHAR POINTERS (RAGGED ALLOCATION)
----------------------------------------------------------------------
An array of pointers stores memory addresses instead of the string 
data directly. Each pointer references a string literal stored 
independently elsewhere in memory.

Syntax Example:
char *fruits[] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};

Memory Layout Visualization:
---------------------------------------------------------
Array Index | Pointer Value ----> Actual String literal
---------------------------------------------------------
fruits[0]   | Address A   ----> "2 Oranges\0"  (10 bytes)
fruits[1]   | Address B   ----> "2 Apples\0"   (9 bytes)
fruits[2]   | Address C   ----> "3 Bananas\0"  (10 bytes)
fruits[3]   | Address D   ----> "1 Pineapple\0"(12 bytes)
---------------------------------------------------------

Key Attributes:
- Each string consumes only the exact bytes required including \0.
- No memory is wasted on empty padding columns.
- Often termed a ragged array because the underlying rows possess 
  varying, non-uniform byte dimensions.


3. STRING COMPARISON MECHANICS (PROGRAM ANALYSIS)
----------------------------------------------------------------------
The strcmp function evaluates strings character by character based 
on their integer ASCII encodings.

Program Trace:
- Element 1 (fruits[1]) resolves to the text block "2 Apples".
- Element 2 (fruits[2]) resolves to the text block "3 Bananas".
- Index 0 Comparison: The routine checks the first character of 
  both targets, contrasting '2' against '3'.
- ASCII Reference: Character '2' has an ASCII code of 50. 
  Character '3' has an ASCII code of 51.
- Because 50 is less than 51, evaluation terminates instantly.

Program Output:
2 Apples are lesser than 3 Bananas
*/