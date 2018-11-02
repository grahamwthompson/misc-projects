#include <stdio.h>
#include <stdint.h>

#define TRUE 1  /* truth */
#define FALSE 0 /* falsehood */

/* Copies input to output and replaces any string of one or more blanks with a single */
main()
{
    int c;
    uint8_t flag = FALSE;
    while((c = getchar()) != EOF){
        if(c==' '){
            if(!flag){
                flag = 1;
                putchar(c);
            }
        }
        else{
            flag = 0;
            putchar(c);
        }
    }
}
