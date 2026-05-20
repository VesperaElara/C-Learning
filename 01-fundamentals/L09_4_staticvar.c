#include <stdio.h>

extern int count;
extern int increment(void);

int main()
{
    int value;

    value = increment();    // returns count = 1
    value = increment();    // returns count = 2
    value = increment();    // returns count = 3

    count += 3;             // count = count + 3

    value = count;     
    printf("%d\n", value);
}

/*

type command:
code L09_4_staticvar.c
gcc L09_4_staticvar.c L09_4_ref.c -o L09
./L09

*/