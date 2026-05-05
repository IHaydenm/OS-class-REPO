#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/*def*/
#define threads 10
#define max_conexiones 3
/*DEF*/

/*variables*/
int active_connections = 0;

pthread_t thread_ids[threads];
sem_t semaphore;
/*VARIABLES*/

void* use_DB(void *arg){
    sem_wait(&semaphore);
    active_connections++;
    printf("Thread is now connected!: Current active connections%d\n", active_connections);
    sleep(1);
    active_connections--;
    sem_post(&semaphore);
    pthread_exit(NULL);
}

int main(){
    sem_init(&semaphore, 0, max_conexiones);
    for(int i = 0; i < threads; i++){
        pthread_create(&thread_ids[i], NULL, use_DB, NULL);
    }
    for(int i = 0; i < threads; i++){
        pthread_join(thread_ids[i], NULL);
    }
    sem_destroy(&semaphore);
    printf("\nConexiones activas finales: %d\n", active_connections);

    return 0;
}