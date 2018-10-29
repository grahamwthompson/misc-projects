#include <stdio.h>

/* print a farenheit-celsisus table
    for far = 0, 20, ... 300; now with floating points */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of tempertature table  */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("  F\t     C\n");
    while (fahr <= upper){
        celsius = 5.0 * (fahr-32) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
