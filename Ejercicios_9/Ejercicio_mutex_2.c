#include <stdio.h>
#include <pthread.h>

/*def*/
#define SIZE 1000
#define thread_count 1000
/*DEF*/

/*variables*/
int current_i = 0;
int buffer_index = 0;
int buffer[SIZE];
pthread_mutex_t mutexid;
/*VARIABLES*/

void* increase_buffer_counter(void *arg){
    for(int i=0; i<SIZE; i++){
        pthread_mutex_lock(&mutexid);
        buffer[buffer_index] = current_i;
        buffer_index++;
        current_i++;
        pthread_mutex_unlock(&mutexid);
        pthread_exit( NULL );
    }
}




int main(){
    pthread_t thread_ids[thread_count];
    //creating mutex 
    pthread_mutex_init(&mutexid, 0);
    //creating threads
    for(int i=0;i<thread_count;i++){
        pthread_create(&thread_ids[i], NULL, increase_buffer_counter, NULL);
    }

    //WAIT for the threads to finish
    for(int i=0;i<thread_count;i++){
        pthread_join(thread_ids[i], NULL);
    }
    pthread_mutex_destroy(&mutexid);

    //checking for any values inside of buffer[] that are 
    for(int i=0; i<SIZE; i++){
        if(buffer[i]==0){
            printf("A value inside buffer[] is 0.\n This is its position %d\n\n", i);
        }
        /*printf("full buffer[] contents: %d", buffer[i]);*/
    }


    return 0;
}