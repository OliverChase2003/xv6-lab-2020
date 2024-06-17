#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    if(argc > 2){
        printf("args too much!\n");
    }
    
    sleep(atoi(argv[1]));   //sleep
    exit(0);
}