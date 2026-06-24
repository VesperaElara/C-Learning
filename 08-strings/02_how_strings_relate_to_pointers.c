#include <stdio.h>

int main() {
    /* Direct demonstration of passing a string literal to printf.
       The compiler passes the memory address of the first character 'E'.
    */
    printf("Earth\n");

    /* Storing the reference of a string literal using a character pointer.
       ptr holds the address of the first character 'G'.
    */
    char *ptr = "Galaxy";
    printf("%s\n", ptr);

    return 0;
}

/*
===============================================================================
                    HOW STRING LITERALS ARE STORED IN C
===============================================================================

1. Character Array Representation
-------------------------------------------------------------------------------
In C, a string literal (e.g., "Earth") is implicitly stored as an array of 
characters in the computer's memory. 

To mark the exact end of the string, the C compiler automatically appends a 
special character called the "Null Character" ('\0') at the very end of the 
array.

Visual Memory Layout for "Earth":
+---+---+---+---+---+----+
| E | a | r | t | h | \0 |
+---+---+---+---+---+----+

Memory Allocation Facts:
* Total Bytes Allocated: Length of string + 1 byte (for the null character).
* For "Earth", even though it has 5 visible letters, it occupies 6 bytes.
* Memory Location: It is stored in a read-only section of data memory.


2. Crucial Distinction: '\0' vs '0'
-------------------------------------------------------------------------------
The null terminator must never be confused with the text character zero. They 
have completely distinct integer codes:

+------------------+------------------+-------------------+
|    Character     |    ASCII Code    |      Purpose      |
+------------------+------------------+-------------------+
|       '\0'       |        0         | Marks string end  |
|       '0'        |        48        | Literal digit zero|
+------------------+------------------+-------------------+


3. String Literals as Pointers
-------------------------------------------------------------------------------
A fundamental rule in C is how the compiler evaluates a string literal when 
it is used inside an expression or passed into a function:

> The compiler treats a string literal as a pointer to its first character.

When executing functions like printf() or scanf():
* The first argument expected by these functions is always a character pointer 
  (char *).
* Writing printf("Earth"); does not pass the entire word "Earth" to the function at 
  once.
* Instead, it passes the memory address (pointer) of the first letter, 'E'.
* The function then reads characters sequentially from that starting address until 
  it encounters the '\0' null terminator, knowing exactly where to stop.
===============================================================================
*/