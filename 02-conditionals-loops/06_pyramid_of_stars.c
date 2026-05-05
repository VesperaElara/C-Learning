#include <stdio.h>

int main()
{
    int row, column;
    int total_rows; // change this variable according to the height you desire!

    do
    {
        printf("What is the height of the pyramid?\n");
        scanf("%d", &total_rows);
    } 
    while (total_rows <= 0);
    

    for (row = 1; row <= 2; row++)
    {
        for (column = 1; column <= 2; column++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");


    for (row = 1; row <= total_rows; row++)
    {
        for (column = 1; column <= total_rows; column++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    /*

        We want a 4 unit long star pyramid.
        *       ---* --> row = 1, space = 4-row, star = row
       **       --** --> row = 2, space = 4-row, star = row
      ***       -***
     **** -->   ****

    */

    for (row = 1; row <= total_rows; row++)
    {
        int space;
        int star;

        for (space = 1; space <= total_rows-row; space++)
        {
            printf("-");
        }

        for (star = 1; star <= row; star++)
        {
            printf("*");
        }

        printf("\n");
    }

    printf("\n");

    /*

    ---*---
    --***--
    -*****-
    ******* 

    ---     *     ---       >>> space = 4-row, star = row-1, * , star, space
    --*     *     *--       >>> space = 4-row, star = row-1, * , star, space
    -**     *     **-       >>> space = 4-row, star = row-1, * , star, space
    ***     *     ***       >>> space = 4-row, star = row-1, * , star, space

    */

    for (row = 1; row <= total_rows; row++)
    {
        int space;
        int star;

        for(space = 1; space <= total_rows-row; space++)
        {
            printf("-");
        }

        for(star = 1; star <= row-1; star++)
        {
            printf("*");
        }

        printf("*");

        for(star = 1; star <= row-1; star++)
        {
            printf("*");
        }

        for(space = 1; space <= total_rows-row; space++)
        {
            printf("-");
        }

        printf("\n");

    }

    printf("\n");

    // A better method to solve the same problem

    /*
    
    Step 1: The relation between rows and columns:
    
    ROW         Column
    3           5
    4           7
    5           9
    6           11

    Relation between the two:     total columns = 2(total rows) - 1

    Star is printed from the columns (j) : n - (i-1)      to      n + (i-1)
    where n = total_rows

    */

    int i;
    int j;
    
    for (i = 1; i <= total_rows; i++)
    {
        for (j = 1;     j <= 2*total_rows-1     ;    j++)
        {
            if (j >= total_rows - (i-1) && j <= total_rows + (i-1))
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }

}