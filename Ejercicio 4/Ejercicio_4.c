#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>




int main(){
    /*variables*/
    char file_name[] = "Array.txt";
    int fd, n, m;
    float num_array[] = {1.45, 75.6, 2.6, 12.1, 3.3, 25.1};
    /*VARIABLES*/
    fd = creat(file_name, 0777);
    printf("The file %c will open shortly\n", file_name);
    fileDescriptor(fd, n, m, file_name);
    return 0; 
}

void fileDescriptor(int fd, int n, int m, char[] file_name, float num_array[]){
    if(fd < 0 )
    {
        if(errno == EGAIN){
            perror("Error");
            printf("The file you are trying to access is blocked. Ask for help in order to enable the access to %c\n", file_name);
        }
        if(errno == EACCESS){
            perror("Error");
            printf("You don't have the permissions necessary in order to access the file %c\n", file_name);
        }   
        if(errno == EBADF){
            perror("Error");
            printf("WARNING: The file descriptor is not the apropiate one.\n");
            exit(1);
        }
        else{
            perror("Error");
            printf("Something happened while opening the file %c\n", file_name);
        }
    }//if error brackets
    else 
    {
        int op;
        printf("Would you like to read or write in the file. Please write 1 for read OR write 2 for write (Press 0 to exit): ");
        scanf("%d", &op);
        if(op == 1){
            fileReadFunction(fd, n, m, num_array);
        }
        else if(op == 2){
            fileWriteFunction(fd, n, m, num_array);
        }
        else if(op == 0 ){
            exit(0);
        }
        else(
            printf("The input was invalid. Please try again.\n")
        )
    }// lse success brackets
}//function brackets


void fileReadFunction(int fd, int n, int m, float num_array){
    n = read(fd, &num_array, sizeof(num_array));
}

void fileWriteFunction(){
    m = read(fd, &num_array, sizeof(num_array));
}