#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
//Function declarations
void print_pid(char name);

int main(){
    pid_t pid_L, pid_D;
    int status;
    pid_L = fork();

    // Child process
    if( pid_L == 0 )
    {
        sleep(3);
        printf("Termine mi ejecucion\n");
        print_pid('L');
        return(11);
    }

    pid_D = fork();

    if(pid_D == 0){
        sleep(1);
        printf("Termine mi ejecucion\n");
        print_pid('R');
        return (4);
    }

    wait(&status);
    printf("Uno de mis hijos ha terminado su ejecucion con estado %d\n\n ", WEXITSTATUS(status));

    
    wait(&status);
    printf("Uno de mis hijos ha terminado su ejecucion con estado %d\n\n ", WEXITSTATUS(status));
}


void print_pid(char name){
    printf("Soy el %c.\n", name);
    printf("Mi ID es %d.\n", getpid());
    printf("El ID de mi padre es %d.\n\n", getppid());
}