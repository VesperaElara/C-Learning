/*

Left shift operator: First operand << Second operand
First operand is the one whose bits get shifted.
The second operand decides the number of places to shift the bits.
When bits are shifted left, trailing positions are left with zero.
e.g., char var = 3 (0000 0011)
      var << 1
      var changes to (0000 0110) which represents 6.
left shifting is equivalent to multiplication with 2^{right operand}
therefore, var changes to 3 * 2^{1} = 6
for var << 4, var changes to 3 * 2^{4} = 48

Right shift operator: First operand >> Second operand
When bits are shifted left, leading positions are left with zero.
e.g., char var = 3 (0000 0011)
      var >> 1
      var changes to (0000 0001) which represents 1
right shifting is equivalent to division with 2^{right operand}
therefore, var change to 3/2^{1} = 1 (not 1.5, due to integer division)
for var = 32, and var >> 4, var changes to 32/2^{4} = 2

*/

#include <stdio.h>

int main()
{
    char x = 3;
    printf("x changes from 3 to %d when left-shifted by 4\n", x << 4);
    char y = 32;
    printf("y changes from 32 to %d when right-shifted by 4\n", y >> 4);
}
