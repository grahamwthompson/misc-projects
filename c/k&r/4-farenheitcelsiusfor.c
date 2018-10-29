#include <stdio.h>

/* print Farenheit-Celsius table
    now with for loops */
main()
{
    int fahr;

    printf("  F\t     C\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
