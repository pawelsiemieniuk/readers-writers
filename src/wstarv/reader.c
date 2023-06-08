#include "../var.h"


void* reader(int* id){
    int thread_id = *id;
    unsigned int reading_time;
    time_t d_time;

    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.writers){
            que.readers--;
            lib.readers++;
            printStatus(thread_id);

            d_time = time(NULL) - threads_last_entry[thread_id];
            if(threads_max_wait_time[thread_id] < d_time){
                threads_max_wait_time[thread_id] = d_time;
            }
            threads_last_entry[thread_id] = time(NULL);

            pthread_mutex_unlock(&lock);
            
            reading_time = rand() % MAX_TIME + 1;
            sleep(reading_time);
            
            pthread_mutex_lock(&lock);
            lib.readers--;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);

            sleep(REST_TIME); 

            pthread_mutex_lock(&lock);
            que.readers++;
            printStatus(thread_id);
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
    }
    
}