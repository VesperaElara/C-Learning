#include <stdio.h>
#include <string.h>

int main() 
{
    char *c = "GATECSIT2017";
    char *p = c;
    printf("%d", (int)strlen(c + 2[p] - 6[p] - 1));
    return 0;
}

/*
================================================================================
POINTER ARITHMETIC AND ARRAY-POINTER DUALITY IN C
================================================================================

This program explores advanced pointer arithmetic expressions, leveraging the 
built-in identity rules of array indexing and operator precedence in C.

---
1. INITIALIZATION AND STRUCTURE OF THE STRING
---
The program initializes a character pointer 'c' to point to the base address of 
the string literal "GATECSIT2017". A second pointer 'p' is assigned to point to 
the exact same memory location as 'c'.

Let's represent the elements of the string along with their respective 
0-indexed offsets from the base pointer:

Index:     0   1   2   3   4   5   6   7   8   9  10  11  12
Character: G   A   T   E   C   S   I   T   2   0   1   7  \0

---
2. DECONSTRUCTING THE CONTROVERSIAL NOTATION: X[Y]
---
In the C programming language, the subscript operator [] is defined purely in 
terms of pointer arithmetic. Specifically:
- The expression 'X[Y]' evaluates internally to '*(X + Y)'.
- Since addition is commutative, '*(X + Y)' is identical to '*(Y + X)'.
- This means 'X[Y]' is exactly equivalent to 'Y[X]'.

Let us apply this foundational identity rule to decode the terms inside the 
strlen argument expression:

* Term 1: 2[p]
  - By commutative property, 2[p] is equivalent to p[2].
  - p[2] represents the character at index 2 of the string "GATECSIT2017".
  - Referring to our layout, index 2 holds the character 'T'.
  - In an arithmetic expression, characters are evaluated by their ASCII value.
  - Therefore, 2[p] evaluates to the ASCII value of 'T'.

* Term 2: 6[p]
  - By commutative property, 6[p] is equivalent to p[6].
  - p[6] represents the character at index 6 of the string "GATECSIT2017".
  - Referring to our layout, index 6 holds the character 'I'.
  - Therefore, 6[p] evaluates to the ASCII value of 'I'.

---
3. EVALUATING THE POINTER EXPRESSION
---
Now substitute these ASCII values directly back into the argument passed to 
the strlen function:

Expression: c + 2[p] - 6[p] - 1
Substitute: c + ASCII('T') - ASCII('I') - 1

We do not need to memorize exact ASCII table positions because we can evaluate 
the relative distance between 'T' and 'I' alphabetically:
- Distance: ASCII('T') - ASCII('I') = 11

Substitute the calculated distance back into the evaluation path:
Expression: c + 11 - 1
Final:      c + 10

---
4. DETERMINING THE STRLEN OUTPUT
---
The expression has simplified cleanly down to 'c + 10'. 
This creates a pointer offset pointing directly to index 10 of the original 
string buffer.

Let us inspect the remaining suffix string starting from index 10:
- At index 10, the character is '1'.
- At index 11, the character is '7'.
- At index 12, the string terminates at '\0'.

The string visible from this new pointer offset is simply "17".
The standard 'strlen' function counts characters until it encounters the null 
terminator ('\0').

- Character at offset 10: '1' (Count = 1)
- Character at offset 11: '7' (Count = 2)
- Character at offset 12: '\0' (Loop ends)

The calculated length of the substring is 2.

---
5. CONCLUSION
---
The program prints out the calculated string length value:
2

This matches option (b) from the standard problem set.
*/