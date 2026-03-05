#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(){
    /*variables*/
    int num_array[5] = {2, 314, 41, 244, 1};
    int buffer = 5;
    int fd, n, m;
    pid_t pid_m = -1;
    char file_name[] = "datos.txt";
    /*VARIABLES*/
    pid_m = fork();
    if(pid_m == 0){
        fd = creat(file_name, 0777);
        n = write(fd, num_array, sizeof(num_array));
    }
    sleep(3);
    else{
        if(fd < 0 ){
            perror("Error in file: ");
            exit(0);
        }
        fd = open(file_name, O_RDONLY, 0);
        m = read(fd, buffer, sizeof(buffer));
    }

}