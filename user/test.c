#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"


int main(int argc, char *argv[]){
    sbrk(16384);
    if (argc == 2){
        int i = atoi(argv[1]);
        printf("%d /n", info(i));
    }
    else {printf("Too many argumnets");}

    exit(0);
}

