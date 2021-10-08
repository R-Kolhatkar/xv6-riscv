#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"


int main(int argc, char *argv[]){
    if (argc == 2){
        int i = atoi(argv[1]);
        printf("%d", info(i));
    }
    else {printf("Too many argumnets");}

    exit(0);
}

