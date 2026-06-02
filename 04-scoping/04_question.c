/*
Question:
Let x be the value printed under static scoping and y be the value 
printed under dynamic scoping. Then, x and y are:
(A) x = 10, y = 10
(B) x = 20, y = 10
(C) x = 10, y = 20
(D) x = 20, y = 20

QUESTION (this is a hypothetical language):

int i ;

program main()
{
    i = 10;
    call f();
}

procedure f()
{
    int i = 20;
    call g();
}

procedure g()
{
    print i;
}

*/

#include <stdio.h>

int i;

int f();
int g();

int main()
{
    i = 10; // This function updates the value of the global variable.
    f();
}

int f()
{
    int i = 20;
    g();
}

int g()
{
    printf("%d\n", i);
}