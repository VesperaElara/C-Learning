#include <stdio.h>

int addition(int, int); // return type of function addition is int; it takes 2 inputs of types int and int;

int main()
{
    int m = 30;
    int n = 70;
    int add = addition(m , n); // This is how a function is "called" inside the main() function
    // m , n are called arguments (actual parameters)
    printf("%d + %d = %d\n", m , n , add);
}

int addition(int a, int b)
// over here, it is important to mention the names of the variables along with their types.
// a , b are called parameters (formal parameters)
{
    return a+b;
}