#include <stdio.h>

int main()
{
    double main_base, base;
    double result = 1;
    int main_power, power;

    printf("Base (integer or float) = ");
    scanf("%lf", &main_base); // %lf is used for double in scanf. DO NOT use %f!
    // printf is forgiving and allows %f to be used for both scanf and printf, but scanf is NOT

    printf("Power (integer) = ");
    scanf("%d", &main_power);

    if (main_power < 0)
    {
        base = 1/main_base;
        power = -main_power;

        while (power != 0)
        {
            result = result * base;
            power--;
        }

        printf("%.10lf ^ %d = %.10lf", main_base, main_power, result);
    }

    else
    {
        base = main_base;
        power = main_power;

        while (power != 0)
        {
            result = result * base;
            power--;
        }

        printf("%.10lf ^ %d = %.10lf", main_base, main_power, result);
    }
}