

#include <stdio.h>

int main()
{
    float marks, total, percentage;

    do
    {
        printf("Enter marks received: ");
        scanf("%f", &marks); // Never write specifics like %.2f in the scanf function
    }
    while (marks < 0);

    printf("\n");

    do
    {
        printf("Enter total marks: ");
        scanf("%f", &total);
    }
    while (total <= 0 || total < marks);

    printf("\n");

    percentage = marks/total;

    printf("Percentage: %f%%\n\n", percentage*100);

    /*
    if (percentage*100 >= 35)
    {
        printf("Pass\n");
    }
    else
    {
        printf("Fail\n");
    }
    
    This can be rewritten using the conditional operation
    */
}
