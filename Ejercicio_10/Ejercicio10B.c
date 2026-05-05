#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

/*variables*/
pthread_mutex_t mutex;
pthread_cond_t condition;

int counter = 1;
int even_turn = 0;
bool is_running_even = true;
bool is_running_odd = true;
/*VARIABLES*/

void* odd_thread(void* arg){
    while(is_running_odd){
        pthread_mutex_lock(&mutex);
        while(even_turn == 1 && is_running_even){
            pthread_cond_wait(&condition, &mutex);
        }

        if(counter > 100){
            is_running_odd = false;
            pthread_cond_signal(&condition);
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("Odds: %d\n", counter);
        counter++;
        even_turn = 1;
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* even_thread(void* arg){
    while(is_running_even){
        pthread_mutex_lock(&mutex);
        while(even_turn == 0 && is_running_odd){
            pthread_cond_wait(&condition, &mutex);
        }
        if(counter > 100){
            is_running_even = false;
            pthread_cond_signal(&condition);
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("Evens: %d\n", counter);
        counter++;
        even_turn = 0;
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(){
    pthread_t thread_even, thread_odd;
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&condition, 0);

    pthread_create(&thread_even, NULL, even_thread, NULL);
    pthread_create(&thread_odd, NULL, odd_thread, NULL);

    pthread_join(thread_even, NULL);
    pthread_join(thread_odd, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);

    return 0;
}