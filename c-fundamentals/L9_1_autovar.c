// auto modifier - variables decladed inside a scope are automatic variables by default.
// syntax: auto int variable_name;

#include <stdio.h>

/*

int main()
{
    auto int var;
    return 0;
    
}

This is the same thing as:

int main ()
{
    int var;
    return 0;
}

If an auto variable is not initialized with some value, it will contain garbage (random) value. 
So, it is always a good practice to initialize the auto variable with some value.

*/

// A global variable is, by default, initialized with 0.



int main ()
{
    auto int var;
    printf("%d\n", var);
    return 0;
}




