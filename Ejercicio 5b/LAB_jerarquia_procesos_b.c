#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


/*functions*/
void print_pid(char name);
/*FUNCTIONS*/

int main(){
    
    /*variables*/
    pid_t pid_T, pid_v, pid_w, pid_s, pid_l, pid_p = -1;
    /*VARIABLES*/

    pid_T = fork();
    if(pid_T != 0){
        pid_w = fork();
    }
    if(pid_T == 0){
        print_pid('T');
        
        pid_v = fork();

        if(pid_v == 0){
            print_pid('V');
            exit(0);
        }
        exit(0);
    }

    if(pid_w == 0){
        print_pid('W');

        pid_s = fork();
        if(pid_T != 0){
            pid_l = fork();
        }
        

        if(pid_s == 0){
            print_pid('S');
            exit(0);
        }
        if(pid_l == 0){
            print_pid('L');
            
            pid_p = fork();

            if(pid_p == 0){
                print_pid('P');
                exit(0);
            }
            exit(0);
        }
    }
    print_pid('R');
    return 0;
}


void print_pid(char name){
    printf("Soy el %c.\n", name);
    printf("Mi ID es %d.\n", getpid());
    printf("El ID de mi padre es %d.\n\n", getppid());
}