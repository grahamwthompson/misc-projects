#include <stdio.h>

/* Conber celsus values to farenheit floating point */
float cToF(float celsius){
    return 9.0 * celsius / 5.0 + 32;
}

float cToFOld(celsius)
float celsius;
{
    return 9.0 * celsius / 5.0 + 32;
}

/* print Celsius-Farenheit table
    for celsius = 0, 20, ... 300; floating point */
int main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;  /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20;  /* step size */

    celsius = lower;
    printf("  C\t     F\n");
    while (celsius <= upper){
        fahr = cToF(celsius);
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
