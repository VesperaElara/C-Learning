#include <stdio.h>

int main()
{
    float marks, total, percentage;
    char result;

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

    percentage = (marks/total)*100;

    printf("Percentage: %f%%\n\n", percentage);

    /*

    if (percentage >= 35)
    {
        result = 'p';
    }
    else
    {
        result = 'f';
    }
    
    This can be rewritten using the conditional operation ( ? for if    &    : for else)

    */

    result = (percentage >= 35) ? 'p' : 'f'; 

    // (percentage >= 35) is a boolean which will either return TRUE or FALSE.
    // if TRUE, result is assigned 'p'      if FALSE, result is assigned 'f'
    // Format --> Expression1 ? Expression2 : Expression3;

    if (result == 'p')
    {
        printf("Pass\n");
    }
    else // if (result == 'f')
    {
        printf("Fail\n");
    }

    return 0;
}
