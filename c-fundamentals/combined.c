#include <stdio.h>
extern int external_variable;

int main()
{
    printf("%d", external_variable);
    return 0;
}#include <stdio.h>

int external_variable = 5;

// global variable for extern variable used in L9_2_externvar.c