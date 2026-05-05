#include <stdio.h>
#include <pthread.h>

/*def*/
#define max_count 1000
#define thread_count 1000
/*DEF*/
/*variables*/
int account_a = 1000000;
int account_b = 1000000;
pthread_mutex_t mutexid; 
/*VARIABLES*/
void* increase_decrease_counter(void *arg){
    
    for(int i=0; i<max_count; i++){
        /*including mutex*/
        pthread_mutex_lock(&mutexid);
        account_a--;
        account_b++;
        pthread_mutex_unlock(&mutexid);
        
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads_IDS[thread_count];
    pthread_mutex_init(&mutexid, 0);
    for(int i=0;i<thread_count;i++){
        pthread_create(&threads_IDS[i], NULL, increase_decrease_counter, NULL);
    }
    
    // WAIT for threads 
    for(int i=0;i<thread_count;i++) {
        pthread_join(threads_IDS[i], NULL);
    }

    pthread_mutex_destroy(&mutexid);

    printf("This is the final count of account_b: %d.\n\nThis is the final count of account_a: %d\n", account_b, account_a);
    return 0;

}