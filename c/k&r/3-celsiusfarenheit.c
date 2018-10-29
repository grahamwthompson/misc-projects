#include <stdio.h>

/* print Celsius-Farenheit table
    for celsius = 0, 20, ... 300; floating point */
main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;  /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20;  /* step size */

    celsius = lower;
    printf("  C\t     F\n");
    while (celsius <= upper){
        fahr = 9.0 * celsius / 5.0 + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
