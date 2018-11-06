#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 20

main()
{
    int c;
    int wl = 0, wc = 0, wp = OUT;
    int wls[MAXLEN] = {0};
    while((c = getchar()) != EOF ){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(wp == IN){
                wls[ (wl < MAXLEN) ? --wl: MAXLEN-1 ]++;
                wl = 0;
                wp = OUT;
            }
        }
        else if(wp == OUT){
            wp = IN;
            ++wc;
            ++wl;
        }
        else{
            ++wl;
        }
    }

    // print histogram
    for(int i = 0; i < MAXLEN; ++i){
        printf("%d ", i+1);
        for(int j=0; j<wls[i]; ++j){
            putchar('=');
        }
        putchar('\n');
    }
    printf("Word Count: %d\n", wc);
}
