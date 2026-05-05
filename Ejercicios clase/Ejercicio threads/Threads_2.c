/*
    Program that creates 10 theads that print Hola mundo.
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_NO 10

/* Print even number and kill the thread. */
void *print_even_number( void *args )
{
    printf( "Hola, soy un hilo par.\n" );
    pthread_exit( NULL );
}

/* Print odd number and kill the thread. */
void *print_odd_number( void *args )
{
    printf( "Hola, soy un hilo impar.\n" );
    pthread_exit( NULL );
}


int main()
{
    pthread_t threads[THREADS_NO];
    int state, i;
    
    for(i=0; i < THREADS_NO; i++) 
    {
        if(i%2 == 0){
            // Thread creation
            pthread_create( &threads[i], NULL, print_even_number, NULL );
        }
        else{
            // Thread creation
            pthread_create( &threads[i], NULL, print_odd_number, NULL );
        }
        printf( "Main creo un hilo en la iteración %d.\n", i );
    }
    for(int j=0; i < THREADS_NO; i++){
        pthread_join(threads[j], NULL);
    }
    exit(0);
}