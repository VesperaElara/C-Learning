/*
In a while-loop, we first evaluate the condition and then implement the loop.
In a do-while loop, the loop is implemented first and then the condition is checked.
Therefore, a do-while loop is always implemented AT LEAST once.
A do-while-loop is preferred over a while-loop in some cases of user-input.
>>> (e.g., when we want to ensure the user-input is ONLY positive, not zero or negative.)
Prefer do-while loop when you need the loop to occur AT LEAST once.
*/

#include <stdio.h>

int main()
{
    int budget;
    do
    {
        printf("Enter budget: \n");
        scanf("%d", &budget);
    }
    while (budget <= 0);

    printf("Your budget: $%d.\n", budget);
    
    int cost;
    printf("Enter cost: \n");
    scanf("%d", &cost);

    while (cost <= 0)
    {
        printf("Enter cost: \n");
        scanf("%d", &cost);
    }

    // As you can see, the while-loop gets a bit redundant.

    if (cost > budget)
        {printf("The item costs $%d. You're short by $%d.", cost , cost-budget);}
    else if (cost == budget)
        {printf("The item costs $%d. You've got exactly $%d.", cost , budget);}
    else
        {printf("The item costs $%d. You've got a surplus of $%d.", cost , budget-cost);}
    
    return 0;
    
}