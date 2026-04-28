// Adding the prefix "const" before a variable prevents us from changing its value anywhere in the function.
// Syntax: const data_type variable_name
#include <stdio.h>

/*
int main()
{
    int var = 67;
    printf("%d\n", var);
    return 0;
}

vs.

int main()
{
    const int var = 67;
    var = 32;            ---> GIVES AN ERROR
    printf("%d\n", var);
}

*/ 