/*
Arithmetic Operators in C: + , - , * , / , %
They are BINARY OPERATORS - require 2 operands.
Groups of operations with the same "precendence" -->
GROUP_1: * , / , %          >>>> (Highest precedence - performed first)
GROUP_2: + , -              >>>> (Lowest precedence - performed last)
Since operators in both groups possess the same precedence:
The compiler performs them in a left-to-right order 
(i.e., it depends on the order WE follow while writing the code from left-to-right) (associativity)
Associativity is only performed on operators with the SAME precedence.
*/

#include <stdio.h>

int main()
{
    int x, y;

    printf("Performing: x / y and x %% y\n"); // Notice how we typed %% to print only one %.
    printf("\n");

    printf("x = ");
    scanf("%d", &x);
    printf("\n");

    printf("y = ");
    scanf("%d", &y);
    printf("\n");

    printf("%d / %d = %d\n", x, y, (x / y));
    printf("%d %% %d = %d\n", x, y, (x % y)); // Notice how we typed %% to print %.
    printf("\n");

    int a, b, c;
    printf("Performing: a + (b * c) - (c %% a)\n");
    printf("\n");

    printf("a = ");
    scanf("%d", &a);
    printf("\n");

    printf("b = ");
    scanf("%d", &b);
    printf("\n");

    printf("c = ");
    scanf("%d", &c);
    printf("\n");

    printf("%d + (%d * %d) - (%d %% %d) = %d\n", a, b, c, c, a, a+b*c-c%a);
    print("\n");

    int beware = 10+5/4*2;
    printf("10+5/4*2 = %d = 10+(5/4)*2, (NOT 10) according to ASSOCIATIVITY!\n", beware);

}
