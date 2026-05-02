#include <stdio.h>

int vespera(), elara();

int main()
{
    int a;
    a = vespera() + elara();
    printf("%d", a);
    return 0;
}

int vespera()
{
    printf("Vespera");
    return 1;
}

int elara()
{
    printf("Elara");
    return 1;
}

/*
    It is not possible to determine which of the 2 functions will be called FIRST.
    Behavior is undefined. The output is dependent on the compiler.
    Therefore, it is largely unpredictable whether the output will be 
    VesperaElara2 or ElaraVespera2
*/