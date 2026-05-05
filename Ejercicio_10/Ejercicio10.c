#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mutex;
pthread_cond_t right_key_cond;
int R_key = 0;
int L_key = 0;

void* right_key_turning(void* arg){
    pthread_mutex_lock(&mutex);
    R_key = 1;
    pthread_cond_signal(&right_key_cond);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void* left_key_turning(void* arg){
    pthread_mutex_lock(&mutex);
    while(R_key != 1){
        pthread_cond_wait(&right_key_cond, &mutex);
    }
    L_key = 1;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}


int main(){
    pthread_t key_lock_1, key_lock_2;
    pthread_mutex_init(&mutex, 0)
    pthread_cond_init(&right_key_cond, 0);

    pthread_create(&key_lock_1, NULL, right_key_turning, NULL);
    pthread_create(&key_lock_2, NULL, left_key_turning, NULL);
    
    pthread_join(key_lock_1, NULL)
    return 0;
}