#include <stdio.h>

int main() {
    /* Method 1: Line Splicing using a Backslash 
       Note: The indentation spaces on the second line will be printed.
    */
    printf("%s\n", "You have to dream before your dreams can come true. \
    --A.P.J. Abdul Kalam");

    /* Method 2: Adjacent String Literal Concatenation
       Note: This avoids the indentation issue completely.
    */
    printf("%s\n", "You have to dream before your dreams can come true. "
    "--A.P.J. Abdul Kalam");

    return 0;
}

/*
===============================================================================
                       CONTINUING STRING LITERALS IN C
===============================================================================

When a string literal is too long to fit comfortably on a single line of code, 
splitting a standard string across lines without special syntax will cause a 
compile-time error. C provides two main ways to handle long string literals.

1. Line Splicing (Using the Backslash '\')
-------------------------------------------------------------------------------
How it works:
Placing a backslash (\) at the absolute end of a line (right before the newline 
character) tells the compiler to merge the current line with the next line. 

The Disadvantage of Splicing:
Any indentation, tabs, or spaces used on the subsequent line to keep the code 
neatly aligned will be treated as literal characters inside your string. This 
frequently results in unwanted whitespace appearing in the final output.


2. Adjacent String Literal Concatenation (Recommended Approach)
-------------------------------------------------------------------------------
How it works:
In C, when two or more distinct string literals (each enclosed in its own double 
quotes) are placed adjacent to one another separated only by whitespace, tabs, 
or a newline, the compiler automatically concatenates them into a single continuous 
string.

The Advantage:
This method completely eliminates the indentation issue. You can safely indent 
the code on the next line for perfect readability without introducing unwanted 
spaces into the printed output.
===============================================================================
*/