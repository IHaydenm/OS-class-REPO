#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>


void RandomNumber(char Name);


int main(){
    pid_t pid_B, pid_M, pid_A;
    srand(time(NULL));
    int status;
    int pid_counter = 0;

    pid_A = fork();

    if(pid_A == 0){
        RandomNumber('A');
        return(0);
    }

    pid_B = fork();

    if(pid_B == 0){
        RandomNumber('B');
        return(0);
    }

    pid_M = fork();

    if(pid_M== 0){
        RandomNumber('M');
        return(0);
    }

    for(int i = 0; i < 3; i++){
        if(wait(&status) == pid_A || wait(&status) == pid_B || wait(&status) == pid_M){
             pid_counter += 1;   
        }
    }
    wait(&status);
    printf("My son ended with the status: %d.\n\n", WEXITSTATUS(status));
    
    wait(&status);
    printf("My son ended with the status: %d.\n\n", WEXITSTATUS(status));
    
    wait(&status);
    printf("My son ended with the status: %d.\n\n", WEXITSTATUS(status));
    
    RandomNumber('Q');

    return 0;
}

void RandomNumber(char Name){
    int N = 100;
    printf("I am %c\n", Name);
    printf("This is my pid %d\n\n", getpid());
    printf("This is my parent's pid %d\n\n", getppid());
    printf("I print this number: %d\n", rand() % (N + 1));
}