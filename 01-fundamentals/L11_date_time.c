// How do I get the live date and time?

// By using predefined macros like __DATE__ and __TIME__

#include <stdio.h>

int main()
{
    printf("DATE: %s\n", __DATE__);
    printf("TIME: %s\n", __TIME__);
    return 0;
}