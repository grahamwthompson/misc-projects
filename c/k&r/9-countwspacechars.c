#include <stdio.h>

/* program to count blanks tabs and newlines */
main()
{
    int c, s = 0, t = 0, n = 0;
    while ((c = getchar()) != EOF)
        switch(c){
            case ' ' :
                ++s;
                break;
            case '\t' :
                ++t;
                break;
            case '\n' :
                ++n;
                break;
        }
    printf("Spaces: %d\tTabs: %d\tNewLines:%d\n", s, t, n);
}
