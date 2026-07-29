#include <stdio.h>
extern int external_variable;

int main()
{
    printf("%d\n", external_variable);
    return 0;
}

/*
NOTE: there shouldn't be a main function in both of the 2 files you are combining!
This leads to an error!
Combine the files L9_2_externvar.c and L9_2_ref.c in the following command:
code L09_2_externvar.c
gcc L09_2_externvar.c L09_2_ref.c -o L09
./L9
*/