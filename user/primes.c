#include "kernel/types.h"
#include "user.h"

int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int idx = 0;

void printprimes();

int main(int argc, char *argv[]){
    printprimes();
    exit(0);
}

void printprimes(){
    int pipefd[2];
    pipe(pipefd);

    int pid;
    pid = fork();

    if(pid == 0){   //child
        close(pipefd[1]);
        char buf[2];
        read(pipefd[0], buf, sizeof(buf));
        printf("prime %d\n", primes[idx]);
        idx++;
        if(idx == 11) return;
        printprimes();
    }else{          //parent
        close(pipefd[0]);
        sleep(1);
        write(pipefd[1], "1", 1);
        wait(&pid);
    }
    exit(0);
}