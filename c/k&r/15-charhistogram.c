#include <stdio.h>
#include <ctype.h>

#define ASCIIMAX 128

main()
{
    int c;
    int chars[ASCIIMAX] = {0};
    while( (c = getchar()) != EOF){
        chars[c]++;
    }

    // only display the printable ascii chars
    for(int i=' '; i<='~'; ++i){
        printf("%c |", i);
        for(int j=0; j<chars[i]; ++j){
            putchar('=');
        }
        putchar('\n');
    }

}
