#include <stdio.h>

/* count characters from input */
main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF){
        ++nc;
    }
    printf("%1ld\n", nc);
}
