#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler_sigusr1(int signum) 
{
    printf("Señal SIGUSR2 recibida.\n");
    for(int i=0; i<10; i++){
        printf("Se imprime el número %d\n", i+1);
    }
}

int main() 
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) 
    {
        // Proceso hijo
        signal(SIGUSR2, signal_handler_sigusr1);
        printf("Proceso hijo en espera de señales.\n");
        pause();
         return 0;
    } 
    
    // Proceso padre
    sleep(1);
    printf("Enviando señal al proceso hijo.\n");
    kill(pid, SIGUSR2);
    wait(&status);

    return 0;
}
