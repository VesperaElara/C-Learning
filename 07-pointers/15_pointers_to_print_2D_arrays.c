/*
================================================================================
               C PROGRAMMING: MULTIDIMENSIONAL ARRAY STORAGE
================================================================================

1. THE MEMORY PARADOX: MULTIDIMENSIONAL VS. LINEAR STORAGE
--------------------------------------------------------------------------------
Conceptually, we think of a 2D array as a table or matrix containing rows and 
columns. However, computer physical memory (RAM) is strictly linear—it is a 
one-dimensional sequence of consecutive memory addresses. 

To bridge this gap, programming compilers map a multi-dimensional structure 
into a flat, continuous linear memory layout using one of two primary methods:
    1. Row-Major Order
    2. Column-Major Order


2. ROW-MAJOR ORDER VS. COLUMN-MAJOR ORDER
--------------------------------------------------------------------------------
The difference centers entirely on the order in which individual dimensions 
are flattened out into consecutive cells.

Row-Major Order:
    Elements are grouped and written down row by row. The entire first row is 
    stored sequentially in memory, followed immediately by the entire second 
    row, then the third, and so on.
    
    Layout Scheme: [ Row 0 ] [ Row 1 ] ... [ Row n-1 ]

Column-Major Order:
    Elements are grouped and written down column by column. The entire first 
    column is stored sequentially, followed by the entire second column, etc.
    
    Layout Scheme: [ Column 0 ] [ Column 1 ] ... [ Column n-1 ]


3. HOW C HANDLES STORAGE: ROW-MAJOR RULE
--------------------------------------------------------------------------------
CRITICAL FACT: The C programming language exclusively stores multidimensional 
arrays in ROW-MAJOR ORDER. 

When you define a 2D matrix in C, the rightmost index (the column index) varies 
the fastest as you move sequentially through memory blocks.


4. PRACTICAL IMPLICATIONS & ADVANTAGES
--------------------------------------------------------------------------------
Understanding C's internal memory alignment allows you to write computationally 
optimal loops. 

Consider a 2x2 grid containing these values:
    Row 0 (r0): 1, 2
    Row 1 (r1): 3, 4

Because C implements Row-Major mapping, this matrix is laid out flat in memory 
in exactly this order:
    Memory Index: [ 0 ]  [ 1 ]  [ 2 ]  [ 3 ]
    Value:        |  1  |   2  |   3  |  4  |
    Conceptual:   \___Row 0___/ \___Row 1___/

Optimized Traversal (Traditional Nested Loop):
    int i, j;
    int a[2][2] = {{1, 2}, {3, 4}};

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d ", a[i][j]);
        }
    }

Why this loop structure is superior:
    The outer loop controls rows ('i'), while the inner loop scans through 
    columns ('j'). This means the program accesses elements in the exact order 
    they sit in the hardware: a[0][0] (1), then a[0][1] (2), then a[1][0] (3), 
    and finally a[1][1] (4).

    Accessing continuous memory chunks optimizes CPU cache usage, reducing 
    memory latency and speeding up code execution drastically.

================================================================================
*/

#include <stdio.h>

int main()
{
    
}
