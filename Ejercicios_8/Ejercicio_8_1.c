#include <stdio.h>
#include <pthread.h>

int receiving_number(int number){
    if( (number % 3) == 0){
        
    }
}

int F_third_of_number, S_third_of_number, T_third_of_number;
int main(){
    printf("This program will calculate the factorial of a given number.\n Disclaimer: THIS WILL ONLY WORK FOR NUMBERS DIVISIBLE BY 3\n\n");
    int number;
    scanf("%d", &number);
    pthread_t P_id_thread;
    pthread_create(P_id_thread, NULL, receiving_number, number);
}