#include <stdio.h>
#include <stdlib.h>

extern int count;

int main()
{
    int value;

    value = increment();    // returns count = 1
    value = increment();    // returns count = 2
    value = increment();    // returns count = 3

    count += 3;             // count = count + 3
    // the main function modifies the global variable count in the other file directly

    value = count;     
    printf("%d\n", value);
}

/*

type command:
code L9_4_staticvar.c
gcc L9_4_staticvar.c L9_4_ref.c -o L9
./L9 

THE GLOBAL MEMORY & LINKAGE SUMMARY

 1. THE "SHARED WHITEBOARD" (Global Scope):
    'int count' in File 2 is a global variable. It lives in the 
    Data Segment of RAM for the entire life of the program.
    It is "Public Property" accessible to any function with the "key."
 
 2. THE "WINDOW" (extern):
    'extern int count' in File 1 is NOT a new variable. 
    It is a declaration telling the compiler: "The 'count' variable 
    exists elsewhere. Link to that specific memory address later."
 
 3. SIDE EFFECTS vs. RETURN VALUES:
    A function call is an ACTION. When increment() runs 'count += 1', 
    it modifies the GLOBAL memory address directly and permanently.
    The 'return count' is just a SNAPSHOT/REPORT. It hands a copy of 
    the current value back to main(), but it doesn't "stay" connected.
 
 4. WHY THE RESULT WAS 6 AND NOT 3:
    Step A: increment() was called 3 times. Each time, it reached 
    out and changed the global 'count' in memory (0 -> 1 -> 2 -> 3).
    Step B: 'count += 3' in main() was a "Direct Intervention." 
    It didn't use the function; it went straight to the global 
    memory address, saw the 3, and manually changed it to 6.
    Step C: 'value = count' updated the local 'value' bucket to 
    match the new reality of the global memory.
 
 5. THE "STATIC" BARRIER (Visibility vs. Lifetime):
    'static' on a global variable keeps the memory alive (Lifetime) 
    but paints over the "window" (Visibility). 
    If 'count' were static in File 2, File 1's 'extern' would fail 
    because the Linker can't find a "public" version of it.
 */