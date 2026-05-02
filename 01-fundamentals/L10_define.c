// defining functions - syntax: #define NAME value
// no semicolon at end
// writing the NAME in ALL CAPITAL is best practice.

#include <stdio.h>

int addition();
int greaterthan();

#define PI 3.14159

int main()
{
    printf("%.5f\n", PI);
    addition();
    greaterthan();
    return 0;
}

#define add(x,y) x+y

int addition()
{
    printf("%d + %d = %d\n", 4, 6, add(4,6));
    printf("%d × %d + %d = %d\n", 5, 4, 6, 5 * add(4,6));  
    return 0;
}
// Notice how this follows BODMAS.
// This is because we have only written x+y, not (x+y)

#define greater(x,y) if (x > y) \
                        printf("%d is greater than %d\n",x,y); \
                    else \
                        printf("%d is greater than %d\n",y,x);
// As you may have noticed, when you only have a single condition, 
// curly braces can be omitted in if-else statements.

int greaterthan()
{
    greater(5,6);
    return 0;
}

/*
REMEMBER!
This will lead in a FATAL error:

#define value 89
int main()
{
    int value = 74;     --> the code replaces all "value" variables with 89 --> int 89 = 74? NO (fatal error)
    printf("%d", value)
}

*/