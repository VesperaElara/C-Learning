/*
Find the sum of all 5 individual rows and columns of array a.
*/

#include <stdio.h>
#define ROWS 5
#define COLS 5

int main()
{
    int a[5][5] =
    {
        {1 , 2 , 3 , 4 , 5},
        {6 , 7 , 8 , 9 , 10},
        {11 , 12 , 13 , 14 , 15},
        {16 , 17 , 18 , 19 , 20},
        {21 , 22 , 23 , 24 , 25},
    };

    int row_sum [5] = {0};
    int column_sum [5] = {0};

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            row_sum[i] += a[i][j];
            column_sum[j] += a[i][j]; // This sentence alone entirely removes the need for the second nested loop.
        }
    }

    /*
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            column_sum[j] += a[i][j];
        }
    }
    */

    printf("ROW SUM:\n");

    for (int n = 0; n < ROWS; n++)
    {
        printf("Row %d sum = %d\n", (n+1) , row_sum[n]);
    }

    printf("\n");

    printf("COLUMN SUM:\n");

    for (int n = 0; n < COLS; n++)
    {
        printf("Column %d sum = %d\n", (n+1) , column_sum[n]);
    }

    return 0;

}