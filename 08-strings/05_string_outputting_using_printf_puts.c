#include <stdio.h>

int main() {
    char *ptr = "Hello World";
    char *s = "Hello";

    // 1. Basic String Printing with printf
    printf("1. Basic output: %s\n", ptr);

    // 2. Precision Specifier (%.ns) - Prints only the first 'n' characters
    printf("2. Precision (.5): %.5s\n", ptr);

    // 3. Field Width + Precision (%m.ns) - Right-aligned inside a field of size 'm'
    printf("3. Field & Precision (10.5): %10.5s\n", ptr);

    // 4. Writing Strings Using puts() - Automatically appends a newline '\n'
    printf("4. Testing puts():\n");
    puts(s);
    puts(s);

    return 0;
}

/*
================================================================================
               C PROGRAMMING STUDY NOTES: OUTPUTTING STRINGS
================================================================================

1. WRITING STRINGS USING printf()
--------------------------------------------------------------------------------
The printf() function uses the "%s" format specifier to output character strings 
to the screen. It reads the string character by character from the provided 
memory location until it encounters the null terminator ('\0').

A. Standard String Output
   Syntax:
   printf("%s", ptr);
   
   - If ptr points to "Hello World", this prints the entire string exactly as-is.

B. The Precision Specifier ("%.ns")
   Syntax:
   printf("%.ns", ptr);
   
   - The dot (.) followed by an integer 'n' sets the maximum number of characters 
     to display from the string.
   - Example: Given "Hello World", using "%.5s" outputs only "Hello" (the first 
     5 characters), cutting off the rest.

C. The Field Width & Precision Specifier ("%m.ns")
   Syntax:
   printf("%m.ns", ptr);
   
   - 'm' specifies the minimum field width (the total spaces reserved for display).
   - 'n' specifies the precision (the max number of characters extracted from the string).
   - If the extracted string length ('n') is less than the total field size ('m'), 
     the text is right-aligned by default, padded with leading spaces on the left.
   - Example: "%6.5s" with "Hello World!" extracts 5 characters ("Hello") and fits 
     them into a field of 6 spaces, creating 1 leading space: " Hello".

2. WRITING STRINGS USING puts()
--------------------------------------------------------------------------------
The puts() function is a specialized, compact function declared in <stdio.h> 
specifically designed to write strings directly to the standard output screen.

Syntax:
puts(string_variable);

Key Differences between puts() and printf():
- Automatic Newline: Unlike printf("%s", s), the puts() function automatically 
  appends a newline character ('\n') to the output screen immediately after 
  writing the string.
- Simplicity: It requires no format specifiers, making it more concise for printing 
  clean, individual lines of text.
================================================================================
*/