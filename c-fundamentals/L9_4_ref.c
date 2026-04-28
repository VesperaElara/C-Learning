#include <stdio.h>

int count; //global variables are by default initiliazed to zero.

int increment()
{
    count += 1;
    return count;
}

/*
To ensure no other file can access the global variables in this file,
we can simply add a 'static' prefix before the global variable to
ensure it won't be accessed by any other file except the one in which
it is present.

static int count;
int increment()
{
    count += 1;
    return count;
}

A local variable, which isn't initialized, gives a garbage value.
A static local variable is always initialized with zero.

Static variable remains in memory even if it is declared within a 
block on the other hand automatic variable is destroyed after the 
completion of function in which it was declared.
Static variable if declared outside the scope of any function will 
act like global variable but only within the file in which it is declared.
You can only assign a constant literal (or value) to a static variable.

*/
