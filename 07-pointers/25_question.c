# include <stdio.h>
int main ()
{
    int i, j;
    char a [2][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}};
    char b [3][2];
    char *p = *b;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++) {
            *(p + 2*j + i) = a [i] [j];
        }
    }

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            printf("%c ", *(p + 2*x + y)); // %c (NOT %d)
        }
        printf("\n");
    }
}
