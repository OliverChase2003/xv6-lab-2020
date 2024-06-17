#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int Cpipefd[2];
    int Ppipefd[2];
    pipe(Cpipefd);      //create child pipe
    pipe(Ppipefd);      //create parent pipe
    char buf[10];

    int pid;
    pid = fork();

    if(pid == -1){
        printf("fork error!");
        exit(1);
    }else if(pid == 0){     //child proc
        read(Cpipefd[0], buf, sizeof(buf));
        printf("%d: receive ping\n", getpid());
        write(Ppipefd[1], "world", 5);
    }else{                  //parent proc
        write(Cpipefd[1], "hello ", 6);
        read(Ppipefd[0], buf, sizeof(buf));
        printf("%d: receive pong\n", getpid());
    }
    exit(0);
}
