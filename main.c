#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/testRunner.h"

int main ( int argc , char *argv[]) {


    if (argc >= 2) {
        if( strcmp( argv[1], "-t" ) == 0 ) {
            if (argc == 3) {
                test(argv[2]);
            }
        }
    }


    return 0;
}
