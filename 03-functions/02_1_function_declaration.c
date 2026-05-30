/*

Function declaration (AKA function prototype):

variable declaration includes: variable_type variable_name;
e.g., int var;

function declaration follows the following pattern:

e.g., int fun(int , char);

- Name of function:                 fun
- return type of function:          int
- number of parameters:             2
- type of 1st parameter:            int
- type of 2nd parameter:            char

it is not necessary to add the names of the parameters during function declaration
e.g., int fun(int var1, char var2); // Not necessary

it may not always be necessary to declare the function before using it,
butt doing so is preferred/recommended.

*/

#include <stdio.h>

char fun(); // function is declared; the function takes no input, and returns a char.

int main()
{
    char c = fun();
    printf("Character number: %d    Character: %c\n", c , c);
}

char fun()
{
    return 'a';
}

/*

using the function without declaring it first is prone to errors.
if the compiler comes across fun() before any declaration, it may assume the return type is int.
that can conflict with the statement char c = fun();
because assigning an "assumed" int return to a char is unsafe without a proper declaration.

*/