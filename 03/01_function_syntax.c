/*

A function is basically a set of statements which take some input(s), 
perform computation, and produce (return) some output.

Syntax of a function: return_type function_name (set_of_inputs)

Benefits of using functions:
1. Reusability
2. Abstraction
   You can use the function even without understanding "how it works" on the inside. 
   E.g., scanf.

*/

#include <stdio.h>

int area_of_rectangle(int length, int breadth)
{
    int area = length * breadth;
    return area;

    /*

    - Using "return area" is CRITICAL to prevent the function from 
      returning garbage values and causing undefined behaviour.
    - Omitting "return area" makes the output depend on compiler
      luck rather than logic.

    The function body can also be compressed into a single return statement:

    return length * breadth;

    */
}

int main()
{
    int l = 10;
    int b = 15;
    int area = area_of_rectangle(l , b);
    printf("Area of rectangle = %d * %d = %d\n", l , b , area);

    l = 25;
    b = 5;
    area = area_of_rectangle(l , b);
    printf("Area of rectangle = %d * %d = %d\n", l , b , area);
}
