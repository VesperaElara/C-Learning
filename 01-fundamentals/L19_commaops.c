/*

comma operator: 
int a; int b; int c; >>> can be rewritten as >>> int a, b, c;

*/

int main()
{
    int a = (3,4,8);
printf("a is %d\n", a);

/* 
    The comma operand returns the right-most value (8). 
    It simply evaluates the rest of the variables and rejects them.
*/

int b = ((printf("%s!", "HELLO WORLD"), 5));
printf("b is %d\n", b);

/*
    In C, the comma operator has the least precedence among all C operators. 
    It is least preferred.
*/

int x;
x = 3, 4, 8;
printf("x is %d\n", x);

/*
    Here, the comma operator acts like a mere separator.
    Assignment operator has more precendence than the comma operator.
    Therefore, x is 3, not 8.
*/

// int y = 3, 4, 8; >>> THIS PRODUCES AN ERROR


int y;
y = (3,4,8);
printf("y is %d\n", y);

/*
    Brackets have the highest precedence.
    Therefore, the comma operator is evaluated before the assignment one.

*/



}