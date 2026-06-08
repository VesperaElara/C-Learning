#include <stdio.h>

int main()
{
    int rowsA, colsA;
    
    do
    {
        printf("No. of rows and columns in matrix A (respectively; separated by a single space) = ");
        scanf("%d %d", &rowsA , &colsA);
    }
    while (rowsA <= 0 || colsA <= 0);

    int matrixA[rowsA][colsA];

    printf("\n");

    printf("Matrix A: \n");
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("\n");

    int rowsB, colsB;

    do
    {
        printf("No. of rows and columns in matrix B (respectively; separated by a single space) = ");
        scanf("%d %d", &rowsB , &colsB);
    }
    while (rowsB <= 0 || colsB <= 0);

    printf("\n");

    if (colsA != rowsB)
    {
        printf("Matrix multiplication is invalid.\n");
        return 0;
    }

    int matrixB[rowsB][colsB];

    printf("Matrix B: \n");
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("\n");

    printf("Product = [A][B] =\n");

    int product[rowsA][colsB];

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0; // This changes EVERYTHING!

            for (int x = 0; x < colsA; x++)
            {
                product[i][j] += matrixA[i][x]*matrixB[x][j];
            }
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
 * NOTE ON SCANF BEHAVIOR:
 * In C, scanf() treats spaces, tabs, and newlines (\n) identically as "whitespace" delimiters.
 * When reading integers with %d, it automatically skips over all whitespace to find the next number.
 * This is why matrix elements can be inputted separated by either spaces or Enter keys.
 * However, note that %c (characters) does NOT skip whitespace and will consume spaces/newlines as data.
 */
