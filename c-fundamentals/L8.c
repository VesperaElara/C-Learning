/*
Scope is the area under which a variable is applicable or alive.
Scope: a block or a region where a variable is declared, defined and used.
When the block or the region ends, the variable is automatically destroyed.
*/

#include <stdio.h>

int duplicate();
int fun();
int cool();

int main()
{
    int var = 34;
    printf("%d\n", var);
    duplicate(); // this will give 4 then 3
    fun(); // this will give 3 then 10 (10 from cool())
    return 0;
    printf("This line will NEVER print because I returned early.\n");
}

/*
int errormain()
{
    printf("%d", var); // this will produce an error
}
*/

/*
int errorduplicate()
{
    int var = 3;
    int var = 4;
    printf("%d\n", var); // this generates an error
    printf("%d\n", var); 
    return 0;
}
*/

int duplicate()
{
    int var = 3;
    {
        int var = 4;
        printf("%d\n", var);
    }

    printf("%d\n", var);
}

int var = 10; // this is a global variable, not a local one.

int fun()
{
    int var = 3;
    printf("%d\n", var);
    cool(); // here I call the cool function
}

int cool()
{
    printf("%d\n", var); //calling the global variable.
}



/* 
DO NOT TYPE return 0 IN THE MAIN FUNCTION UNTIL THE END 
BECAUSE LINES AFTER return 0 ARE IGNORED BY THE COMPUTER.

You can type return 0 in functions other than 
the main ones - like cool(), fun(), duplicate()
without stopping the entire code from running.

All functions defined outside the main one will do nothing
until they are "called" in the main function.

It's best practice to inform the computer about all functions
we will use in the code in the starting itself.
This helps prevent unintentional bugs.
It prevents the computer from panicking.

Another way to prevent the computer from panicking is to shift
all the "other" functions to the top and place the main function
at the bottom.
*/