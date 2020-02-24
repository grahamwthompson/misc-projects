#include "stdio.h"
#include <fcntl.h> // for open
#include <unistd.h> // for close

int main(int argc, char **argv) {

    for(int i=0; i<argc; ++i){
        printf("%s \n", argv[i]);
    }
    return 0;
}
