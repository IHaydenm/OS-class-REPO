#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


/*functions*/
void print_pid(char name);
void create_file(char file_Name[], int num_array[], int array_size);
void read_file(char file_Name_N[], char file_Name_M[], int array_size);
/*FUNCTIONS*/

int main(){

    /*variables*/
    int num_array[5] = {2, 314, 41, 244, 1};
    int array_size = 5;
    pid_t pid_m = -1;
    char file_name[] = "datos.txt";
    /*VARIABLES*/

    pid_m = fork();

    if(pid_m == 0){
        create_file(file_name, num_array, array_size);
        print_pid('M');
        exit(0);
    }

    sleep(3);

    read_file(file_name, array_size);
    print_pid('Q');
    return 0;
}


void create_file(char file_Name[], int num_array[], int array_size){
    int fd, n;
    fd = creat(file_Name, 0777);
    
    n = write(fd, num_array, array_size * sizeof(num_array[0]));

    close(fd);
}


void read_file(char file_Name[], int array_size){
    /*local variables*/
    int fd, m;
    fd = open(file_Name_M, 0);
    int num_array_read[5] = { 0, 0, 0, 0, 0 };
    /*LOCAL VARIABLES*/
    
    if( fd < 0 ){
        perror("Error while trying to open the file");
        exit(1);
    }

    m = read(fd, num_array_read, array_size * sizeof(num_array_read[0]));

    for(int i=0; i < 5; i++){
        printf("The numbers inside the .txt file are: %d\n", num_array_read[i]);
    }
    close(fd);
}


void print_pid(char name){
    printf("Soy el %c.\n", name);
    printf("Mi ID es %d.\n", getpid());
    printf("El ID de mi padre es %d.\n\n", getppid());
}