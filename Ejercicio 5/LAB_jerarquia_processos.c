#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_file(char file_Name[], int num_array[], int array_size);
void read_file(char file_Name_N[], char file_Name_M[], int array_size);
void print_pid(char name);
int main(){
    /*variables*/
    pid_t pid_N, pid_M = -1;
    char file_Name_M[] = "M.txt";
    char file_Name_N[] = "N.txt";
    /*VARAIBLES*/

    pid_N = fork();

    if( pid_N == 0 ){
        int evenNumArray[10] = { 2, 4, 6, 66, 42, 8, 82, 18, 10, 46 };
        create_file(file_Name_N, evenNumArray, 10);
        print_pid('N');
        exit(0);
    }
    
    pid_M = fork();

    if( pid_M == 0 ){
        int oddNumArray[10] = { 7, 13, 5, 9, 91, 21, 31, 55, 107, 83};
        create_file(file_Name_M, oddNumArray, 10);
        print_pid('M');
        exit(0);
    }

    if( pid_N > 0){
        read_file(file_Name_N, file_Name_M, 10);
        print_pid('P');
    }
    return 0;
}


void create_file(char file_Name[], int num_array[], int array_size){
    int fd, n;
    fd = creat(file_Name, 0777);
    
    n = write(fd, num_array, array_size * sizeof(num_array[0]));

    /*printf("%d", n);*/
    close(fd);
}

void read_file(char file_Name_N[], char file_Name_M[], int array_size){
    /*local variables*/
    int fd, fd_1, m, m_1;
    fd = open(file_Name_M, 0);
    fd_1 = open(file_Name_N, 0);
    int temp_total_addition = 0;
    int num_array_M[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, num_array_N[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    /*LOCAL VARIABLES*/
    
    if( fd < 0 ){
        perror("Error while trying to open the file");
        exit(1);
    }
    else if( fd_1 < 0 ) { 
        perror("Error while trying to open the file");
        exit(1);
    }

    m = read(fd, num_array_M, array_size * sizeof(num_array_M[0]));
    
    m_1 = read(fd_1, num_array_N, array_size * sizeof(num_array_N[0]));
    
    /*printf("%d\n", m);*/
    
    /*printf("%d\n", m_1);*/

    for(int i=0; i < 10; i++){
        temp_total_addition = num_array_M[i] + num_array_N[i];
        /*printf("numbers N = %d", num_array_N[i]);*/
        /*printf("numbers M = %d", num_array_M[i]);*/
        printf("Addition of numbers in position %d: %d\n", (i+1), temp_total_addition);
        temp_total_addition = 0;
    }
    close(fd);
    close(fd_1);
}

void print_pid(char name){
    printf("Soy el %c.\n", name);
    printf("Mi ID es %d.\n", getpid());
    printf("El ID de mi padre es %d.\n\n", getppid());
}
